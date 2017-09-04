#include "lib/add.h"

auto main() -> int {
  auto b = Add(1, 2);
  b += 2;
  (void)b;
  return 0;
}

