#ifndef Player_H
#define Player_H

#include "../boolean/boolean.h"
// #include "../array/array.h"
#include "../building/building.h"

typedef struct {
    int playerNumber;
    char username[50];
    int nbBuilding; // jumlah tower yang dimiliki Player
    // Queue skill; // jumlah skill yang dimiliki Player
    // Tower tower[maxtower + 1];
} Player;

#define PlayerNumber(Player) (Player).playerNumber

void PlayerDataInput(Player *Player);

#endif