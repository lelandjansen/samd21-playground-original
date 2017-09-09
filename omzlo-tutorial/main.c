#include <samd21.h>

void delay(int n) {
  int i;
  for (; n >0; n--) {
    for (i=0; i<100; ++i) {
      __asm("nop");
    }
  }
}

int main() {
  PORT->Group[1].DIRSET.reg = PORT_PB30;
  // REG_PORT_DIR0 |= (1<<27);
  while (1) {
    PORT->Group[1].OUTCLR.reg = PORT_PB30;
    // REG_PORT_OUT0 &= ~(1<<27);
    delay(500);
    PORT->Group[1].OUTSET.reg = PORT_PB30;
    // REG_PORT_OUT0 |= (1<<27);
    delay(500);
  }
}
