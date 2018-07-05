// MIDI Channel
const uint8_t channel = 10;

// MIDI Notes to send
// [encoder id][direction ([0]: -; [1]: +)]
const uint8_t midi_map[4][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};

#include <Encoder.h>

long pos[4] = {-999};

Encoder knob[4] = {{11, 9}, {2, 12}, {8, 7}, {21, 20}};

void setup() {
}

long old_millis = 0;

void loop() {
  if(old_millis + 5 <= millis()){
    long new_val[4] = {0};
  
    for(int i=0; i<4; i++)
      new_val[i] = knob[i].read();
  
    for(int i=0; i<4; i++)
      if(new_val[i] != pos[i]){
        if(new_val[i] > pos[i])
          usbMIDI.sendNoteOn(midi_map[i][0], 127, channel);
        else
          usbMIDI.sendNoteOn(midi_map[i][1], 127, channel);
        
        pos[i] = new_val[i];
      }
    old_millis = millis();
  }

  while(usbMIDI.read()){}
}
