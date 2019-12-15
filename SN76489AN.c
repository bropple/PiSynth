
#include "SN76489AN.h"

static const uint8_t YM_IC = 5;
static const uint8_t YM_A0 = 3;
static const uint8_t YM_A1 = 4;
static const uint8_t YM_WR = 1;
static const uint8_t YM_RD = 2;
static const uint8_t YM_CS = 0; //YM registers aren't used here, but are kept just in case

static const uint8_t SN_CE = 6;
static const uint8_t SN_WE = 7; //these are both inverted signals 

static const int bus = 0;			//MCP23S17 parameters
static int chip_select = 0;
static const int hw_addr = 0;
int mcp23s17_fd;


static uint8_t SN_CTRL_PORT = 0x00;

int Play_SN(char * path, char * direction, char * value, char* active_low, int str_pos){
	
	setup_SN();
	
	int menu_select;
	int menu;
	int run = 1;
	
	LCD_sendString("SN76    Keyboard", 1);
	
	while(run == 1){
		if(pin_read("15", value, path, str_pos) == 0x31) { //Open menu for piezo module, a way to switch or quit programs
				usleep(150000); //gives user time to release button without menu exiting (150ms)
				LCD_sendString("SN76 Mode Menu  ", 1);
				menu = 1;
				menu_select = 0;
				while(menu == 1){
					while(menu_select == 0) {
						LCD_sendString("->Resume    Main", 2);
						if(pin_read("18", value, path, str_pos) == 0x31 || pin_read("14", value, path, str_pos) == 0x31){
							usleep(150000);
							menu_select = 1;
						}
						if(pin_read("15", value, path, str_pos) == 0x31){
							usleep(150000);
							 menu = 0;
							 continue;
						 }
						 if(menu==0) break;
					}
					while(menu_select == 1) {
						LCD_sendString("  Resume  ->Main", 2);
						if(pin_read("18", value, path, str_pos) == 0x31 || pin_read("14", value, path, str_pos) == 0x31){
							usleep(150000);
							menu_select = 0;
						}
						if(pin_read("15", value, path, str_pos) == 0x31){
							usleep(150000);
							run = 0;
							goto SN_end;
						}
						if(menu==0) break;
					}
				}
			}
			else { 
				LCD_sendString("SN76    Keyboard", 1);
				LCD_sendString("                ", 2);
			}
		}
		
	SN_end:
	return 0;
}

void reset_SN(uint8_t SN_CTRL_PORT,int mcp23s17_fd){
	SN_CTRL_PORT |= _BV(SN_WE); //Set WE HIGH
	mcp23s17_write_reg(SN_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd); //write change
	write_SN(0x9F);	//this data sequence resets the chip's state
    write_SN(0xBF);
    write_SN(0xDF);
    write_SN(0xFF);
    SN_CTRL_PORT &= ~_BV(SN_WE); //set WE LOW
    mcp23s17_write_reg(SN_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd); //write change
}

void write_SN(uint8_t data){
	SN_CTRL_PORT |= _BV(SN_WE); //set WE HIGH
	mcp23s17_write_reg(SN_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd); //write change
	mcp23s17_write_reg(0xff, GPIOB, hw_addr, mcp23s17_fd); //write data to register
	SN_CTRL_PORT &= ~_BV(SN_WE); //set WE LOW
	mcp23s17_write_reg(SN_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd); //write change
	usleep(25);
}

static int MCPS_init_SN(void){
	
    mcp23s17_fd = mcp23s17_open(bus, chip_select);
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
    
    mcp23s17_write_reg(0x3F, IODIRA, hw_addr, mcp23s17_fd); //only SN control pins are active on GPIOA
    mcp23s17_write_reg(0x00, IODIRB, hw_addr, mcp23s17_fd); //0x00 turns all output, 0xff turns all input
    
    mcp23s17_write_reg(0xff, GPPUA, hw_addr, mcp23s17_fd); //Turn off pull-up resistors for both
    mcp23s17_write_reg(0xff, GPPUB, hw_addr, mcp23s17_fd);
    
    mcp23s17_write_reg(0x00, IOCON, hw_addr, mcp23s17_fd); //Sequential addressing mode 
    
    mcp23s17_write_reg(0xff, GPIOA, hw_addr, mcp23s17_fd); //Set all ports HIGH
    mcp23s17_write_reg(0xff, GPIOB, hw_addr, mcp23s17_fd);
	    
	return 0;
}

static void setup_SN(void){
	MCPS_init_SN();
	reset_SN(SN_CTRL_PORT, mcp23s17_fd);
}
