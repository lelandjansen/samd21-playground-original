#ifndef UTIL_WAIT_H_
#define UTIL_WAIT_H_

// Using a lambda because 
// #define WAIT_UNTIL(expression) while (!expression)
// will still compile if the simicolon is forgotten but will produce an 
// unexpected runtime error.
#ifdef __cplusplus
#define WAIT_UNTIL(expression) [&]{ while (!(expression)); }()
#define WAIT_WHILE(expression) [&]{ while (expression); }()
#endif

#endif // UTIL_WAIT_H_
