#include <tuple>
#include <vector>
#include <cstdlib>
#include <memory>
#include <functional>
#include <cstdint>

#include "bare-metal/dynamic-memory.h"
#include "sam.h"
#include "perhipial/button/sw0.h"
#include "perhipial/led/led0.h"
#include "perhipial/led/io1-led.h"
#include "perhipial/led/led-green.h"
#include "perhipial/led/led-blue.h"
#include "perhipial/led/led-red.h"
#include "util/clock.h"
#include "util/delay.h"

auto main() -> int {
	util::ClockInit();
	util::DelayInit();
	//EnableExternalInterrupts();
	//InitTC3();

  perhipial::Led0 led0;
  //perhipial::LedRed red;
  perhipial::LedGreen green;
  //perhipial::LedBlue blue;
  perhipial::Io1Led io1_led;
  perhipial::Sw0 button;

	//while (true) {
		//button.IsPressed() ? led1.On() : led1.Off();
	//}

  led0.Toggle();  
  while (true) {
		led0.Toggle();
    io1_led.Toggle();
    util::DelayMilliseconds(1000);
	}
	
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
	// This is safe so long as interrupts aren't enabled
	
	// if i choose to have abstract functions, might need to implement the delete operator
	// https://arobenko.gitbooks.io/bare_metal_cpp/content/compiler_output/abstract_classes.html
}
