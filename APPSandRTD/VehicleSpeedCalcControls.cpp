#include "Controls.h"
#include "VehicleSpeedCalcControls.h"
#include "Non_CAN.h"
#include "TR_CAN_Shield_Wrapper.h"
#include "Math_Functions.h"
#include <LiquidCrystal.h>
VehicleSpeedCalcControls::VehicleSpeedCalcControls(int n) : Controls(n){
  prevTime = millis();
  lcd = new LiquidCrystal(A0, A1, A2, A3, A4, A5);
  lcd->begin(16, 2);
  lcd->clear();
}
void VehicleSpeedCalcControls::doAction() {
  
  shield->updateStoredWheelSpeeds();
  wheelSpeed1 = shield->getWheelSpeed(1);
  wheelSpeed2 = shield->getWheelSpeed(2);
  wheelSpeed3 = shield->getWheelSpeed(3);
  wheelSpeed4 = readWheelSpeedSensor();
  
  int vehicleSpeed = calculateVehicleSpeed(wheelSpeed1, wheelSpeed2, wheelSpeed3, wheelSpeed4);

  String v = String(vehicleSpeed);
  unsigned long currTime = millis();
  if (currTime - prevTime > 200) {
    lcd->print(v + "  ");
    lcd->setCursor(0, 0);

    prevTime = currTime;
  }
  
  shield->sendAllData(vehicleSpeed);
}
