#include <alsa/asoundlib.h>

void midi_open(void);
snd_seq_event_t *midi_read(void);
void midi_process(snd_seq_event_t *ev);

