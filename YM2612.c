
#include "YM2612.h"
#include "YM2612_Presets.h"
#include "YM2612_Note_Picker.h"
#include "YM2612_Songs.h"
#include "YM_MIDI_KeyCodes.h"

static const int bus = 0;			//MCP23S17 parameters
static int chip_select; //this is defined later, multiple SPI expanders can be involved
static const int hw_addr = 0;

static int last_channel = 0;//last number of channels playing
 
int mcp23s17_fd;	//for YM3438 #1
//static int mcp23s17_fd_2; //for YM3438 #2
//static int mcp23s17_fd_2; //for YM3438 #3

static int num_YMchips = 1; //We only have one working FM chip for now
 
static int octave = 3;
static int last_octave = 0;

static int note_num;

static char Keyboard_Mode[16] = "YM3438      MIDI";

static char * KeyPins[13] = {"17","27","22","5","6","13","19","26","21","20","16","12","25"}; //Corresponding GPIO pin numbers for each key, in an array for scanning
																							  //Ordered w/ sharps, as shown below:
						  //{C, C#, D, D#, E, F, F#, G, G#, A, A#, B, C(oct+1)}
static int KeyStatus[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0}; //Hold the current status of key
static int Prev_KeyStatus[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0}; //Hold previous status of key
 
//Define bit numbers
static const uint8_t YM_IC = 5;
static const uint8_t YM_A0 = 3;
static const uint8_t YM_A1 = 4;
static const uint8_t YM_WR = 1;
static const uint8_t YM_RD = 2;
static const uint8_t YM_CS = 0;

static const uint8_t SN_CE = 6;
static const uint8_t SN_WE = 7;		//important select lines for the SN76489AN, used to reset it as it is not used in this function.

static uint8_t YM_CTRL_PORT = 0x00; //keeping track of the control port value

int Play_YM2612(int mode, char * path, char * direction, char * value, char* active_low, int str_pos){  //Play the YM2612 on the keyboard
	
	//Channel_Info CI = {{0,0,0,0,0,0},{0,0,0,0,0,0},0,0}; //initialize all members of the channel info struct
	
	char * Current_Voice = "Basic           "; //The default instrument is the piano
	int cur_voice = 0;
	int last_voice = 1;
	int returning_from_menu = 0;
	char * Current_Octave = "3"; //default octave is 3
	char * Default_Note = " "; //no note by default
	char * BlankSharp = " "; //not sharp by default
	LCD_sendString("YM3438  Loading ", 1);
	LCD_sendString("Please wait...  ", 2);
	setup_chips();
	YM_Basic(); //Default voice is the Grand Piano from the Application manual
	LCD_sendString(Current_Voice, 2);
	LCD_WritePos(2, 14, Current_Octave);
	LCD_WritePos(2, 13, Default_Note);

	int run = 1; //Integer controls when the function exits
	int menu; // keeps the menu open until user does something
	int preset;
	int song;
	int song_loop; //int that is 1 when a song is playing and is 0 when user wants to leave
	int song_select;
	int menu_select; //Selection in the menu
	int preset_select; //Selection in preset menu
	int preset_menu;
	
	//YM2612_Square();
	//while(1) YM_Test();
	
	while(run == 1)
	{
		YM2612_Begin:
		
		MIDI_2612(path, direction, value, active_low, str_pos);
		LCD_sendString(Keyboard_Mode, 1);
		
		if(pin_read("15", value, path, str_pos) == 0x31) { //Open menu for YM module, a way to switch or quit programs
			YM_menu_start:
			usleep(150000); //gives user time to release button without menu exiting (150ms)
			LCD_sendString("YM3438 Mode Menu", 1);
			menu = 1;
			menu_select = 0;
			preset = 0;
			while(menu == 1){
				while(menu_select == 0) {
					LCD_sendString("->Resume   Patch", 2);
					if(pin_read("18", value, path, str_pos) == 0x31){
						usleep(150000);
						menu_select = 3;
					}
					if(pin_read("14", value, path, str_pos) == 0x31){
						usleep(150000);
						menu_select = 1;
						continue;
					}
					if(pin_read("15", value, path, str_pos) == 0x31){
						usleep(150000);
						returning_from_menu = 1;
						menu = 0;
					 }
					 if(menu==0) break;
				}
				while(menu_select == 1) {
					LCD_sendString("  Resume ->Patch", 2);
					if(pin_read("18", value, path, str_pos) == 0x31){
						usleep(150000);
						menu_select = 0;
					}
					if(pin_read("14", value, path, str_pos) == 0x31){
						usleep(150000);
						menu_select = 2;
					}
					if(pin_read("15", value, path, str_pos) == 0x31){
						preset_menu_start:
						usleep(150000);
						preset = 1;
						preset_select = 0;
						while(preset == 1){
							LCD_sendString("Preset Selection", 1);
							while(preset_select == 0) {
								LCD_sendString("->Return to Menu", 2);
								if(pin_read("18", value, path, str_pos) == 0x31){
								usleep(150000);
								preset_select = 9;
								}
								if(pin_read("14", value, path, str_pos) == 0x31){
									usleep(150000);
									preset_select = 1;
								}
								if(pin_read("15", value, path, str_pos) == 0x31){
									usleep(150000);
									preset = 0;
								}
								if(preset==0) {
									goto YM_menu_start;
									break;
								}
							}
							while(preset_select == 1) {
								LCD_sendString("->Gnd Piano     ", 2);
								if(pin_read("18", value, path, str_pos) == 0x31){
								usleep(150000);
								preset_select = 0;
								}
								if(pin_read("14", value, path, str_pos) == 0x31){
									usleep(150000);
									preset_select = 2;
								}
								if(pin_read("15", value, path, str_pos) == 0x31){
									usleep(150000);
									Current_Voice = "Grd Piano       ";
									cur_voice = 0;
									reset_2612();
									YM2612_Grand_Piano();
									preset_select = 1;
									returning_from_menu = 1;
									goto YM2612_Begin;
								}
							}
							while(preset_select == 2) {
								LCD_sendString("->Guitar        ", 2);
								if(pin_read("18", value, path, str_pos) == 0x31){
								usleep(150000);
								preset_select = 1;
								}
								if(pin_read("14", value, path, str_pos) == 0x31){
									usleep(150000);
									preset_select = 3;
								}
								if(pin_read("15", value, path, str_pos) == 0x31){
									usleep(150000);
									Current_Voice = "Guitar          ";
									cur_voice = 1;
									reset_2612();
									YM2612_Guitar();
									preset_select = 1;
									returning_from_menu = 1;
									goto YM2612_Begin;
								}
							}
							while(preset_select == 3) {
								LCD_sendString("->Trumpet       ", 2);
								if(pin_read("18", value, path, str_pos) == 0x31){
								usleep(150000);
								preset_select = 2;
								}
								if(pin_read("14", value, path, str_pos) == 0x31){
									usleep(150000);
									preset_select = 4;
								}
								if(pin_read("15", value, path, str_pos) == 0x31){
									usleep(150000);
									Current_Voice = "Trumpet         ";
									cur_voice = 2;
									reset_2612();
									YM2612_Trumpet();
									preset_select = 1;
									returning_from_menu = 1;
									goto YM2612_Begin;
								}
							}
							while(preset_select == 4) {
								LCD_sendString("->Pad           ", 2);
								if(pin_read("18", value, path, str_pos) == 0x31){
								usleep(150000);
								preset_select = 3;
								}
								if(pin_read("14", value, path, str_pos) == 0x31){
									usleep(150000);
									preset_select = 5;
								}
								if(pin_read("15", value, path, str_pos) == 0x31){
									usleep(150000);
									Current_Voice = "Pad             ";
									cur_voice = 3;
									reset_2612();
									YM2612_Pad();
									preset_select = 1;
									returning_from_menu = 1;
									goto YM2612_Begin;
								}
							}
							while(preset_select == 5) {
								LCD_sendString("->Square Wave   ", 2);
								if(pin_read("18", value, path, str_pos) == 0x31){
								usleep(150000);
								preset_select = 4;
								}
								if(pin_read("14", value, path, str_pos) == 0x31){
									usleep(150000);
									preset_select = 6;
								}
								if(pin_read("15", value, path, str_pos) == 0x31){
									usleep(150000);
									Current_Voice = "Square Wave     ";
									cur_voice = 4;
									reset_2612();
									YM2612_Square();
									preset_select = 1;
									returning_from_menu = 1;
									goto YM2612_Begin;
								}
							}
							while(preset_select == 6) {
								LCD_sendString("->Drums         ", 2);
								if(pin_read("18", value, path, str_pos) == 0x31){
								usleep(150000);
								preset_select = 5;
								}
								if(pin_read("14", value, path, str_pos) == 0x31){
									usleep(150000);
									preset_select = 7;
								}
								if(pin_read("15", value, path, str_pos) == 0x31){
									usleep(150000);
									Current_Voice = "Drums           ";
									cur_voice = 5;
									reset_2612();
									YM2612_Drums();
									preset_select = 1;
									returning_from_menu = 1;
									goto YM2612_Begin;
								}
							}
							while(preset_select == 7) {
								LCD_sendString("->SS-EG         ", 2);
								if(pin_read("18", value, path, str_pos) == 0x31){
								usleep(150000);
								preset_select = 6;
								}
								if(pin_read("14", value, path, str_pos) == 0x31){
									usleep(150000);
									preset_select = 8;
								}
								if(pin_read("15", value, path, str_pos) == 0x31){
									usleep(150000);
									Current_Voice = "SS-EG           "; //this instrument sounds like a voice, kind of
									cur_voice = 6;
									reset_2612();
									YM2612_SSEG();
									preset_select = 1;
									returning_from_menu = 1;
									goto YM2612_Begin;
								}
							}
							while(preset_select == 8) {
								LCD_sendString("->Dist. Bass    ", 2);
								if(pin_read("18", value, path, str_pos) == 0x31){
								usleep(150000);
								preset_select = 7;
								}
								if(pin_read("14", value, path, str_pos) == 0x31){
									usleep(150000);
									preset_select = 9;
								}
								if(pin_read("15", value, path, str_pos) == 0x31){
									usleep(150000);
									Current_Voice = "Dist. Bass      ";
									cur_voice = 7;
									reset_2612();
									YM2612_DistBass();
									preset_select = 1;
									returning_from_menu = 1;
									goto YM2612_Begin;
								}
							}
							while(preset_select == 9) {
								LCD_sendString("->Weird         ", 2);
								if(pin_read("18", value, path, str_pos) == 0x31){
								usleep(150000);
								preset_select = 8;
								}
								if(pin_read("14", value, path, str_pos) == 0x31){
									usleep(150000);
									preset_select = 0;
								}
								if(pin_read("15", value, path, str_pos) == 0x31){
									usleep(150000);
									Current_Voice = "Weird           ";
									cur_voice = 8;
									reset_2612();
									YM2612_Weird();
									preset_select = 1;
									returning_from_menu = 1;
									goto YM2612_Begin;
								}
							}
						}
					}
				}
				while(menu_select == 2) {
					LCD_sendString("  Patch  ->Songs", 2);
					if(pin_read("18", value, path, str_pos) == 0x31){
						usleep(150000);
						menu_select = 1;
					}
					if(pin_read("14", value, path, str_pos) == 0x31){
						usleep(150000);
						menu_select = 3;
					}
					if(pin_read("15", value, path, str_pos) == 0x31){
						usleep(150000);
						song = 1;
						while(song == 1){
							YM_songMenu:
							LCD_sendString("Song Selection  ", 1);
							song_select = 0;
							while(song_select == 0) {
								LCD_sendString("->Return to Menu", 2);
								if(pin_read("18", value, path, str_pos) == 0x31){
									usleep(150000);
									song_select = 1;
								}
								if(pin_read("14", value, path, str_pos) == 0x31){
									usleep(150000);
									song_select = 1;
								}
								if(pin_read("15", value, path, str_pos) == 0x31){
									usleep(150000);
									song = 0;
								}
								if(song==0) {
									goto YM_menu_start;
									break;
								}
							}
							while(song_select == 1) {
								LCD_sendString("->Alarm         ", 2);
								if(pin_read("18", value, path, str_pos) == 0x31){
									usleep(150000);
									song_select = 0;
								}
								if(pin_read("14", value, path, str_pos) == 0x31){
									usleep(150000);
									song_select = 0;
								}
								if(pin_read("15", value, path, str_pos) == 0x31){
									LCD_sendString("Current Song:   ", 1);
									LCD_sendString("Alarm           ", 2);
									usleep(150000);
									song_loop = 1;
									while(song_loop == 1){
										Alarm_2612();
										if(pin_read("15", value, path, str_pos) == 0x31){
											song_loop = 0;
										}
										if(song_loop == 0){ //reset the chip and go back to default instrument, avoids note staying on
											reset_2612();
											YM2612_Grand_Piano();
											Current_Voice = "Gnd Piano       ";
											cur_voice = 0;
											break;
										}
									}
									goto YM_songMenu;
								}
							}
						}
					 }
				}
					while(menu_select == 3) {
					LCD_sendString("  Songs  ->Main ", 2);
					if(pin_read("18", value, path, str_pos) == 0x31){
						usleep(150000);
						menu_select = 2;
					}
					if(pin_read("14", value, path, str_pos) == 0x31){
						usleep(150000);
						menu_select = 0;
					}
					if(pin_read("15", value, path, str_pos) == 0x31){
						usleep(150000);
						run = 0;
						goto YM_end;	//exit the entire function
					 }
				}
			}
		}
		else if(pin_read("18", value, path, str_pos) == 0x31){
			usleep(150000);
			octave--;
			if(octave<1) octave = 1;
			
			Current_Octave = Octave_String(octave);
			
		}
		else if(pin_read("14", value, path, str_pos) == 0x31){
			usleep(150000);
			octave++;
			if(octave>6) octave = 6;
			
			Current_Octave = Octave_String(octave);
			
		}
		else { //everything here is lower priority than the keys!
			LCD_sendString(Keyboard_Mode, 1);
			if(cur_voice != last_voice){
				LCD_sendString(Current_Voice, 2); //show nothing for note
				cur_voice = last_voice;
			}
				
			if(octave != last_octave){
				LCD_WritePos(2, 14, Current_Octave);
				last_octave = octave;
			}
			if(returning_from_menu == 1){
				LCD_sendString(Current_Voice, 2);
				LCD_WritePos(2, 14, Current_Octave);
				returning_from_menu = 0;
			}
			LCD_WritePos(2, 13, Default_Note);
			LCD_WritePos(2, 15, BlankSharp);
		}
	}
	YM_end:
	reset_2612(); //make sure the chip stops before exiting to menu
	close(mcp23s17_fd); //close the file descriptor for the SPI GPIO expander, but only happens if you exit this way!
	printf("Returning to main menu...\n");
	return 0;
 }
 
 static int MCPS_init(int num_YMchips){
	
	/*	Support 3 YM3438 Chips at any given time (eventually)
	 * 	For a total of 18 voices (More than the Yamaha DX7!)
	 *
	 *	MCP23S17 #1: Connected to YM3438 #1
	 *				 Connected to SN76489AN #1 (only one?)
	 * 				 -Shared data lines, separate control pins for SN76489AN
	 *
	 *  MCP23S17 #2: Connected to YM3438 #2
	 * 	
	 * MCP23S17 #3: Connected to YM3438 #3
	 * 
	 * 	The MCP23S17 chips can be daisy chained on the same SPI bus, as long as the chip select is changed
	 * 	(1st CS is 0, 2nd is 1, etc.)
	 *
	 */
	 
	if(num_YMchips == 1) chip_select = 0; //2 will be on 1 mcp, sharing most lines (will see how that works)
	else if(num_YMchips == 2) chip_select = 1;
	else if(num_YMchips == 3) chip_select = 2;
	else {
			printf("Invalid number of YM chips called... setting chip select to 0 for now.\n");
			chip_select = 0;
		}
		
	for(chip_select; chip_select > -1; chip_select--){
		
	    mcp23s17_fd = mcp23s17_open(bus, chip_select); //need to do something about this to actually make it dynamic
	    //mcp23s17_fd_2 = mcp23s17_open(bus, chip_select);
	
	    // config register, SEQOP_ON -> sequential execution (MSB -> LSB?)
	    const uint8_t ioconfig = BANK_OFF | \
	                             INT_MIRROR_OFF | \
	                             SEQOP_ON | \
	                             DISSLW_OFF | \
	                             HAEN_ON | \
	                             ODR_OFF | \
	                             INTPOL_LOW;
	                             
	    mcp23s17_write_reg(ioconfig, IOCON, hw_addr, mcp23s17_fd);
	    
	    mcp23s17_write_reg(0xC0, IODIRA, hw_addr, mcp23s17_fd); //Only YM control pins are active on GPIO A
	    mcp23s17_write_reg(0x00, IODIRB, hw_addr, mcp23s17_fd); //0x00 turns all output, 0xff turns all input
	    
	    mcp23s17_write_reg(0xff, GPPUA, hw_addr, mcp23s17_fd); //Turn off pull-up resistors for both
	    mcp23s17_write_reg(0xff, GPPUB, hw_addr, mcp23s17_fd);
	    
	    mcp23s17_write_reg(0x00, IOCON, hw_addr, mcp23s17_fd); //Sequential addressing mode 
	    
	    mcp23s17_write_reg(0xff, GPIOA, hw_addr, mcp23s17_fd); //Set all ports HIGH
	    mcp23s17_write_reg(0xff, GPIOB, hw_addr, mcp23s17_fd);
    }
	return 0;
}

static void write_2612(uint8_t data){
	YM_CTRL_PORT &= ~_BV(YM_CS); //Set YM_CS LOW (Inverted), telling the chip that we are communicating with it
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd); //Write to register to apply change
	mcp23s17_write_reg(data, GPIOB, hw_addr, mcp23s17_fd); //Write the data to the chip, is now ready for input
	//printf("Write DATA is %02X\n", data); //debug
	usleep(1);
	YM_CTRL_PORT &= ~_BV(YM_WR); // Set WR LOW, telling chip we are finished writing data
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd); //apply change
	usleep(1);
	YM_CTRL_PORT |= _BV(YM_WR); //Set WR HIGH
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd); //apply change
	usleep(1);
	YM_CTRL_PORT |= _BV(YM_CS); // CS HIGH, done communicating with chip
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd);
	//printf("				WR_CTRL %02X\n", YM_CTRL_PORT); //debug info
}

void setreg(uint8_t reg, uint8_t data, uint8_t channel){
	/*	To write to channels 4, 5, and 6:
	 * 	You need to set A1 HIGH as well!
	 */
	YM_CTRL_PORT &= ~_BV(YM_A0); // A0 low (select register), tell chip we are choosing register to write to
	if(channel > 2) {
		YM_CTRL_PORT |= _BV(YM_A1);
		data += ((channel << 2)&1);
	}
	//printf("				setreg addr ST_CTRL %02X\n", YM_CTRL_PORT); //debug information
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd); //apply change
	write_2612(reg); //tell chip what address we want to address
	YM_CTRL_PORT |= _BV(YM_A0);  // A0 high (write register), tells chip that we are writing values to previously selected register
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd); //apply change
	write_2612(data); //write the data to the chosen register from earlier
	//printf("				setreg data ST_CTRL %02X\n", YM_CTRL_PORT); //debug information
	YM_CTRL_PORT &= ~_BV(YM_A0); //Set A0 low for next time
	YM_CTRL_PORT &= ~_BV(YM_A1); //Set A1 low if it already isn't (for addressing parallel banks)
}

void reset_2612(void){
	YM_CTRL_PORT &= ~_BV(YM_IC); //Set IC LOW (inverted)
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd); //apply change
	usleep(10);
	YM_CTRL_PORT |= _BV(YM_IC); //Set IC high (inverted)
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd); //apply, this resets all of the set data on the chip
	usleep(10);
}

static void setup_2612(void){
	reset_2612(); //reset chip to get blank slate
	YM_CTRL_PORT |= _BV(YM_IC) | _BV(YM_CS) | _BV(YM_WR) | _BV(YM_RD); /* IC, CS, WR and RD HIGH by default */
	YM_CTRL_PORT &= ~(_BV(YM_A0) | _BV(YM_A1)); /* A0 and A1 LOW by default */
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd); //apply changes to control register
	// printf("Setup ctrl is %02X\n", YM_CTRL_PORT); //debug
	printf("\n\nYM2612 setup complete!\n\n");		 //debug
	usleep(10);											 
}

void setup_chips(void){
	MCPS_init(num_YMchips); //initialize mcp23s17
	setup_2612(); //initialize YM2612
}

static void YM_Test(void){ //Turns a note on and off, but must choose a preset first to use
		setreg(0x28, 0xf0, 0); // Key on
		setreg(0x28, 0xf1, 0); // Key on
		setreg(0x28, 0xf2, 0); // Key on
		usleep(1000000);
		setreg(0x28, 0x00, 0); // Key off
		setreg(0x28, 0x01, 0); // Key off
		setreg(0x28, 0x02, 0); // Key off
		usleep(1000000);
}

static void Quiet_SN(void){ //make sure the SN76489AN doesn't interrupt playing the YM3438 with its noise
	
}

static char * Octave_String(int octave){ //returns an octave string from a representative octave int. Only 8 octaves are used on the chip, I'm using 6 of them (plus C7).
	char * retval;
	switch(octave) {
		case 0: retval = "0"; //Including 0 if I change my mind later
				break;
				
		case 1: retval = "1";
				break;
				
		case 2: retval = "2";
				break;
				
		case 3: retval = "3";
				break;
				
		case 4: retval = "4";
				break;
				
		case 5: retval = "5";
				break;
				
		case 6: retval = "6";
				break;
				
		case 7: retval = "7";
				break;
				
		default: printf("Invalid octave value!\n");
				 break;
		}
		return retval;
}

//SCAN KEYS: depreciated
//void scan_keys(char * path, char * direction, char * value, char* active_low, int str_pos) { //one key at a time, much more efficient than previous implementation
	//int coctave;
	//for(int arrnum = 0; arrnum<13; arrnum++){ //scan through the KeyPin array using arrnum index
		//if(pin_read(KeyPins[arrnum], value, path, str_pos) == 0x31){ //read the GPIO pin specified at the "arrnum"th position in the KeyPin array
			
			//if(strcmp("25", KeyPins[arrnum]) == 0) coctave = octave+1; //Key 25 is the additional C key in the next octave
			//else coctave = octave;
			
			//note_num = KeyVal(KeyPins[arrnum]);
			//note_picker(note_num, coctave);
	
			//setreg(0x28, 0xf0, 0); // CH1 Key on
			
			//while(pin_read(KeyPins[arrnum], value, path, str_pos) == 0x31){
				//LCD_WritePos(2, 13, NoteString(note_num)); //convert note number to corresponding string and write it to lcd
				//LCD_WritePos(2, 14, Octave_String(coctave)); //write octave to lcd
				//LCD_WritePos(2, 15, SharpCheck(note_num)); //write a sharp indicator to the screen if it is indeed a sharp (black key)
			//}
			
			//setreg(0x28, 0x00, 0); // CH1 Key off
			
			//last_octave = coctave;
			
		//}
	//}
//}

//void scan_multiKeys(char * path, char * direction, char * value, char* active_low, int str_pos, Channel_Info CI){ //WIP	
//	int coctave;																			 					  //when completed, scan_keys will be depreciated
//	for(int x = 0; x < 12; x++){
//		if(pin_read(KeyPins[x], value, path, str_pos) == 0x31){
//			KeyStatus[x] = 1;
//			if(KeyStatus[x] != Prev_KeyStatus[x]){
//				CI.Channels++;
//				//note_picker_multi(KeyVal(KeyPins[x]), octave, CI.Channels);
//				CI = channel_handler(CI); 
//			}
//		}
//	}
//	
//	for(int x = 0; x < 12; x++){
//		if(pin_read(KeyPins[x], value, path, str_pos) != 0x31){
//			KeyStatus[x] = 0;
//			if(KeyStatus[x] != Prev_KeyStatus[x]){
//				CI.Channels--;
//			    CI = channel_handler(CI); 
//			}
//		}
//	}
//	
//	memcpy(KeyStatus, Prev_KeyStatus, sizeof(KeyStatus)); //set both arrays equal at the end
//	
//	printf("					Current Channels = %d\n", CI.Channels);
//	printf("					Previous Channels = %d\n\n", CI.Prev_Channels);
//}

//static char * KeyPins[13] = {"17","27","22","5","6","13","19","26","21","20","16","12","25"}
int KeyVal(char * key){ //return int keycodes to set notes, intended to be used with note_picker
		if(strcmp("17", key) == 0) return 1;
		else if(strcmp("27", key) == 0) return 2; //sharp
		else if(strcmp("22", key) == 0) return 3;
		else if(strcmp("5", key) == 0) return 4;  //sharp
		else if(strcmp("6", key) == 0) return 5;
		else if(strcmp("13", key) == 0) return 6; 
		else if(strcmp("19", key) == 0) return 7;  //sharp
		else if(strcmp("26", key) == 0) return 8;  
		else if(strcmp("21", key) == 0) return 9;  //sharp
		else if(strcmp("20", key) == 0) return 10;
		else if(strcmp("16", key) == 0) return 11;  //sharp
		else if(strcmp("12", key) == 0) return 12; 
		else if(strcmp("25", key) == 0) return 1; //but increase octave by 1
		else {	//none of them match!
			printf("Invalid GPIO pin!\n");
			return 0;
		}
			 
}

char * KeyStatus_Updater(char * KeyStatus, char * LastKeyStatus){
	
}

char * NoteString(int note_num){ //returns letter note value for LCD, does not care if sharp or not
	switch(note_num){
		case 1: return "C";
		case 2: return "C"; //sharp
		case 3: return "D";
		case 4: return "D"; //sharp
		case 5: return "E";
		case 6: return "F";
		case 7: return "F"; //sharp
		case 8: return "G";
		case 9: return "G"; //sharp
		case 10: return "A";
		case 11: return "A"; //sharp
		case 12: return "B";
		default: printf("Invalid note_num!\n");
				 break;
	}
}

char * SharpCheck(int note_num){
	switch(note_num){ //for putting the '#' indicator on the LCD for the proper note
		case 2: return "#";
		case 4: return "#";
		case 7: return "#";
		case 9: return "#";
		case 11: return "#";
		default: return " "; //return blank character
	}
}

static void Note_ToggleHandler(char * state, int ch){ //toggles a note on and off on a specified channel, uses strings for input
	if(strcmp("ON", state) == 0){
		switch(ch){
			case 1: CH1_ON;
					break;
			case 2: CH2_ON;
					break;
			case 3: CH3_ON;
					break;
			case 4: CH4_ON;
					break;
			case 5: CH5_ON;
					break;
			case 6: CH6_ON;
					break;
			default: printf("Invalid channel number in Note_ToggleHandler!\n");
					 break;
			}
		}
	else if(strcmp("OFF", state) == 0){
		switch(ch){
			case 1: CH1_OFF;
					break;
			case 2: CH2_OFF;
					break;
			case 3: CH3_OFF;
					break;
			case 4: CH4_OFF;
					break;
			case 5: CH5_OFF;
					break;
			case 6: CH6_OFF;
					break;
			default: printf("Invalid channel number in Note_ToggleHandler!\n");
					 break;
			}
		}
	else {
			printf("Invalid note state in Note_ToggleHandler!\n");
		}
	printf("Channel %d: %s\n\n", ch, state);
}

////////////////MIDI FUNCTIONS  /////////////////////////
const int YM_MAX_CHANNELS = 6;

char channel_tracker[6] = {0,0,0,0,0,0};

static int menu_active = 0;
static int selection = 0;

int MIDI_2612(char * path, char * direction, char * value, char* active_low, int str_pos){
	
	//for(int i = 0; i < YM_MAX_CHANNELS; i++) channel_tracker[i] = 0; //init all channel placeholders 
	//LCD_sendString("YM3438  Loading ", 1);
	//LCD_sendString("Please wait...  ", 2);
	
	
	//keyboard_setup(path, direction, value, active_low, str_pos);
	//setup_chips();
	//YM2612_Grand_Piano();
   
   int status;
   int mode = SND_RAWMIDI_NONBLOCK;
   snd_rawmidi_t* midiin = NULL;
   const char* portname = "hw:1,0,0";  // see alsarawportlist.c example program
   
   if ((status = snd_rawmidi_open(&midiin, NULL, portname, mode)) < 0) {
      MIDI_errormessage("Problem opening MIDI input: %s", snd_strerror(status));
      exit(1);
   }

   //int maxcount = 1000;   // Exit after this many bytes have been received.
   int count = 0;         // Current count of bytes received.
   char buffer[1];        // Storage for input buffer received
   char * output = malloc(3);
   while (1) {
      status = 0;
      while (status != -EAGAIN) {
         status = snd_rawmidi_read(midiin, buffer, 1);
         
         //if(MIDI_menu(path, direction, value, active_low, str_pos, menu_active, selection) == -1);
         
         if ((status < 0) && (status != -EBUSY) && (status != -EAGAIN)) {
            MIDI_errormessage("Problem reading MIDI input: %s",snd_strerror(status));
         } else if (status >= 0) 
            if ((unsigned char)buffer[0] >= 0x80) {  // print command in hex
               //printf("0x%x ", (unsigned char)buffer[0]);
               output[count] = buffer[0]; //put buffered value into output array

            } else {
               //printf("%d ", (unsigned char)buffer[0]);
               output[count+1] = buffer[0]; //put buffered value into output array
               count++;
            }
            fflush(stdout);
            if (count == 2) {
               //printf("Stored Output Value: 0x%x %d %d\n", output[0], output[1], output[2]); //print the stored output value
               if(output[0] == 0x90 || output[0] == 0x80) {
				   MIDI_ChannelHandler(output[0], output[1], channel_tracker);
				   printf("selection = %d\n", selection);
			   }
               count = 0;
            }
            
         }
      }
   //}

   snd_rawmidi_close(midiin);
   midiin  = NULL;    // snd_rawmidi_close() does not clear invalid pointer
   return 0;          // so might be a good idea to erase it after closing.
}

void MIDI_errormessage(const char *format, ...) {
   va_list ap;
   va_start(ap, format);
   vfprintf(stderr, format, ap);
   va_end(ap);
   putc('\n', stderr);
}

int YM_Menu(char * path, char * direction, char * value, char* active_low, int str_pos, int menu_active, int selection){ //the goal of the special MIDI menu is for it to be completely interactive; so you can keep playing while in the menu!
	 
}

uint8_t GetMirrorValue(uint8_t address, bool bank){
	if(bank == true){
		return array1[address-0x30];
	}
	else return array0[address-0x21];
}

void MIDI_NoteOn(char key, unsigned char velocity){
	//if(YM_MIDI_NotePicker(key, 0) == 0) setreg(0x28, 0xf0, 0); // CH0 Key on
	if(YM_MIDI_NotePicker(key, 1) == 0) setreg(0x28, 0xf1, 0); // CH1 Key On
}

void MIDI_NoteOff(char key, unsigned char velocity){
	//setreg(0x28, 0x00, 0); // CH0 Key off
	setreg(0x28, 0x01, 0); // CH1 Key off
}

int channels = 0;

void MIDI_ChannelHandler(char keycode, char key, char * channel_tracker){  //0 = off, 1 = on
	if(keycode == 0x90) {
		for(int i = 0; i < YM_MAX_CHANNELS; i++){
			if(channel_tracker[i] == 0){
				if(YM_MIDI_NotePicker(key, i) != -1){
					Slot2Channel(i, 1);
					channels++;
					channel_tracker[i] = key;
					break;
				}
			}
			else if(channel_tracker[i] == key){
				printf("\n\nA note in the array does not belong! Removing...\n\n");
				channel_tracker[i] = 0;
				channels--;
				break;
			}
		}
	}
	else if(keycode == 0x80) {
		for(int i = YM_MAX_CHANNELS-1; i > -1; i--){
			if(channel_tracker[i] == key){
				Slot2Channel(i, 0);
				channel_tracker[i] = 0;
				break;
			}
		}
	}
	printf("channel_tracker: %d %d %d %d %d %d\n", channel_tracker[0], channel_tracker[1], channel_tracker[2], channel_tracker[3], channel_tracker[4], channel_tracker[5]); //DEBUG see which channel each MIDI key is assigned to
}

void Slot2Channel(int channel, int OnOff){
	if(OnOff == 0){
		if(channel == 0)      setreg(0x28, 0x00, 0); //turn off channel 0
		else if(channel == 1) setreg(0x28, 0x01, 0); //turn off channel 1
		else if(channel == 2) setreg(0x28, 0x02, 0); //turn off channel 2
		else if(channel == 3) setreg(0x28, 0x04, 0); //turn off channel 3
		else if(channel == 4) setreg(0x28, 0x05, 0); //turn off channel 4
		else if(channel == 5) setreg(0x28, 0x06, 0); //turn off channel 5
		else printf("Invalid channel OFF command in Slot2Channel!\n");
	}
	else if(OnOff == 1){
		if(channel == 0)      setreg(0x28, 0xf0, 0); //turn on channel 0
		else if(channel == 1) setreg(0x28, 0xf1, 0); //turn on channel 1
		else if(channel == 2) setreg(0x28, 0xf2, 0); //turn on channel 2
		else if(channel == 3) setreg(0x28, 0xf4, 0); //turn on channel 3
		else if(channel == 4) setreg(0x28, 0xf5, 0); //turn on channel 4
		else if(channel == 5) setreg(0x28, 0xf6, 0); //turn on channel 5
		else printf("Invalid channel ON command in Slot2Channel!\n");
	}
}
