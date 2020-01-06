//Benjamin Ropple
//YM2612.c
//Switch-Case for picking notes and octaves for the YM2612.

#include <stdlib.h>
#include "YM2612.h"
#include "YM2612_Note_Picker.h"

int Channel_Change[6] = {0,0,0,0,0,0};

static uint8_t Note_Addresses[6] = {0xA4, 0xA0, 0xA5, 0xA1, 0xA6, 0xA2}; //These are the addresses that are written to, in this order, when accessing a note

void note_picker(int note, int octave){ //only works for the basic note scanner!
	/* Note Codes
	 * 
	 * AABB
	 * AA = Note
	 * BB = Octave
	 * 
	 * Note Codes - First 2 Digits 0- Omit zero for codes below 10, C thinks these are octals!
	 * The keyboard currently in the code has 13 notes, mostly of 1 octave.
	 * 
	 * 1 = C
	 * 2 = C#
	 * 3 = D
	 * 4 = D#
	 * 5 = E
	 * 6 = F
	 * 7 = F#
	 * 8 = G
	 * 9 - G#
	 * 10 - A
	 * 11 - A#
	 * 12 - B
	 * 
	 * Octave Codes - Last 2 Digits
	 * There are 8 Octaves on the YM2612, ranging from octave 0 (very low) to octave 7 (very high)
	 * This program will not allow octave zero or the full range of octave 7 because the chip cannot play note C0 or c8. (beyond max range).
	 * 
	 * 1 - Octave 1
	 * 2 - Octave 2
	 * 3 - Octave 3
	 * 4 - Octave 4
	 * 5 - Octave 5
	 * 6 - Octave 6
	 * 7 - Octave 7
	 * 
	 */ 
	if(octave == 1) {
		switch (note){
			case 1:  	setreg(0xA4, 0x0A, 0);   //Note C, channel 1
						setreg(0xA0, 0x84, 0);
						setreg(0xA5, 0x0A, 0);   //Note C, channel 2
						setreg(0xA1, 0x84, 0);
						setreg(0xA6, 0x0A, 0);   //Note C, channel 3
						setreg(0xA2, 0x84, 0);
						break;
					
			case 2:  	setreg(0xA4, 0x0A, 0);   //Note C#, channel 1
						setreg(0xA0, 0xAA, 0);
						setreg(0xA5, 0x0A, 0);   //Note C#, channel 2
						setreg(0xA1, 0xAA, 0);
						setreg(0xA6, 0x0A, 0);   //Note C#, channel 3
						setreg(0xA2, 0xAA, 0);
						break;          
										 
			case 3:  	setreg(0xA4, 0x0A, 0);   //Note D, channel 1
						setreg(0xA0, 0xD3, 0);
						setreg(0xA5, 0x0A, 0);   //Note D, channel 2
						setreg(0xA1, 0xD3, 0);
						setreg(0xA6, 0x0A, 0);   //Note D, channel 3
						setreg(0xA2, 0xD3, 0);
						break;           
										 
			case 4:  	setreg(0xA4, 0x0A, 0);   //Note D#, channel 1
						setreg(0xA0, 0xFE, 0);
						setreg(0xA5, 0x0A, 0);   //Note D#, channel 2
						setreg(0xA1, 0xFE, 0);
						setreg(0xA6, 0x0A, 0);   //Note D#, channel 3
						setreg(0xA2, 0xFE, 0);
						break;           
										 
			case 5:  	setreg(0xA4, 0x0B, 0);   //Note E, channel 1
						setreg(0xA0, 0x2B, 0);
						setreg(0xA5, 0x0B, 0);   //Note E, channel 2
						setreg(0xA1, 0x2B, 0);
						setreg(0xA6, 0x0B, 0);   //Note E, channel 3
						setreg(0xA2, 0x2B, 0);
						break;           
										 
			case 6:  	setreg(0xA4, 0x0B, 0);   //Note F, channel 1
						setreg(0xA0, 0x5B, 0);
						setreg(0xA5, 0x0B, 0);   //Note F, channel 2
						setreg(0xA1, 0x5B, 0);
						setreg(0xA6, 0x0B, 0);   //Note F, channel 3
						setreg(0xA2, 0x5B, 0);
						break;           
										 
			case 7:  	setreg(0xA4, 0x0B, 0);   //Note F#, channel 1
						setreg(0xA0, 0x8E, 0);
						setreg(0xA5, 0x0B, 0);   //Note F#, channel 2
						setreg(0xA1, 0x8E, 0);
						setreg(0xA6, 0x0B, 0);   //Note F#, channel 3
						setreg(0xA2, 0x8E, 0);
						break;          
										 
			case 8:  	setreg(0xA4, 0x0B, 0);   //Note G, channel 1
						setreg(0xA0, 0xC5, 0);
						setreg(0xA5, 0x0B, 0);   //Note G, channel 2
						setreg(0xA1, 0xC5, 0);
						setreg(0xA6, 0x0B, 0);   //Note G, channel 3
						setreg(0xA2, 0xC5, 0);
						break;           
										 
			case 9:  	setreg(0xA4, 0x0B, 0);   //Note G#, channel 1
						setreg(0xA0, 0xFE, 0);
						setreg(0xA5, 0x0B, 0);   //Note G#, channel 2
						setreg(0xA1, 0xFE, 0);
						setreg(0xA6, 0x0B, 0);   //Note G#, channel 3
						setreg(0xA2, 0xFE, 0);
						break;           
										
			case 10:  	setreg(0xA4, 0x0C, 0);   //Note A, channel 1
						setreg(0xA0, 0x3B, 0);
						setreg(0xA5, 0x0C, 0);   //Note A, channel 2
						setreg(0xA1, 0x3B, 0);
						setreg(0xA6, 0x0C, 0);   //Note A, channel 3
						setreg(0xA2, 0x3B, 0);
						break;           
										 
			case 11:  	setreg(0xA4, 0x0C, 0);   //Note A#, channel 1
						setreg(0xA0, 0x7B, 0);
						setreg(0xA5, 0x0C, 0);   //Note A#, channel 2
						setreg(0xA1, 0x7B, 0);
						setreg(0xA6, 0x0C, 0);   //Note A#, channel 3
						setreg(0xA2, 0x7B, 0);
						break;           
										 
			case 12:  	setreg(0xA4, 0x0C, 0);   //Note B, channel 1
						setreg(0xA0, 0xBF, 0);
						setreg(0xA5, 0x0C, 0);   //Note B, channel 2
						setreg(0xA1, 0xBF, 0);
						setreg(0xA6, 0x0C, 0);   //Note B, channel 3
						setreg(0xA2, 0xBF, 0);
						break;
					
			default: printf("Invalid octave!\n");
						break;
		}
	}

	// Note labels below are not correct, please reference the correct labels above.
	//will fix someday.
	
	if(octave == 2) {
		switch (note){
			case 1:  	setreg(0xA4, 0x12, 0);   //Note C, channel 1
						setreg(0xA0, 0x84, 0);
						setreg(0xA5, 0x12, 0);   //Note C, channel 2
						setreg(0xA1, 0x84, 0);
						setreg(0xA6, 0x12, 0);   //Note C, channel 3
						setreg(0xA2, 0x84, 0);
						break;           
										 
			case 2:  	setreg(0xA4, 0x12, 0);   //Note C#, channel 1
						setreg(0xA0, 0xAA, 0);
						setreg(0xA5, 0x12, 0);   //Note C#, channel 2
						setreg(0xA1, 0xAA, 0);
						setreg(0xA6, 0x12, 0);   //Note C#, channel 3
						setreg(0xA2, 0xAA, 0);
						break;           
										 
			case 3:  	setreg(0xA4, 0x12, 0);   //Note D, channel 1
						setreg(0xA0, 0xD3, 0);
						setreg(0xA5, 0x12, 0);   //Note D, channel 2
						setreg(0xA1, 0xD3, 0);
						setreg(0xA6, 0x12, 0);   //Note D, channel 3
						setreg(0xA2, 0xD3, 0);
						break;           
										 
			case 4:  	setreg(0xA4, 0x12, 0);   //Note D#, channel 1
						setreg(0xA0, 0xFE, 0);
						setreg(0xA5, 0x12, 0);   //Note D#, channel 2
						setreg(0xA1, 0xFE, 0);
						setreg(0xA6, 0x12, 0);   //Note D#, channel 3
						setreg(0xA2, 0xFE, 0);
						break;           
										
			case 5:  	setreg(0xA4, 0x13, 0);   //Note D, channel 1
						setreg(0xA0, 0x2B, 0);
						setreg(0xA5, 0x13, 0);   //Note D, channel 2
						setreg(0xA1, 0x2B, 0);
						setreg(0xA6, 0x13, 0);   //Note D, channel 3
						setreg(0xA2, 0x2B, 0);
						break;           
										 
			case 6:  	setreg(0xA4, 0x13, 0);   //Note D, channel 1
						setreg(0xA0, 0x5B, 0);
						setreg(0xA5, 0x13, 0);   //Note D, channel 2
						setreg(0xA1, 0x5B, 0);
						setreg(0xA6, 0x13, 0);   //Note D, channel 3
						setreg(0xA2, 0x5B, 0);
						break;           
										 
			case 7:  	setreg(0xA4, 0x13, 0);   //Note D, channel 1
						setreg(0xA0, 0x8E, 0);
						setreg(0xA5, 0x13, 0);   //Note D, channel 2
						setreg(0xA1, 0x8E, 0);
						setreg(0xA6, 0x13, 0);   //Note D, channel 3
						setreg(0xA2, 0x8E, 0);
						break;           
										 
			case 8:  	setreg(0xA4, 0x13, 0);   //Note D, channel 1
						setreg(0xA0, 0xC5, 0);
						setreg(0xA5, 0x13, 0);   //Note D, channel 2
						setreg(0xA1, 0xC5, 0);
						setreg(0xA6, 0x13, 0);   //Note D, channel 3
						setreg(0xA2, 0xC5, 0);
						break;           
										 
			case 9:  	setreg(0xA4, 0x13, 0);   //Note D, channel 1
						setreg(0xA0, 0xFE, 0);
						setreg(0xA5, 0x13, 0);   //Note D, channel 2
						setreg(0xA1, 0xFE, 0);
						setreg(0xA6, 0x13, 0);   //Note D, channel 3
						setreg(0xA2, 0xFE, 0);
						break;           
										 
			case 10:  	setreg(0xA4, 0x14, 0);   //Note D, channel 1
						setreg(0xA0, 0x3B, 0);
						setreg(0xA5, 0x14, 0);   //Note D, channel 2
						setreg(0xA1, 0x3B, 0);
						setreg(0xA6, 0x14, 0);   //Note D, channel 3
						setreg(0xA2, 0x3B, 0);
						break;           
										 
			case 11:  	setreg(0xA4, 0x14, 0);   //Note D, channel 1
						setreg(0xA0, 0x7B, 0);
						setreg(0xA5, 0x14, 0);   //Note D, channel 2
						setreg(0xA1, 0x7B, 0);
						setreg(0xA6, 0x14, 0);   //Note D, channel 3
						setreg(0xA2, 0x7B, 0);
						break;           
										 
			case 12:  	setreg(0xA4, 0x14, 0);   //Note D, channel 1
						setreg(0xA0, 0xBF, 0);
						setreg(0xA5, 0x14, 0);   //Note D, channel 2
						setreg(0xA1, 0xBF, 0);
						setreg(0xA6, 0x14, 0);   //Note D, channel 3
						setreg(0xA2, 0xBF, 0);
						break;
					
			default: printf("Invalid octave!\n");
						break;
		}
	}
	
	if(octave == 3){
		switch (note){
			case 1:  	setreg(0xA4, 0x1A, 0);   //Note C, channel 1
						setreg(0xA0, 0x84, 0);
						setreg(0xA5, 0x1A, 0);   //Note C, channel 2
						setreg(0xA1, 0x84, 0);
						setreg(0xA6, 0x1A, 0);   //Note C, channel 3
						setreg(0xA2, 0x84, 0);
						break;           
										 
			case 2:  	setreg(0xA4, 0x1A, 0);   //Note C#, channel 1
						setreg(0xA0, 0xAA, 0);
						setreg(0xA5, 0x1A, 0);   //Note C#, channel 2
						setreg(0xA1, 0xAA, 0);
						setreg(0xA6, 0x1A, 0);   //Note C#, channel 3
						setreg(0xA2, 0xAA, 0);
						break;           
										
			case 3:  	setreg(0xA4, 0x1A, 0);   //Note D, channel 1
						setreg(0xA0, 0xD3, 0);
						setreg(0xA5, 0x1A, 0);   //Note D, channel 2
						setreg(0xA1, 0xD3, 0);
						setreg(0xA6, 0x1A, 0);   //Note D, channel 3
						setreg(0xA2, 0xD3, 0);
						break;           
										 
			case 4:  	setreg(0xA4, 0x1A, 0);   //Note D#, channel 1
						setreg(0xA0, 0xFE, 0);
						setreg(0xA5, 0x1A, 0);   //Note D#, channel 2
						setreg(0xA1, 0xFE, 0);
						setreg(0xA6, 0x1A, 0);   //Note D#, channel 3
						setreg(0xA2, 0xFE, 0);
						break;           
										
			case 5:  	setreg(0xA4, 0x1B, 0);   //Note E, channel 1
						setreg(0xA0, 0x2B, 0);
						setreg(0xA5, 0x1B, 0);   //Note E, channel 2
						setreg(0xA1, 0x2B, 0);
						setreg(0xA6, 0x1B, 0);   //Note E, channel 3
						setreg(0xA2, 0x2B, 0);
						break;           
										 
			case 6:  	setreg(0xA4, 0x1B, 0);   //Note F, channel 1
						setreg(0xA0, 0x5B, 0);
						setreg(0xA5, 0x1B, 0);   //Note F, channel 2
						setreg(0xA1, 0x5B, 0);
						setreg(0xA6, 0x1B, 0);   //Note F, channel 3
						setreg(0xA2, 0x5B, 0);
						break;           
										 
			case 7:  	setreg(0xA4, 0x1B, 0);   //Note D, channel 1
						setreg(0xA0, 0x8E, 0);
						setreg(0xA5, 0x1B, 0);   //Note D, channel 2
						setreg(0xA1, 0x8E, 0);
						setreg(0xA6, 0x1B, 0);   //Note D, channel 3
						setreg(0xA2, 0x8E, 0);
						break;           
										 
			case 8:  	setreg(0xA4, 0x1B, 0);   //Note D, channel 1
						setreg(0xA0, 0xC5, 0);
						setreg(0xA5, 0x1B, 0);   //Note D, channel 2
						setreg(0xA1, 0xC5, 0);
						setreg(0xA6, 0x1B, 0);   //Note D, channel 3
						setreg(0xA2, 0xC5, 0);
						break;           
										 
			case 9:  	setreg(0xA4, 0x1B, 0);   //Note D, channel 1
						setreg(0xA0, 0xFE, 0);
						setreg(0xA5, 0x1B, 0);   //Note D, channel 2
						setreg(0xA1, 0xFE, 0);
						setreg(0xA6, 0x1B, 0);   //Note D, channel 3
						setreg(0xA2, 0xFE, 0);
						break;           
										 
			case 10:  	setreg(0xA4, 0x1C, 0);   //Note D, channel 1
						setreg(0xA0, 0x3B, 0);
						setreg(0xA5, 0x1C, 0);   //Note D, channel 2
						setreg(0xA1, 0x3B, 0);
						setreg(0xA6, 0x1C, 0);   //Note D, channel 3
						setreg(0xA2, 0x3B, 0);
						break;           
										 
			case 11:  	setreg(0xA4, 0x1C, 0);   //Note D, channel 1
						setreg(0xA0, 0x7B, 0);
						setreg(0xA5, 0x1C, 0);   //Note D, channel 2
						setreg(0xA1, 0x7B, 0);
						setreg(0xA6, 0x1C, 0);   //Note D, channel 3
						setreg(0xA2, 0x7B, 0);
						break;           
										 
			case 12:  	setreg(0xA4, 0x1C, 0);   //Note D, channel 1
						setreg(0xA0, 0xBF, 0);
						setreg(0xA5, 0x1C, 0);   //Note D, channel 2
						setreg(0xA1, 0xBF, 0);
						setreg(0xA6, 0x1C, 0);   //Note D, channel 3
						setreg(0xA2, 0xBF, 0);
						break;
					
			default: printf("Invalid octave!\n");
						break;
		}
	}
	
	if(octave == 4){
		switch (note){
			case 1:  	setreg(0xA4, 0x22, 0);   //Note C, channel 1
						setreg(0xA0, 0x84, 0);
						setreg(0xA5, 0x22, 0);   //Note C, channel 2
						setreg(0xA1, 0x84, 0);
						setreg(0xA6, 0x22, 0);   //Note C, channel 3
						setreg(0xA2, 0x84, 0);
						break;           
										 
			case 2:  	setreg(0xA4, 0x22, 0);   //Note C#, channel 1
						setreg(0xA0, 0xAA, 0);
						setreg(0xA5, 0x22, 0);   //Note C#, channel 2
						setreg(0xA1, 0xAA, 0);
						setreg(0xA6, 0x22, 0);   //Note C#, channel 3
						setreg(0xA2, 0xAA, 0);
						break;           
										 
			case 3:  	setreg(0xA4, 0x22, 0);   //Note D, channel 1
						setreg(0xA0, 0xD3, 0);
						setreg(0xA5, 0x22, 0);   //Note D, channel 2
						setreg(0xA1, 0xD3, 0);
						setreg(0xA6, 0x22, 0);   //Note D, channel 3
						setreg(0xA2, 0xD3, 0);
						break;           
										 
			case 4:  	setreg(0xA4, 0x22, 0);   //Note D, channel 1
						setreg(0xA0, 0xFE, 0);
						setreg(0xA5, 0x22, 0);   //Note D, channel 2
						setreg(0xA1, 0xFE, 0);
						setreg(0xA6, 0x22, 0);   //Note D, channel 3
						setreg(0xA2, 0xFE, 0);
						break;           
										 
			case 5:  	setreg(0xA4, 0x23, 0);   //Note D, channel 1
						setreg(0xA0, 0x2B, 0);
						setreg(0xA5, 0x23, 0);   //Note D, channel 2
						setreg(0xA1, 0x2B, 0);
						setreg(0xA6, 0x23, 0);   //Note D, channel 3
						setreg(0xA2, 0x2B, 0);
						break;           
										 
			case 6:  	setreg(0xA4, 0x23, 0);   //Note D, channel 1
						setreg(0xA0, 0x5B, 0);
						setreg(0xA5, 0x23, 0);   //Note D, channel 2
						setreg(0xA1, 0x5B, 0);
						setreg(0xA6, 0x23, 0);   //Note D, channel 3
						setreg(0xA2, 0x5B, 0);
						break;           
										 
			case 7:  	setreg(0xA4, 0x23, 0);   //Note D, channel 1
						setreg(0xA0, 0x8E, 0);
						setreg(0xA5, 0x23, 0);   //Note D, channel 2
						setreg(0xA1, 0x8E, 0);
						setreg(0xA6, 0x23, 0);   //Note D, channel 3
						setreg(0xA2, 0x8E, 0);
						break;           
										 
			case 8:  	setreg(0xA4, 0x23, 0);   //Note D, channel 1
						setreg(0xA0, 0xC5, 0);
						setreg(0xA5, 0x23, 0);   //Note D, channel 2
						setreg(0xA1, 0xC5, 0);
						setreg(0xA6, 0x23, 0);   //Note D, channel 3
						setreg(0xA2, 0xC5, 0);
						break;           
										 
			case 9:  	setreg(0xA4, 0x23, 0);   //Note D, channel 1
						setreg(0xA0, 0xFE, 0);
						setreg(0xA5, 0x23, 0);   //Note D, channel 2
						setreg(0xA1, 0xFE, 0);
						setreg(0xA6, 0x23, 0);   //Note D, channel 3
						setreg(0xA2, 0xFE, 0);
						break;           
										 
			case 10:  	setreg(0xA4, 0x24, 0);   //Note D, channel 1
						setreg(0xA0, 0x3B, 0);
						setreg(0xA5, 0x24, 0);   //Note D, channel 2
						setreg(0xA1, 0x3B, 0);
						setreg(0xA6, 0x24, 0);   //Note D, channel 3
						setreg(0xA2, 0x3B, 0);
						break;           
										 
			case 11:  	setreg(0xA4, 0x24, 0);   //Note D, channel 1
						setreg(0xA0, 0x7B, 0);
						setreg(0xA5, 0x24, 0);   //Note D, channel 2
						setreg(0xA1, 0x7B, 0);
						setreg(0xA6, 0x24, 0);   //Note D, channel 3
						setreg(0xA2, 0x7B, 0);
						break;           
										 
			case 12:  	setreg(0xA4, 0x24, 0);   //Note D, channel 1
						setreg(0xA0, 0xBF, 0);
						setreg(0xA5, 0x24, 0);   //Note D, channel 2
						setreg(0xA1, 0xBF, 0);
						setreg(0xA6, 0x24, 0);   //Note D, channel 3
						setreg(0xA2, 0xBF, 0);
						break;
					
			default: printf("Invalid octave!\n");
						break;
		}
	}
	
	if(octave == 5){
		switch (note){
			case 1:  	setreg(0xA4, 0x2A, 0);   //Note C, channel 1
						setreg(0xA0, 0x84, 0);
						setreg(0xA5, 0x2A, 0);   //Note C, channel 2
						setreg(0xA1, 0x84, 0);
						setreg(0xA6, 0x2A, 0);   //Note C, channel 3
						setreg(0xA2, 0x84, 0);
						break;           
										 
			case 2:  	setreg(0xA4, 0x2A, 0);   //Note C#, channel 1
						setreg(0xA0, 0xAA, 0);
						setreg(0xA5, 0x2A, 0);   //Note C#, channel 2
						setreg(0xA1, 0xAA, 0);
						setreg(0xA6, 0x2A, 0);   //Note C#, channel 3
						setreg(0xA2, 0xAA, 0);
						break;          
										 
			case 3:  	setreg(0xA4, 0x2A, 0);   //Note D, channel 1
						setreg(0xA0, 0xD3, 0);
						setreg(0xA5, 0x2A, 0);   //Note D, channel 2
						setreg(0xA1, 0xD3, 0);
						setreg(0xA6, 0x2A, 0);   //Note D, channel 3
						setreg(0xA2, 0xD3, 0);
						break;           
										 
			case 4:  	setreg(0xA4, 0x2A, 0);   //Note D, channel 1
						setreg(0xA0, 0xFE, 0);
						setreg(0xA5, 0x2A, 0);   //Note D, channel 2
						setreg(0xA1, 0xFE, 0);
						setreg(0xA6, 0x2A, 0);   //Note D, channel 3
						setreg(0xA2, 0xFE, 0);
						break;           
										 
			case 5:  	setreg(0xA4, 0x2B, 0);   //Note D, channel 1
						setreg(0xA0, 0x2B, 0);
						setreg(0xA5, 0x2B, 0);   //Note D, channel 2
						setreg(0xA1, 0x2B, 0);
						setreg(0xA6, 0x2B, 0);   //Note D, channel 3
						setreg(0xA2, 0x2B, 0);
						break;           
										 
			case 6:  	setreg(0xA4, 0x2B, 0);   //Note D, channel 1
						setreg(0xA0, 0x5B, 0);
						setreg(0xA5, 0x2B, 0);   //Note D, channel 2
						setreg(0xA1, 0x5B, 0);
						setreg(0xA6, 0x2B, 0);   //Note D, channel 3
						setreg(0xA2, 0x5B, 0);
						break;           
										 
			case 7:  	setreg(0xA4, 0x2B, 0);   //Note D, channel 1
						setreg(0xA0, 0x8E, 0);
						setreg(0xA5, 0x2B, 0);   //Note D, channel 2
						setreg(0xA1, 0x8E, 0);
						setreg(0xA6, 0x2B, 0);   //Note D, channel 3
						setreg(0xA2, 0x8E, 0);
						break;           
										 
			case 8:  	setreg(0xA4, 0x2B, 0);   //Note D, channel 1
						setreg(0xA0, 0xC5, 0);
						setreg(0xA5, 0x2B, 0);   //Note D, channel 2
						setreg(0xA1, 0xC5, 0);
						setreg(0xA6, 0x2B, 0);   //Note D, channel 3
						setreg(0xA2, 0xC5, 0);
						break;           
										 
			case 9:  	setreg(0xA4, 0x2B, 0);   //Note D, channel 1
						setreg(0xA0, 0xFE, 0);
						setreg(0xA5, 0x2B, 0);   //Note D, channel 2
						setreg(0xA1, 0xFE, 0);
						setreg(0xA6, 0x2B, 0);   //Note D, channel 3
						setreg(0xA2, 0xFE, 0);
						break;           
										 
			case 10:  	setreg(0xA4, 0x2C, 0);   //Note D, channel 1
						setreg(0xA0, 0x3B, 0);
						setreg(0xA5, 0x2C, 0);   //Note D, channel 2
						setreg(0xA1, 0x3B, 0);
						setreg(0xA6, 0x2C, 0);   //Note D, channel 3
						setreg(0xA2, 0x3B, 0);
						break;           
										 
			case 11:  	setreg(0xA4, 0x2C, 0);   //Note D, channel 1
						setreg(0xA0, 0x7B, 0);
						setreg(0xA5, 0x2C, 0);   //Note D, channel 2
						setreg(0xA1, 0x7B, 0);
						setreg(0xA6, 0x2C, 0);   //Note D, channel 3
						setreg(0xA2, 0x7B, 0);
						break;           
										 
			case 12:  	setreg(0xA4, 0x2C, 0);   //Note D, channel 1
						setreg(0xA0, 0xBF, 0);
						setreg(0xA5, 0x2C, 0);   //Note D, channel 2
						setreg(0xA1, 0xBF, 0);
						setreg(0xA6, 0x2C, 0);   //Note D, channel 3
						setreg(0xA2, 0xBF, 0);
						break;
					
			default: printf("Invalid octave!\n");
						break;
		}
	}

	if(octave == 6){
		switch (note){
			case 1:  	setreg(0xA4, 0x32, 0);   //Note C, channel 1
						setreg(0xA0, 0x84, 0);
						setreg(0xA5, 0x32, 0);   //Note C, channel 2
						setreg(0xA1, 0x84, 0);
						setreg(0xA6, 0x32, 0);   //Note C, channel 3
						setreg(0xA2, 0x84, 0);
						break;           
										 
			case 2:  	setreg(0xA4, 0x32, 0);   //Note C#, channel 1
						setreg(0xA0, 0xAA, 0);
						setreg(0xA5, 0x32, 0);   //Note C#, channel 2
						setreg(0xA1, 0xAA, 0);
						setreg(0xA6, 0x32, 0);   //Note C#, channel 3
						setreg(0xA2, 0xAA, 0);
						break;           
										 
			case 3:  	setreg(0xA4, 0x32, 0);   //Note D, channel 1
						setreg(0xA0, 0xD3, 0);
						setreg(0xA5, 0x32, 0);   //Note D, channel 2
						setreg(0xA1, 0xD3, 0);
						setreg(0xA6, 0x32, 0);   //Note D, channel 3
						setreg(0xA2, 0xD3, 0);
						break;           
										 
			case 4:  	setreg(0xA4, 0x32, 0);   //Note D, channel 1
						setreg(0xA0, 0xFE, 0);
						setreg(0xA5, 0x32, 0);   //Note D, channel 2
						setreg(0xA1, 0xFE, 0);
						setreg(0xA6, 0x32, 0);   //Note D, channel 3
						setreg(0xA2, 0xFE, 0);
						break;           
										 
			case 5:  	setreg(0xA4, 0x33, 0);   //Note D, channel 1
						setreg(0xA0, 0x2B, 0);
						setreg(0xA5, 0x33, 0);   //Note D, channel 2
						setreg(0xA1, 0x2B, 0);
						setreg(0xA6, 0x33, 0);   //Note D, channel 3
						setreg(0xA2, 0x2B, 0);
						break;           
										 
			case 6:  	setreg(0xA4, 0x33, 0);   //Note D, channel 1
						setreg(0xA0, 0x5B, 0);
						setreg(0xA5, 0x33, 0);   //Note D, channel 2
						setreg(0xA1, 0x5B, 0);
						setreg(0xA6, 0x33, 0);   //Note D, channel 3
						setreg(0xA2, 0x5B, 0);
						break;           
										 
			case 7:  	setreg(0xA4, 0x33, 0);   //Note D, channel 1
						setreg(0xA0, 0x8E, 0);
						setreg(0xA5, 0x33, 0);   //Note D, channel 2
						setreg(0xA1, 0x8E, 0);
						setreg(0xA6, 0x33, 0);   //Note D, channel 3
						setreg(0xA2, 0x8E, 0);
						break;           
										 
			case 8:  	setreg(0xA4, 0x33, 0);   //Note D, channel 1
						setreg(0xA0, 0xC5, 0);
						setreg(0xA5, 0x33, 0);   //Note D, channel 2
						setreg(0xA1, 0xC5, 0);
						setreg(0xA6, 0x33, 0);   //Note D, channel 3
						setreg(0xA2, 0xC5, 0);
						break;           
										 
			case 9:  	setreg(0xA4, 0x33, 0);   //Note D, channel 1
						setreg(0xA0, 0xFE, 0);
						setreg(0xA5, 0x33, 0);   //Note D, channel 2
						setreg(0xA1, 0xFE, 0);
						setreg(0xA6, 0x33, 0);   //Note D, channel 3
						setreg(0xA2, 0xFE, 0);
						break;          
										 
			case 10:  	setreg(0xA4, 0x34, 0);   //Note D, channel 1
						setreg(0xA0, 0x3B, 0);
						setreg(0xA5, 0x34, 0);   //Note D, channel 2
						setreg(0xA1, 0x3B, 0);
						setreg(0xA6, 0x34, 0);   //Note D, channel 3
						setreg(0xA2, 0x3B, 0);
						break;          
										 
			case 11:  	setreg(0xA4, 0x34, 0);   //Note D, channel 1
						setreg(0xA0, 0x7B, 0);
						setreg(0xA5, 0x34, 0);   //Note D, channel 2
						setreg(0xA1, 0x7B, 0);
						setreg(0xA6, 0x34, 0);   //Note D, channel 3
						setreg(0xA2, 0x7B, 0);
						break;           
										 
			case 12:  	setreg(0xA4, 0x34, 0);   //Note D, channel 1
						setreg(0xA0, 0xBF, 0);
						setreg(0xA5, 0x34, 0);   //Note D, channel 2
						setreg(0xA1, 0xBF, 0);
						setreg(0xA6, 0x34, 0);   //Note D, channel 3
						setreg(0xA2, 0xBF, 0);
						break;
					
			default: printf("Invalid octave!\n");
						break;
		}
	}
	
	if(octave == 7){
		switch (note){
			case 1:  	setreg(0xA4, 0x3A, 0);   //Note C, channel 1
						setreg(0xA0, 0x84, 0);
						setreg(0xA5, 0x3A, 0);   //Note C, channel 2
						setreg(0xA1, 0x84, 0);
						setreg(0xA6, 0x3A, 0);   //Note C, channel 3
						setreg(0xA2, 0x84, 0);
						break;
					
			default: printf("Invalid octave!\n");
						break;
		}
	}
}
