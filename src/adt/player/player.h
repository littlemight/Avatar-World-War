#ifndef _PLAYER_H
#define _PLAYER_H

#include "../boolean/boolean.h"
#include "../listlinier/listlinier.h"
#include "../queue/queue.h"

typedef struct {
  Kata Username; // copy udah
  // int PlayerID; // 1 itu player1, 2 itu player2
  List Buildings; // udh bikin copy sama free
  Queue Skills; // copy bismillah
  int PShield;
  int PTurn;
  boolean PAttackUp;
  boolean PCriticalHit;
} Player;

#define Username(P) (P).Username
// #define PlayerID(P) (P).PlayerID
#define Buildings(P) (P).Buildings
#define Skills(P) (P).Skills
#define PShield(P) (P).PShield
#define PTurn(P) (P).PTurn
#define PAttackUp(P) (P).PAttackUp
#define PCriticalHit(P) (P).PCriticalHit

void PCreateEmpty(Player *P);
void CopyPlayer(Player Pin, Player *Pout);
void SavePrintPlayer(FILE *file, Player P);

#endif