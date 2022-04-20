#include <math.h>
#include <Arduino.h>
#include "Math_Functions.h"

//slopes for voltage determined by graphs on EV22 ESF doc

float voltageToPercentTravelOne(float voltage){

  voltage = (voltage*5.0/1023.0) - 2.52;
  //String v = String(voltage);
  //Serial.print("voltage:" + v);
  //Serial.print("\t");

  return voltage * 1.0/0.64;
}


float voltageToPercentTravelTwo(float voltage){
  voltage = (voltage*5.0/1023.0) - 2.56;
  String v = String(voltage);
  Serial.print("voltage:" + v);
  Serial.print("\t");

  return voltage * -1.0/0.57;
}


float calculateTorque(float percentTravel) {
  return 140 * percentTravel * percentTravel + 50 * percentTravel;
}

int coolantTempTransfer(int in) {
  double trans = 0;
  double coeff[7] = {317, -435, 463, -280, 90.5, -14.7, 0.941};
  for (int deg = 0; deg <= 6; deg++) {
    trans += pow(in, deg) * coeff[deg];
  }
  return round(trans);
}

//placeholder
int calculateVehicleSpeed(int wheelOne, int wheelTwo, int wheelThree) {
  return 0;
}
