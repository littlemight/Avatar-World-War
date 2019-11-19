#ifndef _STATE_H
#define _STATE_H

#include "arraydin.h"
#include "matrix.h"
#include "graph.h"
#include "player.h"

typedef struct {
    TabBuilding ArrBuilding; // copy function done
    // Matrix Peta; // copy done aman
    // Graph G; // copy graph aman
    Player P[3]; // copy player aman
    int PlayerID; // aman
} State;

#define ArrBuilding(S) (S).ArrBuilding
// #define Peta (S).Peta
// #define G (S).G
#define P(S, i) (S).P[(i)]
#define CurPlayerID(S) (S).PlayerID

void CreateEmptyState(State *S);
void MakeState(TabBuilding InpArr, Player P[3], int PlayerID, State *S);
void PrintState(State S);
void CopyState(State Sin, State *Sout);
void SavePrintState(FILE *file, State S);

#endif