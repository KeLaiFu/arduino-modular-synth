#include <MIDI.h>

static bool done = 0;

const byte sysexArray[325] = {240, 0, 127, 21, 1, 2, 0, 1, 1, 12, 1, 15, 11, 1, 1, 0, 11, 2, 0, 1, 11, 3, 0, 0, 11, 4, 0, 127, 11, 5, 0, 1, 11, 7, 0, 3, 11, 8, 0, 3, 12, 1, 1, 0, 12, 2, 0, 2, 12, 3, 0, 0, 12, 4, 0, 127, 12, 5, 0, 1, 12, 7, 0, 3, 12, 8, 0, 3, 13, 1, 0, 0, 13, 2, 0, 0, 13, 3, 0, 0, 13, 4, 0, 0, 13, 5, 0, 0, 13, 7, 0, 0, 13, 8, 0, 0, 14, 1, 0, 0, 14, 2, 0, 0, 14, 3, 0, 0, 14, 4, 0, 0, 14, 5, 0, 0, 14, 7, 0, 0, 14, 8, 0, 0, 21, 1, 11, 1, 21, 16, 0, 0, 21, 14, 0, 64, 22, 1, 11, 20, 22, 15, 0, 5, 23, 1, 12, 1, 23, 16, 0, 0, 23, 14, 0, 64, 24, 1, 12, 20, 24, 15, 0, 5, 31, 1, 11, 1, 31, 12, 0, 0, 32, 1, 12, 1, 32, 12, 0, 0, 33, 1, 11, 1, 33, 12, 2, 0, 34, 1, 12, 1, 34, 12, 2, 0, 35, 1, 1, 60, 35, 2, 0, 10, 35, 4, 0, 60, 35, 5, 0, 1, 35, 12, 2, 0, 36, 1, 1, 62, 36, 2, 0, 10, 36, 4, 0, 62, 36, 5, 0, 1, 36, 12, 2, 0, 37, 1, 1, 64, 37, 2, 0, 10, 37, 4, 0, 64, 37, 5, 0, 1, 37, 12, 2, 0, 38, 1, 1, 65, 38, 2, 0, 10, 38, 4, 0, 65, 38, 5, 0, 1, 38, 12, 2, 0, 39, 1, 21, 12, 39, 11, 0, 0, 39, 12, 2, 0, 40, 1, 21, 6, 40, 11, 0, 0, 40, 12, 2, 0, 41, 1, 21, 3, 41, 11, 0, 0, 41, 12, 2, 0, 42, 1, 20, 3, 42, 11, 0, 0, 42, 12, 2, 0, 247};
// MIDI interface
MIDI_CREATE_INSTANCE(HardwareSerial, Serial, MIDI);

void setup() {
  // Initiate MIDI communications, listen to all channels
  MIDI.begin();

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
}


void loop() {
  if (!done) {
    done = 1;
    MIDI.sendSysEx(325, sysexArray, true);
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
  }
}