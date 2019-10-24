#ifndef Building_H
#define Building_H

#include "../boolean/boolean.h"

#define MaxBuilding 9999;

typedef struct {
    int level;
    int playerNumber; // 0: ga dimiliki, 1: player 1, 2: player 2
    int nbTroops;
    int addTroops;
    int maxTroops; // ini perlu struct khusus
    boolean defense;
} Building;


#endif