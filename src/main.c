#include "adt/player/player.c"
#include "adt/building/building.c"
#include <stdio.h>

int main() {
  Player player1, player2;
  PlayerDataInput(&player1);
  PlayerDataInput(&player2);
  printf("halo halo saya adalah program main yang sederhana, masukkan n: \n");
  int n;
  scanf("%d", &n);
  boolean himpunan = (n == 135182);
  if (himpunan) {
    printf("moshi moshi hmif\n");
  } else printf("heh\n");
  return 0;
}