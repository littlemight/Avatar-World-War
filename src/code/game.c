#include "../header/coordinator.h"
#include <stdlib.h>
/** ================================================================================ **/

int main() {
  clear();
  MakeAllBase();
  STARTKATA("data/config.dat");
  LoadInit();
  TOSTDIN();

  // Kata filename;
  // printf("Masukkan nama file: ");
  // InputKata(&filename);
  // PrintKata(filename);
  // printf("\n");
  // char eff[50];
  // KataToArrChar(eff, filename);

  AvatarWW();
  return 0;
}