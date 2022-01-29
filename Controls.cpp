#include "Controls.h"
#include "Non_CAN.h"
#include "TR_CAN_Shield_Wrapper.h"

Controls::Controls() {
  currentState = State::STARTUP_SEQUENCE;

  startUpFlag = false;
  timeOutFault = false;
  rangeFault = false;
  shutDownFlag = false;

  shield = new TR_CAN_Shield_Wrapper(15, false);
}

void Controls::startUpSequence() {
  if (ignitionOn() && readBrakeVoltage() > 2.0) {
    playBuzzer();
    currentState = State::STARTED;
  }
}

void Controls::doAction() {
  if (currentState == State::STARTUP_SEQUENCE) {
    startUpSequence();
  } else if (currentState == State::STARTED){
    
  }
}
