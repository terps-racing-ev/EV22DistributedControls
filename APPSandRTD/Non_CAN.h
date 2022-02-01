#ifndef NON_CAN
#define NON_CAN
#include <Arduino.h>

/*
 * Functions to read the  different inputs that don't use information sent over CAN.
 * Right now the content  these functions is just a placeholder.
 */

float readBrakeVoltage();

float readAPPS3V();

float readAPPS5V();

bool ignitionOn();

bool shutdownSignal();

void playBuzzer();
#endif
