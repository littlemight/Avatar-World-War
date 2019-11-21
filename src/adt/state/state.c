#include "state.h"

void CreateEmptyState(State *S) {
    AMakeEmpty(&ArrBuilding(*S), 600);
    for (int i = 0; i < 3; i++) {
        PCreateEmpty(&P(*S, i));
    }
    CurPlayerID(*S) = 0;
}

void MakeState(TabBuilding InpArr, Player P[], int PlayerID, State *S) {
    CreateEmptyState(S);
    CopyTab(InpArr, &ArrBuilding(*S));
    for (int i = 0; i < 3; i++) {
        CopyPlayer(P[i], &(P(*S, i)));
    }
    CurPlayerID(*S) = PlayerID;
}

void PrintState(State S) {
    for (int i = 1; i <= ANbElmt(ArrBuilding(S)); i++) {
        PrintBuilding(AElmt(ArrBuilding(S), i));
    }
}

void CopyState(State Sin, State *Sout) {
    CreateEmptyState(Sout);
    CopyTab(ArrBuilding(Sin), &ArrBuilding(*Sout));
    for (int i = 1; i < 3; i++) {
        PCreateEmpty(&P(*Sout, i));
        CopyPlayer(P(Sin, i), &(P(*Sout, i)));
    }
    CurPlayerID(*Sout) = CurPlayerID(Sin);
    return;
}

void SavePrintState(FILE *file, State S, Matrix AdjMat) {
    SavePrintTabBuilding(file, ArrBuilding(S));
    SavePrintMatrix(file, AdjMat);
    for (int i = 1; i <= 2; i++) {
        SavePrintPlayer(file, P(S, i));
    }
    fprintf(file, "%d\n", CurPlayerID(S));
}