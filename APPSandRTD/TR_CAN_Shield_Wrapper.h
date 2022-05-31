#ifndef TR_CAN_SHIELD_WRAPPER_H
#define TR_CAN_SHIELD_WRAPPER_H

#include <TR_CAN_Shield.h>

/*
 * This class contains functions to abstract out the details of 
 * sending information over CAN using the TR_CAN_Shield class.
 */
 
class TR_CAN_Shield_Wrapper {
  private:
    /* specific numbers are placeholders */
    const int wheelSpeedCANID1 = 1;
    const int wheelSpeedCANID2 = 2;
    const int wheelSpeedCANID3 = 3;

    int wheelSpeed1;
    int wheelSpeed2;
    int wheelSpeed3;

    /* for testing */
    int receivedTorque;
  public:
    TR_CAN_Shield_Wrapper(byte can_id, bool debug);
    TR_CAN_Shield* shield;
    void sendTorque(int torque, int enable);
    void sendRangeFault();
    void sendTimeoutFault();
    void updateStoredWheelSpeeds();
    void updateStoredTorque();
    int getWheelSpeed(int n);
    int getStoredTorque();
    void sendAllData(int vehicleSpeed);
};

#endif
