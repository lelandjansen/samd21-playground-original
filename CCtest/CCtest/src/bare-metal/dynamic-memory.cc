#include "dynamic-memory.h"

// resource for dynamic memory allocation:
// https://arobenko.gitbooks.io/bare_metal_cpp/content/compiler_output/dyn_mem.html

auto operator new(std::size_t size, const std::nothrow_t&) noexcept -> void* {
	return malloc(size);
}

auto operator delete(void* p) noexcept -> void {
	free(p);
}

auto operator new[](std::size_t size, const std::nothrow_t&) noexcept -> void* {
	return operator new(size);
}

auto operator delete[](void* p) noexcept -> void {
	operator delete(p);
}

auto operator new(std::size_t size, std::nothrow_t) noexcept -> void* {
	return operator new(size);
}

auto operator delete(void* p,  std::nothrow_t) noexcept -> void {
	operator delete(p);
}

auto operator delete(void* p, std::size_t) noexcept -> void {
	operator delete(p);
}

auto operator new[](size_t size, std::nothrow_t) noexcept -> void* {
	return operator new(size);
}

auto operator delete[](void* p,  std::nothrow_t) noexcept -> void {
	operator delete(p);
}

auto operator delete [](void* p, std::size_t) noexcept -> void {
	operator delete(p);
}
