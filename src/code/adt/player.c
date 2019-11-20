#include "../../header/adt/player.h"

void PCreateEmpty(Player *P) {
    KCreateEmpty(&Username(*P));
    LCreateEmpty(&Buildings(*P));
    QCreateEmpty(&Skills(*P), 10);
    PShield(*P) = PTurn(*P) = 0;
    PAttackUp(*P) = PCriticalHit(*P) = false;
}

void CopyPlayer(Player Pin, Player *Pout) {
    CopyKata(Username(Pin), &Username(*Pout));
    // PlayerID(*Pout) = PlayerID(Pin);
    CopySkills(Skills(Pin), &Skills(*Pout));
    CopyList(Buildings(Pin), &Buildings(*Pout));
    PShield(*Pout) = PShield(Pin);
    PTurn(*Pout) = PTurn(Pin);
    PAttackUp(*Pout) = PAttackUp(Pin);
    PCriticalHit(*Pout) = PCriticalHit(Pin);
    // printf("player success copy\n");
    return;
}

void SavePrintPlayer(FILE *file, Player P) {
    SavePrintKata(file, Username(P));
    SavePrintList(file, Buildings(P));
    SavePrintQueue(file, Skills(P));
    fprintf(file,  "%d\n", PShield(P));
    fprintf(file,  "%d\n", PTurn(P));
    fprintf(file,  "%d\n", PAttackUp(P));
    fprintf(file,  "%d\n", PCriticalHit(P));
}