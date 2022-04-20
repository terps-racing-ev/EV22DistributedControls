#include "Controls.h"
#include "Non_CAN.h"
#include "TR_CAN_Shield_Wrapper.h"
#include "Math_Functions.h"

Controls::Controls(int n) {
  shield = new TR_CAN_Shield_Wrapper(n, false);
}
