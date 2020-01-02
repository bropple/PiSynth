//Benjamin Ropple
//YM2151_Presets.c
//Contains a number of presets that can be used for the YM2151. Basically VGM data that can be
//invoked at any time to change the instruments.

#include "YM2151.h"
#include "YM2151_Presets.h"
void YM2151_Piano(void){
	setreg_2151(0x18, 0x00);
	setreg_2151(0x1B, 0x00);
	setreg_2151(0x19, 0xFF);
	setreg_2151(0x19, 0x7F);
	setreg_2151(0x08, 0x00);
	setreg_2151(0x20, 0xC0);
	setreg_2151(0x60, 0x7F);
	setreg_2151(0x68, 0x7F);
	setreg_2151(0x70, 0x7F);
	setreg_2151(0x78, 0x7F);
	setreg_2151(0x08, 0x01);
	setreg_2151(0x21, 0xC0);
	setreg_2151(0x61, 0x7F);
	setreg_2151(0x69, 0x7F);
	setreg_2151(0x71, 0x7F);
	setreg_2151(0x79, 0x7F);
	setreg_2151(0x08, 0x02);
	setreg_2151(0x22, 0xC0); 
	setreg_2151(0x62, 0x7F);
	setreg_2151(0x6A, 0x7F); 
	setreg_2151(0x72, 0x7F); 
	setreg_2151(0x7A, 0x7F); 
	setreg_2151(0x08, 0x03);  
	setreg_2151(0x23, 0xC0); 
	setreg_2151(0x63, 0x7F);
	setreg_2151(0x6B, 0x7F);
	setreg_2151(0x73, 0x7F);
	setreg_2151(0x7B, 0x7F);
	setreg_2151(0x08, 0x04);
	setreg_2151(0x24, 0xC0); 
	setreg_2151(0x64, 0x7F);  
	setreg_2151(0x6C, 0x7F);  
	setreg_2151(0x74, 0x7F); 
	setreg_2151(0x7C, 0x7F);  
	setreg_2151(0x08, 0x05);  
	setreg_2151(0x25, 0xC0);  
	setreg_2151(0x65, 0x7F);   
	setreg_2151(0x6D, 0x7F);   
	setreg_2151(0x75, 0x7F);   
	setreg_2151(0x7D, 0x7F);  
	setreg_2151(0x08, 0x06);   
	setreg_2151(0x26, 0xC0);   
	setreg_2151(0x66, 0x7F);   
	setreg_2151(0x6E, 0x7F);   
	setreg_2151(0x76, 0x7F);   
	setreg_2151(0x7E, 0x7F);  
	setreg_2151(0x08, 0x07);  
	setreg_2151(0x27, 0xC0);
	setreg_2151(0x67, 0x7F);
	setreg_2151(0x6F, 0x7F);
	setreg_2151(0x77, 0x7F);
	setreg_2151(0x7F, 0x7F); 
	setreg_2151(0x40, 0x31); 
	setreg_2151(0x60, 0x25); 
	setreg_2151(0x80, 0x9C);
	setreg_2151(0xA0, 0x04);  
	setreg_2151(0xC0, 0x00);   
	setreg_2151(0xE0, 0x15);  
	setreg_2151(0x48, 0x03);   
	setreg_2151(0x68, 0x25);  
	setreg_2151(0x88, 0x5D);   
	setreg_2151(0xA8, 0x04);   
	setreg_2151(0xC8, 0x00); 
	setreg_2151(0xE8, 0x16);   
	setreg_2151(0x50, 0x7C);  
	setreg_2151(0x70, 0x2F);   
	setreg_2151(0x90, 0x96);  
	setreg_2151(0xB0, 0x09);   
	setreg_2151(0xD0, 0x00);  
	setreg_2151(0xF0, 0x12);  
	setreg_2151(0x58, 0x71);  
	setreg_2151(0x78, 0x10);  
	setreg_2151(0x98, 0x8F); 
	setreg_2151(0xB8, 0x07);  
	setreg_2151(0xD8, 0x00);   
	setreg_2151(0xF8, 0xA5);  
	setreg_2151(0x20, 0xFA); 
	setreg_2151(0x38, 0x00);  
}	