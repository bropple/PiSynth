//Keyboard.c
//Benjamin Ropple
//Uses Raspberry Pi's GPIO pins with simple tactile switches for a 13-key piano.
//Includes 3 additional buttons for navigating menus on a 16x2 LCD.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "Keyboard.h"

//these are essentially more powerful versions of the functions used in the GPIO homeworks.

//enable any given GPIO pin
void pin_enable(char *pin_num, int bytes) {
        int fd = open("/sys/class/gpio/export", O_WRONLY); //open file for$
        if (fd<0) printf("\n\nError enabling pin %s.\n\n", pin_num); //ret$
        write(fd, pin_num, bytes); //enable the pin
        close(fd); //Done with the file.
}
//change direction of any given GPIO pin
void pin_direction(char * pin_num, char * direction, char* path, char *dir, int bytes, int str_pos) {
        int fd = open(insert_string(direction, pin_num, path, str_pos), O_WRONLY);
        usleep(500);
        if(fd<0) printf("\n\nError opening the direction file on pin %s.\n\n", pin_num); //ch$
        write(fd, dir, bytes); //change to either input or output
        close(fd); //done with file.
}
//change value of any given GPIO pin
void pin_value(char * pin_num, char * value, char * path, char *val, int str_pos){
        int fd = open(insert_string(value, pin_num, path, str_pos), O_WRONLY); //open th$
        if(fd<0) printf("\n\nError opening the value file on pin %s.\n\n", pin_num); //check $
        write(fd, val, 1); //Write either a 1 or a 0, always one byte
        close(fd); //Done
}
//read value from any given pin
int pin_read(char * pin_num, char * value, char * path, int str_pos){
        int result; //the result will be stored here.
        char buffer[16]; //create a buffer 16 bytes long

        int fd=open(insert_string(value, pin_num, path, str_pos),O_RDONLY); //open the fd of specified device.
        if(fd<0) printf("Error opening the value file on pin %s.\n\n",pin_num);
        read(fd, buffer, 16); //read the pin value
        result = *buffer; //result is in the buffer
        close(fd); //Done with the file
        return result; //return the result to main
	}
void pin_active_low(char * pin_num, char * active_low, char * path, char * val, int str_pos){
        int fd = open(insert_string(active_low, pin_num, path, str_pos), O_WRONLY); //open th$
        if(fd<0) printf("\n\nError opening the active_low file on pin %s.\n\n", pin_num); //check $
        write(fd, val, 1); //Write nonzero for active low
        close(fd); //Done
}

char * insert_string(char * str1, char * str2, char * str3, int location){ //allows inserting a string into another at any point,
		strncpy(str3, str1, location);									   //returns third modified string
		str3[location] = '\0';
		strcat(str3, str2);
		strcat(str3, str1+location);
		//printf("%s\n", str3);
		return str3;
}

/* Menu Keys
 * GPIO 18 - Left
 * GPIO 15 - Select
 * GPIO 14 - Right
 */

void keyboard_setup(char * path, char * direction, char * value, char* active_low, int str_pos) {
	//setup GPIO pins 17, 27, 22, 05, 06, 13, 19, 26, 20, 16, and 12 as input, active low
	char *pins[17] = {"17","27","22","26","5","6","13","19","21","20","16","12","25", "14", "15", "18", "24"}; //24 is the rotary encoder's push button
	int i;
	//do all these actions at once, one pin at a time
	for(i=0; i<17; i++){
		pin_enable(pins[i], 2); //enable pins
		pin_direction(pins[i], direction, path, "in", 2, str_pos); //input direction
	}
	pin_active_low("24", active_low, path, "0", str_pos); //Doing HW implementation for now instead of messing with internal PUDs
	printf("Keyboard setup is complete!\n");
}
