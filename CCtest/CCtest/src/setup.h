#ifndef SETUP_H_ 
#define SETUP_H_

// TODO: Can I do setup in the CC file if I wrap the library headers with this?
#ifdef __cplusplus
extern "C" {
#endif

#  define CONF_CLOCK_DFLL_MAX_COARSE_STEP_SIZE    (0x1f / 4)
#  define CONF_CLOCK_DFLL_MAX_FINE_STEP_SIZE      (0xff / 4)

void SetupClock(void);
void EnableExternalInterrupts(void);
void DisableExternalInterrupts(void);
void InitTC3(void);

#ifdef __cplusplus
}
#endif

#endif // SETUP_H_
