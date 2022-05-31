#ifndef VEHICLESPEEDCALCCONTROLS
#define VEHICLESPEEDCALCCONTROLS
#include <LiquidCrystal.h>
class VehicleSpeedCalcControls: public Controls {
  private:
    int wheelSpeed1;
    int wheelSpeed2;
    int wheelSpeed3;
    int wheelSpeed4;

    LiquidCrystal* lcd;

    unsigned long prevTime;

    bool enabled;
  public:
    VehicleSpeedCalcControls(int n);
    void doAction();
};

#endif
