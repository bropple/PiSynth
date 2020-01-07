
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <getopt.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

#include <alsa/asoundlib.h> 

#include "i2c_1602.h"
#include "Keyboard.h"
#include "mcps.h"
//#include "YM2612_Note_Picker.h"

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

#define CH1_ON setreg(0x28, 0xf0, 0) // Ch 1 key on
#define CH2_ON setreg(0x28, 0xf1, 0) // Ch 2 key on
#define CH3_ON setreg(0x28, 0xf2, 0) // Ch 3 key on
#define CH4_ON setreg(0x28, 0xF4, 0) // Ch 4 key on
#define CH5_ON setreg(0x28, 0xF5, 0) // Ch 5 key on
#define CH6_ON setreg(0x28, 0xF6, 0) // Ch 6 key on

#define CH1_OFF setreg(0x28, 0x00, 0) // Ch 1 Key off
#define CH2_OFF setreg(0x28, 0x01, 0) // Ch 2 Key off
#define CH3_OFF setreg(0x28, 0x02, 0) // Ch 3 Key off
#define CH4_OFF setreg(0x28, 0x04, 0) // Ch 4 Key off
#define CH5_OFF setreg(0x28, 0x05, 0) // Ch 5 Key off
#define CH6_OFF setreg(0x28, 0x06, 0) // Ch 6 Key off

unsigned char array0[0xB7-0x21]; //Mirror register arrays
unsigned char array1[0xB7-0x30];

int Play_YM2612(int mode, char * path, char * direction, char * value, char* active_low, int str_pos);
static int MCPS_init(int num_YMchips);
static void write_2612(uint8_t data);
void setreg(uint8_t reg, uint8_t data, uint8_t isYM_A1);
void reset_2612(void);
static void setup_2612(void);
void setup_chips(void);
static void YM_Test();
static char * Octave_String(int octave);
static void Quiet_SN(void);
void scan_keys(char * path, char * direction, char * value, char* active_low, int str_pos);
//void scan_multiKeys(char * path, char * direction, char * value, char* active_low, int str_pos, Channel_Info CI);
int KeyVal(char * key);
char * NoteString(int note_num);
char * SharpCheck(int note_num);
//static void Note_ToggleHandler(char * state, int ch);


int MIDI_2612(char * path, char * direction, char * value, char* active_low, int str_pos);
void MIDI_errormessage(const char *format, ...);
void MIDI_menu(char * path, char * direction, char * value, char* active_low, int str_pos);
void MIDI_NoteOn(char key, unsigned char velocity);
void MIDI_NoteOff(char key, unsigned char velocity);
