#include "util/delay.h"

#include <cstdint>

#include "samd21/samd21.h"
#include "util/wait.h"
#include "util/clock.h"

namespace util {

namespace {

const uint32_t kClockCyclesPerMillisecond = 
    kMainClockFrequencyHz / static_cast<uint32_t>(1000);
const uint32_t kClockCyclesPerMicrosecond = 
    kMainClockFrequencyHz / static_cast<uint32_t>(1000000);

}  // namespace

auto DelayInit() -> void {
	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;
}

auto DelayMilliseconds(const uint32_t milliseconds) -> void {
  for (uint32_t millisecond = 0; millisecond < milliseconds; ++millisecond) {
		DelayClockCycles(kClockCyclesPerMillisecond);
	}
}

auto DelayMicroseconds(const uint32_t microseconds) -> void {
  for (uint32_t microsecond = 0; microsecond < microseconds; ++microsecond) {
		DelayClockCycles(kClockCyclesPerMicrosecond);
	}
}

auto DelayClockCycles(const uint32_t clock_cycles) -> void {
	if (clock_cycles == 0) return;
	SysTick->LOAD = clock_cycles;
	SysTick->VAL = 0;
	WAIT_UNTIL((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) != 0);
}

}  // namespace util

