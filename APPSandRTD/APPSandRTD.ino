#include <TR_CAN_Shield.h>
#include "TR_CAN_Shield_Wrapper.h"
#include "Non_CAN.h"
#include "Controls.h"
#include "APPSControls.h"
#include "DataSendingControls.h"
#include "VehicleSpeedCalcControls.h"
#include "TorqueTestControls.h"

TR_CAN_Shield canShield();

int sensor_value;
//TorqueTestControls* car;
Controls* car;
//LiquidCrystal lcd2(4, 6, 10, 11, 12, 13);
int board_type = 0;
int id = 0;
void setup() {
  Serial.begin(9600);
  if (board_type == 0)
  {
    car = new APPSControls(id);
  } else if (board_type == 1)
  {
    car = new DataSendingControls(id);
  } else if (board_type == 2)
  {
    car = new VehicleSpeedCalcControls(id);
  } else
  {
    car = new TorqueTestControls(id);
  }
  

}

void loop() {
  car->doAction();
}
