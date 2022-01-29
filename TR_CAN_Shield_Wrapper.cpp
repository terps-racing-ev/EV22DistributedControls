#include "TR_CAN_Shield_Wrapper.h"

TR_CAN_Shield_Wrapper::TR_CAN_Shield_Wrapper(byte can_id, bool debug) {
  shield = new TR_CAN_Shield(can_id, debug);
}

void TR_CAN_Shield_Wrapper::sendTorque(int torque) {
  
}
