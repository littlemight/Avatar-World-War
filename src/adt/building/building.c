#include "building.h"
#include "../pcolor/pcolor.h"


boolean IsEQBuilding(Building B1, Building B2) {
    return (
        OwnerID(B1) == OwnerID(B2) &&
        Type(B1) == Type(B2) &&
        Level(B1) == Level(B2) &&
        Troop(B1) == Troop(B2) &&
        Regen(B1) == Regen(B2) &&
        MaxCap(B1) == MaxCap(B2) &&
        Defense(B1) == Defense(B2) &&
        IsEQPoint(Pos(B1), Pos(B2)) &&
        HasAttacked(B1) == HasAttacked(B2) &&
        HasMoved(B1) == HasMoved(B2)
    );
}

void MakeBaseProperty(Building *B, char Type, int Level, int A, int M, boolean P, int U) {
    OwnerID(*B) = 0;
    Type(*B) = Type;
    Level(*B) = Level;
    Regen(*B) = A;
    Defense(*B) = P;
    MaxCap(*B) = M;
    Troop(*B) = U;
    HasAttacked(*B) = false;
    HasMoved(*B) = false;
}

void MakeBuilding(Building *B, Building Base, int Owner, Point Pos, boolean HasAttacked, boolean HasMoved) {
    OwnerID(*B) = Owner;
    Type(*B) = Base.Type;
    Level(*B) = Base.Level;
    Troop(*B) = Base.Troop;
    Regen(*B) = Base.Regen;
    MaxCap(*B) = Base.MaxCap;
    Defense(*B) = Base.Defense;

    HasAttacked(*B) = HasAttacked;
    HasMoved(*B) = HasMoved;
    Pos(*B) = MakePoint(Row(Pos), Col(Pos));
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
            printf("Castle ");
            break;
        case 'T':
            printf("Tower  ");
            break;
        case 'F':
            printf("Fort   ");
            break;
        case 'V':
            printf("Village");
            break;
    }
}

void PrintBuilding(Building B) {
    PrintBuildingType(B);
    printf(" ");
    if (Row((B).Pos) < 10) printf(" ");
    TulisPoint((B).Pos); 
    if (Col((B).Pos) < 10) printf(" ");
    printf(" | Lv. %d |", Level(B)); 
    printf(" %d", Troop(B));
}

void SavePrintBuilding(FILE *file, Building B) {
    fprintf(file, "%d %c %d %d %d %d %d %d\n",
        OwnerID(B),
        Type(B), // dari tipe sama level bisa dapat Regen, MaxCap, Defense
        Row(Pos(B)), Col(Pos(B)),
        Level(B),
        Troop(B),
        HasAttacked(B),
        HasMoved(B)
    );
}

void CopyBuilding(Building Bin, Building *Bout) {
    OwnerID(*Bout) = OwnerID(Bin);
    Type(*Bout) = Type(Bin);
    Level(*Bout) = Level(Bin);
    Troop(*Bout) = Troop(Bin);
    Regen(*Bout) = Regen(Bin);
    MaxCap(*Bout) = MaxCap(Bin);
    Defense(*Bout) = Defense(Bin);
    CopyPoint(Pos(Bin), &Pos(*Bout));
    HasAttacked(*Bout) = HasAttacked(Bin);
}