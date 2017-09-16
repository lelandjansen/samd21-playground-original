#include "delay.h"

#include <cstdint>

#include "samd21/samd21j18a.h"
#include "wait.h"
#include "clock.h"

namespace util {

namespace {
const uint32_t kClockCyclesPerMillisecond = kMainClockFrequency / 1000ul;
const uint32_t kClockCyclesPerMicrosecond = kMainClockFrequency / 1000000ul;
}

auto DelayInit() -> void {
	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;
}

auto DelayMilliseconds(uint32_t milliseconds) -> void {
	while (milliseconds--) {
		DelayClockCycles(kClockCyclesPerMillisecond);
	}
}

auto DelayMicroseconds(uint32_t microseconds) -> void {
	while (microseconds--) {
		DelayClockCycles(kClockCyclesPerMicrosecond);
	}
}

auto DelayClockCycles(uint32_t clock_cycles) -> void {
	if (clock_cycles == 0) return;
	SysTick->LOAD = clock_cycles;
	SysTick->VAL = 0;
	WAIT_UNTIL((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) != 0);
}

}  // namespace util
