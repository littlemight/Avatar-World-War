#include "player.h"
#include <stdio.h>

void PCreateEmpty(Player *P) {
    KCreateEmpty(&Username(*P));
    LCreateEmpty(&Buildings(*P));
    QCreateEmpty(&Skills(*P), 10);
    PShield(*P) = PTurn(*P) = 0;
    PAttackUp(*P) = PCriticalHit(*P) = false;
}

void CopyPlayer(Player Pin, Player *Pout) {
    PCreateEmpty(Pout); 
    CopyKata(Username(Pin), &Username(*Pout));
    CopySkills(Skills(Pin), &Skills(*Pout));
    CopyList(Buildings(Pin), &Buildings(*Pout));
    PShield(*Pout) = PShield(Pin);
    PTurn(*Pout) = PTurn(Pin);
    PAttackUp(*Pout) = PAttackUp(Pin);
    PCriticalHit(*Pout) = PCriticalHit(Pin);
}

void SavePrintPlayer(FILE *file, Player P) {
    SavePrintKata(file, Username(P));
    fprintf(file, "\n");
    SavePrintList(file, Buildings(P));
    SavePrintQueue(file, Skills(P));
    fprintf(file, "%d %d %d %d\n", PShield(P), PTurn(P), PAttackUp(P), PCriticalHit(P));
}