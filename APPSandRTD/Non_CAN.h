#ifndef NON_CAN_H
#define NON_CAN_H
#include <Arduino.h>
#include "TR_CAN_Shield_Wrapper.h"

/*
 * Functions to read the  different inputs that don't use information sent over CAN.
 * Right now the content  these functions is just a placeholder.
 */

float readBrakeVoltage();

float readAPPSOne(TR_CAN_Shield* shield);

float readAPPSTwo(TR_CAN_Shield* shield);

bool ignitionOn(TR_CAN_Shield* shield);

int getSteeringAngle(TR_CAN_Shield* shield);

int getCoolantTemp(TR_CAN_Shield* shield);

int getSuspensionTravel(TR_CAN_Shield* shield);

const int PULSES_PER_ROTATION = 60;
int readWheelSpeedSensor(TR_CAN_Shield* shield);

void playBuzzer();
#endif
