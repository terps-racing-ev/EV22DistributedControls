#ifndef VEHICLESPEEDCALCCONTROLS
#define VEHICLESPEEDCALCCONTROLS

class VehicleSpeedCalcControls: public Controls {
  private:
    int wheelSpeed1;
    int wheelSpeed2;
    int wheelSpeed3;
    int wheelSpeed4;
  public:
    VehicleSpeedCalcControls(int n);
    void doAction();
};

#endif
