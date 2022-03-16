#ifndef MATH_FUNCTIONS
#define MATH_FUNCTIONS
/*
 * This file collects the various math functions we need.
 */

float voltageToPercentTravelOne(float voltage);


float voltageToPercentTravelTwo(float voltage);


float calculateTorque(float percentTravel);


int coolantTempTransfer(int in);

int calculateVehicleSpeed(int wheelOne, int wheelTwo, int wheelThree);
#endif
