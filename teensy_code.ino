#include <Bounce.h>  // Bounce library makes button change detection easy
const int channel = 1;
const int ports[] = {A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16};
int v[2][17];
int last;
Bounce button1 = Bounce(1, 5);  // 5 = 5 ms debounce time
Bounce button2 = Bounce(2, 5);  // which is appropriate for good
Bounce button3 = Bounce(3, 5);  // quality mechanical pushbuttons

void setup() {
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
}

// knob code
void loop() {
  for(int i=0;i<17;i++) {
    last = v[0][i];
    v[0][i] = (analogRead(ports[i]) / 4 + v[1][i]) / 2;
    if(v[0][i] != last)
      usbMIDI.sendControlChange(i, v[0][i] / 2, 1);
      
    v[1][i] = v[0][i];

//button code
  button1.update();
  button2.update();
  button3.update();
  // Note On messages when each button is pressed
  if (button1.fallingEdge()) {
    usbMIDI.sendNoteOn(60, 99, channel);  // 60 = C4
  }
  if (button2.fallingEdge()) {
    usbMIDI.sendNoteOn(61, 99, channel);  // 61 = C#4
  }
  if (button3.fallingEdge()) {
    usbMIDI.sendNoteOn(62, 99, channel);  // 62 = D4
  }
  // Note Off messages when each button is released
  if (button1.risingEdge()) {
    usbMIDI.sendNoteOff(60, 0, channel);  // 60 = C4
  }
  if (button2.risingEdge()) {
    usbMIDI.sendNoteOff(61, 0, channel);  // 61 = C#4
  }
  if (button3.risingEdge()) {
    usbMIDI.sendNoteOff(62, 0, channel);  // 62 = D4
  }

  // MIDI Controllers should discard incoming MIDI messages.
  while (usbMIDI.read()) {
  }

  }
  delay(4);
}