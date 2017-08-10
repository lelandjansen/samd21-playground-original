#include "sam.h"
#include <tuple>
#include <vector>
#include <cstdlib>
#include <memory>
#include <functional>


// resource for dynamic memory allocation:
// https://arobenko.gitbooks.io/bare_metal_cpp/content/compiler_output/dyn_mem.html

void* operator new(size_t size) noexcept {
	return malloc(size);
}

void operator delete(void *p) noexcept {
	free(p);
}

void* operator new[](size_t size) noexcept {
	return operator new(size); // Same as regular new
}

void operator delete[](void *p) noexcept {
	operator delete(p); // Same as regular delete
}

void* operator new(size_t size, std::nothrow_t) noexcept {
	return operator new(size); // Same as regular new
}

void operator delete(void *p,  std::nothrow_t) noexcept {
	operator delete(p); // Same as regular delete
}

void* operator new[](size_t size, std::nothrow_t) noexcept {
	return operator new(size); // Same as regular new
}

void operator delete[](void *p,  std::nothrow_t) noexcept {
	operator delete(p); // Same as regular delete
}



auto main() -> int {
    /* Initialize the SAM system */
    SystemInit();
	
	auto v = std::vector<int>(10);
	v.push_back(1);
	
	auto t = new std::pair<int, int>(1, 2);
	t->second = t->first;
	delete t;
	
	auto func = []{
		auto nv = std::make_unique<std::vector<int>>(10);
		nv->push_back(12);
	};
	
	func();
	
	// exceptions disabled. this code should fail.
	// resource for exception handling: https://arobenko.gitbooks.io/bare_metal_cpp/content/compiler_output/exceptions.html
	// note that the standard library throws exceptions
	// throw std::runtime_error("Some error");
	
	// rtti: Run Time Type Information
	// this also has a large code size overhead. Can be disabled via -no-rtti
	// this means no dynamic_cast or typeid
	// resource: https://arobenko.gitbooks.io/bare_metal_cpp/content/compiler_output/rtti.html
	
	// disable thread safe statics:
	// -fno-threadsafe-statics
	// This is safe so long as interrups aren't enabled
	
	// if i choose to have abstract functions, might need to implement the delete operator
	// https://arobenko.gitbooks.io/bare_metal_cpp/content/compiler_output/abstract_classes.html

    while (true);
}
