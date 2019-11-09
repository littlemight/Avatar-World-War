#ifndef BUILDING_H
#define BUILDING_H

#include "boolean.h"
#include "point.h"
#include "player.h"

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
} Building;

#define OwnerID(P) (P).OwnerID
#define Type(P) (P).Type
#define Level(P) (P).Level
#define Troop(P) (P).Troop
#define Regen(P) (P).Regen
#define MaxCap(P) (P).MaxCap
#define Defense(P) (P).Defense
#define Pos(P) (P).Pos

Building CASTLE[5];
Building TOWER[5];
Building FORT[5];
Building VILLAGE[5];

void MakeBaseProperty(Building *B, char Type, int Level, int A, int M, boolean P, int U) {
  OwnerID(*B) = 0;
  Type(*B) = Type;
  Level(*B) = Level;
  Regen(*B) = A;
  Defense(*B) = P;
  MaxCap(*B) = M;
  Troop(*B) = U;
}

void MakeBuilding(Building *B, Building Base, int Owner, Point Pos) {
    OwnerID(*B) = Owner;
    Type(*B) = Base.Type;
    Level(*B) = Base.Level;
    Troop(*B) = Base.Troop;
    Regen(*B) = Base.Regen;
    MaxCap(*B) = Base.MaxCap;
    Defense(*B) = Base.Defense;

    Row(Pos(*B)) = Row(Pos);
    Col(Pos(*B)) = Col(Pos);
}

void ChangeBaseProperty(Building *B, Building Base) {
    Level(*B) = Base.Level;
    Regen(*B) = Base.Regen;
    MaxCap(*B) = Base.MaxCap;
    Defense(*B) = Base.Defense;
}

void MakeAllBase() {
    MakeBaseProperty(&CASTLE[1], 'C', 1, 10, 40, false, 40);
    MakeBaseProperty(&CASTLE[2], 'C', 2, 15, 60, false, 0);
    MakeBaseProperty(&CASTLE[3], 'C', 3, 20, 80, false, 0);
    MakeBaseProperty(&CASTLE[4], 'C', 4, 25, 100, false, 0);

    MakeBaseProperty(&TOWER[1], 'T', 1, 5, 20, true, 30);
    MakeBaseProperty(&TOWER[2], 'T', 2, 10, 30, true, 0);
    MakeBaseProperty(&TOWER[3], 'T', 3, 20, 40, true, 0);
    MakeBaseProperty(&TOWER[4], 'T', 4, 30, 50, true, 0);

    MakeBaseProperty(&FORT[1], 'F', 1, 10, 20, false, 80);
    MakeBaseProperty(&FORT[2], 'F', 2, 20, 40, false, 0);
    MakeBaseProperty(&FORT[3], 'F', 3, 30, 60, true, 0);
    MakeBaseProperty(&FORT[4], 'F', 4, 40, 80, true, 0);

    MakeBaseProperty(&VILLAGE[1], 'V', 1, 5, 20, false, 20);
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

void PrintBuildingType(Building B){
    switch (Type(B)) {
        case 'C':
            printf("Castle");
            break;
        case 'T':
            printf("Tower");
            break;
        case 'F':
            printf("Fort");
            break;
        case 'V':
            printf("Village");
            break;
    }
}

void PrintBuilding(Building B) {
    PrintBuildingType(B);
    printf(" Level %d. ", Level(B)); 
    if (Troop(B) <= 1) printf("Troop");
    else printf("Troops");
    printf(" ready: %d. ", Troop(B));
    printf("Position in map: "); 
    TulisPoint(B.Pos);
    // printf(" %d lv. %d", B.Troop, B.Level);
}




#endif