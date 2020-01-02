//main.c
//Benjamin Ropple

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

//#include "Piezo.h"
#include "Keyboard.h"
#include "i2c_1602.h"
#include "mcps.h"
#include "YM2612.h"
#include "SN76489AN.h"
#include "Clock.h"
#include "MIDI.h"

#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

int main(void){

	char * direction = "/sys/class/gpio/gpio/direction";
	char * value = "/sys/class/gpio/gpio/value";
	char * active_low = "/sys/class/gpio/gpio/active_low";
	char * path = (char*)malloc(35); //allocate memory for GPIO path string, placeholder for other functions in main to use
	int str_pos = 20; //The location of the number after 2nd "gpio" in the strings
	
	int menu;
	int menu_select;
	int piezo = 1;
	int Inst_Active = 1;
	
	LCD_init();
	keyboard_setup(path, direction, value, active_low, str_pos);
	
	while(1){
		
		menu = 1;
		menu_select = 0;
		while(menu == 1){
			menu_start:
			Inst_Active = 1;
			LCD_sendString("PiSynth     v1.0", 1);
			while(menu_select == 0) {
				LCD_sendString("->YM3438   SN76 ", 2); //used to be piezo, depreciated
				if(pin_read("18", value, path, str_pos) == 0x31){
					usleep(150000);
					menu_select = 3;
				}
				if(pin_read("14", value, path, str_pos) == 0x31){
					usleep(150000);
					menu_select = 1;
				}
				if(pin_read("15", value, path, str_pos) == 0x31){
					 int mode_picker = 1;
					 int mode_selection = 0;
					 usleep(150000);
					 while(mode_picker == 1){
						LCD_sendString("Mode Selection  ", 1);
						while(mode_selection == 0) {
							LCD_sendString("->Basic   Adv.  ", 2);
							if(pin_read("15", value, path, str_pos) == 0x31){
								usleep(150000);
								Inst_Active = Play_YM2612(mode_selection, path, direction, value, active_low, str_pos);
							}
							if(pin_read("18", value, path, str_pos) == 0x31){
								usleep(150000);
								mode_selection = 2;
							}
							if(pin_read("14", value, path, str_pos) == 0x31){
								usleep(150000);
								mode_selection = 1;
							}
							if(Inst_Active == 0) goto menu_start;
						}
						while(mode_selection == 1){
							LCD_sendString("  Basic ->Adv.  ", 2);
							if(pin_read("15", value, path, str_pos) == 0x31){
								usleep(150000);
								Inst_Active = Play_YM2612(mode_selection, path, direction, value, active_low, str_pos);
							}
							if(pin_read("18", value, path, str_pos) == 0x31){
								usleep(150000);
								mode_selection = 0;
							}
							if(pin_read("14", value, path, str_pos) == 0x31){
								usleep(150000);
								mode_selection = 2;
							}
							if(Inst_Active == 0) goto menu_start;
						}
						while(mode_selection == 2){
							LCD_sendString("  Adv.  ->MIDI  ", 2);
							if(pin_read("15", value, path, str_pos) == 0x31){
								usleep(150000);
								Inst_Active = MIDI_input();
							}
							if((pin_read("18", value, path, str_pos) == 0x31) || (pin_read("14", value, path, str_pos) == 0x31)){
								usleep(150000);
								mode_selection = 1;
							}
							if(pin_read("14", value, path, str_pos) == 0x31){
								usleep(150000);
								mode_selection = 0;
							}
							if(Inst_Active == 0) goto menu_start;
						}
					}
				 }
			}
			while(menu_select == 1) {
				LCD_sendString("  YM3438 ->SN76 ", 2);
				if(pin_read("18", value, path, str_pos) == 0x31){
					usleep(150000);
					menu_select = 0;
				}
				if(pin_read("14", value, path, str_pos) == 0x31){
					usleep(150000);
					menu_select = 2;
				}
				if(pin_read("15", value, path, str_pos) == 0x31){
					usleep(150000);
					Inst_Active = Play_SN(path, direction, value, active_low, str_pos);
					usleep(150000);
					if(Inst_Active == 0) goto menu_start;
				}
			}
			while(menu_select == 2) {
				LCD_sendString("  SN76   ->Clock", 2);
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
					Inst_Active = display_clock(path, direction, value, active_low, str_pos);
					usleep(150000);
					if(Inst_Active == 0) goto menu_start;
				}
			}
			while(menu_select == 3) {
				LCD_sendString("  Clock   ->Exit", 2);
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
					menu = 0;
				}
				if(menu==0) goto prog_end; //close the program
			}
		}	
	}
	prog_end:
	printf("Exiting...\n");
	
	LCD_sendString("    Goodbye!    ", 1);
	LCD_sendString("PiSynth Ended :(", 2);
	usleep(3000000); //display this message for 3 seconds
	LCD_sendString("                ", 1);
	LCD_sendString("                ", 2); //clear the screen
	free(path);
	return 0;
}
