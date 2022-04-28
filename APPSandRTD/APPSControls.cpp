#include "Controls.h"
#include "APPSControls.h"
#include "Non_CAN.h"
#include "TR_CAN_Shield_Wrapper.h"
#include "Math_Functions.h"

APPSControls::APPSControls(int n): Controls(n) {
  currentState = State::STARTUP_SEQUENCE;

  startUpFlag = false;
  timeOutFault = false;
  rangeFault = false;
  shutDownFlag = false;
}

void APPSControls::startUpSequence() {
  if (true || (ignitionOn() && readBrakeVoltage() > 2.0)) {
    playBuzzer();
    currentState = State::STARTED;
  }
}

void APPSControls::APPS() {
  //get the percent travel for each pedal.
  float pedalOneTravel = voltageToPercentTravelOne(readAPPSOne(shield->shield));
  float pedalTwoTravel = voltageToPercentTravelTwo(readAPPSTwo(shield->shield));
  String p = String(pedalTwoTravel);
  /*
  Serial.print("pedal_travel:" + p);
  Serial.print("\t");
  */
  //Serial.print("pedal_travel:" + p);
  //Serial.print("\t");
  //check their percent difference00
  float pedalPercentDifference = abs(pedalOneTravel - pedalTwoTravel);

  boolean implausibleDifference = false;

  if(pedalOneTravel > 0 || pedalTwoTravel > 0) {
    digitalWrite(brakeIndicatorPin, HIGH);
  }

  /*
   * according to T.4.2.5, if the pedal percent difference is greater than
   * 10, and this implausibility persists for more than 100 ms, then 
   * the motor should be shut down (timeOutFlag set to true)
   */
  //TODO: Move implausibility check into another function?
  if (false && pedalPercentDifference > 0.1) {
    implausibleDifference = true;
    long startTime = millis();
    
    //check if the implausibility persists for more than 100 ms
    //TODO: might want to not block other code while this check runs?
    while ((millis() - startTime) <= 100) {
      
      pedalOneTravel = voltageToPercentTravelOne(readAPPSOne(shield->shield));
      pedalTwoTravel = voltageToPercentTravelTwo(readAPPSTwo(shield->shield));
      pedalPercentDifference = abs(pedalOneTravel - pedalTwoTravel);

      //if the implausibility stops, then continue as normal
      if (pedalPercentDifference < 10) {
        implausibleDifference = false;
        break;
      }
      
    }   
  }

  if (!implausibleDifference) {
    /*
    Serial.print("pedal_one: ");
    Serial.print(pedalOneTravel);
    Serial.print("\t");
    Serial.print("pedal_two: "); 
    Serial.print("\t");
    Serial.print(pedalTwoTravel);
    */
    float averagePedalPercent = (pedalOneTravel + pedalTwoTravel) / 2.0;
    //Serial.print("avg_percent: ");
    //Serial.print(averagePedalPercent);
    //Serial.print("\t");
    
    //float torqueRequest = calculateTorque(averagePedalPercent);
    float torqueRequest = calculateTorque(pedalOneTravel);
  

    if (torqueRequest >= MIN_TORQUE && torqueRequest <= MAX_TORQUE) {
      String t = String(torqueRequest);
      Serial.println("torque request: " + t);
      shield->sendTorque(torqueRequest);
    } else {
      rangeFault = true;
    }
  } else {
    //timeOutFault = true;
  }
}

void APPSControls::doAction() {
  if (rangeFault) {
    shield->sendRangeFault();
  } else if (timeOutFault) {
    shield->sendTimeoutFault();
  } else if (currentState == State::STARTUP_SEQUENCE) {
    startUpSequence();
  } else if (currentState == State::STARTED){
    APPS();
  }
}
