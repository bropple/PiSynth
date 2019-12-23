#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

#include "mcps.h"

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
 
 static void write_2612(uint8_t data);
 static void setreg(uint8_t reg, uint8_t data);
 static void reset_2612(void);
 static void setup_2612(void);
 static void test_2612(void);
 
 const int bus = 0;
 const int chip_select = 0;
 const int hw_addr = 0;
 
 int mcp23s17_fd;
 
//Define bit numbers
const uint8_t YM_IC = 5; //0b00100000;
const uint8_t YM_A0 = 3; //0b00001000;
const uint8_t YM_A1 = 4; //0b00010000;
const uint8_t YM_WR = 1; //0b00000010;
const uint8_t YM_RD = 2; //0b00000100;
const uint8_t YM_CS = 0; //0b00000001;

//IRQ is not needed

#define _BV(bit) (1<<(bit))
 
uint8_t YM_CTRL_PORT = 0x00;

//GPIOA and B on the MCP are equivalent to PORTs on the arduino
 
int main(void){

    mcp23s17_fd = mcp23s17_open(bus, chip_select);

    // config register, SEQOP_ON -> sequential execution (MSB -> LSB?)
    const uint8_t ioconfig = BANK_OFF | \
                             INT_MIRROR_OFF | \
                             SEQOP_ON | \
                             DISSLW_OFF | \
                             HAEN_ON | \
                             ODR_OFF | \
                             INTPOL_LOW;
                             
	//mcp23s17_write_reg(uint8_t data, uint8_t reg, uint8_t hw_addr, int fd)
                             
    mcp23s17_write_reg(ioconfig, IOCON, hw_addr, mcp23s17_fd);
    
    mcp23s17_write_reg(0x00, IODIRA, hw_addr, mcp23s17_fd); //both GPIO ports set to outputs
    mcp23s17_write_reg(0x00, IODIRB, hw_addr, mcp23s17_fd); //0x00 turns all output, 0xff turns all input
    
    mcp23s17_write_reg(0x00, GPPUA, hw_addr, mcp23s17_fd); //Turn off? pull-up resistors for both
    mcp23s17_write_reg(0x00, GPPUB, hw_addr, mcp23s17_fd);
    
    mcp23s17_write_reg(0x00, IOCON, hw_addr, mcp23s17_fd); //byte mode and seq mode (IOCON)
    
    mcp23s17_write_reg(0xff, GPIOA, hw_addr, mcp23s17_fd); //Set all ports HIGH
    mcp23s17_write_reg(0xff, GPIOB, hw_addr, mcp23s17_fd);
    
	setup_2612();
	test_2612();
	
	printf("Testing YM2612...\n");
	
	while(1){
		setreg(0x28, 0xf0); // Key on
		setreg(0x28, 0xf1); // Key on
		setreg(0x28, 0xf2); // Key on
		usleep(100000);
		setreg(0x28, 0x00); // Key off
		setreg(0x28, 0x01); // Key off
		setreg(0x28, 0x02); // Key off
		usleep(100000);
	}
	close(mcp23s17_fd);
	return 0;
}

static void write_2612(uint8_t data){
	YM_CTRL_PORT &= ~_BV(YM_CS);
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd);
	mcp23s17_write_reg(data, GPIOB, hw_addr, mcp23s17_fd);
	printf("Write DATA is %02X\n", data);
	usleep(1);
	YM_CTRL_PORT &= ~_BV(YM_WR); // Write data
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd);
	usleep(5);
	YM_CTRL_PORT |= _BV(YM_WR);
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd);
	usleep(5);
	YM_CTRL_PORT |= _BV(YM_CS); // CS HIGH
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd);
	printf("				WR_CTRL %02X\n", YM_CTRL_PORT);
}

static void setreg(uint8_t reg, uint8_t data){
	YM_CTRL_PORT &= ~_BV(YM_A0); // A0 low (select register)
	printf("				setreg addr ST_CTRL %02X\n", YM_CTRL_PORT);
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd);
	write_2612(reg);
	YM_CTRL_PORT |= _BV(YM_A0);  // A0 high (write register)
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd);
	write_2612(data);
	printf("				setreg data ST_CTRL %02X\n", YM_CTRL_PORT);
}

static void reset_2612(void){
	YM_CTRL_PORT &= ~_BV(YM_IC);
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd);
	usleep(10000);
	YM_CTRL_PORT |= _BV(YM_IC);
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd);
	usleep(10000);
	printf("Reset ctrl is %02X\n", YM_CTRL_PORT);
	printf("\n\nYM2612 reset!\n\n");
	usleep(1000000);
}

static void setup_2612(void){
	reset_2612();
	//IC_HIGH(ctrl); //Set IC, CS, WR and RD high (inv) and A0 and A1 low by default	
	YM_CTRL_PORT |= _BV(YM_IC) | _BV(YM_CS) | _BV(YM_WR) | _BV(YM_RD); /* IC, CS, WR and RD HIGH by default */
	YM_CTRL_PORT &= ~(_BV(YM_A0) | _BV(YM_A1)); /* A0 and A1 LOW by default */
	mcp23s17_write_reg(YM_CTRL_PORT, GPIOA, hw_addr, mcp23s17_fd);
	printf("Setup ctrl is %02X\n", YM_CTRL_PORT);
	printf("\n\nYM2612 setup complete!\n\n");		
	usleep(1000000);											 
}

static void test_2612(void){
  setreg(0x22, 0x00); // LFO off
  setreg(0x27, 0x00); // Note off (channel 0)
  setreg(0x28, 0x00); // Note off (channel 1)
  setreg(0x28, 0x01); // Note off (channel 1)
  setreg(0x28, 0x02); // Note off (channel 2)
  setreg(0x28, 0x03); // Note off (channel 1)
  setreg(0x28, 0x04); // Note off (channel 3)
  setreg(0x28, 0x05); // Note off (channel 4)
  setreg(0x28, 0x06); // Note off (channel 5)
  setreg(0x2B, 0x00); // DAC off
  
  setreg(0x30, 0x71); //
  setreg(0x34, 0x0d); //
  setreg(0x38, 0x33); //
  setreg(0x3C, 0x01); // DT1/MUL
  setreg(0x40, 0x23); //
  setreg(0x44, 0x2D); //
  setreg(0x48, 0x26); //
  setreg(0x4C, 0x00); // Total level
  setreg(0x50, 0x5F); //
  setreg(0x54, 0x99); //
  setreg(0x58, 0x5F); //
  setreg(0x5C, 0x94); // RS/AR 
  setreg(0x60, 0x05); //
  setreg(0x64, 0x05); //
  setreg(0x68, 0x05); //
  setreg(0x6C, 0x02); // AM/D1R
  setreg(0x70, 0x02); //
  setreg(0x74, 0x02); //
  setreg(0x78, 0x02); //
  setreg(0x7C, 0x02); // D2R
  setreg(0x80, 0x11); //
  setreg(0x84, 0x11); //
  setreg(0x88, 0x11); //
  setreg(0x8C, 0xb3); // D1L/RR

  setreg(0x31, 0x71); //
  setreg(0x35, 0x0d); //
  setreg(0x39, 0x33); //
  setreg(0x3d, 0x01); // DT1/MUL
  setreg(0x41, 0x23); //
  setreg(0x45, 0x2D); //
  setreg(0x49, 0x26); //
  setreg(0x4d, 0x00); // Total level
  setreg(0x51, 0x5F); //
  setreg(0x55, 0x99); //
  setreg(0x59, 0x5F); //
  setreg(0x5d, 0x94); // RS/AR 
  setreg(0x61, 0x05); //
  setreg(0x65, 0x05); //
  setreg(0x69, 0x05); //
  setreg(0x6d, 0x02); // AM/D1R
  setreg(0x71, 0x02); //
  setreg(0x75, 0x02); //
  setreg(0x79, 0x02); //
  setreg(0x7d, 0x02); // D2R
  setreg(0x81, 0x11); //
  setreg(0x85, 0x11); //
  setreg(0x89, 0x31); //
  setreg(0x8d, 0xb3); // D1L/RR
  
  setreg(0x32, 0x71); //
  setreg(0x36, 0x0D); //
  setreg(0x3a, 0x33); //
  setreg(0x3e, 0x01); // DT1/MUL
  setreg(0x42, 0x23); //
  setreg(0x46, 0x2D); //
  setreg(0x4a, 0x26); //
  setreg(0x4e, 0x0f); // Total level
  setreg(0x52, 0x5F); //
  setreg(0x56, 0x99); //
  setreg(0x5a, 0x5F); //
  setreg(0x5e, 0x94); // RS/AR 
  setreg(0x62, 0x05); //
  setreg(0x66, 0x05); //
  setreg(0x6a, 0x05); //
  setreg(0x6e, 0x02); // AM/D1R
  setreg(0x72, 0x02); //
  setreg(0x76, 0x02); //
  setreg(0x7a, 0x02); //
  setreg(0x7e, 0x02); // D2R
  setreg(0x82, 0x11); //
  setreg(0x86, 0x11); //
  setreg(0x8a, 0x31); //
  setreg(0x8e, 0xb4); // D1L/RR
  
  setreg(0x90, 0x00); //
  setreg(0x94, 0x00); //
  setreg(0x98, 0x00); //
  setreg(0x9C, 0x00); // Proprietary
  setreg(0xB0, 0x03); // Feedback/algorithm
  setreg(0xB1, 0x03); // Feedback/algorithm
  setreg(0xB2, 0x03); // Feedback/algorithm
  setreg(0xB4, 0x93); // Both speakers on
  setreg(0xB5, 0x43); // Both speakers on
  setreg(0xB6, 0xC4); // Both speakers on
  
  setreg(0xA4, 0x22); // 
  setreg(0xA0, 0x69); // Set frequency ch 1
  
  setreg(0xA5, 0x22); // 
  setreg(0xA1, 0xdd); // Set frequency ch 2
  
  setreg(0xA6, 0x23); // 
  setreg(0xA2, 0x9c); // Set frequency ch 3
  printf("\n\nGrand Piano voice programmed!\n\n");
  usleep(1000000);
}
