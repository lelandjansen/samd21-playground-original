#ifndef UTIL_CLOCK_H_
#define UITL_CLOCK_H_

#include <cstdint>

namespace util {

const uint32_t kMainClockFrequency = 48000000; // Hz
const uint32_t kExternalOscillatorFrequency = 32768; // Hz

auto ClockInit() -> void;
	
}  // namespace util

#endif // UTIL_CLOCK_H_