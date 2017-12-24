/*
 * helpers.h
 *
 * Created: 7/1/2014 9:12:44 AM
 *  Author: MRoszko
 */ 


#ifndef HELPERS_H_
#define HELPERS_H_

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))

#define BYTE0(x) (uint8_t)(x)
#define BYTE1(x) (uint8_t)(x >> 8)
#define BYTE2(x) (uint8_t)(x >> 16)
#define BYTE3(x) (uint8_t)(x >> 24)

#define LE_BYTES_TO_INT32(BUFF, OFFSET)	((BUFF[OFFSET+3] << 24) | (BUFF[OFFSET+2] << 16) | (BUFF[OFFSET+1] << 8) | BUFF[OFFSET])
#define LE_BYTES_TO_INT16(BUFF, OFFSET) ((BUFF[OFFSET+1] << 8)| BUFF[OFFSET])

#undef likely
#define likely(x)      __builtin_expect(!!(x), 1)
#undef unlikely
#define unlikely(x)    __builtin_expect(!!(x), 0)

#endif /* HELPERS_H_ */