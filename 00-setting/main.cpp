#include <stdio.h>

#include "game/game.h"

#if defined(__clang__)
#define _name "__clang__"
#else
#define _name "__msvc__"
#endif
int main(int args, char *argv[]) {
  int ad = 100;

  uintptr_t v = 100;

  printf("i like %s and game name : %s\n", _name, game::get_name());
  return 0;
}