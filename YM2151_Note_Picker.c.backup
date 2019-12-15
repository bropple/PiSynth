//Benjamin Ropple
//YM2151_Note_Picker.c
//Switch-Case for picking notes and octaves for the YM2612.

#include "YM2151.h"
#include "YM2151_Note_Picker.h"

void note_picker_2151(int note, int octave){
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
	 * There are 8 Octaves on the YM2151, ranging from octave 0 (very low) to octave 7 (very high)
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
			case 1:  	setreg_2151(0xA4, 0x0A);   //Note C, channel 1
						setreg_2151(0xA0, 0x84);
						setreg_2151(0xA5, 0x0A);   //Note C, channel 2
						setreg_2151(0xA1, 0x84);
						setreg_2151(0xA6, 0x0A);   //Note C, channel 3
						setreg_2151(0xA2, 0x84);
						break;
					
			case 2:  	setreg_2151(0xA4, 0x0A);   //Note C#, channel 1
						setreg_2151(0xA0, 0xAA);
						setreg_2151(0xA5, 0x0A);   //Note C#, channel 2
						setreg_2151(0xA1, 0xAA);
						setreg_2151(0xA6, 0x0A);   //Note C#, channel 3
						setreg_2151(0xA2, 0xAA);
						break;
					
			case 3:  	setreg_2151(0xA4, 0x0A);   //Note D, channel 1
						setreg_2151(0xA0, 0xD3);
						setreg_2151(0xA5, 0x0A);   //Note D, channel 2
						setreg_2151(0xA1, 0xD3);
						setreg_2151(0xA6, 0x0A);   //Note D, channel 3
						setreg_2151(0xA2, 0xD3);
						break;
								
			case 4:  	setreg_2151(0xA4, 0x0A);   //Note D, channel 1
						setreg_2151(0xA0, 0xFE);
						setreg_2151(0xA5, 0x0A);   //Note D, channel 2
						setreg_2151(0xA1, 0xFE);
						setreg_2151(0xA6, 0x0A);   //Note D, channel 3
						setreg_2151(0xA2, 0xFE);
						break;
								
			case 5:  	setreg_2151(0xA4, 0x0B);   //Note D, channel 1
						setreg_2151(0xA0, 0x2B);
						setreg_2151(0xA5, 0x0B);   //Note D, channel 2
						setreg_2151(0xA1, 0x2B);
						setreg_2151(0xA6, 0x0B);   //Note D, channel 3
						setreg_2151(0xA2, 0x2B);
						break;
								
			case 6:  	setreg_2151(0xA4, 0x0B);   //Note D, channel 1
						setreg_2151(0xA0, 0x5B);
						setreg_2151(0xA5, 0x0B);   //Note D, channel 2
						setreg_2151(0xA1, 0x5B);
						setreg_2151(0xA6, 0x0B);   //Note D, channel 3
						setreg_2151(0xA2, 0x5B);
						break;
									
			case 7:  	setreg_2151(0xA4, 0x0B);   //Note D, channel 1
						setreg_2151(0xA0, 0x8E);
						setreg_2151(0xA5, 0x0B);   //Note D, channel 2
						setreg_2151(0xA1, 0x8E);
						setreg_2151(0xA6, 0x0B);   //Note D, channel 3
						setreg_2151(0xA2, 0x8E);
						break;
									
			case 8:  	setreg_2151(0xA4, 0x0B);   //Note D, channel 1
						setreg_2151(0xA0, 0xC5);
						setreg_2151(0xA5, 0x0B);   //Note D, channel 2
						setreg_2151(0xA1, 0xC5);
						setreg_2151(0xA6, 0x0B);   //Note D, channel 3
						setreg_2151(0xA2, 0xC5);
						break;
								
			case 9:  	setreg_2151(0xA4, 0x0B);   //Note D, channel 1
						setreg_2151(0xA0, 0xFE);
						setreg_2151(0xA5, 0x0B);   //Note D, channel 2
						setreg_2151(0xA1, 0xFE);
						setreg_2151(0xA6, 0x0B);   //Note D, channel 3
						setreg_2151(0xA2, 0xFE);
						break;
								
			case 10:  	setreg_2151(0xA4, 0x0C);   //Note D, channel 1
						setreg_2151(0xA0, 0x3B);
						setreg_2151(0xA5, 0x0C);   //Note D, channel 2
						setreg_2151(0xA1, 0x3B);
						setreg_2151(0xA6, 0x0C);   //Note D, channel 3
						setreg_2151(0xA2, 0x3B);
						break;
									
			case 11:  	setreg_2151(0xA4, 0x0C);   //Note D, channel 1
						setreg_2151(0xA0, 0x7B);
						setreg_2151(0xA5, 0x0C);   //Note D, channel 2
						setreg_2151(0xA1, 0x7B);
						setreg_2151(0xA6, 0x0C);   //Note D, channel 3
						setreg_2151(0xA2, 0x7B);
						break;
									
			case 12:  	setreg_2151(0xA4, 0x0C);   //Note D, channel 1
						setreg_2151(0xA0, 0xBF);
						setreg_2151(0xA5, 0x0C);   //Note D, channel 2
						setreg_2151(0xA1, 0xBF);
						setreg_2151(0xA6, 0x0C);   //Note D, channel 3
						setreg_2151(0xA2, 0xBF);
						break;
					
			default: printf("Invalid octave!\n");
						break;
		}
	}
	
	if(octave == 2) {
		switch (note){
			case 1:  	setreg_2151(0x28, 0x2E);   //Note C, channel 1
						setreg_2151(0xA0, 0x84);
						setreg_2151(0xA5, 0x12);   //Note C, channel 2
						setreg_2151(0xA1, 0x84);
						setreg_2151(0xA6, 0x12);   //Note C, channel 3
						setreg_2151(0xA2, 0x84);
						break;
					
			case 2:  	setreg_2151(0xA4, 0x12);   //Note C#, channel 1
						setreg_2151(0xA0, 0xAA);
						setreg_2151(0xA5, 0x12);   //Note C#, channel 2
						setreg_2151(0xA1, 0xAA);
						setreg_2151(0xA6, 0x12);   //Note C#, channel 3
						setreg_2151(0xA2, 0xAA);
						break;
					
			case 3:  	setreg_2151(0xA4, 0x12);   //Note D, channel 1
						setreg_2151(0xA0, 0xD3);
						setreg_2151(0xA5, 0x12);   //Note D, channel 2
						setreg_2151(0xA1, 0xD3);
						setreg_2151(0xA6, 0x12);   //Note D, channel 3
						setreg_2151(0xA2, 0xD3);
						break;
								
			case 4:  	setreg_2151(0xA4, 0x12);   //Note D, channel 1
						setreg_2151(0xA0, 0xFE);
						setreg_2151(0xA5, 0x12);   //Note D, channel 2
						setreg_2151(0xA1, 0xFE);
						setreg_2151(0xA6, 0x12);   //Note D, channel 3
						setreg_2151(0xA2, 0xFE);
						break;
								
			case 5:  	setreg_2151(0xA4, 0x13);   //Note D, channel 1
						setreg_2151(0xA0, 0x2B);
						setreg_2151(0xA5, 0x13);   //Note D, channel 2
						setreg_2151(0xA1, 0x2B);
						setreg_2151(0xA6, 0x13);   //Note D, channel 3
						setreg_2151(0xA2, 0x2B);
						break;
								
			case 6:  	setreg_2151(0xA4, 0x13);   //Note D, channel 1
						setreg_2151(0xA0, 0x5B);
						setreg_2151(0xA5, 0x13);   //Note D, channel 2
						setreg_2151(0xA1, 0x5B);
						setreg_2151(0xA6, 0x13);   //Note D, channel 3
						setreg_2151(0xA2, 0x5B);
						break;
									
			case 7:  	setreg_2151(0xA4, 0x13);   //Note D, channel 1
						setreg_2151(0xA0, 0x8E);
						setreg_2151(0xA5, 0x13);   //Note D, channel 2
						setreg_2151(0xA1, 0x8E);
						setreg_2151(0xA6, 0x13);   //Note D, channel 3
						setreg_2151(0xA2, 0x8E);
						break;
									
			case 8:  	setreg_2151(0xA4, 0x13);   //Note D, channel 1
						setreg_2151(0xA0, 0xC5);
						setreg_2151(0xA5, 0x13);   //Note D, channel 2
						setreg_2151(0xA1, 0xC5);
						setreg_2151(0xA6, 0x13);   //Note D, channel 3
						setreg_2151(0xA2, 0xC5);
						break;
								
			case 9:  	setreg_2151(0xA4, 0x13);   //Note D, channel 1
						setreg_2151(0xA0, 0xFE);
						setreg_2151(0xA5, 0x13);   //Note D, channel 2
						setreg_2151(0xA1, 0xFE);
						setreg_2151(0xA6, 0x13);   //Note D, channel 3
						setreg_2151(0xA2, 0xFE);
						break;
								
			case 10:  	setreg_2151(0xA4, 0x14);   //Note D, channel 1
						setreg_2151(0xA0, 0x3B);
						setreg_2151(0xA5, 0x14);   //Note D, channel 2
						setreg_2151(0xA1, 0x3B);
						setreg_2151(0xA6, 0x14);   //Note D, channel 3
						setreg_2151(0xA2, 0x3B);
						break;
									
			case 11:  	setreg_2151(0xA4, 0x14);   //Note D, channel 1
						setreg_2151(0xA0, 0x7B);
						setreg_2151(0xA5, 0x14);   //Note D, channel 2
						setreg_2151(0xA1, 0x7B);
						setreg_2151(0xA6, 0x14);   //Note D, channel 3
						setreg_2151(0xA2, 0x7B);
						break;
									
			case 12:  	setreg_2151(0xA4, 0x14);   //Note D, channel 1
						setreg_2151(0xA0, 0xBF);
						setreg_2151(0xA5, 0x14);   //Note D, channel 2
						setreg_2151(0xA1, 0xBF);
						setreg_2151(0xA6, 0x14);   //Note D, channel 3
						setreg_2151(0xA2, 0xBF);
						break;
					
			default: printf("Invalid octave!\n");
						break;
		}
	}
	
	if(octave == 3){
		switch (note){
			case 1:  	setreg_2151(0x28, 0x2E);   //Note C, channel 1
						//setreg_2151(0xA0, 0x84);
						setreg_2151(0x29, 0x2E);   //Note C, channel 2
						//setreg_2151(0xA1, 0x84);
						setreg_2151(0x2A, 0x2E);   //Note C, channel 3
						//setreg_2151(0xA2, 0x84);
						break;
					
			case 2:  	setreg_2151(0xA4, 0x1A);   //Note C#, channel 1
						setreg_2151(0xA0, 0xAA);
						setreg_2151(0xA5, 0x1A);   //Note C#, channel 2
						setreg_2151(0xA1, 0xAA);
						setreg_2151(0xA6, 0x1A);   //Note C#, channel 3
						setreg_2151(0xA2, 0xAA);
						break;
					
			case 3:  	setreg_2151(0xA4, 0x1A);   //Note D, channel 1
						setreg_2151(0xA0, 0xD3);
						setreg_2151(0xA5, 0x1A);   //Note D, channel 2
						setreg_2151(0xA1, 0xD3);
						setreg_2151(0xA6, 0x1A);   //Note D, channel 3
						setreg_2151(0xA2, 0xD3);
						break;
								
			case 4:  	setreg_2151(0xA4, 0x1A);   //Note D, channel 1
						setreg_2151(0xA0, 0xFE);
						setreg_2151(0xA5, 0x1A);   //Note D, channel 2
						setreg_2151(0xA1, 0xFE);
						setreg_2151(0xA6, 0x1A);   //Note D, channel 3
						setreg_2151(0xA2, 0xFE);
						break;
								
			case 5:  	setreg_2151(0xA4, 0x1B);   //Note D, channel 1
						setreg_2151(0xA0, 0x2B);
						setreg_2151(0xA5, 0x1B);   //Note D, channel 2
						setreg_2151(0xA1, 0x2B);
						setreg_2151(0xA6, 0x1B);   //Note D, channel 3
						setreg_2151(0xA2, 0x2B);
						break;
								
			case 6:  	setreg_2151(0xA4, 0x1B);   //Note D, channel 1
						setreg_2151(0xA0, 0x5B);
						setreg_2151(0xA5, 0x1B);   //Note D, channel 2
						setreg_2151(0xA1, 0x5B);
						setreg_2151(0xA6, 0x1B);   //Note D, channel 3
						setreg_2151(0xA2, 0x5B);
						break;
									
			case 7:  	setreg_2151(0xA4, 0x1B);   //Note D, channel 1
						setreg_2151(0xA0, 0x8E);
						setreg_2151(0xA5, 0x1B);   //Note D, channel 2
						setreg_2151(0xA1, 0x8E);
						setreg_2151(0xA6, 0x1B);   //Note D, channel 3
						setreg_2151(0xA2, 0x8E);
						break;
									
			case 8:  	setreg_2151(0xA4, 0x1B);   //Note D, channel 1
						setreg_2151(0xA0, 0xC5);
						setreg_2151(0xA5, 0x1B);   //Note D, channel 2
						setreg_2151(0xA1, 0xC5);
						setreg_2151(0xA6, 0x1B);   //Note D, channel 3
						setreg_2151(0xA2, 0xC5);
						break;
								
			case 9:  	setreg_2151(0xA4, 0x1B);   //Note D, channel 1
						setreg_2151(0xA0, 0xFE);
						setreg_2151(0xA5, 0x1B);   //Note D, channel 2
						setreg_2151(0xA1, 0xFE);
						setreg_2151(0xA6, 0x1B);   //Note D, channel 3
						setreg_2151(0xA2, 0xFE);
						break;
								
			case 10:  	setreg_2151(0xA4, 0x1C);   //Note D, channel 1
						setreg_2151(0xA0, 0x3B);
						setreg_2151(0xA5, 0x1C);   //Note D, channel 2
						setreg_2151(0xA1, 0x3B);
						setreg_2151(0xA6, 0x1C);   //Note D, channel 3
						setreg_2151(0xA2, 0x3B);
						break;
									
			case 11:  	setreg_2151(0xA4, 0x1C);   //Note D, channel 1
						setreg_2151(0xA0, 0x7B);
						setreg_2151(0xA5, 0x1C);   //Note D, channel 2
						setreg_2151(0xA1, 0x7B);
						setreg_2151(0xA6, 0x1C);   //Note D, channel 3
						setreg_2151(0xA2, 0x7B);
						break;
									
			case 12:  	setreg_2151(0xA4, 0x1C);   //Note D, channel 1
						setreg_2151(0xA0, 0xBF);
						setreg_2151(0xA5, 0x1C);   //Note D, channel 2
						setreg_2151(0xA1, 0xBF);
						setreg_2151(0xA6, 0x1C);   //Note D, channel 3
						setreg_2151(0xA2, 0xBF);
						break;
					
			default: printf("Invalid octave!\n");
						break;
		}
	}
	
	if(octave == 4){
		switch (note){
			case 1:  	setreg_2151(0xA4, 0x22);   //Note C, channel 1
						setreg_2151(0xA0, 0x84);
						setreg_2151(0xA5, 0x22);   //Note C, channel 2
						setreg_2151(0xA1, 0x84);
						setreg_2151(0xA6, 0x22);   //Note C, channel 3
						setreg_2151(0xA2, 0x84);
						break;
					
			case 2:  	setreg_2151(0xA4, 0x22);   //Note C#, channel 1
						setreg_2151(0xA0, 0xAA);
						setreg_2151(0xA5, 0x22);   //Note C#, channel 2
						setreg_2151(0xA1, 0xAA);
						setreg_2151(0xA6, 0x22);   //Note C#, channel 3
						setreg_2151(0xA2, 0xAA);
						break;
					
			case 3:  	setreg_2151(0xA4, 0x22);   //Note D, channel 1
						setreg_2151(0xA0, 0xD3);
						setreg_2151(0xA5, 0x22);   //Note D, channel 2
						setreg_2151(0xA1, 0xD3);
						setreg_2151(0xA6, 0x22);   //Note D, channel 3
						setreg_2151(0xA2, 0xD3);
						break;
								
			case 4:  	setreg_2151(0xA4, 0x22);   //Note D, channel 1
						setreg_2151(0xA0, 0xFE);
						setreg_2151(0xA5, 0x22);   //Note D, channel 2
						setreg_2151(0xA1, 0xFE);
						setreg_2151(0xA6, 0x22);   //Note D, channel 3
						setreg_2151(0xA2, 0xFE);
						break;
								
			case 5:  	setreg_2151(0xA4, 0x23);   //Note D, channel 1
						setreg_2151(0xA0, 0x2B);
						setreg_2151(0xA5, 0x23);   //Note D, channel 2
						setreg_2151(0xA1, 0x2B);
						setreg_2151(0xA6, 0x23);   //Note D, channel 3
						setreg_2151(0xA2, 0x2B);
						break;
								
			case 6:  	setreg_2151(0xA4, 0x23);   //Note D, channel 1
						setreg_2151(0xA0, 0x5B);
						setreg_2151(0xA5, 0x23);   //Note D, channel 2
						setreg_2151(0xA1, 0x5B);
						setreg_2151(0xA6, 0x23);   //Note D, channel 3
						setreg_2151(0xA2, 0x5B);
						break;
									
			case 7:  	setreg_2151(0xA4, 0x23);   //Note D, channel 1
						setreg_2151(0xA0, 0x8E);
						setreg_2151(0xA5, 0x23);   //Note D, channel 2
						setreg_2151(0xA1, 0x8E);
						setreg_2151(0xA6, 0x23);   //Note D, channel 3
						setreg_2151(0xA2, 0x8E);
						break;
									
			case 8:  	setreg_2151(0xA4, 0x23);   //Note D, channel 1
						setreg_2151(0xA0, 0xC5);
						setreg_2151(0xA5, 0x23);   //Note D, channel 2
						setreg_2151(0xA1, 0xC5);
						setreg_2151(0xA6, 0x23);   //Note D, channel 3
						setreg_2151(0xA2, 0xC5);
						break;
								
			case 9:  	setreg_2151(0xA4, 0x23);   //Note D, channel 1
						setreg_2151(0xA0, 0xFE);
						setreg_2151(0xA5, 0x23);   //Note D, channel 2
						setreg_2151(0xA1, 0xFE);
						setreg_2151(0xA6, 0x23);   //Note D, channel 3
						setreg_2151(0xA2, 0xFE);
						break;
								
			case 10:  	setreg_2151(0xA4, 0x24);   //Note D, channel 1
						setreg_2151(0xA0, 0x3B);
						setreg_2151(0xA5, 0x24);   //Note D, channel 2
						setreg_2151(0xA1, 0x3B);
						setreg_2151(0xA6, 0x24);   //Note D, channel 3
						setreg_2151(0xA2, 0x3B);
						break;
									
			case 11:  	setreg_2151(0xA4, 0x24);   //Note D, channel 1
						setreg_2151(0xA0, 0x7B);
						setreg_2151(0xA5, 0x24);   //Note D, channel 2
						setreg_2151(0xA1, 0x7B);
						setreg_2151(0xA6, 0x24);   //Note D, channel 3
						setreg_2151(0xA2, 0x7B);
						break;
									
			case 12:  	setreg_2151(0xA4, 0x24);   //Note D, channel 1
						setreg_2151(0xA0, 0xBF);
						setreg_2151(0xA5, 0x24);   //Note D, channel 2
						setreg_2151(0xA1, 0xBF);
						setreg_2151(0xA6, 0x24);   //Note D, channel 3
						setreg_2151(0xA2, 0xBF);
						break;
					
			default: printf("Invalid octave!\n");
						break;
		}
	}
	
	if(octave == 5){
		switch (note){
			case 1:  	setreg_2151(0xA4, 0x2A);   //Note C, channel 1
						setreg_2151(0xA0, 0x84);
						setreg_2151(0xA5, 0x2A);   //Note C, channel 2
						setreg_2151(0xA1, 0x84);
						setreg_2151(0xA6, 0x2A);   //Note C, channel 3
						setreg_2151(0xA2, 0x84);
						break;
					
			case 2:  	setreg_2151(0xA4, 0x2A);   //Note C#, channel 1
						setreg_2151(0xA0, 0xAA);
						setreg_2151(0xA5, 0x2A);   //Note C#, channel 2
						setreg_2151(0xA1, 0xAA);
						setreg_2151(0xA6, 0x2A);   //Note C#, channel 3
						setreg_2151(0xA2, 0xAA);
						break;
					
			case 3:  	setreg_2151(0xA4, 0x2A);   //Note D, channel 1
						setreg_2151(0xA0, 0xD3);
						setreg_2151(0xA5, 0x2A);   //Note D, channel 2
						setreg_2151(0xA1, 0xD3);
						setreg_2151(0xA6, 0x2A);   //Note D, channel 3
						setreg_2151(0xA2, 0xD3);
						break;
								
			case 4:  	setreg_2151(0xA4, 0x2A);   //Note D, channel 1
						setreg_2151(0xA0, 0xFE);
						setreg_2151(0xA5, 0x2A);   //Note D, channel 2
						setreg_2151(0xA1, 0xFE);
						setreg_2151(0xA6, 0x2A);   //Note D, channel 3
						setreg_2151(0xA2, 0xFE);
						break;
								
			case 5:  	setreg_2151(0xA4, 0x2B);   //Note D, channel 1
						setreg_2151(0xA0, 0x2B);
						setreg_2151(0xA5, 0x2B);   //Note D, channel 2
						setreg_2151(0xA1, 0x2B);
						setreg_2151(0xA6, 0x2B);   //Note D, channel 3
						setreg_2151(0xA2, 0x2B);
						break;
								
			case 6:  	setreg_2151(0xA4, 0x2B);   //Note D, channel 1
						setreg_2151(0xA0, 0x5B);
						setreg_2151(0xA5, 0x2B);   //Note D, channel 2
						setreg_2151(0xA1, 0x5B);
						setreg_2151(0xA6, 0x2B);   //Note D, channel 3
						setreg_2151(0xA2, 0x5B);
						break;
									
			case 7:  	setreg_2151(0xA4, 0x2B);   //Note D, channel 1
						setreg_2151(0xA0, 0x8E);
						setreg_2151(0xA5, 0x2B);   //Note D, channel 2
						setreg_2151(0xA1, 0x8E);
						setreg_2151(0xA6, 0x2B);   //Note D, channel 3
						setreg_2151(0xA2, 0x8E);
						break;
									
			case 8:  	setreg_2151(0xA4, 0x2B);   //Note D, channel 1
						setreg_2151(0xA0, 0xC5);
						setreg_2151(0xA5, 0x2B);   //Note D, channel 2
						setreg_2151(0xA1, 0xC5);
						setreg_2151(0xA6, 0x2B);   //Note D, channel 3
						setreg_2151(0xA2, 0xC5);
						break;
								
			case 9:  	setreg_2151(0xA4, 0x2B);   //Note D, channel 1
						setreg_2151(0xA0, 0xFE);
						setreg_2151(0xA5, 0x2B);   //Note D, channel 2
						setreg_2151(0xA1, 0xFE);
						setreg_2151(0xA6, 0x2B);   //Note D, channel 3
						setreg_2151(0xA2, 0xFE);
						break;
								
			case 10:  	setreg_2151(0xA4, 0x2C);   //Note D, channel 1
						setreg_2151(0xA0, 0x3B);
						setreg_2151(0xA5, 0x2C);   //Note D, channel 2
						setreg_2151(0xA1, 0x3B);
						setreg_2151(0xA6, 0x2C);   //Note D, channel 3
						setreg_2151(0xA2, 0x3B);
						break;
									
			case 11:  	setreg_2151(0xA4, 0x2C);   //Note D, channel 1
						setreg_2151(0xA0, 0x7B);
						setreg_2151(0xA5, 0x2C);   //Note D, channel 2
						setreg_2151(0xA1, 0x7B);
						setreg_2151(0xA6, 0x2C);   //Note D, channel 3
						setreg_2151(0xA2, 0x7B);
						break;
									
			case 12:  	setreg_2151(0xA4, 0x2C);   //Note D, channel 1
						setreg_2151(0xA0, 0xBF);
						setreg_2151(0xA5, 0x2C);   //Note D, channel 2
						setreg_2151(0xA1, 0xBF);
						setreg_2151(0xA6, 0x2C);   //Note D, channel 3
						setreg_2151(0xA2, 0xBF);
						break;
					
			default: printf("Invalid octave!\n");
						break;
		}
	}

	if(octave == 6){
		switch (note){
			case 1:  	setreg_2151(0xA4, 0x32);   //Note C, channel 1
						setreg_2151(0xA0, 0x84);
						setreg_2151(0xA5, 0x32);   //Note C, channel 2
						setreg_2151(0xA1, 0x84);
						setreg_2151(0xA6, 0x32);   //Note C, channel 3
						setreg_2151(0xA2, 0x84);
						break;
					
			case 2:  	setreg_2151(0xA4, 0x32);   //Note C#, channel 1
						setreg_2151(0xA0, 0xAA);
						setreg_2151(0xA5, 0x32);   //Note C#, channel 2
						setreg_2151(0xA1, 0xAA);
						setreg_2151(0xA6, 0x32);   //Note C#, channel 3
						setreg_2151(0xA2, 0xAA);
						break;
					
			case 3:  	setreg_2151(0xA4, 0x32);   //Note D, channel 1
						setreg_2151(0xA0, 0xD3);
						setreg_2151(0xA5, 0x32);   //Note D, channel 2
						setreg_2151(0xA1, 0xD3);
						setreg_2151(0xA6, 0x32);   //Note D, channel 3
						setreg_2151(0xA2, 0xD3);
						break;
								
			case 4:  	setreg_2151(0xA4, 0x32);   //Note D, channel 1
						setreg_2151(0xA0, 0xFE);
						setreg_2151(0xA5, 0x32);   //Note D, channel 2
						setreg_2151(0xA1, 0xFE);
						setreg_2151(0xA6, 0x32);   //Note D, channel 3
						setreg_2151(0xA2, 0xFE);
						break;
								
			case 5:  	setreg_2151(0xA4, 0x33);   //Note D, channel 1
						setreg_2151(0xA0, 0x2B);
						setreg_2151(0xA5, 0x33);   //Note D, channel 2
						setreg_2151(0xA1, 0x2B);
						setreg_2151(0xA6, 0x33);   //Note D, channel 3
						setreg_2151(0xA2, 0x2B);
						break;
								
			case 6:  	setreg_2151(0xA4, 0x33);   //Note D, channel 1
						setreg_2151(0xA0, 0x5B);
						setreg_2151(0xA5, 0x33);   //Note D, channel 2
						setreg_2151(0xA1, 0x5B);
						setreg_2151(0xA6, 0x33);   //Note D, channel 3
						setreg_2151(0xA2, 0x5B);
						break;
									
			case 7:  	setreg_2151(0xA4, 0x33);   //Note D, channel 1
						setreg_2151(0xA0, 0x8E);
						setreg_2151(0xA5, 0x33);   //Note D, channel 2
						setreg_2151(0xA1, 0x8E);
						setreg_2151(0xA6, 0x33);   //Note D, channel 3
						setreg_2151(0xA2, 0x8E);
						break;
									
			case 8:  	setreg_2151(0xA4, 0x33);   //Note D, channel 1
						setreg_2151(0xA0, 0xC5);
						setreg_2151(0xA5, 0x33);   //Note D, channel 2
						setreg_2151(0xA1, 0xC5);
						setreg_2151(0xA6, 0x33);   //Note D, channel 3
						setreg_2151(0xA2, 0xC5);
						break;
								
			case 9:  	setreg_2151(0xA4, 0x33);   //Note D, channel 1
						setreg_2151(0xA0, 0xFE);
						setreg_2151(0xA5, 0x33);   //Note D, channel 2
						setreg_2151(0xA1, 0xFE);
						setreg_2151(0xA6, 0x33);   //Note D, channel 3
						setreg_2151(0xA2, 0xFE);
						break;
								
			case 10:  	setreg_2151(0xA4, 0x34);   //Note D, channel 1
						setreg_2151(0xA0, 0x3B);
						setreg_2151(0xA5, 0x34);   //Note D, channel 2
						setreg_2151(0xA1, 0x3B);
						setreg_2151(0xA6, 0x34);   //Note D, channel 3
						setreg_2151(0xA2, 0x3B);
						break;
									
			case 11:  	setreg_2151(0xA4, 0x34);   //Note D, channel 1
						setreg_2151(0xA0, 0x7B);
						setreg_2151(0xA5, 0x34);   //Note D, channel 2
						setreg_2151(0xA1, 0x7B);
						setreg_2151(0xA6, 0x34);   //Note D, channel 3
						setreg_2151(0xA2, 0x7B);
						break;
									
			case 12:  	setreg_2151(0xA4, 0x34);   //Note D, channel 1
						setreg_2151(0xA0, 0xBF);
						setreg_2151(0xA5, 0x34);   //Note D, channel 2
						setreg_2151(0xA1, 0xBF);
						setreg_2151(0xA6, 0x34);   //Note D, channel 3
						setreg_2151(0xA2, 0xBF);
						break;
					
			default: printf("Invalid octave!\n");
						break;
		}
	}
	
	if(octave == 7){
		switch (note){
			case 1:  	setreg_2151(0xA4, 0x3A);   //Note C, channel 1
						setreg_2151(0xA0, 0x84);
						setreg_2151(0xA5, 0x3A);   //Note C, channel 2
						setreg_2151(0xA1, 0x84);
						setreg_2151(0xA6, 0x3A);   //Note C, channel 3
						setreg_2151(0xA2, 0x84);
						break;
					
			default: printf("Invalid octave!\n");
						break;
		}
	}
	
}
