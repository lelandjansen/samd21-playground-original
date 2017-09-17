#ifndef SAMD21_SEGMENTS_H_
#define SAMD21_SEGMENTS_H_

#include <stdint.h>

extern uint32_t _sfixed;
extern uint32_t _efixed;
extern uint32_t _etext;
extern uint32_t _srelocate;
extern uint32_t _erelocate;
extern uint32_t _szero;
extern uint32_t _ezero;
extern uint32_t _sstack;
extern uint32_t _estack;

#endif  // SAMD21_SEGMENTS_H_

