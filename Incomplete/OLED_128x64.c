
#include i2c_1602.h

static int tx_bytes = 4;
static int fd;
static int result;

void OLED_init(void){

	int result; //Used to conduct i2c transactions.
	char i2c_device[]="/dev/i2c-1"; //The Raspberry Pi's i2c interface.
	fd = open(i2c_device, O_RDWR); //Open the file descriptor.

	//Check for error reading file descriptor
	if(fd<0){	//check for errors...
		printf("Error opening the file descriptor!\n");
	}
	
	/* Set slave address */
	result=ioctl(fd, I2C_SLAVE, 0x3c); //set slave address to the address of the display
	if(fd<0){ //check for errors
		printf("Error setting the i2c slave address!\n");
	}

	//code to initialize this specific display...
					
}
