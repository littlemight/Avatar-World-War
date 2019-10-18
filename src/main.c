#include "adt/boolean/boolean.h"
#include <stdio.h>

int main() {
  printf("halo halo saya adalah program main yang sederhana, masukkan n: \n");
  int n;
  scanf("%d", &n);
  boolean himpunan = (n == 135182);
  if (himpunan) {
    printf("moshi moshi hmif\n");
  } else printf("heh\n");
  return 0;
}