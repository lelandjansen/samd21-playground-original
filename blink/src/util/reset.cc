#include "util/reset.h"

#include "samd21/samd21.h"
#include "util/wait.h"

namespace util {

auto SoftwareReset() -> void {
  GCLK->CTRL.reg = GCLK_CTRL_SWRST;
	WAIT_WHILE((GCLK->CTRL.reg & GCLK_CTRL_SWRST) &&
             (GCLK->STATUS.reg & GCLK_STATUS_SYNCBUSY));
}

}  // namespace util

