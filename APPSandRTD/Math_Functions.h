#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H
/*
 * This file collects the various math functions we need.
 */

float voltageToPercentTravelOne(float voltage);


float voltageToPercentTravelTwo(float voltage);


float calculateTorque(float percentTravel);


int coolantTempTransfer(int in);

int calculateVehicleSpeed(int wheelOne, int wheelTwo, int wheelThree, int wheelFour);
#endif
