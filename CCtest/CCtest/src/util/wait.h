#ifndef UTIL_WAIT_H_
#define UTIL_WAIT_H_

// WAIT_UNTIL translates to a lambda because using the macro but forgetting the semicolon
// will compile and cause a weird runtime error.
#ifdef __cplusplus
#define WAIT_UNTIL(expression) [&]{ while (!(expression)); }()
#endif

#endif // UTIL_WAIT_H_
