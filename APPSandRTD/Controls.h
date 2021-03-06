#ifndef STATE
#define STATE

#include "TR_CAN_Shield_Wrapper.h"

/*
 * This class is supposed to represent the current state of the program, where
 * doAction() (which is called in loop()) calls the appropriate function
 * depending on the current state. I'm still not fully sure on how the different
 * states work in the Simulink code work so this will probably need some changes
 * in the future.
 */

/*
 * Could do a subclass for each state where each subclass has a doAction() method that
 * returns the next state. e.g. a StartupSequence class with a doAction() method that
 * returns a Started object.
 * 
 * I used enums to keep it simple for now but might want to switch it to make the code cleaner.
 */

class Controls {
  protected:
    TR_CAN_Shield_Wrapper* shield;
   
  public:
    Controls();
    virtual void doAction() = 0;
    
  
};
#endif
