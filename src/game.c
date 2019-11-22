#include "coordinator/coordinator.h"
#include <stdlib.h>

void PrintLogo() {
  printf("%s", RED);
  printf("........................&*#,.                 .(#*..........................\n");
  printf("........................&*#,.  W E L C O M E   .(#*..........................\n");
  printf("....................&&&**##.                  .(##*&&&......................\n");
  printf("................&**####(/*,.       T  O         .*/(#####*&&.................\n");
  printf("%s", NORMAL);
  printf("%s", BLUE);
  printf("..............&*#/,,...                             ...,,(*&................\n");
  printf("..............&*#/,..      A   V   A   T   A   R      .,,#*&................\n");
  printf("................&*#(,.                              ..,##*&.................\n");
  printf("..................&*##,.                          ../##*&...................\n");
  printf(".. "); printf("%s", YELLOW); printf("1. S T A R T"); printf("%s", BLUE); printf(" .....*##,..  W   O   R   L   D  ..(##&&.....................\n");
  printf("......................&*##*..                  ,(#*&........................\n");
  printf("..... "); printf("%s", YELLOW); printf("2. L O A D"); printf("%s", BLUE); printf(" ........&*#(..             .,##*&..........................\n");
  printf("...........................&*##.. W  A  R .,##*&............................\n");
  printf("....... "); printf("%s", YELLOW); printf("3. E X I T"); printf("%s", BLUE); printf(" .........&*##,.    ..,##*&..............................\n");
  printf("...............................&*##*..,/##*&................................\n");
  printf("..................................&*###*&...................................\n");
  printf("%s", NORMAL);
}

int main() {
  clear();
  MakeAllBase();
  InitKamusSkill();

  STARTKATA(0);
  char cmd[50];
  do {
    Kata inp;
    clear();
    PrintLogo();
    printf(">>> ");
    InputKata(&inp);
    KataToArrChar(inp, cmd);
    if (IsStrEQ(cmd, "START")) {
      STARTKATA("data/config.dat");
      LoadInit();
      TOSTDIN();
      clear();
      StartGame();
    } else if (IsStrEQ(cmd, "LOAD")) {
      if (Load() == 0) {
        DoGame();
      } else {
        printf("Load failed\n");
      }
    } else if (IsStrEQ(cmd, "EXIT")) {
      printf("So long...");
    } else {
      printf("%s", MAGENTA); printf("INVALID\n"); printf("%s", NORMAL);
      ADV();
    }
  } while (!IsStrEQ(cmd, "EXIT"));

  return 0;
}