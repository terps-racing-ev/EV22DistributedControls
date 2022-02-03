
//slopes for voltage determined by graphs on EV22 ESF doc

float voltageToPercentTravelOne(float voltage){
  return voltage * 125 - 20;
}


float voltageToPercentTravelTwo(float voltage){
  return voltage * -129.87 + 167.53;
}
