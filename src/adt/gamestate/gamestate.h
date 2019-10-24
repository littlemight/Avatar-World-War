#include "../boolean/boolean.h"
#include "../player/player.h"
#include "../building/building.h"

typedef struct {
    Player currentPlayer1;
    Player currentPlayer2;
    Building currentBuilding;
} GameState;