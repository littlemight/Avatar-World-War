#include "../boolean/boolean.h"

#define MaxTower 9999;

typedef struct {
    int level;
    Player user;
    int nbTroops;
    int addTroops;
    int maxTroops; // ini perlu struct khusus
    boolean defense;
} Tower;