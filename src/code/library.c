// #ifndef LIBRARY_H
// #define LIBRARY_H

#include "../header/library.h"

Building CASTLE[5];
Building TOWER[5];
Building FORT[5];
Building VILLAGE[5];

State S;
Graph G;
Matrix Peta, AdjMat; // AdjMat buat gampang simpan ke file
Stack UndoStack;
Kata InstantUpgrade, Shield, ExtraTurn, AttackUp, CriticalHit, InstantReinforcement, Barrage;

// /** ======================================== SETUPS  ========================================  **/
void MakeAllBase()
{
    MakeBaseProperty(&CASTLE[1], 'C', 1, 10, 40, false, 40);
    MakeBaseProperty(&CASTLE[2], 'C', 2, 15, 60, false, 0);
    MakeBaseProperty(&CASTLE[3], 'C', 3, 20, 80, false, 0);
    MakeBaseProperty(&CASTLE[4], 'C', 4, 25, 100, false, 0);

    MakeBaseProperty(&TOWER[1], 'T', 1, 5, 20, true, 30);
    MakeBaseProperty(&TOWER[2], 'T', 2, 10, 30, true, 0);
    MakeBaseProperty(&TOWER[3], 'T', 3, 20, 40, true, 0);
    MakeBaseProperty(&TOWER[4], 'T', 4, 30, 50, true, 0);

    MakeBaseProperty(&FORT[1], 'F', 1, 10, 20, false, 80);
    MakeBaseProperty(&FORT[2], 'F', 2, 20, 40, false, 0);
    MakeBaseProperty(&FORT[3], 'F', 3, 30, 60, true, 0);
    MakeBaseProperty(&FORT[4], 'F', 4, 40, 80, true, 0);

    MakeBaseProperty(&VILLAGE[1], 'V', 1, 5, 20, false, 20);
    MakeBaseProperty(&VILLAGE[2], 'V', 2, 10, 30, false, 0);
    MakeBaseProperty(&VILLAGE[3], 'V', 3, 15, 40, false, 0);
    MakeBaseProperty(&VILLAGE[4], 'V', 4, 20, 50, false, 0);
}

Building GetBase(Building B, int Level)
{
    Building ret;
    switch (B.Type)
    {
    case 'C':
        ret = CASTLE[Level];
        break;
    case 'T':
        ret = TOWER[Level];
        break;
    case 'F':
        ret = FORT[Level];
        break;
    case 'V':
        ret = VILLAGE[Level];
        break;
    }
    return ret;
}

void InitKamusSkill() {
    InstantUpgrade = StrToKata("IU");
    Shield = StrToKata("S");
    ExtraTurn = StrToKata("ET");
    AttackUp = StrToKata("AU");
    CriticalHit = StrToKata("CH");
    InstantReinforcement = StrToKata("IR");
    Barrage = StrToKata("B");
}

void LoadInit()
{
    InitKamusSkill();
    TabBuilding ArrBuilding;
    Player P[3];
    for (int i = 0; i < 3; i++) {
        PCreateEmpty(&P[i]);
    }
    int N, M, B;
    InputInt(&N);
    InputInt(&M);
    InputInt(&B);
    AMakeEmpty(&ArrBuilding, N * M);
    ANeff(ArrBuilding) = B;
    MakeMatrix(&Peta, N, M);
    for (int i = 1; i <= B; i++)
    {
        int OwnerID = i;
        if (i > 2)
            OwnerID = 0;
        else
        {
            if (i == 1) {
                AddBuilding(&Buildings(P[i]), i);
            }
            else {
                AddBuilding(&Buildings(P[i]), i);
            }
        }
        Kata type;
        int r, c;
        InputKata(&type);
        InputInt(&r);
        InputInt(&c);
        Point pos;
        pos = MakePoint(r, c);
        Building base;
        switch (type.TabKata[1])
        {
        case 'C':
            base = CASTLE[1];
            break;
        case 'T':
            base = TOWER[1];
            break;
        case 'F':
            base = FORT[1];
            break;
        case 'V':
            base = VILLAGE[1];
            break;
        }
        MakeBuilding(&AElmt(ArrBuilding, i), base, OwnerID, pos);
        MElmt(Peta, Row(pos), Col(pos)) = i;
    }
    CreateGraph(1, &G);
    MakeMatrix(&AdjMat, B, B);
    for (int i = 1; i <= B; i++)
    {
        for (int j = 1; j <= B; j++)
        {
            int x;
            InputInt(&x);
            MElmt(AdjMat, i, j) = x;
            if (x == 1)
            {
                InsertEdge(&G, i, j);
            }
        }
    }
    CreateEmptyState(&S);
    SCreateEmpty(&UndoStack);
    MakeState(ArrBuilding, P, 1, &S);
    SCreateEmpty(&UndoStack);
}
/** ======================================== ----  ========================================  **/

/** ======================================== PRINT  ========================================  **/
void PrintPeta()
{
    for (int i = 0; i <= REff(Peta) + 1; i++)
    {
        for (int j = 0; j <= CEff(Peta) + 1; j++)
        {
            if (i == 0 || j == 0 || i == REff(Peta) + 1 || j == CEff(Peta) + 1)
            {
                printf("*");
                continue;
            }
            if (MElmt(Peta, i, j) == 0)
            {
                printf(" ");
            }
            else
            {
                switch (AElmt(ArrBuilding(S), MElmt(Peta, i, j)).OwnerID)
                {
                case 0:
                    printf("%c", AElmt(ArrBuilding(S), MElmt(Peta, i, j)).Type);
                    break;
                case 1:
                    print_blue(AElmt(ArrBuilding(S), MElmt(Peta, i, j)).Type);
                    break;
                case 2:
                    print_red(AElmt(ArrBuilding(S), MElmt(Peta, i, j)).Type);
                    break;
                }
            }
        }
        printf("\n");
    }
}

void PrintPlayerBuildings(int curPlayerID)
{
    printf("Building List:\n");
    addressList cur = LFirst(Buildings(P(S, curPlayerID)));
    int sz = LNbElmt(Buildings(P(S, curPlayerID)));
    for (int i = 1; i <= sz; i++) {
        printf("%d. ", i);
        PrintBuilding(AElmt(ArrBuilding(S), LInfo(cur)));
        printf("\n");
        cur = LNext(cur);
    }
}

void PrintNeighbourBuilding(int BuildID)
{ // mencetak building yang tetangga dan beda ownership
    adrNode Pn = SearchNode(G, BuildID);
    adrSuccNode P = Trail(Pn);
    int cnt = 1;
    Building Cur = AElmt(ArrBuilding(S), BuildID);
    while (P != NilGraph)
    {
        Building B = AElmt(ArrBuilding(S), Id(Succ(P)));
        if (OwnerID(B) != OwnerID(Cur))
        {
            printf("%d. ", cnt++);
            PrintBuilding(B);
            printf("\n");
        }
        // printf("%d\n", cnt);
        P = Next(P);
    }
    if (cnt == 1)
    {
        printf("Tidak ada.\n");
    }
}

void PrintOurBuilding(int BuildID)
{ // mencetak building yang tetangga dan sama ownership
    adrNode Pn = SearchNode(G, BuildID);
    adrSuccNode P = Trail(Pn);
    int cnt = 1;
    Building Cur = AElmt(ArrBuilding(S), BuildID);
    while (P != NilGraph)
    {
        Building B = AElmt(ArrBuilding(S), Id(Succ(P)));
        if (OwnerID(B) == OwnerID(Cur))
        {
            printf("%d. ", cnt++);
            PrintBuilding(B);
            printf("\n");
        }
        P = Next(P);
    }
    if (cnt == 1)
    {
        printf("Tidak ada.\n");
    }
}
/** ======================================== ----  ========================================  **/

/** ======================================== NEIGHBOURHOOD TOOLS  ========================================  **/
int GGetNeighbourNthInfo(Graph G, infotypeGraph X, int n)
{
    adrNode Pn = SearchNode(G, X);
    adrSuccNode P = Trail(Pn);
    Building Cur = AElmt(ArrBuilding(S), X);
    while (P != NilGraph)
    {
        Building B = AElmt(ArrBuilding(S), Id(Succ(P)));
        if (OwnerID(B) != OwnerID(Cur)) {
            if (n == 1) {
                return Id(Succ(P));
            } else n--;
        }
        P = Next(P);
    }
    // printf("%d\n", Id(Succ(P)));
    return Id(Succ(P));
}

int GGetOurNthInfo(Graph G, infotypeGraph X, int n)
{
    adrNode Pn = SearchNode(G, X);
    adrSuccNode P = Trail(Pn);
    Building Cur = AElmt(ArrBuilding(S), X);
    while (P != NilGraph)
    {
        Building B = AElmt(ArrBuilding(S), Id(Succ(P)));
        if (OwnerID(B) == OwnerID(Cur)) {
            if (n == 1) {
                return Id(Succ(P));
            } else n--;
        }
        P = Next(P);
    }
    return Id(Succ(P));
}

int NeighbourDegree(Graph G, infotypeGraph X)
{
    adrNode Pn = SearchNode(G, X);
    Building Cur = AElmt(ArrBuilding(S), X);
    int cnt = 0;
    adrSuccNode P = Trail(Pn);
    while (P != NilGraph)
    {
        Building B = AElmt(ArrBuilding(S), Id(Succ(P)));
        if (OwnerID(B) != OwnerID(Cur))
        {
            cnt++;
        }
        P = Next(P);
    }
    return cnt;
}

int OurDegree(Graph G, infotypeGraph X)
{
    adrNode Pn = SearchNode(G, X);
    Building Cur = AElmt(ArrBuilding(S), X);
    int cnt = 0;
    adrSuccNode P = Trail(Pn);
    while (P != NilGraph)
    {
        Building B = AElmt(ArrBuilding(S), Id(Succ(P)));
        if (OwnerID(B) == OwnerID(Cur))
        {
            cnt++;
        }
        P = Next(P);
    }
    return cnt;
}
/** ======================================== ----  ========================================  **/

/** ======================================== MEKANISME  ========================================  **/
void RegenTroop()
{
    for (int i = 1; i <= ANeff(ArrBuilding(S)); i++)
    {
        if (OwnerID(AElmt(ArrBuilding(S), i)) == CurPlayerID(S))
        {
            Building *B = &AElmt(ArrBuilding(S), i);
            if (Troop(*B) < MaxCap(*B))
            {
                Troop(*B) += Regen(*B);
            }
        }
    }
}
// /** ======================================== ----  ========================================  **/

void SavePrintGame(FILE *file, Matrix Peta, Matrix AdjMat, State S, Stack UndoStack) {
    SavePrintMatrix(file, Peta);
    SavePrintMatrix(file, AdjMat);
    SavePrintState(file, S);
    SavePrintStack(file, UndoStack);
    fprintf(file, "#");
    fclose(file);
}
