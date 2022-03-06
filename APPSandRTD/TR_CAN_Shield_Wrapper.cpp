#include "TR_CAN_Shield_Wrapper.h"

TR_CAN_Shield_Wrapper::TR_CAN_Shield_Wrapper(byte can_id, bool debug) {
  shield = new TR_CAN_Shield(can_id, debug);
}

void TR_CAN_Shield_Wrapper::sendTorque(int torque) {
  byte torqueFieldOne = torque;
  byte torqueFieldTwo = 0;

  if (torque > 255) {
    torqueFieldOne = 255;
    torqueFieldTwo = (byte) (torque - 255);
  }
  
  byte arrayToSend[8] = {torqueFieldOne, torqueFieldTwo, 0, 0, 1, 0, 0, 0};
  
  shield->can_send(0, arrayToSend);
}

void TR_CAN_Shield_Wrapper::sendRangeFault() {
  sendTorque(0);
}

void TR_CAN_Shield_Wrapper::sendTimeoutFault() {
  sendTorque(0);  
}
