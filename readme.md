Teensy 3.2 code for a simple 16 knob, 3 button midi controller.

Wiring:

#Knobs
With pot pins facing down:
* Connect rightmost leg to GND.
* Connect leftmost leg to 3.3V.
* Connect middle leg to A0 pin.

Et voila, voltage divider across Teensy analog pin.

Rinse and repeat, A0-A15 pins.

#Buttons
Connect lugs to GND, digi pins 0-2.