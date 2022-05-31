#include "Non_CAN.h"

float readBrakeVoltage(){
  if (digitalRead(0) == 1){
    return 3.0;
  }
  return 3.0;
}

float readAPPSOne(TR_CAN_Shield* shield) {
  return shield->analogRead(0);
}

float readAPPSTwo(TR_CAN_Shield* shield) {
  //placeholder
  return shield->analogRead(2);
}

bool ignitionOn(TR_CAN_Shield* shield) {
  //Serial.println(shield->analogRead(0));
  return shield->analogRead(6);
}

int getSteeringAngle(TR_CAN_Shield* shield) {
  return shield->analogRead(2);
}

int getCoolantTemp(TR_CAN_Shield* shield){
  return shield->analogRead(4);
}

int getSuspensionTravel(TR_CAN_Shield* shield){
  return shield->analogRead(0);
}

int readWheelSpeedSensor(TR_CAN_Shield* shield){
  int pulseCount = 0;
  boolean pulseState = LOW;
  unsigned long currentTime;
  
  unsigned long startTime = millis();
  
  //count how many ms it takes to do one full rotation
  while (pulseCount <= PULSES_PER_ROTATION)
  {
    if (shield->analogRead(6) == HIGH){
      pulseState = HIGH;
    }
    
    if (shield->analogRead(6) == LOW && pulseState == HIGH){
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
