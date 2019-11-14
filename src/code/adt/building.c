#include "../../header/adt/building.h"

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
    TulisPoint((B).Pos);
    // printf(" %d lv. %d", B.Troop, B.Level);
}