#ifndef __COMMON_H__
#define __COMMON_H__

#define CAT_(a, b) a##b
#define CAT(a, b)  CAT_(a, b)

#define RESERVED(from, to) uint8_t CAT(reserved_, __LINE__)[(to) - (from)]

#define __IO volatile

#endif  // __COMMON_H__
