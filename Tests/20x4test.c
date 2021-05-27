#include "i2c_1602.h"

static int tx_bytes; //The number of bytes to send over i2c.
static int fd; //i2c file desriptor.
static int result; //Used to conduct i2c transactions.

int main(int argc, char *argv[]) {
	
	tx_bytes = 4;
	char i2c_device[]="/dev/i2c-1"; //The Raspberry Pi's i2c interface.
	fd = open(i2c_device, O_RDWR); //Open the file descriptor.
	
	//Check for error reading file descriptor
	if(fd<0){	//check for errors...
		printf("Error opening the file descriptor!\n");
		return -1;
	}
	
	/* Set slave address */
	result=ioctl(fd, I2C_SLAVE, 0x27); //set slave address to the address of the display
	if(fd<0){ //check for errors
			printf("Error setting the i2c slave address!\n");
			return -1;
	}
	
	/*Test Program*/
	
	LCD_init();
	LCD_sendString(argv[1],1); //Print argument 1 from terminal on row 1 of display
	LCD_sendString(argv[2],2); //Print argument 2 from terminal on row 2 of display
	LCD_sendString(argv[3],3); //Print argument 3 from terminal on row 3 of display
	LCD_sendString(argv[4],4); //Print argument 4 from terminal on row 4 of display
	
	return 0;
}
