
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

/* Pin Connections from MCP23S17 to YM3438
 * 
 * D0-D7 are on GPB0-GPB7, MSB is D7
 * 
 * CSbar = GPA0
 * WRbar = GPA1
 * RDbar = GPA2
 * A0 = GPA3
 * A1 = GPA4
 * ICbar = GPA5
 * 
 */
 
 //IRQ is not needed

#define _BV(bit) (1<<(bit)) //creates mask for the given bit number automatically


int Play_YM2612(char * path, char * direction, char * value, char* active_low, int str_pos);
static int MCPS_init(int num_YMchips);
static void write_2612(uint8_t data);
void setreg(uint8_t reg, uint8_t data);
static void reset_2612(void);
static void setup_2612(void);
static void setup_chips(void);
static void YM_Test();
static char * Octave_String(int octave);
static void Quiet_SN(void);
void scan_keys(char * path, char * direction, char * value, char* active_low, int str_pos);
void scan_multiKeys(char * path, char * direction, char * value, char* active_low, int str_pos);
int KeyVal(char * key);
char * NoteString(int note_num);
char * SharpCheck(int note_num);
void Channel_Checker(void);
