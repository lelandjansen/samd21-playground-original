#include "delay.h"

#include "samd21/samd21.h"

auto Delay(int n) -> void {
  int i;
  for (; n >0; n--) {
    for (i=0; i<100; ++i) {
      __asm("nop");
    }
  }
}

