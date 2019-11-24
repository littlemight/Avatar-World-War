#ifndef _STATE_H
#define _STATE_H

#include "../arraydin/arraydin.h"
#include "../matrix/matrix.h"
#include "../graph/graph.h"
#include "../player/player.h"

typedef struct {
    TabBuilding ArrBuilding;
    Player P[3];
    int PlayerID;
} State;

#define ArrBuilding(S) (S).ArrBuilding
#define P(S, i) (S).P[(i)]
#define CurPlayerID(S) (S).PlayerID

void CreateEmptyState(State *S);
void MakeState(TabBuilding InpArr, Player P[3], int PlayerID, State *S);
void PrintState(State S);
void CopyState(State Sin, State *Sout);
void SavePrintState(FILE *file, State S, Matrix M);

#endif