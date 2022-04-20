#ifndef APPSCONTROLS
#define APPSCONTROLS
class APPSControls: public Controls {
   private:
    const float MAX_TORQUE = 190.0f;
    const float MIN_TORQUE = 0.0f;
    
    enum State {STARTUP_SEQUENCE, STARTED};
    State currentState;
    
    bool startUpFlag;
    bool timeOutFault;
    bool rangeFault;
    bool shutDownFlag;
       
    void startUpSequence();
    void APPS();

    const int brakeIndicatorPin = 13;
    
  public:
    APPSControls(int n);
    void doAction();
};

#endif
