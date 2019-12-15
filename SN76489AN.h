#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

#include "Keyboard.h"
#include "mcps.h"
#include "i2c_1602.h"

#define _BV(bit) (1<<(bit)) //creates mask for the given bit automatically

static int MCPS_init_SN(void);

int Play_SN(char * path, char * direction, char * value, char* active_low, int str_pos);
void reset_SN(uint8_t SN_CTRL_PORT, int mcp23s17_fd);
void write_SN(uint8_t data);
static void setup_SN(void);
