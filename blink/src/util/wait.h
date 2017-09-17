#ifndef UTIL_WAIT_H_
#define UTIL_WAIT_H_

// Using a lambda because while (expression) will still compile if the simicolon
// is forgotten and produce an unexpected runtime error because loops without
// braces include the first statement.
#ifdef __cplusplus
#define WAIT_UNTIL(expression) [&]{ while (!(expression)); }()
#define WAIT_WHILE(expression) [&]{ while (expression); }()
#endif

#endif  // UTIL_WAIT_H_

