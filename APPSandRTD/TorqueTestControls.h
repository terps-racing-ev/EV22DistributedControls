#ifndef TORQUETESTCONTROLS_H
#define TORQUETESTCONTROLS_H
class TorqueTestControls: public Controls {
  private:
    int torque;
  public:
    TorqueTestControls(int n);
    void doAction();
};

#endif
