#include "Controls.h"
#include "DataSendingControls.h"
#include "Non_CAN.h"
#include "TR_CAN_Shield_Wrapper.h"
#include "Math_Functions.h"

void DataSendingControls::doAction() {
  shield->sendAllData(0);
}
