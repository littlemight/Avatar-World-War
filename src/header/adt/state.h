#ifndef _STATE_H
#define _STATE_H

#include "arraydin.h"
#include "matrix.h"
#include "graph.h"
#include "player.h"

typedef struct {
    TabBuilding ArrBuilding; // copy function done
    Matrix Peta; // copy done aman
    Graph G; // copy graph aman
    Player P[3]; // copy player aman
    int PlayerID; // aman
} State;

#define ArrBuilding(S) (S).ArrBuilding
#define Peta(S) (S).Peta
#define G(S) (S).G
#define P(S) (S).P
#define CurPlayerID(S) (S).PlayerID

void MakeState(TabBuilding InpArr, Matrix InpPeta, Graph InpG, Player P[3], int PlayerID, State *S);
void PrintState(State S);
void CopyState(State Sin, State *Sout);

#endif