#include "Non_CAN.h"

float readBrakeVoltage(){
  if (digitalRead(7) == 1){
    return 3.0;
  }
  return 0.0;
}

float readAPPSOne() {
  //placeholder
  return 1.0;
}

float readAPPSTwo() {
  //placeholder
  return 1.0;
}

bool ignitionOn() {
  return digitalRead(2);
}

bool shutdownSignal() {
  return false;
}

void playBuzzer() {
  //TODO: replace 9 with constant
  tone(9, 1000);
  delay(1000);
  noTone(9);
}
