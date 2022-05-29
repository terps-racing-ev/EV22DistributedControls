#include <TR_CAN_Shield.h>
#include "TR_CAN_Shield_Wrapper.h"
#include "Non_CAN.h"
#include "Controls.h"
#include "APPSControls.h"
#include "TorqueTestControls.h"

TR_CAN_Shield canShield();

int sensor_value;
TorqueTestControls* car;
//APPSControls* car;
//LiquidCrystal lcd2(4, 6, 10, 11, 12, 13);
void setup() {
  Serial.flush();
  Serial.begin(9600);
  //Serial.print("Voltage, Calculated Travel, Calculated Torque\n");
  //buzzer
  car = new TorqueTestControls(1);
  
  //lcd2.begin(16, 2);
  //lcd2.clear();
  //lcd2.print("hello");
  //delay(250);
  //lcd2.clear();
  //car = new APPSControls(0);

}

void loop() {
  car->doAction();
}
