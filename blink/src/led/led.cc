#include "led.h"

#include "samd21/samd21.h"

namespace led {

auto SetOutput() -> void {
  PORT->Group[1].DIRSET.reg = PORT_PB30;
}

auto On() -> void {
  PORT->Group[1].OUTCLR.reg = PORT_PB30;
}

auto Off() -> void {
  PORT->Group[1].OUTSET.reg = PORT_PB30;
}

}  // namespace led

