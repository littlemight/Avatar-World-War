#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../utility/utility.h"

void LineBr() {
  printf("--------------------------------------------------\n");
}

void PrintCWD() {
  // CWD : Current Working Directory
  // nge print CWD .exe yang dijalanin, biar tau .exe nya dijalanin dimana
  char cwd[255];
  getcwd(cwd, sizeof(cwd));
  printf(">>> CWD : %s\n", cwd);
}

void clear()
{
  system("clear || cls");
}