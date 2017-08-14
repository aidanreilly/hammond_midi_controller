#include <Bounce.h>  // Bounce library
const int ports[] = {A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11};
int v[2][12];
int last;
Bounce button0 = Bounce(0, 5);  // 5 = 5 ms debounce time
Bounce button1 = Bounce(1, 5); 
Bounce button2 = Bounce(2, 5);  
const int channel = 2; //channel 2 for buttons

void setup() {
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  for(int i=0;i<12;i++) {
    last = v[0][i];
    v[0][i] = (analogRead(ports[i]) / 4 + v[1][i]) / 2;
    if(v[0][i] != last)
      usbMIDI.sendControlChange(i, v[0][i] / 2, 1);
      
    v[1][i] = v[0][i];
  }
  delay(5);

    // MIDI Controllers should discard incoming MIDI messages.
  while (usbMIDI.read()) {
  }

//button code
  button0.update();
  button1.update();
  button2.update();
  // Note On messages when each button is pressed
  if (button0.fallingEdge()) {
    usbMIDI.sendNoteOn(60, 99, channel);  // 60 = C4
  }
  if (button1.fallingEdge()) {
    usbMIDI.sendNoteOn(61, 99, channel);  // 61 = E#4
  }
  if (button2.fallingEdge()) {
    usbMIDI.sendNoteOn(62, 99, channel);  // 62 = G4
  }
  // Note Off messages when each button is released
  if (button0.risingEdge()) {
    usbMIDI.sendNoteOff(60, 0, channel);  // 60 = C4
  }
  if (button1.risingEdge()) {
    usbMIDI.sendNoteOff(61, 0, channel);  // 61 = E#4
  }
  if (button2.risingEdge()) {
    usbMIDI.sendNoteOff(62, 0, channel);  // 62 = G4
  }


}
