#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

#include "i2c_1602.h"
#include "Keyboard.h"
#include "mcps.h"
#include "YM2612_Note_Picker.h"

#define _BV(bit) (1<<(bit)) //creates mask for the given bit automatically

int Play_YM2151(char * path, char * direction, char * value, char* active_low, int str_pos);
static int MCPS_init(void);
void setreg_2151(uint8_t reg, uint8_t data);
static void reset_2151(void);
static void setup_chips(void);
static char * Octave_String(int octave);
