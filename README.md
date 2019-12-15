# 471-Final-Project  
Final Project for ECE 471 Umaine class using Raspberry Pi 3B+.  

Includes code for interfacing with a I2C 16x2 LCD display and configuring GPIO pins, all using the linux interface.  

YM3438 chip is driven with a MCP23S17 SPI GPIO Expander, using the library libmcp23s17.  
This library can be found at https://github.com/piface/libmcp23s17  

Current Status:
The YM3438 is fully playable, with several presets to choose from. An alarm "song" can also be automatically played back.  
The SN76489AN is non-functional at this time.  

Currently working on: SN76489AN sound chip support (for full Sega Genesis song support)  
                      YM3438 Keyboard mode with polyphony support (up to 6 channels per chip, at once)  
                      
Future Plans:         Add OLED displays to view and adjust operators (ideally x4).  
                      Add rotary encoders for ADSR envelope / LFO adjustment (number matching amount of OLED displays?)  
                      Support up to 3 YM3438 chips at once to support up to 18 channels (on-par with 'real' 80's synths)  
                      Add the ability to create and save your own custom patches  
                      Add ability to record songs entirely with the hardware, without needing a DAW  
                      Additional output circuitry to add advanced afterFX (reverb, chorus), surpass chip limitations a bit  
                      MIDI input/output support(v. difficult)   
                          - Input, for using an external MIDI device to play notes and adjust YM3438, instead of GPIO buttons  
                          - Output, for interfacing and exporting audio to a DAW of user's choice  
                      VGM Playback(difficult)  
                      VGM export from songs recorded in hardware (v. difficult)  
                      Add Schematic and PCB files (ez)  
                      
 
