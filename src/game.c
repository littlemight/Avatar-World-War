#include "coordinator/coordinator.h"
#include <stdlib.h>

void PrintMenu() {
  printf("1. start\n");
  printf("2. load\n");
  printf("3. exit\n");
}

int main() {
  clear();
  MakeAllBase();
  InitKamusSkill();

  STARTKATA(0);
  int inp;
  do {
    clear();
    PrintMenu();
    printf(">>> ");
    InputInt(&inp);
    switch (inp) {
    case 1:
      STARTKATA("data/config.dat");
      LoadInit();
      TOSTDIN();
      StartGame();
      break;
    case 2:
      if (Load() == 0) {
        DoGame();
      } else {
        printf("Load failed\n");
      }
      break;
    case 3:
      printf("bye\n");
      break;
    default:
      printf("invalid input\n");
    }
  } while (inp != 3);

  return 0;
}