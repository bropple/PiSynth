//#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "Piezo.h"
#include "Keyboard.h"
#include "i2c_1602.h"

#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

int Play_Piezo(char * path, char * direction, char * value, char* active_low, int str_pos){
	
	pin_enable(PIEZO,2); //enable GPIO 23
	pin_direction(PIEZO,direction, path, "out",3, str_pos); //set GPIO 18 as output
  
	printf("Switching to Piezo buzzer...\n");
	//LCD_sendString("Piezo   Keyboard", 1);
	int run = 1; //Integer controls when the function exits
	int menu; // keeps the menu open until user does something
	int menu_select; //Selection in the menu
	while(run == 1)
	{
		//printf("Pin %d value is %d.\n\n", 17, pin_read("17", value, path, str_pos));
		if(pin_read("17", value, path, str_pos) == 0x31) { //need to do IF before looping note or the timing will not work!
			LCD_sendString("Note: C5", 2);
			while(pin_read("17", value, path, str_pos) == 0x31){
				pin_value(PIEZO, value, path, "0", str_pos);
				usleep(PIEZO_C5);
				pin_value(PIEZO, value, path, "1", str_pos);
				usleep(PIEZO_C5);
			}
		}
		else if(pin_read("27", value, path, str_pos) == 0x31) {
			LCD_sendString("Note: C5 sharp", 2);
			while(pin_read("27", value, path, str_pos) == 0x31){
				pin_value(PIEZO, value, path, "0", str_pos);
				usleep(PIEZO_C5sharp);
				pin_value(PIEZO, value, path, "1", str_pos);
				usleep(PIEZO_C5sharp);
			}
		}
		else if(pin_read("22", value, path, str_pos) == 0x31) {
			LCD_sendString("Note: D5", 2);
			while(pin_read("22", value, path, str_pos) == 0x31){
				pin_value(PIEZO, value, path, "0", str_pos);
				usleep(PIEZO_D5);
				pin_value(PIEZO, value, path, "1", str_pos);
				usleep(PIEZO_D5);
			}
		}
		else if(pin_read("5", value, path, str_pos) == 0x31) {
			LCD_sendString("Note: D5 sharp", 2);
			while(pin_read("5", value, path, str_pos) == 0x31){
				pin_value(PIEZO, value, path, "0", str_pos);
				usleep(PIEZO_D5sharp);
				pin_value(PIEZO, value, path, "1", str_pos);
				usleep(PIEZO_D5sharp);
			}
		}
		else if(pin_read("6", value, path, str_pos) == 0x31) {
			LCD_sendString("Note: E5", 2);
			while(pin_read("6", value, path, str_pos) == 0x31){
				pin_value(PIEZO, value, path, "0", str_pos);
				usleep(PIEZO_E5);
				pin_value(PIEZO, value, path, "1", str_pos);
				usleep(PIEZO_E5);
			}
		}
		else if(pin_read("13", value, path, str_pos) == 0x31) {
			LCD_sendString("Note: F5", 2);
			while(pin_read("13", value, path, str_pos) == 0x31){
				pin_value(PIEZO, value, path, "0", str_pos);
				usleep(PIEZO_F5);
				pin_value(PIEZO, value, path, "1", str_pos);
				usleep(PIEZO_F5);
			}
		}
		else if (pin_read("19", value, path, str_pos) == 0x31) {
			LCD_sendString("Note: F5 sharp", 2);
			while(pin_read("19", value, path, str_pos) == 0x31){
				pin_value(PIEZO, value, path, "0", str_pos);
				usleep(PIEZO_F5sharp);
				pin_value(PIEZO, value, path, "1", str_pos);
				usleep(PIEZO_F5sharp);
			}
		}
		else if(pin_read("26", value, path, str_pos) == 0x31) {
			LCD_sendString("Note: G5", 2);
			while(pin_read("26", value, path, str_pos) == 0x31) {
				pin_value(PIEZO, value, path, "0", str_pos);
				usleep(PIEZO_G5);
				pin_value(PIEZO, value, path, "1", str_pos);
				usleep(PIEZO_G5);
			}
		}
		else if(pin_read("21", value, path, str_pos) == 0x31) {
			LCD_sendString("Note: G5 sharp", 2);
			while(pin_read("21", value, path, str_pos) == 0x31){
				pin_value(PIEZO, value, path, "0", str_pos);
				usleep(PIEZO_G5sharp);
				pin_value(PIEZO, value, path, "1", str_pos);
				usleep(PIEZO_G5sharp);
			}
		}
		else if(pin_read("20", value, path, str_pos) == 0x31) {
			LCD_sendString("Note: A5", 2);
			while(pin_read("20", value, path, str_pos) == 0x31){
				pin_value(PIEZO, value, path, "0", str_pos);
				usleep(PIEZO_A5);
				pin_value(PIEZO, value, path, "1", str_pos);
				usleep(PIEZO_A5);
			}
		}
		else if (pin_read("16", value, path, str_pos) == 0x31) {
			LCD_sendString("Note: A5 sharp", 2);
			while(pin_read("16", value, path, str_pos) == 0x31){
				pin_value(PIEZO, value, path, "0", str_pos);
				usleep(PIEZO_A5sharp);
				pin_value(PIEZO, value, path, "1", str_pos);
				usleep(PIEZO_A5sharp);
			}
		}
		else if (pin_read("12", value, path, str_pos) == 0x31) {
			LCD_sendString("Note: B5", 2);
			while(pin_read("12", value, path, str_pos) == 0x31){
				pin_value(PIEZO, value, path, "0", str_pos);
				usleep(PIEZO_B5);
				pin_value(PIEZO, value, path, "1", str_pos);
				usleep(PIEZO_B5);
			}
		}
		else if(pin_read("25", value, path, str_pos) == 0x31) {
			LCD_sendString("Note: C6", 2);
			while(pin_read("25", value, path, str_pos) == 0x31){
				pin_value(PIEZO, value, path, "0", str_pos);
				usleep(PIEZO_C6);
				pin_value(PIEZO, value, path, "1", str_pos);
				usleep(PIEZO_C6);
			}
		}
		else if(pin_read("15", value, path, str_pos) == 0x31) { //Open menu for piezo module, a way to switch or quit programs
			usleep(150000); //gives user time to release button without menu exiting (150ms)
			LCD_sendString("Piezo Mode Menu ", 1);
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
						//return 0; //exit the entire function
						goto piezo_end;
					}
					if(menu==0) break;
				}
				//if menu==0 break;
			}
		}
		else {
			LCD_sendString("Piezo   Keyboard", 1);
			LCD_sendString("Note:           ", 2); //show nothing for note
		}
	}
	piezo_end:
	printf("Exiting Piezo mode...\n");
	return 0;
}
