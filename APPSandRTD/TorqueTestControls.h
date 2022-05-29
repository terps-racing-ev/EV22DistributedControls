#ifndef TORQUETESTCONTROLS_H
#define TORQUETESTCONTROLS_H
#include <LiquidCrystal.h>
class TorqueTestControls: public Controls {
  private:
    int torque;
    unsigned long prevTime;
    
    LiquidCrystal* lcd;
  public:
    TorqueTestControls(int n);
    void doAction();
};

#endif
