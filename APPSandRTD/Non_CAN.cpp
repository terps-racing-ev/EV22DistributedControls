#include "Non_CAN.h"

float readBrakeVoltage(){
  if (digitalRead(0) == 1){
    return 3.0;
  }
  return 0.0;
}

float readAPPSOne() {
  return analogRead(1);
}

float readAPPSTwo() {
  //placeholder
  return analogRead(2);
}

bool ignitionOn() {
  return digitalRead(2);
}

int getSteeringAngle() {
  return analogRead(3);
}

int getCoolantTemp(){
  return analogRead(4);
}

int getSuspensionTravel(){
  return analogRead(0);
}

int readWheelSpeedSensor(){
  int pulseCount = 0;
  boolean pulseState = LOW;
  unsigned long currentTime;
  
  unsigned long startTime = millis();
  
  //count how many ms it takes to do one full rotation
  while (pulseCount <= PULSES_PER_ROTATION)
  {
    if (digitalRead(1) == HIGH){
      pulseState = HIGH;
    }
    
    if (digitalRead(1) == LOW && pulseState == HIGH){
      pulseCount++;
      pulseState = LOW;
    }
  }

  currentTime = millis();

  unsigned long milliPerRotation = currentTime - startTime;

  //calculate rpm based on that figure.
  unsigned long rpm = ((unsigned long)1000 * 60) / (unsigned long)milliPerRotation;

  return rpm;
  
}

void playBuzzer() {
  //TODO: replace 9 with constant
  tone(9, 1000);
  delay(1000);
  noTone(9);
}
