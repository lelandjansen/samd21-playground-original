// Copyright (C) 2012-2016 Atmel Corporation. All rights reserved.

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:

// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.

// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.

// 3. The name of Atmel may not be used to endorse or promote products derived
//    from this software without specific prior written permission.

// 4. This software may only be redistributed and used in connection with an
//    Atmel microcontroller product.

// THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
// EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
// ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#include "util/syscalls.h"

#include <stddef.h>
#include <sys/stat.h>

#include "util/unused.h"

extern void* _sbrk(int incr) {
  static unsigned char *heap = NULL;
  unsigned char *prev_heap;
  if (heap == NULL) {
    heap = (unsigned char*)&_end;
  }
  prev_heap = heap;
  heap += incr;
  return (void*)prev_heap;
}

extern int link(char* c_old, char* c_new) {
  UNUSED(c_old);
  UNUSED(c_new);
  return -1;
}

extern int _close(int file) {
  UNUSED(file);
  return -1;
}

extern int _isatty(int file) {
  UNUSED(file);
  return 1;
}

extern int _lseek(int file, int ptr, int dir) {
  UNUSED(file);
  UNUSED(ptr);
  UNUSED(dir);
  return 0;
}

extern void _exit(int status) {
  UNUSED(status);
  asm("BKPT #0"); // breakpoint
  for (;;);
}

extern void _kill(int pid, int sig) {
  UNUSED(pid);
  UNUSED(sig);
  return;
}

extern int _getpid(void) {
  return -1;
}

