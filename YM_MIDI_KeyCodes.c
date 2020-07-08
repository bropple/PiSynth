
#include "YM_MIDI_KeyCodes.h"


int YM_MIDI_NotePicker(char key, int channel){
	
	/* Channel Handling
	 * 
	 * Channels are handled by the int 'channel'. The channel number ranges from zero to the maximum
	 * number of channels that can be used, depending on the number of YM3438 chips in the configuration.
	 * 
	 * This code ony sets the note for the channel number passed to it. The handling is done
	 * in an external function, which will be in charge of activating this function and sending the
	 * "note on" command.
	 * 
	 * The minimum note is C0#, while the maximum note is B7.\
	 * -> Cannot handle MIDI note codes below 13 and above 107!
	 * 
	 * Will hopefully make this more elegant than just a predefined list at some point.
	 * 
	 */
	
	//int isA1 = sent
	
	if((channel == 0 )||(channel == 3)){ //Channel 0 and Channel 3 are the same, but A1 enabled and with a slight value shift

		//[EVERY POSSIBLE NOTE FOR CHANNELS 0 AND 3]//
		
		//There is no C0!
		if(key == 13)       C0shp_ch03(channel);
		else if(key == 14)  D0_ch03(channel);
		else if(key == 15)  D0shp_ch03(channel);
		else if(key == 16)  E0_ch03(channel);
		else if(key == 17)  F0_ch03(channel);
		else if(key == 18)  F0shp_ch03(channel);
		else if(key == 19)  G0_ch03(channel);
		else if(key == 20)  G0shp_ch03(channel);
		else if(key == 21)  A0_ch03(channel);
		else if(key == 22)  A0shp_ch03(channel);
		else if(key == 23)  B0_ch03(channel);
		else if(key == 24)  C1_ch03(channel);
		else if(key == 25)  C1shp_ch03(channel);
		else if(key == 26)  D1_ch03(channel);
		else if(key == 27)  D1shp_ch03(channel);
		else if(key == 28)  E1_ch03(channel);
		else if(key == 29)  F1_ch03(channel);
		else if(key == 30)  F1shp_ch03(channel);
		else if(key == 31)  G1_ch03(channel);
		else if(key == 32)  G1shp_ch03(channel);
		else if(key == 33)  A1_ch03(channel);
		else if(key == 34)  A1shp_ch03(channel);
		else if(key == 35)  B1_ch03(channel);
		else if(key == 36)  C2_ch03(channel);
		else if(key == 37)  C2shp_ch03(channel);
		else if(key == 38)  D2_ch03(channel);
		else if(key == 39)  D2shp_ch03(channel);
		else if(key == 40)  E2_ch03(channel);
		else if(key == 41)  F2_ch03(channel);
		else if(key == 42)  F2shp_ch03(channel);
		else if(key == 43)  G2_ch03(channel);
		else if(key == 44)  G2shp_ch03(channel);
		else if(key == 45)  A2_ch03(channel);
		else if(key == 46)  A2shp_ch03(channel);
		else if(key == 47)  B2_ch03(channel);
		else if(key == 48)  C3_ch03(channel);
		else if(key == 49)  C3shp_ch03(channel);
		else if(key == 50)  D3_ch03(channel);
		else if(key == 51)  D3shp_ch03(channel);
		else if(key == 52)  E3_ch03(channel);
		else if(key == 53)  F3_ch03(channel);
		else if(key == 54)  F3shp_ch03(channel);
		else if(key == 55)  G3_ch03(channel);
		else if(key == 56)  G3shp_ch03(channel);
		else if(key == 57)  A3_ch03(channel);
		else if(key == 58)  A3shp_ch03(channel);
		else if(key == 59)  B3_ch03(channel);
		else if(key == 60)  C4_ch03(channel);
		else if(key == 61)  C4shp_ch03(channel);
		else if(key == 62)  D4_ch03(channel);
		else if(key == 63)  D4shp_ch03(channel);
		else if(key == 64)  E4_ch03(channel);
		else if(key == 65)  F4_ch03(channel);
		else if(key == 66)  F4shp_ch03(channel);
		else if(key == 67)  G4_ch03(channel);
		else if(key == 68)  G4shp_ch03(channel);
		else if(key == 69)  A4_ch03(channel);
		else if(key == 70)  A4shp_ch03(channel);
		else if(key == 71)  B4_ch03(channel);
		else if(key == 72)  C5_ch03(channel);
		else if(key == 73)  C5shp_ch03(channel);
		else if(key == 74)  D5_ch03(channel);
		else if(key == 75)  D5shp_ch03(channel);
		else if(key == 76)  E5_ch03(channel);
		else if(key == 77)  F5_ch03(channel);
		else if(key == 78)  F5shp_ch03(channel);
		else if(key == 79)  G5_ch03(channel);
		else if(key == 80)  G5shp_ch03(channel);
		else if(key == 81)  A5_ch03(channel);
		else if(key == 82)  A5shp_ch03(channel);
		else if(key == 83)  B5_ch03(channel);
		else if(key == 84)  C6_ch03(channel);
		else if(key == 85)  C6shp_ch03(channel);
		else if(key == 86)  D6_ch03(channel);
		else if(key == 87)  D6shp_ch03(channel);
		else if(key == 88)  E6_ch03(channel);
		else if(key == 89)  F6_ch03(channel);
		else if(key == 90)  F6shp_ch03(channel);
		else if(key == 91)  G6_ch03(channel);
		else if(key == 92)  G6shp_ch03(channel);
		else if(key == 93)  A6_ch03(channel);
		else if(key == 94)  A6shp_ch03(channel);
		else if(key == 95)  B6_ch03(channel);
		else if(key == 96)  C7_ch03(channel);
		else if(key == 97)  C7shp_ch03(channel);
		else if(key == 98)  D7_ch03(channel);
		else if(key == 99)  D7shp_ch03(channel);
		else if(key == 100) E7_ch03(channel);
		else if(key == 101) F7_ch03(channel);
		else if(key == 102) F7shp_ch03(channel);
		else if(key == 103) G7_ch03(channel);
		else if(key == 104) G7shp_ch03(channel);
		else if(key == 105) A7_ch03(channel);
		else if(key == 106) A7shp_ch03(channel);
		else if(key == 107) B7_ch03(channel);
		else{
				printf("Invalid or out of range key: %d, %c, 0x%x\n", key, key, key);
				return -1;
			}
		return 0;
	}
	
	if((channel == 1 )||(channel == 4)){ //Channel 1 and Channel 4 are the same, but A1 enabled and with a slight value shift
		
		//[EVERY POSSIBLE NOTE FOR CHANNELS 1 AND 4]//
		
		if(key == 13)       C0shp_ch14(channel);
		else if(key == 14)  D0_ch14(channel);
		else if(key == 15)  D0shp_ch14(channel);
		else if(key == 16)  E0_ch14(channel);
		else if(key == 17)  F0_ch14(channel);
		else if(key == 18)  F0shp_ch14(channel);
		else if(key == 19)  G0_ch14(channel);
		else if(key == 20)  G0shp_ch14(channel);
		else if(key == 21)  A0_ch14(channel);
		else if(key == 22)  A0shp_ch14(channel);
		else if(key == 23)  B0_ch14(channel);
		else if(key == 24)  C1_ch14(channel);
		else if(key == 25)  C1shp_ch14(channel);
		else if(key == 26)  D1_ch14(channel);
		else if(key == 27)  D1shp_ch14(channel);
		else if(key == 28)  E1_ch14(channel);
		else if(key == 29)  F1_ch14(channel);
		else if(key == 30)  F1shp_ch14(channel);
		else if(key == 31)  G1_ch14(channel);
		else if(key == 32)  G1shp_ch14(channel);
		else if(key == 33)  A1_ch14(channel);
		else if(key == 34)  A1shp_ch14(channel);
		else if(key == 35)  B1_ch14(channel);
		else if(key == 36)  C2_ch14(channel);
		else if(key == 37)  C2shp_ch14(channel);
		else if(key == 38)  D2_ch14(channel);
		else if(key == 39)  D2shp_ch14(channel);
		else if(key == 40)  E2_ch14(channel);
		else if(key == 41)  F2_ch14(channel);
		else if(key == 42)  F2shp_ch14(channel);
		else if(key == 43)  G2_ch14(channel);
		else if(key == 44)  G2shp_ch14(channel);
		else if(key == 45)  A2_ch14(channel);
		else if(key == 46)  A2shp_ch14(channel);
		else if(key == 47)  B2_ch14(channel);
		else if(key == 48)  C3_ch14(channel);
		else if(key == 49)  C3shp_ch14(channel);
		else if(key == 50)  D3_ch14(channel);
		else if(key == 51)  D3shp_ch14(channel);
		else if(key == 52)  E3_ch14(channel);
		else if(key == 53)  F3_ch14(channel);
		else if(key == 54)  F3shp_ch14(channel);
		else if(key == 55)  G3_ch14(channel);
		else if(key == 56)  G3shp_ch14(channel);
		else if(key == 57)  A3_ch14(channel);
		else if(key == 58)  A3shp_ch14(channel);
		else if(key == 59)  B3_ch14(channel);
		else if(key == 60)  C4_ch14(channel);
		else if(key == 61)  C4shp_ch14(channel);
		else if(key == 62)  D4_ch14(channel);
		else if(key == 63)  D4shp_ch14(channel);
		else if(key == 64)  E4_ch14(channel);
		else if(key == 65)  F4_ch14(channel);
		else if(key == 66)  F4shp_ch14(channel);
		else if(key == 67)  G4_ch14(channel);
		else if(key == 68)  G4shp_ch14(channel);
		else if(key == 69)  A4_ch14(channel);
		else if(key == 70)  A4shp_ch14(channel);
		else if(key == 71)  B4_ch14(channel);
		else if(key == 72)  C5_ch14(channel);
		else if(key == 73)  C5shp_ch14(channel);
		else if(key == 74)  D5_ch14(channel);
		else if(key == 75)  D5shp_ch14(channel);
		else if(key == 76)  E5_ch14(channel);
		else if(key == 77)  F5_ch14(channel);
		else if(key == 78)  F5shp_ch14(channel);
		else if(key == 79)  G5_ch14(channel);
		else if(key == 80)  G5shp_ch14(channel);
		else if(key == 81)  A5_ch14(channel);
		else if(key == 82)  A5shp_ch14(channel);
		else if(key == 83)  B5_ch14(channel);
		else if(key == 84)  C6_ch14(channel);
		else if(key == 85)  C6shp_ch14(channel);
		else if(key == 86)  D6_ch14(channel);
		else if(key == 87)  D6shp_ch14(channel);
		else if(key == 88)  E6_ch14(channel);
		else if(key == 89)  F6_ch14(channel);
		else if(key == 90)  F6shp_ch14(channel);
		else if(key == 91)  G6_ch14(channel);
		else if(key == 92)  G6shp_ch14(channel);
		else if(key == 93)  A6_ch14(channel);
		else if(key == 94)  A6shp_ch14(channel);
		else if(key == 95)  B6_ch14(channel);
		else if(key == 96)  C7_ch14(channel);
		else if(key == 97)  C7shp_ch14(channel);
		else if(key == 98)  D7_ch14(channel);
		else if(key == 99)  D7shp_ch14(channel);
		else if(key == 100) E7_ch14(channel);
		else if(key == 101) F7_ch14(channel);
		else if(key == 102) F7shp_ch14(channel);
		else if(key == 103) G7_ch14(channel);
		else if(key == 104) G7shp_ch14(channel);
		else if(key == 105) A7_ch14(channel);
		else if(key == 106) A7shp_ch14(channel);
		else if(key == 107) B7_ch14(channel);
		else{
				printf("Invalid or out of range key: %d, %c, 0x%x\n", key, key, key);
				return -1;
			}
		return 0;
	}
	
	if((channel == 2 )||(channel == 5)){ //Channel 2 and Channel 5 are the same, but A1 enabled and with a slight value shift
		//switch(key){
			
			////[EVERY POSSIBLE NOTE FOR CHANNELS 2 AND 5]//
			
		if(key == 13)       C0shp_ch25(channel);
		else if(key == 14)  D0_ch25(channel);
		else if(key == 15)  D0shp_ch25(channel);
		else if(key == 16)  E0_ch25(channel);
		else if(key == 17)  F0_ch25(channel);
		else if(key == 18)  F0shp_ch25(channel);
		else if(key == 19)  G0_ch25(channel);
		else if(key == 20)  G0shp_ch25(channel);
		else if(key == 21)  A0_ch25(channel);
		else if(key == 22)  A0shp_ch25(channel);
		else if(key == 23)  B0_ch25(channel);
		else if(key == 24)  C1_ch25(channel);
		else if(key == 25)  C1shp_ch25(channel);
		else if(key == 26)  D1_ch25(channel);
		else if(key == 27)  D1shp_ch25(channel);
		else if(key == 28)  E1_ch25(channel);
		else if(key == 29)  F1_ch25(channel);
		else if(key == 30)  F1shp_ch25(channel);
		else if(key == 31)  G1_ch25(channel);
		else if(key == 32)  G1shp_ch25(channel);
		else if(key == 33)  A1_ch25(channel);
		else if(key == 34)  A1shp_ch25(channel);
		else if(key == 35)  B1_ch25(channel);
		else if(key == 36)  C2_ch25(channel);
		else if(key == 37)  C2shp_ch25(channel);
		else if(key == 38)  D2_ch25(channel);
		else if(key == 39)  D2shp_ch25(channel);
		else if(key == 40)  E2_ch25(channel);
		else if(key == 41)  F2_ch25(channel);
		else if(key == 42)  F2shp_ch25(channel);
		else if(key == 43)  G2_ch25(channel);
		else if(key == 44)  G2shp_ch25(channel);
		else if(key == 45)  A2_ch25(channel);
		else if(key == 46)  A2shp_ch25(channel);
		else if(key == 47)  B2_ch25(channel);
		else if(key == 48)  C3_ch25(channel);
		else if(key == 49)  C3shp_ch25(channel);
		else if(key == 50)  D3_ch25(channel);
		else if(key == 51)  D3shp_ch25(channel);
		else if(key == 52)  E3_ch25(channel);
		else if(key == 53)  F3_ch25(channel);
		else if(key == 54)  F3shp_ch25(channel);
		else if(key == 55)  G3_ch25(channel);
		else if(key == 56)  G3shp_ch25(channel);
		else if(key == 57)  A3_ch25(channel);
		else if(key == 58)  A3shp_ch25(channel);
		else if(key == 59)  B3_ch25(channel);
		else if(key == 60)  C4_ch25(channel);
		else if(key == 61)  C4shp_ch25(channel);
		else if(key == 62)  D4_ch25(channel);
		else if(key == 63)  D4shp_ch25(channel);
		else if(key == 64)  E4_ch25(channel);
		else if(key == 65)  F4_ch25(channel);
		else if(key == 66)  F4shp_ch25(channel);
		else if(key == 67)  G4_ch25(channel);
		else if(key == 68)  G4shp_ch25(channel);
		else if(key == 69)  A4_ch25(channel);
		else if(key == 70)  A4shp_ch25(channel);
		else if(key == 71)  B4_ch25(channel);
		else if(key == 72)  C5_ch25(channel);
		else if(key == 73)  C5shp_ch25(channel);
		else if(key == 74)  D5_ch25(channel);
		else if(key == 75)  D5shp_ch25(channel);
		else if(key == 76)  E5_ch25(channel);
		else if(key == 77)  F5_ch25(channel);
		else if(key == 78)  F5shp_ch25(channel);
		else if(key == 79)  G5_ch25(channel);
		else if(key == 80)  G5shp_ch25(channel);
		else if(key == 81)  A5_ch25(channel);
		else if(key == 82)  A5shp_ch25(channel);
		else if(key == 83)  B5_ch25(channel);
		else if(key == 84)  C6_ch25(channel);
		else if(key == 85)  C6shp_ch25(channel);
		else if(key == 86)  D6_ch25(channel);
		else if(key == 87)  D6shp_ch25(channel);
		else if(key == 88)  E6_ch25(channel);
		else if(key == 89)  F6_ch25(channel);
		else if(key == 90)  F6shp_ch25(channel);
		else if(key == 91)  G6_ch25(channel);
		else if(key == 92)  G6shp_ch25(channel);
		else if(key == 93)  A6_ch25(channel);
		else if(key == 94)  A6shp_ch25(channel);
		else if(key == 95)  B6_ch25(channel);
		else if(key == 96)  C7_ch25(channel);
		else if(key == 97)  C7shp_ch25(channel);
		else if(key == 98)  D7_ch25(channel);
		else if(key == 99)  D7shp_ch25(channel);
		else if(key == 100) E7_ch25(channel);
		else if(key == 101) F7_ch25(channel);
		else if(key == 102) F7shp_ch25(channel);
		else if(key == 103) G7_ch25(channel);
		else if(key == 104) G7shp_ch25(channel);
		else if(key == 105) A7_ch25(channel);
		else if(key == 106) A7shp_ch25(channel);
		else if(key == 107) B7_ch25(channel);
		else{
				printf("Invalid or out of range key: %d, %c, 0x%x\n", key, key, key);
				return -1;
			}
		return 0;
	}
	
}
