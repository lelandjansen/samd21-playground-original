#ifndef UTIL_SYSCALLS_H_
#define UITL_SYSCALLS_H_

#ifdef __cplusplus
extern "C" {
#endif

extern int errno;
extern int _end;

extern void* _sbrk(int incr);
extern int link(char* c_old, char* c_new);
extern int _close(int file);
extern int _isatty(int file);
extern int _lseek(int file, int ptr, int dir);
extern void _exit(int status);
extern void _kill(int pid, int sig);
extern int _getpid(void);

#ifdef __cplusplus
}
#endif

#endif  // UTIL_SYSCALLS_H_

