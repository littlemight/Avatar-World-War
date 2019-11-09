#include "mesinkata.h"
#include "coordinator.h"
/** ================================================================================ **/

int main() {
  clear();
  MakeAllBase();
  STARTKATA(NULL);

  STARTKATA("config.dat");
  LoadInit();
  ADV();
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