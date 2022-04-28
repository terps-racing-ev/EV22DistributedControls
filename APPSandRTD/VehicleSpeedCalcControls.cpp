#include "Controls.h"
#include "VehicleSpeedCalcControls.h"
#include "Non_CAN.h"
#include "TR_CAN_Shield_Wrapper.h"
#include "Math_Functions.h"

VehicleSpeedCalcControls::VehicleSpeedCalcControls(int n) : Controls(n){
}
void VehicleSpeedCalcControls::doAction() {
  
  shield->updateStoredWheelSpeeds();
  wheelSpeed1 = shield->getWheelSpeed(1);
  wheelSpeed2 = shield->getWheelSpeed(2);
  wheelSpeed3 = shield->getWheelSpeed(3);
  wheelSpeed4 = readWheelSpeedSensor();
  
  int vehicleSpeed = calculateVehicleSpeed(wheelSpeed1, wheelSpeed2, wheelSpeed3, wheelSpeed4);
  
  shield->sendAllData(vehicleSpeed);
}
