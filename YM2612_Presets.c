//Benjamin Ropple
//YM2612_Presets.c
//Contains a number of presets that can be used for the YM2612. Basically VGM data that can be
//invoked at any time to change the instruments.

#include "YM2612.h"
#include "YM2612_Presets.h"


void YM2612_Grand_Piano(void){  //from datasheet, a grand piano with three voices at once
  setreg(0x22, 0x00, 0); // LFO off
  setreg(0x27, 0x00, 0); // Note off (channel 0)
  setreg(0x28, 0x00, 0); // Note off (channel 1)
  setreg(0x28, 0x01, 0); // Note off (channel 1)
  setreg(0x28, 0x02, 0); // Note off (channel 2)
  setreg(0x28, 0x03, 0); // Note off (channel 1)
  setreg(0x28, 0x04, 0); // Note off (channel 3)
  setreg(0x28, 0x05, 0); // Note off (channel 4)
  setreg(0x28, 0x06, 0); // Note off (channel 5)
  setreg(0x2B, 0x00, 0); // DAC off
  setreg(0x30, 0x71, 0); //
  setreg(0x34, 0x0d, 0); //
  setreg(0x38, 0x33, 0); //
  setreg(0x3C, 0x01, 0); // DT1/MUL
  setreg(0x40, 0x23, 0); //
  setreg(0x44, 0x2D, 0); //
  setreg(0x48, 0x26, 0); //
  setreg(0x4C, 0x00, 0); // Total level
  setreg(0x50, 0x5F, 0); //
  setreg(0x54, 0x99, 0); //
  setreg(0x58, 0x5F, 0); //
  setreg(0x5C, 0x94, 0); // RS/AR 
  setreg(0x60, 0x05, 0); //
  setreg(0x64, 0x05, 0); //
  setreg(0x68, 0x05, 0); //
  setreg(0x6C, 0x02, 0); // AM/D1R
  setreg(0x70, 0x02, 0); //
  setreg(0x74, 0x02, 0); //
  setreg(0x78, 0x02, 0); //
  setreg(0x7C, 0x02, 0); // D2R
  setreg(0x80, 0x11, 0); //
  setreg(0x84, 0x11, 0); //
  setreg(0x88, 0x11, 0); //
  setreg(0x8C, 0xb3, 0); // D1L/RR
  setreg(0x31, 0x71, 0); //
  setreg(0x35, 0x0d, 0); //
  setreg(0x39, 0x33, 0); //
  setreg(0x3d, 0x01, 0); // DT1/MUL
  setreg(0x41, 0x23, 0); //
  setreg(0x45, 0x2D, 0); //
  setreg(0x49, 0x26, 0); //
  setreg(0x4d, 0x00, 0); // Total level
  setreg(0x51, 0x5F, 0); //
  setreg(0x55, 0x99, 0); //
  setreg(0x59, 0x5F, 0); //
  setreg(0x5d, 0x94, 0); // RS/AR 
  setreg(0x61, 0x05, 0); //
  setreg(0x65, 0x05, 0); //
  setreg(0x69, 0x05, 0); //
  setreg(0x6d, 0x02, 0); // AM/D1R
  setreg(0x71, 0x02, 0); //
  setreg(0x75, 0x02, 0); //
  setreg(0x79, 0x02, 0); //
  setreg(0x7d, 0x02, 0); // D2R
  setreg(0x81, 0x11, 0); //
  setreg(0x85, 0x11, 0); //
  setreg(0x89, 0x31, 0); //
  setreg(0x8d, 0xb3, 0); // D1L/RR
  setreg(0x32, 0x71, 0); //
  setreg(0x36, 0x0D, 0); //
  setreg(0x3a, 0x33, 0); //
  setreg(0x3e, 0x01, 0); // DT1/MUL
  setreg(0x42, 0x23, 0); //
  setreg(0x46, 0x2D, 0); //
  setreg(0x4a, 0x26, 0); //
  setreg(0x4e, 0x0f, 0); // Total level
  setreg(0x52, 0x5F, 0); //
  setreg(0x56, 0x99, 0); //
  setreg(0x5a, 0x5F, 0); //
  setreg(0x5e, 0x94, 0); // RS/AR 
  setreg(0x62, 0x05, 0); //
  setreg(0x66, 0x05, 0); //
  setreg(0x6a, 0x05, 0); //
  setreg(0x6e, 0x02, 0); // AM/D1R
  setreg(0x72, 0x02, 0); //
  setreg(0x76, 0x02, 0); //
  setreg(0x7a, 0x02, 0); //
  setreg(0x7e, 0x02, 0); // D2R
  setreg(0x82, 0x11, 0); //
  setreg(0x86, 0x11, 0); //
  setreg(0x8a, 0x31, 0); //
  setreg(0x8e, 0xb4, 0); // D1L/RR
  setreg(0x90, 0x00, 0); //
  setreg(0x94, 0x00, 0); //
  setreg(0x98, 0x00, 0); //
  setreg(0x9C, 0x00, 0); // Proprietary
  setreg(0xB0, 0x03, 0); // Feedback/algorithm
  setreg(0xB1, 0x03, 0); // Feedback/algorithm
  setreg(0xB2, 0x03, 0); // Feedback/algorithm
  setreg(0xB4, 0x93, 0); // Both speakers on
  setreg(0xB5, 0x43, 0); // Both speakers on
  setreg(0xB6, 0xC4, 0); // Both speakers on
  setreg(0xA4, 0x22, 0); // 
  setreg(0xA0, 0x69, 0); // Set frequency ch 1
  setreg(0xA5, 0x22, 0); // 
  setreg(0xA1, 0xdd, 0); // Set frequency ch 2
  setreg(0xA6, 0x23, 0); // 
  setreg(0xA2, 0x9c, 0); // Set frequency ch 3
  
  setreg(0x30, 0x71, 3); //
  setreg(0x34, 0x0d, 3); //
  setreg(0x38, 0x33, 3); //
  setreg(0x3C, 0x01, 3); // DT1/MUL
  setreg(0x40, 0x23, 3); //
  setreg(0x44, 0x2D, 3); //
  setreg(0x48, 0x26, 3); //
  setreg(0x4C, 0x00, 3); // Total level
  setreg(0x50, 0x5F, 3); //
  setreg(0x54, 0x99, 3); //
  setreg(0x58, 0x5F, 3); //
  setreg(0x5C, 0x94, 3); // RS/AR 
  setreg(0x60, 0x05, 3); //
  setreg(0x64, 0x05, 3); //
  setreg(0x68, 0x05, 3); //
  setreg(0x6C, 0x02, 3); // AM/D1R
  setreg(0x70, 0x02, 3); //
  setreg(0x74, 0x02, 3); //
  setreg(0x78, 0x02, 3); //
  setreg(0x7C, 0x02, 3); // D2R
  setreg(0x80, 0x11, 3); //
  setreg(0x84, 0x11, 3); //
  setreg(0x88, 0x11, 3); //
  setreg(0x8C, 0xb3, 3); // D1L/RR
  setreg(0x31, 0x71, 4); //
  setreg(0x35, 0x0d, 4); //
  setreg(0x39, 0x33, 4); //
  setreg(0x3d, 0x01, 4); // DT1/MUL
  setreg(0x41, 0x23, 4); //
  setreg(0x45, 0x2D, 4); //
  setreg(0x49, 0x26, 4); //
  setreg(0x4d, 0x00, 4); // Total level
  setreg(0x51, 0x5F, 4); //
  setreg(0x55, 0x99, 4); //
  setreg(0x59, 0x5F, 4); //
  setreg(0x5d, 0x94, 4); // RS/AR 
  setreg(0x61, 0x05, 4); //
  setreg(0x65, 0x05, 4); //
  setreg(0x69, 0x05, 4); //
  setreg(0x6d, 0x02, 4); // AM/D1R
  setreg(0x71, 0x02, 4); //
  setreg(0x75, 0x02, 4); //
  setreg(0x79, 0x02, 4); //
  setreg(0x7d, 0x02, 4); // D2R
  setreg(0x81, 0x11, 4); //
  setreg(0x85, 0x11, 4); //
  setreg(0x89, 0x31, 4); //
  setreg(0x8d, 0xb3, 4); // D1L/RR
  setreg(0x32, 0x71, 5); //
  setreg(0x36, 0x0D, 5); //
  setreg(0x3a, 0x33, 5); //
  setreg(0x3e, 0x01, 5); // DT1/MUL
  setreg(0x42, 0x23, 5); //
  setreg(0x46, 0x2D, 5); //
  setreg(0x4a, 0x26, 5); //
  setreg(0x4e, 0x0f, 5); // Total level
  setreg(0x52, 0x5F, 5); //
  setreg(0x56, 0x99, 5); //
  setreg(0x5a, 0x5F, 5); //
  setreg(0x5e, 0x94, 5); // RS/AR 
  setreg(0x62, 0x05, 5); //
  setreg(0x66, 0x05, 5); //
  setreg(0x6a, 0x05, 5); //
  setreg(0x6e, 0x02, 5); // AM/D1R
  setreg(0x72, 0x02, 5); //
  setreg(0x76, 0x02, 5); //
  setreg(0x7a, 0x02, 5); //
  setreg(0x7e, 0x02, 5); // D2R
  setreg(0x82, 0x11, 5); //
  setreg(0x86, 0x11, 5); //
  setreg(0x8a, 0x31, 5); //
  setreg(0x8e, 0xb4, 5); // D1L/RR
  setreg(0x90, 0x00, 5); //
  setreg(0x94, 0x00, 5); //
  setreg(0x98, 0x00, 5); //
  setreg(0x9C, 0x00, 5); // Proprietary
  setreg(0xB0, 0x03, 3); // Feedback/algorithm
  setreg(0xB1, 0x03, 4); // Feedback/algorithm
  setreg(0xB2, 0x03, 5); // Feedback/algorithm
  setreg(0xB4, 0x93, 3); // Both speakers on
  setreg(0xB5, 0x43, 4); // Both speakers on
  setreg(0xB6, 0xC4, 5); // Both speakers on
  setreg(0xA4, 0x22, 5); // 
  setreg(0xA0, 0x69, 3); // Set frequency ch 1
  setreg(0xA5, 0x22, 3); // 
  setreg(0xA1, 0xdd, 4); // Set frequency ch 2
  setreg(0xA6, 0x23, 4); // 
  setreg(0xA2, 0x9c, 5); // Set frequency ch 3
  setreg(0xA7, 0x24, 5); // 
  
  
  
  printf("\n\nGrand Piano voice programmed!\n\n");
  
}

void YM2612_Guitar(void) { //created using Deflemask Tracker
	setreg(0x22, 0x08, 0);    //YM2612:		Low Frequency Oscillator: 3.98 Hz
	setreg(0x27, 0x00, 0);    //YM2612:		CSM Mode: Disable, 3 Slot Mode: Disable, Timer B Disable, Timer A Disable, Stop Timer B, Stop Timer A
	setreg(0xB4, 0xC0, 0);    //YM2612:		Ch 0 PMS: 0x0, AMS: 0x0, Stereo: LR
	setreg(0xB5, 0xC0, 0);    //YM2612:		Ch 1 PMS: 0x0, AMS: 0x0, Stereo: LR
	setreg(0xB6, 0xC0, 0);    //YM2612:		Ch 2 PMS: 0x0, AMS: 0x0, Stereo: LR
	setreg(0xB4, 0xC0, 0);    //YM2612:		Ch 3 PMS: 0x0, AMS: 0x0, Stereo: LR
	setreg(0xB5, 0xC0, 0);    //YM2612:		Ch 4 PMS: 0x0, AMS: 0x0, Stereo: LR
	setreg(0xB6, 0xC0, 0);    //YM2612:		Ch 5 PMS: 0x0, AMS: 0x0, Stereo: LR
	setreg(0x28, 0x00, 0);    //YM2612:		Channel 0 Key On/Off: Slot1 Off, Slot2 Off, Slot3 Off, Slot4 Off
	setreg(0x28, 0x01, 0);    //YM2612:		Channel 1 Key On/Off: Slot1 Off, Slot2 Off, Slot3 Off, Slot4 Off
	setreg(0x28, 0x02, 0);    //YM2612:		Channel 2 Key On/Off: Slot1 Off, Slot2 Off, Slot3 Off, Slot4 Off
	setreg(0x28, 0x03, 0);    //YM2612:		Key On/Off: Invalid Channel
	setreg(0x28, 0x04, 0);    //YM2612:		Channel 3 Key On/Off: Slot1 Off, Slot2 Off, Slot3 Off, Slot4 Off
	setreg(0x28, 0x05, 0);    //YM2612:		Channel 4 Key On/Off: Slot1 Off, Slot2 Off, Slot3 Off, Slot4 Off
	setreg(0x28, 0x06, 0);    //YM2612:		Channel 5 Key On/Off: Slot1 Off, Slot2 Off, Slot3 Off, Slot4 Off
	setreg(0x30, 0x16, 0);    //YM2612:		Ch 0 Slot 0 Detune: 1, Multiple: Freq * 0
	setreg(0x40, 0x1E, 0);    //YM2612:		Ch 0 Slot 0 Total Level: 0x1E = 93%
	setreg(0x50, 0x1F, 0);    //YM2612:		Ch 0 Slot 0 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x60, 0x07, 0);    //YM2612:		Ch 0 Slot 0 Amplitude Modulation: Disable, Decay Rate: 07
	setreg(0x70, 0x00, 0);    //YM2612:		Ch 0 Slot 0 Sustain Rate: 00
	setreg(0x80, 0x53, 0);    //YM2612:		Ch 0 Slot 0 Sustain Level: 5, Release Rate: 3
	setreg(0x90, 0x00, 0);    //YM2612:		Ch 0 Slot 0 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x34, 0x00, 0);    //YM2612:		Ch 0 Slot 1 Detune: 0, Multiple: Freq * 0
	setreg(0x44, 0x16, 0);    //YM2612:		Ch 0 Slot 1 Total Level: 0x16 = 96%
	setreg(0x54, 0x1F, 0);   //YM2612:		Ch 0 Slot 1 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x64, 0x03, 0);    //YM2612:		Ch 0 Slot 1 Amplitude Modulation: Disable, Decay Rate: 03
	setreg(0x74, 0x00, 0);    //YM2612:		Ch 0 Slot 1 Sustain Rate: 00
	setreg(0x84, 0x71, 0);    //YM2612:		Ch 0 Slot 1 Sustain Level: 7, Release Rate: 1
	setreg(0x94, 0x00, 0);    //YM2612:		Ch 0 Slot 1 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x38, 0x54, 0);    //YM2612:		Ch 0 Slot 2 Detune: 1, Multiple: Freq * 0
	setreg(0x48, 0x21, 0);    //YM2612:		Ch 0 Slot 2 Total Level: 0x21 = 92%
	setreg(0x58, 0x1F, 0);    //YM2612:		Ch 0 Slot 2 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x68, 0x03, 0);    //YM2612:		Ch 0 Slot 2 Amplitude Modulation: Disable, Decay Rate: 03
	setreg(0x78, 0x00, 0);    //YM2612:		Ch 0 Slot 2 Sustain Rate: 00
	setreg(0x88, 0x33, 0);    //YM2612:		Ch 0 Slot 2 Sustain Level: 3, Release Rate: 3
	setreg(0x98, 0x00, 0);    //YM2612:		Ch 0 Slot 2 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x3C, 0x00, 0);    //YM2612:		Ch 0 Slot 3 Detune: 0, Multiple: Freq * 0
	setreg(0x4C, 0x00, 0);    //YM2612:		Ch 0 Slot 3 Total Level: 0x00 = 100%
	setreg(0x5C, 0x1F, 0);    //YM2612:		Ch 0 Slot 3 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x6C, 0x00, 0);    //YM2612:		Ch 0 Slot 3 Amplitude Modulation: Disable, Decay Rate: 00
	setreg(0x7C, 0x07, 0);    //YM2612:		Ch 0 Slot 3 Sustain Rate: 07
	setreg(0x8C, 0x06, 0);    //YM2612:		Ch 0 Slot 3 Sustain Level: 0, Release Rate: 6
	setreg(0x9C, 0x00, 0);    //YM2612:		Ch 0 Slot 3 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0xB0, 0x31, 0);    //YM2612:		Ch 0 Feedback: 12, Algorithm: 1
	setreg(0x31, 0x16, 0);    //YM2612:		Ch 1 Slot 0 Detune: 1, Multiple: Freq * 0
	setreg(0x41, 0x1E, 0);    //YM2612:		Ch 1 Slot 0 Total Level: 0x1E = 93%
	setreg(0x51, 0x1F, 0);    //YM2612:		Ch 1 Slot 0 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x61, 0x07, 0);    //YM2612:		Ch 1 Slot 0 Amplitude Modulation: Disable, Decay Rate: 07
	setreg(0x71, 0x00, 0);    //YM2612:		Ch 1 Slot 0 Sustain Rate: 00
	setreg(0x81, 0x53, 0);    //YM2612:		Ch 1 Slot 0 Sustain Level: 5, Release Rate: 3
	setreg(0x91, 0x00, 0);    //YM2612:		Ch 1 Slot 0 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x35, 0x00, 0);    //YM2612:		Ch 1 Slot 1 Detune: 0, Multiple: Freq * 0
	setreg(0x45, 0x16, 0);    //YM2612:		Ch 1 Slot 1 Total Level: 0x16 = 96%
	setreg(0x55, 0x1F, 0);    //YM2612:		Ch 1 Slot 1 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x65, 0x03, 0);    //YM2612:		Ch 1 Slot 1 Amplitude Modulation: Disable, Decay Rate: 03
	setreg(0x75, 0x00, 0);    //YM2612:		Ch 1 Slot 1 Sustain Rate: 00
	setreg(0x85, 0x71, 0);    //YM2612:		Ch 1 Slot 1 Sustain Level: 7, Release Rate: 1
	setreg(0x95, 0x00, 0);    //YM2612:		Ch 1 Slot 1 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x39, 0x54, 0);    //YM2612:		Ch 1 Slot 2 Detune: 1, Multiple: Freq * 0
	setreg(0x49, 0x21, 0);    //YM2612:		Ch 1 Slot 2 Total Level: 0x21 = 92%
	setreg(0x59, 0x1F, 0);    //YM2612:		Ch 1 Slot 2 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x69, 0x03, 0);    //YM2612:		Ch 1 Slot 2 Amplitude Modulation: Disable, Decay Rate: 03
	setreg(0x79, 0x00, 0);    //YM2612:		Ch 1 Slot 2 Sustain Rate: 00
	setreg(0x89, 0x33, 0);    //YM2612:		Ch 1 Slot 2 Sustain Level: 3, Release Rate: 3
	setreg(0x99, 0x00, 0);    //YM2612:		Ch 1 Slot 2 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x3D, 0x00, 0);    //YM2612:		Ch 1 Slot 3 Detune: 0, Multiple: Freq * 0
	setreg(0x4D, 0x00, 0);    //YM2612:		Ch 1 Slot 3 Total Level: 0x00 = 100%
	setreg(0x5D, 0x1F, 0);    //YM2612:		Ch 1 Slot 3 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x6D, 0x00, 0);    //YM2612:		Ch 1 Slot 3 Amplitude Modulation: Disable, Decay Rate: 00
	setreg(0x7D, 0x07, 0);    //YM2612:		Ch 1 Slot 3 Sustain Rate: 07
	setreg(0x8D, 0x06, 0);    //YM2612:		Ch 1 Slot 3 Sustain Level: 0, Release Rate: 6
	setreg(0x9D, 0x00, 0);    //YM2612:		Ch 1 Slot 3 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0xB1, 0x31, 0);    //YM2612:		Ch 1 Feedback: 12, Algorithm: 1
	
	printf("\n\nGuitar voice programmed!\n\n");
	
}

void YM2612_Trumpet(void) {
	setreg(0x22, 0x08, 0);
	setreg(0x27, 0x00, 0);  
	setreg(0xB4, 0xC0, 0);  
	setreg(0xB5, 0xC0, 0);  
	setreg(0xB6, 0xC0, 0);  
	setreg(0xB4, 0xC0, 0);   
	setreg(0xB5, 0xC0, 0);  
	setreg(0xB6, 0xC0, 0);   
	setreg(0x28, 0x00, 0);  
	setreg(0x28, 0x01, 0);   
	setreg(0x28, 0x02, 0);  
	setreg(0x28, 0x03, 0);  
	setreg(0x28, 0x04, 0);  
	setreg(0x28, 0x05, 0);   
	setreg(0x28, 0x06, 0);  
	setreg(0x30, 0x01, 0);   
	setreg(0x40, 0x17, 0);   
	setreg(0x50, 0x11, 0);   
	setreg(0x60, 0x0D, 0);  
	setreg(0x70, 0x03, 0);   
	setreg(0x80, 0x17, 0);   
	setreg(0x90, 0x00, 0);    
	setreg(0x34, 0x02, 0);   
	setreg(0x44, 0x0C, 0);   
	setreg(0x54, 0x14, 0);   
	setreg(0x64, 0x07, 0); 
	setreg(0x74, 0x00, 0);  
	setreg(0x84, 0xFF, 0);   
	setreg(0x94, 0x00, 0);   
	setreg(0x38, 0x53, 0);  
	setreg(0x48, 0x0C, 0);   
	setreg(0x58, 0x13, 0);  
	setreg(0x68, 0x09, 0);  
	setreg(0x78, 0x00, 0);  
	setreg(0x88, 0xFF, 0);   
	setreg(0x98, 0x00, 0);  
	setreg(0x3C, 0x11, 0);  
	setreg(0x4C, 0x0C, 0);   
	setreg(0x5C, 0x16, 0);   
	setreg(0x6C, 0x02, 0);  
	setreg(0x7C, 0x00, 0);  
	setreg(0x8C, 0xFF, 0);   
	setreg(0x9C, 0x00, 0);  
	setreg(0xB0, 0x3D, 0);   
	setreg(0xB4, 0xC1, 0);   
	
	printf("\n\nTrumpet voice programmed!\n\n");
}

void YM2612_Pad(void){
	setreg(0x22, 0x08, 0);  
	setreg(0x27, 0x00, 0);    
	setreg(0xB4, 0xC0, 0);    
	setreg(0xB5, 0xC0, 0);   
	setreg(0xB6, 0xC0, 0);   
	setreg(0xB4, 0xC0, 0);    
	setreg(0xB5, 0xC0, 0);   
	setreg(0xB6, 0xC0, 0);   
	setreg(0x28, 0x00, 0);   
	setreg(0x28, 0x01, 0);   
	setreg(0x28, 0x02, 0);   
	setreg(0x28, 0x03, 0);   
	setreg(0x28, 0x04, 0);   
	setreg(0x28, 0x05, 0);   
	setreg(0x28, 0x06, 0);   
	setreg(0x30, 0x31, 0); 
	setreg(0x40, 0x11, 0);   
	setreg(0x50, 0x1F, 0);  
	setreg(0x60, 0x00, 0);  
	setreg(0x70, 0x00, 0); 
	setreg(0x80, 0x05, 0);  
	setreg(0x90, 0x00, 0);   
	setreg(0x34, 0x71, 0);   
	setreg(0x44, 0x11, 0); 
	setreg(0x54, 0x1F, 0);  
	setreg(0x64, 0x00, 0);  
	setreg(0x74, 0x00, 0); 
	setreg(0x84, 0x05, 0); 
	setreg(0x94, 0x00, 0); 
	setreg(0x38, 0x72, 0);  
	setreg(0x48, 0x0B, 0);  
	setreg(0x58, 0x0B, 0); 
	setreg(0x68, 0x00, 0); 
	setreg(0x78, 0x00, 0);  
	setreg(0x88, 0x04, 0);   
	setreg(0x98, 0x00, 0); 
	setreg(0x3C, 0x32, 0); 
	setreg(0x4C, 0x0B, 0); 
	setreg(0x5C, 0x0B, 0); 
	setreg(0x6C, 0x00, 0); 
	setreg(0x7C, 0x00, 0); 
	setreg(0x8C, 0x04, 0); 
	setreg(0x9C, 0x00, 0); 
	setreg(0xB0, 0x04, 0); 
	setreg(0xB4, 0xC4, 0); 
	
	printf("\n\nPad voice programmed!\n\n");
}

void YM2612_Square(void){
	setreg(0x22,0x08, 0);    
	setreg(0x27,0x00, 0);    
	setreg(0xB4,0xC0, 0);    
	setreg(0xB5,0xC0, 0);    
	setreg(0xB6,0xC0, 0);    
	setreg(0xB4,0xC0, 0);    
	setreg(0xB5,0xC0, 0);    
	setreg(0xB6,0xC0, 0);    
	setreg(0x28,0x00, 0);    
	setreg(0x28,0x01, 0);    
	setreg(0x28,0x02, 0);    
	setreg(0x28,0x03, 0);    
	setreg(0x28,0x04, 0);    
	setreg(0x28,0x05, 0);    
	setreg(0x28,0x06, 0);     
	setreg(0x30,0x32, 0);    
	setreg(0x40,0x1A, 0);    
	setreg(0x50,0x1F, 0);    
	setreg(0x60,0x00, 0);    
	setreg(0x70,0x00, 0);    
	setreg(0x80,0x0F, 0);    
	setreg(0x90,0x00, 0);    
	setreg(0x34,0x72, 0);    
	setreg(0x44,0x57, 0);    
	setreg(0x54,0x1F, 0);    
	setreg(0x64,0x00, 0);    
	setreg(0x74,0x00, 0);    
	setreg(0x84,0x0F, 0);    
	setreg(0x94,0x00, 0);    
	setreg(0x38,0x31, 0);    
	setreg(0x48,0x00, 0);    
	setreg(0x58,0x1F, 0);    
	setreg(0x68,0x00, 0);    
	setreg(0x78,0x00, 0);    
	setreg(0x88,0x0F, 0);    
	setreg(0x98,0x00, 0);    
	setreg(0x3C,0x71, 0);    
	setreg(0x4C,0x18, 0);    
	setreg(0x5C,0x1F, 0);    
	setreg(0x6C,0x00, 0);    
	setreg(0x7C,0x1F, 0);    
	setreg(0x8C,0x02, 0);    
	setreg(0x9C,0x04, 0);    
	setreg(0xB0,0x3D, 0);    
	setreg(0xA4,0x1A, 0);    
	setreg(0xA0,0x84, 0);    
 
}

void YM2612_Drums(void){
	setreg(0x22, 0x08, 0);
	setreg(0x27, 0x00, 0);
	setreg(0xB4, 0xC0, 0);
	setreg(0xB5, 0xC0, 0);
	setreg(0xB6, 0xC0, 0);
	setreg(0xB4, 0xC0, 0);
	setreg(0xB5, 0xC0, 0);
	setreg(0xB6, 0xC0, 0);
	setreg(0x28, 0x00, 0);
	setreg(0x28, 0x01, 0);
	setreg(0x28, 0x02, 0);
	setreg(0x28, 0x03, 0);
	setreg(0x28, 0x04, 0);
	setreg(0x28, 0x05, 0);
	setreg(0x28, 0x06, 0);
	setreg(0x30, 0x7F, 0);
	setreg(0x40, 0x00, 0);
	setreg(0x50, 0x1F, 0);
	setreg(0x60, 0x00, 0);
	setreg(0x70, 0x00, 0);
	setreg(0x80, 0xF0, 0);
	setreg(0x90, 0x00, 0);
	setreg(0x34, 0x70, 0);
	setreg(0x44, 0x00, 0);
	setreg(0x54, 0x1F, 0);
	setreg(0x64, 0x00, 0);
	setreg(0x74, 0x00, 0);
	setreg(0x84, 0xF0, 0);
	setreg(0x94, 0x00, 0);
	setreg(0x38, 0x7F, 0);
	setreg(0x48, 0x5B, 0);
	setreg(0x58, 0x1F, 0);
	setreg(0x68, 0x00, 0);
	setreg(0x78, 0x00, 0);
	setreg(0x88, 0xF0, 0);
	setreg(0x98, 0x00, 0);
	setreg(0x3C, 0x7F, 0);
	setreg(0x4C, 0x00, 0);
	setreg(0x5C, 0x1F, 0);
	setreg(0x6C, 0x1F, 0);
	setreg(0x7C, 0x16, 0);
	setreg(0x8C, 0x0F, 0);
	setreg(0x9C, 0x00, 0);
	setreg(0xB0, 0x00, 0);
}


void YM2612_SSEG(void){
	
	setreg(0x22, 0x08, 0);
	setreg(0x27, 0x00, 0);
	setreg(0xB4, 0xC0, 0);
	setreg(0xB5, 0xC0, 0);
	setreg(0xB6, 0xC0, 0);
	setreg(0xB4, 0xC0, 0);
	setreg(0xB5, 0xC0, 0);
	setreg(0xB6, 0xC0, 0);
	setreg(0x28, 0x00, 0);
	setreg(0x28, 0x01, 0);
	setreg(0x28, 0x02, 0);
	setreg(0x28, 0x03, 0);
	setreg(0x28, 0x04, 0);
	setreg(0x28, 0x05, 0);
	setreg(0x28, 0x06, 0);
	setreg(0x30, 0x70, 0);
	setreg(0x40, 0x4C, 0);
	setreg(0x50, 0x1F, 0);
	setreg(0x60, 0x00, 0);
	setreg(0x70, 0x00, 0);
	setreg(0x80, 0x00, 0);
	setreg(0x90, 0x09, 0);
	setreg(0x34, 0x31, 0);
	setreg(0x44, 0x00, 0);
	setreg(0x54, 0x1F, 0);
	setreg(0x64, 0x00, 0);
	setreg(0x74, 0x00, 0);
	setreg(0x84, 0x00, 0);
	setreg(0x94, 0x0D, 0);
	setreg(0x38, 0x72, 0);
	setreg(0x48, 0x00, 0);
	setreg(0x58, 0x12, 0);
	setreg(0x68, 0x07, 0);
	setreg(0x78, 0x07, 0);
	setreg(0x88, 0x38, 0);
	setreg(0x98, 0x09, 0);
	setreg(0x3C, 0x31, 0);
	setreg(0x4C, 0x00, 0);
	setreg(0x5C, 0x1F, 0);
	setreg(0x6C, 0x07, 0);
	setreg(0x7C, 0x07, 0);
	setreg(0x8C, 0x38, 0);
	setreg(0x9C, 0x0C, 0);
	setreg(0xB0, 0x04, 0);
	setreg(0xB4, 0xC6, 0);
}

void YM2612_DistBass(void){
	setreg(0x22, 0x08, 0);
	setreg(0x27, 0x00, 0);
	setreg(0xB4, 0xC0, 0);
	setreg(0xB5, 0xC0, 0);
	setreg(0xB6, 0xC0, 0);
	setreg(0xB4, 0xC0, 0);
	setreg(0xB5, 0xC0, 0);
	setreg(0xB6, 0xC0, 0);
	setreg(0x28, 0x00, 0);
	setreg(0x28, 0x01, 0);
	setreg(0x28, 0x02, 0);
	setreg(0x28, 0x03, 0);
	setreg(0x28, 0x04, 0);
	setreg(0x28, 0x05, 0);
	setreg(0x28, 0x06, 0);
	setreg(0x30, 0x64, 0);
	setreg(0x40, 0x0F, 0);
	setreg(0x50, 0x05, 0);
	setreg(0x60, 0x1F, 0);
	setreg(0x70, 0x08, 0);
	setreg(0x80, 0x09, 0);
	setreg(0x90, 0x00, 0);
	setreg(0x34, 0x35, 0);
	setreg(0x44, 0x0E, 0);
	setreg(0x54, 0x05, 0);
	setreg(0x64, 0x1F, 0);
	setreg(0x74, 0x08, 0);
	setreg(0x84, 0x09, 0);
	setreg(0x94, 0x00, 0);
	setreg(0x38, 0x04, 0);
	setreg(0x48, 0x15, 0);
	setreg(0x58, 0x1F, 0);
	setreg(0x68, 0x1F, 0);
	setreg(0x78, 0x00, 0);
	setreg(0x88, 0x09, 0);
	setreg(0x98, 0x00, 0);
	setreg(0x3C, 0x05, 0);
	setreg(0x4C, 0x15, 0);
	setreg(0x5C, 0x1F, 0);
	setreg(0x6C, 0x1F, 0);
	setreg(0x7C, 0x00, 0);
	setreg(0x8C, 0x09, 0);
	setreg(0x9C, 0x00, 0);
	setreg(0xB0, 0x2C, 0);
}

void YM2612_Weird(void){
	setreg(0x22, 0x08, 0);   
	setreg(0x27, 0x00, 0);   
	setreg(0xB4, 0xC0, 0);   
	setreg(0xB5, 0xC0, 0);   
	setreg(0xB6, 0xC0, 0);   
	setreg(0xB4, 0xC0, 0);   
	setreg(0xB5, 0xC0, 0);   
	setreg(0xB6, 0xC0, 0);   
	setreg(0x28, 0x00, 0);   
	setreg(0x28, 0x01, 0);   
	setreg(0x28, 0x02, 0);   
	setreg(0x28, 0x03, 0);   
	setreg(0x28, 0x04, 0);   
	setreg(0x28, 0x05, 0);   
	setreg(0x28, 0x06, 0);   
	setreg(0x30, 0x31, 0);   
	setreg(0x40, 0x17, 0);   
	setreg(0x50, 0x8C, 0);   
	setreg(0x60, 0x06, 0);   
	setreg(0x70, 0x14, 0);   
	setreg(0x80, 0x87, 0);   
	setreg(0x90, 0x00, 0);   
	setreg(0x34, 0x0D, 0);   
	setreg(0x44, 0x00, 0);   
	setreg(0x54, 0x00, 0);   
	setreg(0x64, 0x1F, 0);   
	setreg(0x74, 0x17, 0);   
	setreg(0x84, 0x03, 0);   
	setreg(0x94, 0x07, 0);   
	setreg(0x38, 0x00, 0);   
	setreg(0x48, 0x00, 0);   
	setreg(0x58, 0x09, 0);   
	setreg(0x68, 0x11, 0);   
	setreg(0x78, 0x08, 0);   
	setreg(0x88, 0x06, 0);   
	setreg(0x98, 0x00, 0);   
	setreg(0x3C, 0x70, 0);   
	setreg(0x4C, 0x0C, 0);   
	setreg(0x5C, 0x07, 0);   
	setreg(0x6C, 0x17, 0);   
	setreg(0x7C, 0x02, 0);   
	setreg(0x8C, 0xA4, 0);   
	setreg(0x9C, 0x05, 0);   
	setreg(0xB0, 0x3D, 0);   
	setreg(0xB4, 0xC7, 0);   
}

void YM_Basic(void){
	setreg(0x22, 0x08, 0);    //    YM2612:   Low Frequency Oscillator: 3.98 Hz
	setreg(0x27, 0x00, 0);   //    YM2612:   CSM Mode: Disable, 3 Slot Mode: Disable, Timer B Disable, Timer A Disable, Stop Timer B, Stop Timer A
	setreg(0xB4, 0xC0, 0);   //    YM2612:   Ch 0 PMS: 0x0, AMS: 0x0, Stereo: LR
	setreg(0xB5, 0xC0, 0);   //    YM2612:   Ch 1 PMS: 0x0, AMS: 0x0, Stereo: LR
	setreg(0xB6, 0xC0, 0);   //    YM2612:   Ch 2 PMS: 0x0, AMS: 0x0, Stereo: LR
	setreg(0xB4, 0xC0, 0);   //    YM2612:   Ch 3 PMS: 0x0, AMS: 0x0, Stereo: LR
	setreg(0xB5, 0xC0, 0);   //    YM2612:   Ch 4 PMS: 0x0, AMS: 0x0, Stereo: LR
	setreg(0xB6, 0xC0, 0);   //    YM2612:   Ch 5 PMS: 0x0, AMS: 0x0, Stereo: LR
	setreg(0x28, 0x00, 0);   //    YM2612:   Channel 0 Key On/Off: Slot1 Off, Slot2 Off, Slot3 Off, Slot4 Off
	setreg(0x28, 0x01, 0);   //    YM2612:   Channel 1 Key On/Off: Slot1 Off, Slot2 Off, Slot3 Off, Slot4 Off
	setreg(0x28, 0x02, 0);   //    YM2612:   Channel 2 Key On/Off: Slot1 Off, Slot2 Off, Slot3 Off, Slot4 Off
	setreg(0x28, 0x03, 0);   //    YM2612:   Key On/Off: Invalid Channel
	setreg(0x28, 0x04, 0);   //    YM2612:   Channel 3 Key On/Off: Slot1 Off, Slot2 Off, Slot3 Off, Slot4 Off
	setreg(0x28, 0x05, 0);   //    YM2612:   Channel 4 Key On/Off: Slot1 Off, Slot2 Off, Slot3 Off, Slot4 Off
	setreg(0x28, 0x06, 0);   //    YM2612:   Channel 5 Key On/Off: Slot1 Off, Slot2 Off, Slot3 Off, Slot4 Off
	setreg(0x30, 0x01, 0);   //    YM2612:   Ch 0 Slot 0 Detune: 0, Multiple: Freq * 0
	setreg(0x40, 0x07, 0);   //    YM2612:   Ch 0 Slot 0 Total Level: 0x07 = 100%
	setreg(0x50, 0x1F, 0);   //    YM2612:   Ch 0 Slot 0 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x60, 0x09, 0);   //    YM2612:   Ch 0 Slot 0 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x70, 0x00, 0);   //    YM2612:   Ch 0 Slot 0 Sustain Rate: 00
	setreg(0x80, 0xFF, 0);   //    YM2612:   Ch 0 Slot 0 Sustain Level: F, Release Rate: F
	setreg(0x90, 0x00, 0);   //    YM2612:   Ch 0 Slot 0 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x34, 0x01, 0);   //    YM2612:   Ch 0 Slot 1 Detune: 0, Multiple: Freq * 0
	setreg(0x44, 0x11, 0);   //    YM2612:   Ch 0 Slot 1 Total Level: 0x11 = 98%
	setreg(0x54, 0x1F, 0);   //    YM2612:   Ch 0 Slot 1 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x64, 0x09, 0);   //    YM2612:   Ch 0 Slot 1 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x74, 0x00, 0);   //    YM2612:   Ch 0 Slot 1 Sustain Rate: 00
	setreg(0x84, 0xFF, 0);   //    YM2612:   Ch 0 Slot 1 Sustain Level: F, Release Rate: F
	setreg(0x94, 0x00, 0);   //    YM2612:   Ch 0 Slot 1 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x38, 0x01, 0);   //    YM2612:   Ch 0 Slot 2 Detune: 0, Multiple: Freq * 0
	setreg(0x48, 0x08, 0);   //    YM2612:   Ch 0 Slot 2 Total Level: 0x08 = 100%
	setreg(0x58, 0x1F, 0);   //    YM2612:   Ch 0 Slot 2 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x68, 0x09, 0);   //    YM2612:   Ch 0 Slot 2 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x78, 0x00, 0);   //    YM2612:   Ch 0 Slot 2 Sustain Rate: 00
	setreg(0x88, 0xFF, 0);   //    YM2612:   Ch 0 Slot 2 Sustain Level: F, Release Rate: F
	setreg(0x98, 0x00, 0);   //    YM2612:   Ch 0 Slot 2 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x3C, 0x00, 0);   //    YM2612:   Ch 0 Slot 3 Detune: 0, Multiple: Freq * 0
	setreg(0x4C, 0x24, 0);   //    YM2612:   Ch 0 Slot 3 Total Level: 0x24 = 90%
	setreg(0x5C, 0x1F, 0);   //    YM2612:   Ch 0 Slot 3 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x6C, 0x09, 0);   //    YM2612:   Ch 0 Slot 3 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x7C, 0x00, 0);   //    YM2612:   Ch 0 Slot 3 Sustain Rate: 00
	setreg(0x8C, 0xFF, 0);   //    YM2612:   Ch 0 Slot 3 Sustain Level: F, Release Rate: F
	setreg(0x9C, 0x00, 0);   //    YM2612:   Ch 0 Slot 3 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0xB0, 0x24, 0);   //    YM2612:   Ch 0 Feedback: 10, Algorithm: 4
	setreg(0xA4, 0x1A, 0);   //    YM2612:   Ch 0 F-Num (prepare) MSB = 2, Octave 3
	setreg(0xA0, 0x84, 0);   //    YM2612:   Ch 0 F-Num (set) LSB = 84
	
	setreg(0x31, 0x01, 1);   //    YM2612:   Ch 1 Slot 0 Detune: 0, Multiple: Freq * 0
	setreg(0x41, 0x07, 1);   //    YM2612:   Ch 1 Slot 0 Total Level: 0x07 = 100%
	setreg(0x51, 0x1F, 1);   //    YM2612:   Ch 1 Slot 0 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x61, 0x09, 1);   //    YM2612:   Ch 1 Slot 0 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x71, 0x00, 1);   //    YM2612:   Ch 1 Slot 0 Sustain Rate: 00
	setreg(0x81, 0xFF, 1);   //    YM2612:   Ch 1 Slot 0 Sustain Level: F, Release Rate: F
	setreg(0x91, 0x00, 1);   //    YM2612:   Ch 1 Slot 0 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x35, 0x01, 1);   //    YM2612:   Ch 1 Slot 1 Detune: 0, Multiple: Freq * 0
	setreg(0x45, 0x11, 1);   //    YM2612:   Ch 1 Slot 1 Total Level: 0x11 = 98%
	setreg(0x55, 0x1F, 1);   //    YM2612:   Ch 1 Slot 1 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x65, 0x09, 1);   //    YM2612:   Ch 1 Slot 1 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x75, 0x00, 1);   //    YM2612:   Ch 1 Slot 1 Sustain Rate: 00
	setreg(0x85, 0xFF, 1);   //    YM2612:   Ch 1 Slot 1 Sustain Level: F, Release Rate: F
	setreg(0x95, 0x00, 1);   //    YM2612:   Ch 1 Slot 1 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x39, 0x01, 1);   //    YM2612:   Ch 1 Slot 2 Detune: 0, Multiple: Freq * 0
	setreg(0x49, 0x08, 1);   //    YM2612:   Ch 1 Slot 2 Total Level: 0x08 = 100%
	setreg(0x59, 0x1F, 1);   //    YM2612:   Ch 1 Slot 2 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x69, 0x09, 1);   //    YM2612:   Ch 1 Slot 2 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x79, 0x00, 1);   //    YM2612:   Ch 1 Slot 2 Sustain Rate: 00
	setreg(0x89, 0xFF, 1);   //    YM2612:   Ch 1 Slot 2 Sustain Level: F, Release Rate: F
	setreg(0x99, 0x00, 1);   //    YM2612:   Ch 1 Slot 2 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x3D, 0x00, 1);   //    YM2612:   Ch 1 Slot 3 Detune: 0, Multiple: Freq * 0
	setreg(0x4D, 0x24, 1);   //    YM2612:   Ch 1 Slot 3 Total Level: 0x24 = 90%
	setreg(0x5D, 0x1F, 1);   //    YM2612:   Ch 1 Slot 3 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x6D, 0x09, 1);   //    YM2612:   Ch 1 Slot 3 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x7D, 0x00, 1);   //    YM2612:   Ch 1 Slot 3 Sustain Rate: 00
	setreg(0x8D, 0xFF, 1);   //    YM2612:   Ch 1 Slot 3 Sustain Level: F, Release Rate: F
	setreg(0x9D, 0x00, 1);   //    YM2612:   Ch 1 Slot 3 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0xB1, 0x24, 1);   //    YM2612:   Ch 1 Feedback: 10, Algorithm: 4
	setreg(0xA5, 0x1A, 1);   //    YM2612:   Ch 1 F-Num (prepare) MSB = 2, Octave 3
	setreg(0xA1, 0xD3, 1);   //    YM2612:   Ch 1 F-Num (set) LSB = D3
	
	setreg(0x32, 0x01, 2);   //    YM2612:   Ch 2 Slot 0 Detune: 0, Multiple: Freq * 0
	setreg(0x42, 0x07, 2);   //    YM2612:   Ch 2 Slot 0 Total Level: 0x07 = 100%
	setreg(0x52, 0x1F, 2);   //    YM2612:   Ch 2 Slot 0 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x62, 0x09, 2);   //    YM2612:   Ch 2 Slot 0 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x72, 0x00, 2);   //    YM2612:   Ch 2 Slot 0 Sustain Rate: 00
	setreg(0x82, 0xFF, 2);   //    YM2612:   Ch 2 Slot 0 Sustain Level: F, Release Rate: F
	setreg(0x92, 0x00, 2);   //    YM2612:   Ch 2 Slot 0 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x36, 0x01, 2);   //    YM2612:   Ch 2 Slot 1 Detune: 0, Multiple: Freq * 0
	setreg(0x46, 0x11, 2);   //    YM2612:   Ch 2 Slot 1 Total Level: 0x11 = 98%
	setreg(0x56, 0x1F, 2);   //    YM2612:   Ch 2 Slot 1 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x66, 0x09, 2);   //    YM2612:   Ch 2 Slot 1 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x76, 0x00, 2);   //    YM2612:   Ch 2 Slot 1 Sustain Rate: 00
	setreg(0x86, 0xFF, 2);   //    YM2612:   Ch 2 Slot 1 Sustain Level: F, Release Rate: F
	setreg(0x96, 0x00, 2);   //    YM2612:   Ch 2 Slot 1 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x3A, 0x01, 2);   //    YM2612:   Ch 2 Slot 2 Detune: 0, Multiple: Freq * 0
	setreg(0x4A, 0x08, 2);   //    YM2612:   Ch 2 Slot 2 Total Level: 0x08 = 100%
	setreg(0x5A, 0x1F, 2);   //    YM2612:   Ch 2 Slot 2 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x6A, 0x09, 2);   //    YM2612:   Ch 2 Slot 2 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x7A, 0x00, 2);   //    YM2612:   Ch 2 Slot 2 Sustain Rate: 00
	setreg(0x8A, 0xFF, 2);   //    YM2612:   Ch 2 Slot 2 Sustain Level: F, Release Rate: F
	setreg(0x9A, 0x00, 2);   //    YM2612:   Ch 2 Slot 2 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x3E, 0x00, 2);   //    YM2612:   Ch 2 Slot 3 Detune: 0, Multiple: Freq * 0
	setreg(0x4E, 0x24, 2);   //    YM2612:   Ch 2 Slot 3 Total Level: 0x24 = 90%
	setreg(0x5E, 0x1F, 2);   //    YM2612:   Ch 2 Slot 3 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x6E, 0x09, 2);   //    YM2612:   Ch 2 Slot 3 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x7E, 0x00, 2);   //    YM2612:   Ch 2 Slot 3 Sustain Rate: 00
	setreg(0x8E, 0xFF, 2);   //    YM2612:   Ch 2 Slot 3 Sustain Level: F, Release Rate: F
	setreg(0x9E, 0x00, 2);   //    YM2612:   Ch 2 Slot 3 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0xB2, 0x24, 2);   //    YM2612:   Ch 2 Feedback: 10, Algorithm: 4
	setreg(0xA6, 0x1B, 2);   //    YM2612:   Ch 2 F-Num (prepare) MSB = 3, Octave 3
	setreg(0xA2, 0x2B, 2);   //    YM2612:   Ch 2 F-Num (set) LSB = 2B
	
	setreg(0x30, 0x01, 3);   //    YM2612:   Ch 3 Slot 0 Detune: 0, Multiple: Freq * 0
	setreg(0x40, 0x07, 3);   //    YM2612:   Ch 3 Slot 0 Total Level: 0x07 = 100%
	setreg(0x50, 0x1F, 3);   //    YM2612:   Ch 3 Slot 0 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x60, 0x09, 3);   //    YM2612:   Ch 3 Slot 0 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x70, 0x00, 3);   //    YM2612:   Ch 3 Slot 0 Sustain Rate: 00
	setreg(0x80, 0xFF, 3);   //    YM2612:   Ch 3 Slot 0 Sustain Level: F, Release Rate: F
	setreg(0x90, 0x00, 3);   //    YM2612:   Ch 3 Slot 0 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x34, 0x01, 3);   //    YM2612:   Ch 3 Slot 1 Detune: 0, Multiple: Freq * 0
	setreg(0x44, 0x11, 3);   //    YM2612:   Ch 3 Slot 1 Total Level: 0x11 = 98%
	setreg(0x54, 0x1F, 3);   //    YM2612:   Ch 3 Slot 1 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x64, 0x09, 3);   //    YM2612:   Ch 3 Slot 1 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x74, 0x00, 3);   //    YM2612:   Ch 3 Slot 1 Sustain Rate: 00
	setreg(0x84, 0xFF, 3);   //    YM2612:   Ch 3 Slot 1 Sustain Level: F, Release Rate: F
	setreg(0x94, 0x00, 3);   //    YM2612:   Ch 3 Slot 1 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x38, 0x01, 3);   //    YM2612:   Ch 3 Slot 2 Detune: 0, Multiple: Freq * 0
	setreg(0x48, 0x08, 3);   //    YM2612:   Ch 3 Slot 2 Total Level: 0x08 = 100%
	setreg(0x58, 0x1F, 3);   //    YM2612:   Ch 3 Slot 2 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x68, 0x09, 3);   //    YM2612:   Ch 3 Slot 2 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x78, 0x00, 3);   //    YM2612:   Ch 3 Slot 2 Sustain Rate: 00
	setreg(0x88, 0xFF, 3);   //    YM2612:   Ch 3 Slot 2 Sustain Level: F, Release Rate: F
	setreg(0x98, 0x00, 3);   //    YM2612:   Ch 3 Slot 2 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x3C, 0x00, 3);   //    YM2612:   Ch 3 Slot 3 Detune: 0, Multiple: Freq * 0
	setreg(0x4C, 0x24, 3);   //    YM2612:   Ch 3 Slot 3 Total Level: 0x24 = 90%
	setreg(0x5C, 0x1F, 3);   //    YM2612:   Ch 3 Slot 3 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x6C, 0x09, 3);   //    YM2612:   Ch 3 Slot 3 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x7C, 0x00, 3);   //    YM2612:   Ch 3 Slot 3 Sustain Rate: 00
	setreg(0x8C, 0xFF, 3);   //    YM2612:   Ch 3 Slot 3 Sustain Level: F, Release Rate: F
	setreg(0x9C, 0x00, 3);   //    YM2612:   Ch 3 Slot 3 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0xB0, 0x24, 3);   //    YM2612:   Ch 3 Feedback: 10, Algorithm: 4
	setreg(0xA4, 0x1B, 3);   //    YM2612:   Ch 3 F-Num (prepare) MSB = 3, Octave 3
	setreg(0xA0, 0x5B, 3);   //    YM2612:   Ch 3 F-Num (set) LSB = 5B
	
	setreg(0x31, 0x01, 4);   //    YM2612:   Ch 4 Slot 0 Detune: 0, Multiple: Freq * 0
	setreg(0x41, 0x07, 4);   //    YM2612:   Ch 4 Slot 0 Total Level: 0x07 = 100%
	setreg(0x51, 0x1F, 4);   //    YM2612:   Ch 4 Slot 0 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x61, 0x09, 4);   //    YM2612:   Ch 4 Slot 0 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x71, 0x00, 4);   //    YM2612:   Ch 4 Slot 0 Sustain Rate: 00
	setreg(0x81, 0xFF, 4);   //    YM2612:   Ch 4 Slot 0 Sustain Level: F, Release Rate: F
	setreg(0x91, 0x00, 4);   //    YM2612:   Ch 4 Slot 0 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x35, 0x01, 4);   //    YM2612:   Ch 4 Slot 1 Detune: 0, Multiple: Freq * 0
	setreg(0x45, 0x11, 4);   //    YM2612:   Ch 4 Slot 1 Total Level: 0x11 = 98%
	setreg(0x55, 0x1F, 4);   //    YM2612:   Ch 4 Slot 1 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x65, 0x09, 4);   //    YM2612:   Ch 4 Slot 1 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x75, 0x00, 4);   //    YM2612:   Ch 4 Slot 1 Sustain Rate: 00
	setreg(0x85, 0xFF, 4);   //    YM2612:   Ch 4 Slot 1 Sustain Level: F, Release Rate: F
	setreg(0x95, 0x00, 4);   //    YM2612:   Ch 4 Slot 1 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x39, 0x01, 4);   //    YM2612:   Ch 4 Slot 2 Detune: 0, Multiple: Freq * 0
	setreg(0x49, 0x08, 4);   //    YM2612:   Ch 4 Slot 2 Total Level: 0x08 = 100%
	setreg(0x59, 0x1F, 4);   //    YM2612:   Ch 4 Slot 2 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x69, 0x09, 4);   //    YM2612:   Ch 4 Slot 2 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x79, 0x00, 4);   //    YM2612:   Ch 4 Slot 2 Sustain Rate: 00
	setreg(0x89, 0xFF, 4);   //    YM2612:   Ch 4 Slot 2 Sustain Level: F, Release Rate: F
	setreg(0x99, 0x00, 4);   //    YM2612:   Ch 4 Slot 2 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x3D, 0x00, 4);   //    YM2612:   Ch 4 Slot 3 Detune: 0, Multiple: Freq * 0
	setreg(0x4D, 0x24, 4);   //    YM2612:   Ch 4 Slot 3 Total Level: 0x24 = 90%
	setreg(0x5D, 0x1F, 4);   //    YM2612:   Ch 4 Slot 3 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x6D, 0x09, 4);   //    YM2612:   Ch 4 Slot 3 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x7D, 0x00, 4);   //    YM2612:   Ch 4 Slot 3 Sustain Rate: 00
	setreg(0x8D, 0xFF, 4);   //    YM2612:   Ch 4 Slot 3 Sustain Level: F, Release Rate: F
	setreg(0x9D, 0x00, 4);   //    YM2612:   Ch 4 Slot 3 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0xB1, 0x24, 4);   //    YM2612:   Ch 4 Feedback: 10, Algorithm: 4
	setreg(0xA5, 0x1B, 4);   //    YM2612:   Ch 4 F-Num (prepare) MSB = 3, Octave 3
	setreg(0xA1, 0xC5, 4);   //    YM2612:   Ch 4 F-Num (set) LSB = C5
	
	setreg(0x32, 0x01, 5);   //    YM2612:   Ch 5 Slot 0 Detune: 0, Multiple: Freq * 0
	setreg(0x42, 0x07, 5);   //    YM2612:   Ch 5 Slot 0 Total Level: 0x07 = 100%
	setreg(0x52, 0x1F, 5);   //    YM2612:   Ch 5 Slot 0 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x62, 0x09, 5);   //    YM2612:   Ch 5 Slot 0 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x72, 0x00, 5);   //    YM2612:   Ch 5 Slot 0 Sustain Rate: 00
	setreg(0x82, 0xFF, 5);   //    YM2612:   Ch 5 Slot 0 Sustain Level: F, Release Rate: F
	setreg(0x92, 0x00, 5);   //    YM2612:   Ch 5 Slot 0 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x36, 0x01, 5);   //    YM2612:   Ch 5 Slot 1 Detune: 0, Multiple: Freq * 0
	setreg(0x46, 0x11, 5);   //    YM2612:   Ch 5 Slot 1 Total Level: 0x11 = 98%
	setreg(0x56, 0x1F, 5);   //    YM2612:   Ch 5 Slot 1 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x66, 0x09, 5);   //    YM2612:   Ch 5 Slot 1 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x76, 0x00, 5);   //    YM2612:   Ch 5 Slot 1 Sustain Rate: 00
	setreg(0x86, 0xFF, 5);   //    YM2612:   Ch 5 Slot 1 Sustain Level: F, Release Rate: F
	setreg(0x96, 0x00, 5);   //    YM2612:   Ch 5 Slot 1 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x3A, 0x01, 5);   //    YM2612:   Ch 5 Slot 2 Detune: 0, Multiple: Freq * 0
	setreg(0x4A, 0x08, 5);   //    YM2612:   Ch 5 Slot 2 Total Level: 0x08 = 100%
	setreg(0x5A, 0x1F, 5);   //    YM2612:   Ch 5 Slot 2 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x6A, 0x09, 5);   //    YM2612:   Ch 5 Slot 2 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x7A, 0x00, 5);   //    YM2612:   Ch 5 Slot 2 Sustain Rate: 00
	setreg(0x8A, 0xFF, 5);   //    YM2612:   Ch 5 Slot 2 Sustain Level: F, Release Rate: F
	setreg(0x9A, 0x00, 5);   //    YM2612:   Ch 5 Slot 2 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0x3E, 0x00, 5);   //    YM2612:   Ch 5 Slot 3 Detune: 0, Multiple: Freq * 0
	setreg(0x4E, 0x24, 5);   //    YM2612:   Ch 5 Slot 3 Total Level: 0x24 = 90%
	setreg(0x5E, 0x1F, 5);   //    YM2612:   Ch 5 Slot 3 Attack Rate: 1F, Key Scale: 1 / 3
	setreg(0x6E, 0x09, 5);   //    YM2612:   Ch 5 Slot 3 Amplitude Modulation: Disable, Decay Rate: 09
	setreg(0x7E, 0x00, 5);   //    YM2612:   Ch 5 Slot 3 Sustain Rate: 00
	setreg(0x8E, 0xFF, 5);   //    YM2612:   Ch 5 Slot 3 Sustain Level: F, Release Rate: F
	setreg(0x9E, 0x00, 5);   //    YM2612:   Ch 5 Slot 3 SSG-EG Flags: Envelope Off, Attack Off, Alternate Off, Hold Off
	setreg(0xB2, 0x24, 5);   //    YM2612:   Ch 5 Feedback: 10, Algorithm: 4
	setreg(0xA6, 0x1C, 5);   //    YM2612:   Ch 5 F-Num (prepare) MSB = 4, Octave 3
	setreg(0xA2, 0x3B, 5);   //    YM2612:   Ch 5 F-Num (set) LSB = 3B
}
