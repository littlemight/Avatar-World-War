#include "../boolean/boolean.h"
// #include "../array/array.h"
#include "../tower/tower.h"

typedef struct {
    char username[50];
    int nbtower; // jumlah tower yang dimiliki player
    int nbskill; // jumlah skill yang dimiliki player
    // Tower tower[maxtower + 1];
    // Skill skill[maxskill + 1];
} Player;