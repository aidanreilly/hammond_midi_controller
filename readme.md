Teensy 3.2 code for a simple 16 knob, 3 button midi controller.

- Hardware
    - teensy 3.2 board
    - 12 10K linear pots
    - 3 momentary on buttons
- Wiring
    - Knobs
        With pot pins facing down:
            * Connect rightmost leg to AGND.
            * Connect leftmost leg to 3.3V.
            * Connect middle leg to A0 pin.
Et voila, voltage divider across Teensy analog pin.
Rinse and repeat for pins A0-A15.

- Buttons
    - Connect lugs to AGND, digi pins 0-2.