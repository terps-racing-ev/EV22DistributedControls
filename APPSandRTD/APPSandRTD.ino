#include <TR_CAN_Shield.h>
#include "TR_CAN_Shield_Wrapper.h"
#include "Non_CAN.h"
#include "Controls.h"

TR_CAN_Shield canShield();

int sensor_value;
Controls* car;

void setup() {
  Serial.begin(9600);
  Serial.print("started");
  //buzzer
  pinMode(9, OUTPUT);
  //input buttons for testing
  pinMode(2, INPUT);
  pinMode(7, INPUT);
  car = new Controls();

}

void loop() {
  car->doAction();
}
