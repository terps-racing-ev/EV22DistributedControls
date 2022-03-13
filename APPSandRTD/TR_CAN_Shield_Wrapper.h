#ifndef TR_CAN_SHIELD_WRAPPER
#define TR_CAN_SHIELD_WRAPPER

#include <TR_CAN_Shield.h>

/*
 * This class contains functions to abstract out the details of 
 * sending information over CAN using the TR_CAN_Shield class.
 */
 
class TR_CAN_Shield_Wrapper {
  private:
    TR_CAN_Shield* shield;
    /* specific numbers are placeholders */
    const int wheelSpeedCANID1 = 1;
    const int wheelSpeedCANID2 = 2;
    const int wheelSpeedCANID3 = 3;

    int wheelSpeed1;
    int wheelSpeed2;
    int wheelSpeed3;
  public:
    TR_CAN_Shield_Wrapper(byte can_id, bool debug);
    void sendTorque(int torque);
    void sendRangeFault();
    void sendTimeoutFault();
    void updateStoredWheelSpeeds();
    int getWheelSpeed(int n);
};

#endif
