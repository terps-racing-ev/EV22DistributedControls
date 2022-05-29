#include "Controls.h"
#include "TorqueTestControls.h"
#include "Non_CAN.h"
#include "TR_CAN_Shield_Wrapper.h"
#include "Math_Functions.h"
#include <LiquidCrystal.h>
TorqueTestControls::TorqueTestControls(int n) : Controls(n){
  prevTime = millis();
  lcd = new LiquidCrystal(A0, A1, A2, A3, A4, A5);
  lcd->begin(16, 2);
  lcd->clear();
}
void TorqueTestControls::doAction() {
  shield->updateStoredTorque();
  torque = shield->getStoredTorque();
  String s = String(torque);
  Serial.println("received torque: " + s);
  unsigned long currTime = millis();
  if (currTime - prevTime > 200) {
    lcd->print(s + "  ");
    lcd->setCursor(0, 0);

    prevTime = currTime;
  }
}
