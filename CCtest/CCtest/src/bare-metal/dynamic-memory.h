#ifndef BARE_METAL_DYNAMIC_MEMORY_H_
#define BARE_METAL_DYNAMIC_MEMORY_H_

#include <cstdlib>
#include <new>

// resource for dynamic memory allocation:
// https://arobenko.gitbooks.io/bare_metal_cpp/content/compiler_output/dyn_mem.html

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

#endif // BARE_METAL_DYNAMIC_MEMORY_H_