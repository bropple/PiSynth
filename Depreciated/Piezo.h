
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "Keyboard.h"
#include "i2c_1602.h"

#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#include "i2c_1602.h"

#define PIEZO "23"

//usleep periods for Piezo notes
//White keys
#define PIEZO_C5 1912
#define PIEZO_D5 1704
#define PIEZO_E5 1517
#define PIEZO_F5 1433
#define PIEZO_G5 1276
#define PIEZO_A5 1136
#define PIEZO_B5 1012
#define PIEZO_C6 955
//Black keys (Sharps/Flats)
#define PIEZO_C5sharp 1805
#define PIEZO_D5sharp 1608
#define PIEZO_F5sharp 1351
#define PIEZO_G5sharp 1203
#define PIEZO_A5sharp 1073

int Play_Piezo(char * path, char * direction, char * value, char* active_low, int str_pos);
