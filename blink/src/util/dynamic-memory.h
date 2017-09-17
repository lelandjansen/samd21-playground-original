#ifndef UTIL_DYNAMIC_MEMORY_H_
#define UTIL_DYNAMIC_MEMORY_H_

#include <cstdlib>
#include <new>

auto operator new(std::size_t size) noexcept -> void*;
auto operator delete(void* p) noexcept -> void;
auto operator new[](std::size_t size) noexcept -> void*;
auto operator delete[](void* p) noexcept -> void;
auto operator new(std::size_t size, std::nothrow_t) noexcept -> void*;
auto operator delete(void* p,  std::nothrow_t) noexcept -> void;
auto operator delete(void* p, std::size_t) noexcept -> void;
auto operator new[](std::size_t size, std::nothrow_t) noexcept -> void*;
auto operator delete[](void* p,  std::nothrow_t) noexcept -> void;
auto operator delete [](void* p, std::size_t) noexcept -> void;

#endif  // UTIL_DYNAMIC_MEMORY_H_

