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

void TR_CAN_Shield_Wrapper::updateStoredWheelSpeeds() {
  boolean wheelSpeed1Updated = false;
  boolean wheelSpeed2Updated = false;
  boolean wheelSpeed3Updated = false;

  byte receiveBuffer[8];
  while (!wheelSpeed1Updated && !wheelSpeed2Updated && !wheelSpeed3Updated) {
    byte sendingID = shield->can_receive(0, receiveBuffer);
        
    int data = receiveBuffer[1] + receiveBuffer[2];
    
    if (sendingID == wheelSpeedCANID1) {
      wheelSpeed1 = data;
      wheelSpeed1Updated = true;
    } else if (sendingID == wheelSpeedCANID2) {
      wheelSpeed2 = data;
      wheelSpeed2Updated = true;
    } else if (sendingID == wheelSpeedCANID3) {
      wheelSpeed3 = data;
      wheelSpeed3Updated = true;
    }
  }
  
}

int TR_CAN_Shield_Wrapper::getWheelSpeed(int n){
  if (n == 1) {
    return wheelSpeed1;
  } else if (n == 2) {
    return wheelSpeed2;
  } else if (n == 3) {
    return wheelSpeed3;
  }

  return -1;
}
