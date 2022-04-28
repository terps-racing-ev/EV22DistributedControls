#include "Controls.h"
#include "TorqueTestControls.h"
#include "Non_CAN.h"
#include "TR_CAN_Shield_Wrapper.h"
#include "Math_Functions.h"

TorqueTestControls::TorqueTestControls(int n) : Controls(n){
}
void TorqueTestControls::doAction() {
  shield->updateStoredTorque();
  torque = shield->getStoredTorque();
  String s = String(torque);
  Serial.println("received torque: " + s);
}
