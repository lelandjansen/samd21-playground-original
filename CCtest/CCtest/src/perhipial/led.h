#ifndef PERHIPIAL_LED_H_
#define PERHIPIAL_LED_H_

#include <cstdint>

namespace perhipial {

class Led {
  public:
	Led(int32_t group, int32_t port);
	~Led();
	auto On() const -> void;
	auto Off() const -> void;
	auto Toggle() const -> void;
	
  private:
	auto SetAsOutput() const -> void;
	const uint32_t group_;
	const uint32_t port_;
};

}  // namespace perhipial

#endif // PERHIPIAL_LED_H_
