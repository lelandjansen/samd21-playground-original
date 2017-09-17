#ifndef UITL_DELAY_H_
#define UTIL_DELAY_H_

#include <cstdint>

namespace util {

auto DelayInit() -> void;
auto DelayMilliseconds(uint32_t milliseconds) -> void;
auto DelayMicroseconds(uint32_t microseconds) -> void;
auto DelayClockCycles(uint32_t cycles) -> void;

}  // namespace util

#endif  // UTIL_DELAY_H_

