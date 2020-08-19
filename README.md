# PiSynth
  
Final Project for ECE 471 at University of Maine.

PiSynth is a functional hardware FM synthesizer featuring the Yamaha YM3438 (or YM2612) chip. It is driven by a Raspberry Pi running Raspbian Linux.  

Includes code for interfacing with a I2C 16x2 LCD display and configuring GPIO pins, all using the linux interface.  

YM3438 chip is driven with a MCP23S17 SPI GPIO Expander, using the library libmcp23s17.  
This library can be found at https://github.com/piface/libmcp23s17  
  
ALSA raw MIDI read code based on code found here:  
https://ccrma.stanford.edu/~craig/articles/linuxmidi/alsa-1.0/alsarawmidiin.c  

Current Status:  
The YM3438 is fully playable in MIDI keyboard mode with several presets to choose from.  
3 GPIO buttons are used for menu navigation.  
GPIO input for note playback is depreciated. May bring back as an option later, but the code is still here to do it.  

An alarm "song" can also be automatically played back.  
The SN76489AN is non-functional at this time.  
  
A clock function displays the current date and time on the LCD display. An alarm can be set using only the hardware buttons.  

YM2151 stuff may work with some modifications. I cannot test that, however, since I do not have a working YM2151/YM3012 to test it with at this time.  

Currently working on  
----------------------------------------------------------------------------  
SN76489AN sound chip support (for full Sega Genesis song support)  
YM3438 Keyboard mode with polyphony support (up to 6 channels per chip, at once)  
MIDI Keyboard stuff  
.VGM file parsing  
Instrument data storage using .DMP files  
Code optimization  
                      
Future Plans  
-----------------------------------------------------------------------------  
Add 128x64 OLED displays to view and adjust operators (ideally x4, 1 per operator).  
Add rotary encoders for ADSR envelope / LFO adjustment (number matching amount of OLED displays?)  
Support up to 3 YM3438 chips at once to support up to 18 channels  
Add the ability to create and save your own custom patches  
Add ability to record songs entirely with the hardware, without needing a DAW
An optional graphical application  
Additional output circuitry to add advanced afterFX (reverb, chorus)
MIDI input/output support(eventually)  
  - Input, for using an external MIDI device to play notes and adjust YM3438, instead of GPIO buttons  
  - Output, for interfacing and exporting audio to a DAW of user's choice  
.VGM Playback(eventually)  
export .VGM from songs recorded in hardware (eventually)  
Add Schematic and PCB files  

Build Instructions  
-------------------------------------------------
You will need to have libasound2-dev installed on your Raspberry Pi for MIDI functionality.
In the PiSynth directory, run the following command:  
gcc -lasound i2c_1602.c i2c_1602.h Keyboard.c Keyboard.h main.c mcps.c mcps.h YM2612.c YM2612.h YM2612_Presets.c YM2612_Presets.h YM2612_Note_Picker.c YM2612_Note_Picker.h YM2612_Songs.c YM2612_Songs.h SN76489AN.c SN76489AN.h Clock.c Clock.h YM_MIDI_KeyCodes.c YM_MIDI_KeyCodes.h -o PiSynth  

A makefile will be made when the project has most desired functions added.  
  
Licensing  
-------------------------------------------------  
This code will be released under the MIT License. This license is included in the LICENSE file.  
