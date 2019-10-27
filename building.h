#ifndef BUILDING_H
#define BUILDING_H

#include <bits/stdc++.h>
#include "boolean.h"
#include "point.h"
using namespace std;

Building CASTLE[5];
Building TOWER[5];
Building FORT[5];
Building VILLAGE[5];

typedef struct {
  int Owner;
  /**
   * 0 : Ga punya siapa-siapa
   * 1 : Punya Player 1
   * 2 : Punya Player 2
   * */

  char Type;
  int Level;
  int Troop;
  int Regen;
  int MaxCap; /** If Troop >= MaxCap, dont regen **/
  boolean Defense;
  POINT Pos;

  int ID; // Indeks dia di array of building
} Building;

void MakeBaseProperty(Building *B, char Type, int Level, int A, int M, boolean P, int U) {
  (*B).Owner = 0;
  (*B).Type = Type;
  (*B).Level = Level;
  (*B).Regen = A;
  (*B).Defense = P;
  (*B).MaxCap = M;
  (*B).Troop = U;
}

void MakeBuilding(Building *B, Building Base, int Owner, POINT Pos, int ID) {
  (*B).Owner = Owner;
  (*B).Type = Base.Type;
  (*B).Level = Base.Level;
  (*B).Troop = Base.Troop;
  (*B).Regen = Base.Regen;
  (*B).MaxCap = Base.MaxCap;
  (*B).Defense = Base.Defense;
  (*B).ID = ID;

  Absis((*B).Pos) = Absis(Pos);
  Ordinat((*B).Pos) = Ordinat(Pos);
}

void ChangeBaseProperty(Building *B, Building Base) {
  (*B).Level = Base.Level;
  (*B).Regen = Base.Regen;
  (*B).MaxCap = Base.MaxCap;
  (*B).Defense = Base.Defense;
}

void MakeAllBase() {
  MakeBaseProperty(&CASTLE[1], 'C', 1, 10, 40, false, 40);
  MakeBaseProperty(&CASTLE[2], 'C', 2, 15, 60, false, 0);
  MakeBaseProperty(&CASTLE[3], 'C', 3, 20, 80, false, 0);
  MakeBaseProperty(&CASTLE[4], 'C', 4, 25, 100, false, 0);

  MakeBaseProperty(&TOWER[1], 'T', 1, 5, 20, true, 40);
  MakeBaseProperty(&TOWER[2], 'T', 2, 10, 30, true, 0);
  MakeBaseProperty(&TOWER[3], 'T', 3, 20, 40, true, 0);
  MakeBaseProperty(&TOWER[4], 'T', 4, 30, 50, true, 0);

  MakeBaseProperty(&FORT[1], 'F', 1, 10, 20, false, 40);
  MakeBaseProperty(&FORT[2], 'F', 2, 20, 40, false, 0);
  MakeBaseProperty(&FORT[3], 'F', 3, 30, 60, true, 0);
  MakeBaseProperty(&FORT[4], 'F', 4, 40, 80, true, 0);

  MakeBaseProperty(&VILLAGE[1], 'V', 1, 5, 20, false, 40);
  MakeBaseProperty(&VILLAGE[2], 'V', 2, 10, 30, false, 0);
  MakeBaseProperty(&VILLAGE[3], 'V', 3, 15, 40, false, 0);
  MakeBaseProperty(&VILLAGE[4], 'V', 4, 20, 50, false, 0);
}

Building GetBase(Building B, int Level) {
  Building ret;
  switch (B.Type) {
    case 'C':
      ret = CASTLE[Level];
      break;
    case 'T':
      ret = TOWER[Level];
      break;
    case 'F':
      ret = FORT[Level];
      break;
    case 'V':
      ret = VILLAGE[Level];
      break;      
  }
  return ret;
}
#endif