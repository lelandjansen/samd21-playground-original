#include "util/dynamic-memory.h"

auto operator new(std::size_t size, const std::nothrow_t& /*unused*/) noexcept
    -> void* {
  return malloc(size);  // NOLINT
}

auto operator delete(void* p) noexcept -> void {
  free(p);  // NOLINT
}

auto operator new[](std::size_t size, const std::nothrow_t& /*unused*/) noexcept
    -> void* {
  return operator new(size);
}

auto operator delete[](void* p /*unused*/) noexcept -> void {
  operator delete(p);
}

auto operator new(std::size_t size, std::nothrow_t /*unused*/) noexcept
    -> void* {
  return operator new(size);
}

auto operator delete(void* p, std::nothrow_t /*unused*/) noexcept -> void {
  operator delete(p);
}

auto operator delete(void* p, std::size_t /*unused*/) noexcept -> void {
  operator delete(p);
}

auto operator new[](size_t size, std::nothrow_t /*unused*/) noexcept -> void* {
  return operator new(size);
}

auto operator delete[](void* p, std::nothrow_t /*unused*/) noexcept -> void {
  operator delete(p);
}

auto operator delete[](void* p, std::size_t /*unused*/) noexcept -> void {
  operator delete(p);
}
