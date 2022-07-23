#include <hpgcc49.h> // dont worry, compatible with HP 39gs

int main(void) {
  clear_screen();
  printf("Hello From Lobakkang");
  while (!keyb_isON());
  return 0;
}
