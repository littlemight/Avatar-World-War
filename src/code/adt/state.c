#include "../../header/adt/state.h"

void MakeState(TabBuilding InpArr, Matrix InpPeta, Graph InpG, Player P[], int PlayerID, State *S) {
    CopyTab(InpArr, &ArrBuilding(*S));
    CopyMatrix(InpPeta, &Peta(*S));
    CopyGraph(InpG, &G(*S));
    for (int i = 0; i < 3; i++) {
        P(*S)[i] = P[i];
    }
    CurPlayerID(*S) = PlayerID;
}

void PrintState(State S) {
    for (int i = 1; i <= ANbElmt(ArrBuilding(S)); i++) {
        PrintBuilding(AElmt(ArrBuilding(S), i));
        printf("\n");
    }
}

void CopyState(State Sin, State *Sout) {
    AMakeEmpty(&ArrBuilding(*Sout), ANbElmt(ArrBuilding(Sin)));
    CopyTab(ArrBuilding(Sin), &ArrBuilding(*Sout));
    CopyMatrix(Peta(Sin), &Peta(*Sout));
    CopyGraph(G(Sin), &G(*Sout));
    for (int i = 1; i < 3; i++) {
        PCreateEmpty(&P(*Sout)[i]);
        CopyPlayer(P(Sin)[i], &(P(*Sout)[i]));
    }
    CurPlayerID(*Sout) = CurPlayerID(Sin);
    // printf("state success copy\n");
    return;
}