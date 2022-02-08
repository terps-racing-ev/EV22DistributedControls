
//slopes for voltage determined by graphs on EV22 ESF doc

float voltageToPercentTravelOne(float voltage){
  return voltage * 1.25 - 0.20;
}


float voltageToPercentTravelTwo(float voltage){
  return voltage * -1.2987 + 1.6753;
}


float calculateTorque(float percentTravel) {
  return 140 * percentTravel * percentTravel + 50 * percentTravel;
}
