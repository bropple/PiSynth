#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdint.h>

#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

static void oled_transact(unsigned char * buffer, int nBytes){ //Consolidates a i2c transaction.
	result = write(fd, buffer, nBytes);
	if (result != nBytes) {
		printf("An error occured during the I2C tranaction.\n\n");
		usleep(1000000);
	}
	//return result;
}
