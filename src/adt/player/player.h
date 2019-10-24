#ifndef PLAYER_H
#define PLAYER_H

#include "../boolean/boolean.h"
// #include "../array/array.h"
#include "../building/building.h"

typedef struct {
    int playerNumber;
    char username[50];
    int nbBuilding; // jumlah tower yang dimiliki player
    // Queue skill; // jumlah skill yang dimiliki player
    // Tower tower[maxtower + 1];
} Player;

#endif