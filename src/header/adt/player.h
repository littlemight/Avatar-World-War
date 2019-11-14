#ifndef _PLAYER_H
#define _PLAYER_H

#include "boolean.h"
#include "listlinier.h"
#include "queue.h"

typedef struct {
  Kata Username;
  int PlayerID; // 1 itu player1, 2 itu player2
  List Buildings;
  Queue Skills; // queue of skill yang dimiliki
  int PShield;
  int PTurn;
  boolean PAttackUp;
  boolean PCriticalHit;
} Player;

#define Username(P) (P).Username
#define PlayerID(P) (P).PlayerID
#define Buildings(P) (P).Buildings
#define Skills(P) (P).Skills
#define PShield(P) (P).PShield
#define PTurn(P) (P).PTurn
#define PAttackUp(P) (P).PAttackUp
#define PCriticalHit(P) (P).PCriticalHit

#endif