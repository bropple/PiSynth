
#include "YM2151.h"
#include "YM2151_Presets.h"
#include "YM2151_Note_Picker.h"


static const int bus_2151 = 0;
static const int chip_select_2151 = 0;
static const int hw_addr = 0;
static const int hw_addr_2151 = 0;
//vars different if you want to use a different bus/chip
 
static int mcp23s17_fd;
 
//Define bit numbers
static const uint8_t YM_CS = 7; //using same lines fro 3438, save for chip select
static const uint8_t YM_IC = 1;
static const uint8_t YM_A0 = 2;
static const uint8_t YM_WR = 3;
static const uint8_t YM_RD = 4;

static uint8_t YM_CTRL_PORT = 0x00; //keeping track of the control port value

 int Play_YM2151(char * path, char * direction, char * value, char* active_low, int str_pos){  //Play the YM2151 on the keyboard
	char * Current_Voice = "Piano           "; //The default instrument is the piano
	int cur_voice = 0;
	int last_voice = 1;
	int returning_from_menu = 0;
	char * Current_Octave = "3"; //default octave is 3
	char * Default_Note = " "; //no note by default
	char * IsSharp = " "; //not sharp by default
	LCD_sendString("YM2151  Keyboard", 1);
	LCD_sendString("Initializing... ", 2);
	setup_chips();
	YM2151_Piano(); //Default voice is the Grand Piano from the Application manual
	usleep(1000000); //Sleep for 1s
	LCD_sendString(Current_Voice, 2);
	LCD_WritePos(2, 14, Current_Octave);
	LCD_WritePos(2, 13, Default_Note);
	 
	int octave = 3; //default octave is 3
	int last_octave = 0;

	int run = 1; //Integer controls when the function exits
	int menu; // keeps the menu open until user does something
	int preset;
	int menu_select; //Selection in the menu
	int preset_select;
	int preset_menu;
	while(run == 1)
	{
		YM2151_Begin:
		//printf("Pin %d value is %d.\n\n", 17, pin_read("17", value, path, str_pos));
		if(pin_read("17", value, path, str_pos) == 0x31) { //need to do IF before looping note or the timing will not work!
			note_picker_2151(1, octave);
			setreg_2151(0x08, 0x78); // Key on
			setreg_2151(0x08, 0x79); // Key on
			setreg_2151(0x08, 0x7A); // Key on
			while(pin_read("17", value, path, str_pos) == 0x31){
				LCD_WritePos(2, 13, "C");
				LCD_WritePos(2, 15, " ");
			}
			setreg_2151(0x28, 0x00); // Key off
			setreg_2151(0x28, 0x01); // Key off
			setreg_2151(0x28, 0x02); // Key off
			
		}
		else if(pin_read("27", value, path, str_pos) == 0x31) {
			note_picker_2151(2, octave);
			setreg_2151(0x28, 0xf0); // Key on
			setreg_2151(0x28, 0xf1); // Key on
			setreg_2151(0x28, 0xf2); // Key on
			while(pin_read("27", value, path, str_pos) == 0x31){
				LCD_WritePos(2, 13, "C");
				LCD_WritePos(2, 15, "#");
			}
			setreg_2151(0x28, 0x00); // Key off
			setreg_2151(0x28, 0x01); // Key off
			setreg_2151(0x28, 0x02); // Key off
		}
		else if(pin_read("22", value, path, str_pos) == 0x31) {
			note_picker_2151(3, octave);
			setreg_2151(0x28, 0xf0); // Key on
			setreg_2151(0x28, 0xf1); // Key on
			setreg_2151(0x28, 0xf2); // Key on
			while(pin_read("22", value, path, str_pos) == 0x31){
				LCD_WritePos(2, 13, "D");
				LCD_WritePos(2, 15, " ");
			}
			setreg_2151(0x28, 0x00); // Key off
			setreg_2151(0x28, 0x01); // Key off
			setreg_2151(0x28, 0x02); // Key off
		}
		else if(pin_read("5", value, path, str_pos) == 0x31) {
			note_picker_2151(4, octave);
			setreg_2151(0x28, 0xf0); // Key on
			setreg_2151(0x28, 0xf1); // Key on
			setreg_2151(0x28, 0xf2); // Key on
			while(pin_read("5", value, path, str_pos) == 0x31){
				LCD_WritePos(2, 13, "D");
				LCD_WritePos(2, 15, "#");
			}
			setreg_2151(0x28, 0x00); // Key off
			setreg_2151(0x28, 0x01); // Key off
			setreg_2151(0x28, 0x02); // Key off
		}
		else if(pin_read("6", value, path, str_pos) == 0x31) {
			note_picker_2151(5, octave);
			setreg_2151(0x28, 0xf0); // Key on
			setreg_2151(0x28, 0xf1); // Key on
			setreg_2151(0x28, 0xf2); // Key on
			while(pin_read("6", value, path, str_pos) == 0x31){
				LCD_WritePos(2, 13, "E");
				LCD_WritePos(2, 15, " ");
			}
			setreg_2151(0x28, 0x00); // Key off
			setreg_2151(0x28, 0x01); // Key off
			setreg_2151(0x28, 0x02); // Key off
		}
		else if(pin_read("13", value, path, str_pos) == 0x31) {
			note_picker_2151(6, octave);
			setreg_2151(0x28, 0xf0); // Key on
			setreg_2151(0x28, 0xf1); // Key on
			setreg_2151(0x28, 0xf2); // Key on
			while(pin_read("13", value, path, str_pos) == 0x31){
				LCD_WritePos(2, 13, "F");
				LCD_WritePos(2, 15, " ");
			}
			setreg_2151(0x28, 0x00); // Key off
			setreg_2151(0x28, 0x01); // Key off
			setreg_2151(0x28, 0x02); // Key off
		}
		else if (pin_read("19", value, path, str_pos) == 0x31) {
			note_picker_2151(7, octave);
			setreg_2151(0x28, 0xf0); // Key on
			setreg_2151(0x28, 0xf1); // Key on
			setreg_2151(0x28, 0xf2); // Key on
			while(pin_read("19", value, path, str_pos) == 0x31){
				LCD_WritePos(2, 13, "F");
				LCD_WritePos(2, 15, "#");
			}
			setreg_2151(0x28, 0x00); // Key off
			setreg_2151(0x28, 0x01); // Key off
			setreg_2151(0x28, 0x02); // Key off
		}
		else if(pin_read("26", value, path, str_pos) == 0x31) {
			note_picker_2151(8, octave);
			setreg_2151(0x28, 0xf0); // Key on
			setreg_2151(0x28, 0xf1); // Key on
			setreg_2151(0x28, 0xf2); // Key on
			while(pin_read("26", value, path, str_pos) == 0x31){
				LCD_WritePos(2, 13, "G");
				LCD_WritePos(2, 15, " ");
			}
			setreg_2151(0x28, 0x00); // Key off
			setreg_2151(0x28, 0x01); // Key off
			setreg_2151(0x28, 0x02); // Key off
		}
		else if(pin_read("21", value, path, str_pos) == 0x31) {
			note_picker_2151(9, octave);
			setreg_2151(0x28, 0xf0); // Key on
			setreg_2151(0x28, 0xf1); // Key on
			setreg_2151(0x28, 0xf2); // Key on
			while(pin_read("21", value, path, str_pos) == 0x31){
				LCD_WritePos(2, 13, "G");
				LCD_WritePos(2, 15, "#");
			}
			setreg_2151(0x28, 0x00); // Key off
			setreg_2151(0x28, 0x01); // Key off
			setreg_2151(0x28, 0x02); // Key off
		}
		else if(pin_read("20", value, path, str_pos) == 0x31) {
			note_picker_2151(10, octave);
			setreg_2151(0x28, 0xf0); // Key on
			setreg_2151(0x28, 0xf1); // Key on
			setreg_2151(0x28, 0xf2); // Key on
			while(pin_read("20", value, path, str_pos) == 0x31){
				LCD_WritePos(2, 13, "A");
				LCD_WritePos(2, 15, " ");
			}
			setreg_2151(0x28, 0x00); // Key off
			setreg_2151(0x28, 0x01); // Key off
			setreg_2151(0x28, 0x02); // Key off
		}
		else if (pin_read("16", value, path, str_pos) == 0x31) {
			note_picker_2151(11, octave);
			setreg_2151(0x28, 0xf0); // Key on
			setreg_2151(0x28, 0xf1); // Key on
			setreg_2151(0x28, 0xf2); // Key on
			while(pin_read("16", value, path, str_pos) == 0x31){
				LCD_WritePos(2, 13, "A");
				LCD_WritePos(2, 15, "#");
			}
			setreg_2151(0x28, 0x00); // Key off
			setreg_2151(0x28, 0x01); // Key off
			setreg_2151(0x28, 0x02); // Key off
		}
		else if (pin_read("12", value, path, str_pos) == 0x31) {
			note_picker_2151(12, octave);
			setreg_2151(0x28, 0xf0); // Key on
			setreg_2151(0x28, 0xf1); // Key on
			setreg_2151(0x28, 0xf2); // Key on
			while(pin_read("12", value, path, str_pos) == 0x31){
				LCD_WritePos(2, 13, "B");
				LCD_WritePos(2, 15, " ");
			}
			setreg_2151(0x28, 0x00); // Key off
			setreg_2151(0x28, 0x01); // Key off
			setreg_2151(0x28, 0x02); // Key off
		}
		else if(pin_read("25", value, path, str_pos) == 0x31) {
			note_picker_2151(1, octave+1);
			setreg_2151(0x28, 0xf0); // Key on
			setreg_2151(0x28, 0xf1); // Key on
			setreg_2151(0x28, 0xf2); // Key on
			while(pin_read("25", value, path, str_pos) == 0x31){
				LCD_WritePos(2, 13, "C");
				LCD_WritePos(2, 14, Octave_String(octave+1));
			}
			setreg_2151(0x28, 0x00); // Key off
			setreg_2151(0x28, 0x01); // Key off
			setreg_2151(0x28, 0x02); // Key off
			last_octave = octave+1;
		}
		else if(pin_read("15", value, path, str_pos) == 0x31) { //Open menu for YM module, a way to switch or quit programs
			YM_menu_start:
			usleep(150000); //gives user time to release button without menu exiting (150ms)
			LCD_sendString("YM2151 Mode Menu", 1);
			menu = 1;
			menu_select = 0;
			preset = 0;
			while(menu == 1){
				while(menu_select == 0) {
					LCD_sendString("->Resume   Patch", 2);
					if(pin_read("18", value, path, str_pos) == 0x31){
						usleep(150000);
						menu_select = 2;
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
						while(preset == 1){
							LCD_sendString("Preset Selection", 1);
							preset_select = 0;
							while(preset_select == 0) {
								LCD_sendString("->Return to Menu", 2);
								if(pin_read("18", value, path, str_pos) == 0x31){
								usleep(150000);
								preset_select = 4;
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
								LCD_sendString("->Grand Piano   ", 2);
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
									Current_Voice = "Piano           ";
									cur_voice = 0;
									reset_2151();
									YM2151_Piano();
									preset_select = 1;
									returning_from_menu = 1;
									goto YM2151_Begin;
								}
							}

							if(preset > 1) preset = 0; //ensure that preset does not go beyond the amount of available presets
						}
					}
				}
				while(menu_select == 2) {
					LCD_sendString("  Patch   ->Main", 2);
					if(pin_read("18", value, path, str_pos) == 0x31){
						usleep(150000);
						menu_select = 1;
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
				//if menu==0 break;
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
			LCD_sendString("YM2151  Keyboard", 1);
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
			LCD_WritePos(2, 15, IsSharp);
		}
	}
	YM_end:
	printf("Returning to main menu...\n");
	return 0;
 }
 
 static int MCPS_init(void){

    mcp23s17_fd = mcp23s17_open(bus_2151, chip_select_2151);
    //mcp23s17_fd_2 = mcp23s17_open(bus_2151, chip_select_2151);

    // config register, SEQOP_ON -> sequential execution (MSB -> LSB?)
    const uint8_t ioconfig = BANK_OFF | \
                             INT_MIRROR_OFF | \
                             SEQOP_ON | \
                             DISSLW_OFF | \
                             HAEN_ON | \
                             ODR_OFF | \
                             INTPOL_LOW;
                             
    mcp23s17_write_reg(ioconfig, IOCON, hw_addr_2151, mcp23s17_fd);
    
    mcp23s17_write_reg(0x00, IODIRA, hw_addr_2151, mcp23s17_fd); //both GPIO ports set to outputs
    mcp23s17_write_reg(0x00, IODIRB, hw_addr_2151, mcp23s17_fd); //0x00 turns all output, 0xff turns all input
    
    mcp23s17_write_reg(0xff, GPPUA, hw_addr_2151, mcp23s17_fd); //Turn off pull-up resistors for both
    mcp23s17_write_reg(0xff, GPPUB, hw_addr_2151, mcp23s17_fd);
    
    mcp23s17_write_reg(0x00, IOCON, hw_addr_2151, mcp23s17_fd); //Sequential addressing mode 
    
    mcp23s17_write_reg(0xff, GPIOA, hw_addr_2151, mcp23s17_fd); //Set all ports HIGH
    mcp23s17_write_reg(0xff, GPIOB, hw_addr_2151, mcp23s17_fd);
    
    
	//close(mcp23s17_fd);
	//close(mcp23s17_fd_2);
	return 0;
}

void setreg_2151(uint8_t reg, uint8_t data){
	YM_CTRL_PORT &= ~_BV(YM_WR); // WR low
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd);
	YM_CTRL_PORT &= ~_BV(YM_A0); // A0 low
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd);
	
	mcp23s17_write_reg(reg, GPIOB, hw_addr, mcp23s17_fd);
	usleep(1);
	
	YM_CTRL_PORT |= _BV(YM_CS); // CS high
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd);
	YM_CTRL_PORT &= ~_BV(YM_WR); // WR low
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd);
	YM_CTRL_PORT |= _BV(YM_A0); // A0 high
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd);
	
	mcp23s17_write_reg(data, GPIOB, hw_addr, mcp23s17_fd);
	YM_CTRL_PORT &= ~_BV(YM_CS); // CS low
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd);
	usleep(1);
	
	YM_CTRL_PORT |= _BV(YM_CS); // CS high
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd);
	YM_CTRL_PORT |= _BV(YM_WR); // WR high
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd);
	
}

static void reset_2151(void){
	YM_CTRL_PORT &= ~_BV(YM_IC); //Set IC LOW (inverted)
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd); //apply change
	usleep(25);
	YM_CTRL_PORT |= _BV(YM_IC); //Set IC high (inverted)
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd); //apply, this resets all of the set data on the chip
	usleep(25);
}

static void setup_chips(void){
	MCPS_init(); //initialize mcp23s17
	reset_2151(); //initialize YM2151
	
	YM_CTRL_PORT |= _BV(YM_IC) | _BV(YM_CS) | _BV(YM_WR) | _BV(YM_RD); /* IC, CS, WR and RD HIGH by default */
	YM_CTRL_PORT |= _BV(YM_A0); /* A0 HIGH by default */
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd); //apply changes to control register
	// printf("Setup ctrl is %02X\n", YM_CTRL_PORT); //debug
	printf("\n\nYM2151 setup complete!\n\n");		 //debug
	usleep(10);									
}

static char * Octave_String(int octave){ //returns an octave string from an octave int. Only 8 octaves are used on the chip.
	char * retval;
	switch(octave) {
		case 0: retval = "0";
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
