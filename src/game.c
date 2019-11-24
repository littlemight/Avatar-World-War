#include "coordinator/coordinator.h"
#include <stdlib.h>
#include <string.h>

void PrintPick() {
  red();
  printf("........................&*#,.                 .(#*..........................\n");
  printf("........................&*#,.  W E L C O M E   .(#*..........................\n");
  printf("....................&&&**##.                  .(##*&&&......................\n");
  printf("................&**####(/*,.       T  O         .*/(#####*&&.................\n");
  normal();
  blue();
  printf("..............&*#/,,...                             ...,,(*&................\n");
  printf("..............&*#/,..      A   V   A   T   A   R      .,,#*&................\n");
  printf("................&*#(,.                              ..,##*&.................\n");
  printf("..................&*##,.                          ../##*&...................\n");
  printf(".. "); yellow(); printf("1. S T A R T"); blue(); printf(" .....*##,..  W   O   R   L   D  ..(##&&.....................\n");
  printf("......................&*##*..                  ,(#*&........................\n");
  printf("..... "); yellow(); printf("2. L O A D"); blue(); printf(" ........&*#(..             .,##*&..........................\n");
  printf("...........................&*##.. W  A  R .,##*&............................\n");
  printf("....... "); yellow(); printf("3. E X I T"); blue(); printf(" .........&*##,.    ..,##*&..............................\n");
  printf("...............................&*##*..,/##*&................................\n");
  printf("..................................&*###*&...................................\n");
  normal();
}

void print_image(FILE *fptr)
{
    char read_string[128];
    red();
    printf("%c", 201);
    for (int i = 2; i <= 120; i++) {
      printf("%c", 205);
    }
    printf("%c", 187);
    red();
    printf("\n");
    while(fgets(read_string,sizeof(read_string),fptr) != NULL) {
      int len = strlen(read_string);
      red(); printf("%c", 186); normal();
      read_string[len - 1] = 0;
      blue();
      printf("%s",read_string);
      normal();
      red(); printf("%c", 186); normal();
      printf("\n");
    }
    red();
    printf("%c", 200);
    for (int i = 2; i <= 120; i++) {
      printf("%c", 205);
    }
    printf("%c", 188);
    normal();
    printf("\n");
}

void PrintLogo() {
  char *filename = "data/image.txt";
  FILE *fptr = NULL;

  if((fptr = fopen(filename,"r")) == NULL)
  {
      fprintf(stderr,"error opening %s\n",filename);
      return;
  }
 
  print_image(fptr);
 
  fclose(fptr);
}


int main() {
  clear();
  MakeAllBase();
  InitKamusSkill();

  STARTKATA(0);
  PrintLogo();
  ADV();
  clear();

  char cmd[50];
  // Input Main Menu
  do {
    Kata inp;
    clear();
    PrintPick();
    printf("\t\t\t   >       ");
    InputKata(&inp);
    KataToArrChar(inp, cmd);
    if (IsStrEQ(cmd, "START")) {
      STARTKATA("data/config.dat");
      LoadInit();
      TOSTDIN();
      clear();
      StartGame();
    } else if (IsStrEQ(cmd, "LOAD")) {
      clear();
      if (Load() == 0) {
        DoGame();
      } else {
        printf("Load failed\n");
      }
    } else if (IsStrEQ(cmd, "EXIT")) {
      printf("So long...");
    } else {
      magenta(); printf("\t\t\t   >       INVALID\n"); normal();
      ADV();
    }
  } while (!IsStrEQ(cmd, "EXIT"));

  return 0;
}