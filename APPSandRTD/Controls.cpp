#include "Controls.h"
#include "Non_CAN.h"
#include "TR_CAN_Shield_Wrapper.h"
#include "Math_Functions.h"

Controls::Controls() {
  shield = new TR_CAN_Shield_Wrapper(15, false);
}
