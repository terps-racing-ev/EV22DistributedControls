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
  public:
    TR_CAN_Shield_Wrapper(byte can_id, bool debug);
    void sendTorque(int torque);
  
};

#endif
