#ifndef Utility_H
#define Utility_H
#include "utility.h"
#include <stdio.h>
#include <unistd.h>

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
  // #ifdef WINDOWS
  //     system("cls");
  // #else
  //     // Assume POSIX
  //     system ("clear");
  // #endif
  system("clear || cls");
}
#endif