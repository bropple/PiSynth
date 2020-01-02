
#include "MIDI.h"

int MIDI_input(void) {
   int status;
   int mode = SND_RAWMIDI_SYNC;
   snd_rawmidi_t* midiin = NULL;
   const char* portname = "hw:1,0,0";  // Raw ALSA MIDI hardware port for the MIDI controller you want to use (if there's only one, then this should be fine)
   
   if ((status = snd_rawmidi_open(&midiin, NULL, portname, mode)) < 0) {
      errormessage("Problem opening MIDI input: %s", snd_strerror(status));
      exit(1);
   }

   int count = 0;         // Keep track of the number of integers printed out after the MIDI command (should always be 2)
   char buffer[1];        // Storage for input buffer received
   
   while (1) { //infinite loop
      if ((status = snd_rawmidi_read(midiin, buffer, 1)) < 0) {
         errormessage("Problem reading MIDI input: %s", snd_strerror(status));
      }
      
      if ((unsigned char)buffer[0] >= 0x80) {   // command byte: print in hex
         printf("0x%x ", (unsigned char)buffer[0]);
      } else {
         printf("%d ", (unsigned char)buffer[0]);
         count ++;
      }
      fflush(stdout);
      if(count == 2){
			  printf("\n");
			  count = 0;
      }
   }

   snd_rawmidi_close(midiin);
   midiin  = NULL;    // snd_rawmidi_close() does not clear invalid pointer,
   return 0;          // so might be a good idea to erase it after closing.
}

void errormessage(const char *format, ...) { //print error messages
   va_list ap;
   va_start(ap, format);
   vfprintf(stderr, format, ap);
   va_end(ap);
   putc('\n', stderr);
}
