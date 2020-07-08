/*	Ben Ropple
 * 	i2c_1602.c
 * 
 * 	This program provides several helper functions
 * 	to make it easier to interface with PCF8574AT-based
 *  i2c	display modules using C code on Raspbian. This can 
 *  also work with 16x4 displays and 20x4 displays with 
 *  minor edits.
 *  
 * 
 *  This code assumes you want the backlight ON. If not, remove
 * 	every " | LCD_BACKLIGHT | En " and  " | LCD_BACKLIGHT | ~En ".
 * 
 * 	i2c_transact: Consolidates an i2c transaction using linux functions.
 * 	LCD_writeCommand: write a single command to the display.
 * 	LCD_sendChar: send a char value to the display.
 * 	LCD_sendString: send a string to the display, specifying the row.
 *  LCD_init: initialize the LCD. Run at start of code.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdint.h>

#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#include "i2c_1602.h"

static int tx_bytes = 4;
int fd;
int result;
int address = 0x27; //address of i2c display

//LCD commands and flags are listed in the i2c_1602.h file.

//int tx_bytes; //The number of bytes to send over i2c.
//int fd; //i2c file desriptor.
//int result; //Used to conduct i2c transactions.

//int main(int argc, char *argv[]) {
//	
//	tx_bytes = 4;
//	char i2c_device[]="/dev/i2c-1"; //The Raspberry Pi's i2c interface.
//	fd = open(i2c_device, O_RDWR); //Open the file descriptor.
//	
//	//Check for error reading file descriptor
//	if(fd<0){	//check for errors...
//		printf("Error opening the file descriptor!\n");
//		return -1;
//	}
	
//	/* Set slave address */
//	result=ioctl(fd, I2C_SLAVE, 0x3f); //set slave address to the address of the display
//	if(fd<0){ //check for errors
//			printf("Error setting the i2c slave address!\n");
//			return -1;
//	}
	
//	/*Test Program*/
	
//	LCD_init();
//	LCD_sendString(argv[1],1); //Print argument 1 from terminal on row 1 of display
//	LCD_sendString(argv[2],2); //Print argument 2 from terminal on row 2 of display
//	
//	return 0;
//}

void i2c_transact(unsigned char * buffer, int nBytes){ //Consolidates a i2c transaction.
	result = write(fd, buffer, nBytes);
	//if (result != nBytes) {
	//	printf("An error occured during the I2C tranaction.\n\n");
	//	usleep(1000000);
	//}
	//return result;
}

void LCD_writeCommand(int command){ //Send a single command to the LCD.
	int dataUpper, dataLower; //
	uint8_t buffer[4];
	dataUpper = command&0xF0;								//0x04 = LCDENTRYMODESET
	dataLower = (command<<4)&0xF0;							//ORing the backlight and enable keeps backlight on
	buffer[0] = dataUpper | 0x04 | LCD_BACKLIGHT | En;		//enable=1
	buffer[1] = dataUpper | LCD_BACKLIGHT | ~En;		    //enable=0
	buffer[2] = dataLower |0x04 | LCD_BACKLIGHT | En;	    //enable=1
	buffer[3] = dataLower | LCD_BACKLIGHT | ~En;		    //enable=0
	i2c_transact((unsigned char *)buffer, tx_bytes);
}

void LCD_sendChar(char chr){
	char dataUpper, dataLower;
	uint8_t buffer[4];
	dataUpper = chr&0xF0;
	dataLower = (chr<<4)&0xF0;
	buffer[0] = dataUpper|0x05| LCD_BACKLIGHT | En;		//enable=1 
	buffer[1] = dataUpper|0x01| LCD_BACKLIGHT | ~En;	//enable=0
	buffer[2] = dataLower|0x05| LCD_BACKLIGHT | En;		//enable=1
	buffer[3] = dataLower|0x01| LCD_BACKLIGHT | ~En;	//enable=0
	i2c_transact((unsigned char *)buffer, tx_bytes);
}

void LCD_sendString(char *str, int row){ //Supports up to 4 rows [Tested with 2]
	switch(row) {
		case 1: LCD_writeCommand(0x80); //switch to first row
				while (*str) LCD_sendChar (*str++);	//Displays a string, writing one char at a time
				break;
				
		case 2: LCD_writeCommand(0xC0); //switch to second row
				while (*str) LCD_sendChar (*str++);
				break;
				
		case 3: LCD_writeCommand(0x94); //switch to third row
				while (*str) LCD_sendChar (*str++);
				break;
				
		case 4: LCD_writeCommand(0xD4); //switch to fourth row
				while (*str) LCD_sendChar (*str++);
				break;
		default: printf("Invalid display row value!\n");
	}
	LCD_writeCommand(0x00); //reset to first row
}

void LCD_init(void){

	int result; //Used to conduct i2c transactions.
	char i2c_device[]="/dev/i2c-1"; //The Raspberry Pi's i2c interface.
	fd = open(i2c_device, O_RDWR); //Open the file descriptor.

	//Check for error reading file descriptor
	if(fd<0){	//check for errors...
		printf("Error opening the file descriptor!\n");
	}
	
	/* Set slave address */
	result=ioctl(fd, I2C_SLAVE, address); //set slave address to the address of the display
	if(fd<0){ //check for errors
		printf("Error setting the i2c slave address!\n");
	}


	usleep(42000);				//Datasheet specified delay
	//Test
	for(int i = 0; i<3; i++) {
		LCD_writeCommand(0x03);
		usleep(42000);
	}
	LCD_writeCommand(0x00);	//Reset Display to first row/clear
	usleep(1000);					//Datasheet specified delay
	LCD_writeCommand(0x02);	//Return cursor home
	usleep(1000);					
	LCD_writeCommand(0x0C);	//Display on, cursor off
	usleep(1000);					
	LCD_writeCommand(0x80);	//Force cursor to beginning  of line 1
	usleep(1000);
	printf("LCD is initialized!\n");					
}

void LCD_WritePos(int row, int numshifts, char *str){ //assumes right shift from origin of row
	//#define LCD_ENTRYSHIFTINCREMENT  0x01
	//#define LCD_ENTRYSHIFTDECREMENT  0x00
	
	uint8_t rowaddr;
	
	if(row == 1){
		rowaddr = 0x80;
		LCD_writeCommand(rowaddr); //move to beginning of desired row
	}
	else if(row == 2){
		rowaddr = 0xC0;
		LCD_writeCommand(0xC0);
	 }
	
	for(int x = 0; x<numshifts; x++){
		rowaddr = rowaddr + 0x01;
	}
	
	LCD_writeCommand(rowaddr);
	
	while (*str) LCD_sendChar (*str++); //write char in specified location
	//printf("Write complete!\n");
}
