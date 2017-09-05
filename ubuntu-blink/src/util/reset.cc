#include "reset.h"

#include "samd21/samd21j18a.h"
#include "wait.h"

namespace util {

auto SoftwareReset() -> void {
    GCLK->CTRL.reg = GCLK_CTRL_SWRST ;
	WAIT_UNTIL(((GCLK->CTRL.reg & GCLK_CTRL_SWRST) && (GCLK->STATUS.reg & GCLK_STATUS_SYNCBUSY)) == false);
}

}  // namespace util
