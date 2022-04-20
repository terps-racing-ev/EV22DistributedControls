#include "Controls.h"
#include "DataSendingControls.h"
#include "Non_CAN.h"
#include "TR_CAN_Shield_Wrapper.h"
#include "Math_Functions.h"

DataSendingControls::DataSendingControls(int n): Controls(n) {

}
void DataSendingControls::doAction() {
  shield->sendAllData(0);
}
