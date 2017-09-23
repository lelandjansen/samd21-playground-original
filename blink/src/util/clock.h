#ifndef UTIL_CLOCK_H_
#define UTIL_CLOCK_H_

#include <cstdint>

namespace util {

const uint32_t kMainClockFrequencyHz = 48000000;
const uint32_t kExternalOscillatorFrequencyHz = 32768;

auto ClockInit() -> void;
	
}  // namespace util

#endif  // UTIL_CLOCK_H_

