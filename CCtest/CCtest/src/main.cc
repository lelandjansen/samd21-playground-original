#include "sam.h"

#include <tuple>
#include <vector>
#include <cstdlib>
#include <memory>
#include <functional>

#include "setup.h"

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


namespace device {

class Led {
  public:
	Led() {
		// Set as output
		PORT->Group[1].DIRSET.reg = PORT_PB30;
		//REG_PORT_DIRSET1 = PORT_PB30;
		//alternately:
		//REG_PORT_DIR1 |= PORT_PB30;
		Off();
	}
	
	~Led() {
		Off();
	}
	
	auto On() const -> void {
		PORT->Group[1].OUTCLR.reg = PORT_PB30;
		//REG_PORT_OUTCLR1 = PORT_PB30;
		//alternatively:
		//REG_PORT_OUT1 &= ~PORT_PB30;
	}
	
	auto Off() const -> void {
		PORT->Group[1].OUTSET.reg = PORT_PB30;
		//REG_PORT_OUTSET1 = PORT_PB30;
		//alternatively:
		//REG_PORT_OUT1 |= PORT_PB30;
	}
	
	auto Toggle() const -> void {
		PORT->Group[1].OUTTGL.reg = PORT_PB30;

		//REG_PORT_OUTTGL1 = PORT_PB30;
		//alternatively:
		//REG_PORT_OUT1 ^= PORT_PB30;
	}	
};

class Button {
  public:
	Button() {
		// Set input with pull-up resistor
		//PORT->Group[0].PINCFG[15].reg = PORT_PINCFG_INEN | PORT_PINCFG_PULLEN;
		PORT->Group[0].PINCFG[15].bit.INEN = true;
		PORT->Group[0].PINCFG[15].bit.PULLEN = true;
		PORT->Group[0].OUTSET.reg = PORT_PA15;
		//REG_PORT_OUTSET0 = PORT_PA15;
	}
	
	auto IsPressed() const -> bool {
		return !(REG_PORT_IN0 & PORT_PA15);
	}
};

}  // namespace device

device::Led led;
device::Button button;

auto main() -> int {
    /* Initialize the SAM system */
    SystemInit();
	SetupClock();
	EnableExternalInterrupts();
	InitTC3();

	//while (true) {
		//button.IsPressed() ? led.On() : led.Off();
	//}
	
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
