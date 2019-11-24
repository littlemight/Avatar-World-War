#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../utility/utility.h"

void LineBr() {
  printf("--------------------------------------------------\n");
}

void PrintCWD() {
  // CWD : Current Working Directory
  char cwd[255];
  getcwd(cwd, sizeof(cwd));
  printf(">>> CWD : %s\n", cwd);
}

// Utility function to clear the screen for better viewing
void clear()
{
  system("clear || cls");
}