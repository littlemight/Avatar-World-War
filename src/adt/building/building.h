#ifndef _BUILDING_H
#define _BUILDING_H

#include "../boolean/boolean.h"
#include "../point/point.h"

typedef struct {
  int OwnerID;
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
  Point Pos;
  boolean HasAttacked;
  boolean HasMoved;
} Building;

#define OwnerID(P) (P).OwnerID
#define Type(P) (P).Type
#define Level(P) (P).Level
#define Troop(P) (P).Troop
#define Regen(P) (P).Regen
#define MaxCap(P) (P).MaxCap
#define Defense(P) (P).Defense
#define Pos(P) (P).Pos
#define HasAttacked(P) (P).HasAttacked
#define HasMoved(P) (P).HasMoved

boolean IsEQBuilding(Building B1, Building B2);
void MakeBaseProperty(Building *B, char Type, int Level, int A, int M, boolean P, int U);
void MakeBuilding(Building *B, Building Base, int Owner, Point Pos, boolean HasAttacked, boolean HasMoved);
void ChangeBaseProperty(Building *B, Building Base);
void PrintBuilding(Building B);
void PrintBuildingType(Building B);
void SavePrintBuilding(FILE *file, Building B); 
void CopyBuilding(Building Bin, Building *Bout);
#endif