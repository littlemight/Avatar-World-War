#include "library.h"

Building CASTLE[5];
Building TOWER[5];
Building FORT[5];
Building VILLAGE[5];

State S;
Graph G;
Matrix Peta, AdjMat; // AdjMat buat gampang simpan ke file
Stack UndoStack, RedoStack;
Kata InstantUpgrade, Shield, ExtraTurn, AttackUp, CriticalHit, InstantReinforcement, Barrage;

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
            AddBuilding(&Buildings(P[i]), i);
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
        MakeBuilding(&AElmt(ArrBuilding, i), base, OwnerID, pos, false, false);
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
    MakeState(ArrBuilding, P, 1, &S);
    SCreateEmpty(&UndoStack);
    SCreateEmpty(&RedoStack);
}

void LoadSaved(){
    TabBuilding ArrBuilding;
    Player P[3];
    for (int i = 0; i < 3; i++) {
        PCreateEmpty(&P[i]);
    }
    int N, M, Build;
    InputInt(&N);
    InputInt(&M);
    InputInt(&Build);
    AMakeEmpty(&ArrBuilding, Build);
    ANeff(ArrBuilding) = Build;
    MakeMatrix(&Peta, N, M);

    for(int i = 1; i <= Build; i ++){
        int milik, r, c;
        InputInt(&milik);

        Kata type;
        InputKata(&type);

        Point pos;
        InputInt(&r);
        InputInt(&c);
        pos = MakePoint(r, c);

        int level;
        InputInt(&level);
        
        Building base;
        switch (type.TabKata[1])
        {
        case 'C':
            CopyBuilding(CASTLE[level], &base);
            break;
        case 'T':
            CopyBuilding(TOWER[level], &base);
            break;
        case 'F':
            CopyBuilding(FORT[level], &base);
            break;
        case 'V':
            CopyBuilding(VILLAGE[level], &base);
            break;
        }

        int troops, hasAttacked, hasMoved;
        InputInt(&troops);
        base.Troop = troops;

        InputInt(&hasAttacked);
        InputInt(&hasMoved);
        boolean attack = false, move = false;
        if(hasAttacked == 1){ attack = true; }
        if(hasMoved == 1){ move = true; }
        MakeBuilding(&AElmt(ArrBuilding, i), base, milik, pos, attack, move);
        MElmt(Peta, Row(pos), Col(pos)) = i;
    }
    CreateGraph(1, &G);
    MakeMatrix(&AdjMat, Build, Build);
    for (int i = 1; i <= Build; i++){
        for (int j = 1; j <= Build; j++){
            int x;
            InputInt(&x);
            MElmt(AdjMat, i, j) = x;
            if (x == 1){
                InsertEdge(&G, i, j);
            }
        }
    }
    for(int i = 1; i <= 2; i ++){
        Kata usname;
        int nbBuild, nbSkill, shield, turn, attackup, critical;
        InputKata(&usname);
        CopyKata(usname, &Username(P[i]));

        InputInt(&nbBuild);
        for(int j = 1; j <= nbBuild; j ++){
            int readBuild;
            InputInt(&readBuild);
            AddBuilding(&Buildings(P[i]), readBuild);
        }
        InputInt(&nbSkill);
        for(int j = 1; j <= nbSkill; j ++){
            Kata readSkill;
            InputKata(&readSkill);
            QAdd(&Skills(P[i]), readSkill);
        }
        InputInt(&shield);
        InputInt(&turn);
        InputInt(&attackup);
        InputInt(&critical);
        PShield(P[i]) = shield;
        PTurn(P[i]) = turn;
        boolean attack = false, critic = false;
        if(attackup == 1){ attack = true; }
        if(critical == 1){ critic = true; }
        PAttackUp(P[i]) = attack;
        PCriticalHit(P[i]) = critic;
    }
    int curplayer;
    InputInt(&curplayer);
    SCreateEmpty(&UndoStack);
    SCreateEmpty(&RedoStack);
    MakeState(ArrBuilding, P, curplayer, &S);
}

int FindConnected(int id) {
    adrNode Pn = SearchNode(G, id);
    boolean c1 = false, c2 = false;
    adrSuccNode P = Trail(Pn);
    while (P != NilGraph) {
        int ownerCur = OwnerID(AElmt(ArrBuilding(S), Id(Succ(P))));
        if (ownerCur == 1) {
            c1 = true;
        } else if (ownerCur == 2) {
            c2 = true;
        }
        P = Next(P);
    }
    int ret;
    if (c1 && c2) ret = 3;
    else if (c1) ret = 1;
    else if (c2) ret = 2;
    else ret = 0;
    return ret;
}

void PrintPeta()
{
    // Left indent
    printf("    ");
    
    // Col Number
    for (int j = 1; j <= CEff(Peta); j++) {
        if (j < 10) {
            printf(" ");
        }
        printf(" ");
        yellow();
        printf("%d", j);
        normal();
        printf(" ");
    } printf("\n");

    // Left indent
    printf("    ");

    // Border
    green();
    printf("%c", 201);
    for (int j = 2; j <= 4*CEff(Peta); j++) {
        if (j % 4 == 1) printf("%c", 209);
        else printf("%c", 205);
    }
    printf("%c", 187);
    printf("\n");
    normal();

    for (int i = 1; i <= REff(Peta); i++)
    {
        // Row Number
        if (i < 10) {
            printf(" ");
        }
        printf(" ");
        yellow();
        printf("%d", i);
        normal();
        printf(" ");

        // Print contents
        for (int j = 1; j <= CEff(Peta); j++)
        {   
            green();
            if (j == 1) {
                printf("%c", 186);
            } else printf("%c", 179);
            normal();

            if (MElmt(Peta, i, j) == 0)
            {
                printf("   ");
            }
            else
            {   
                int idx = 0;
                int curOwn = OwnerID(AElmt(ArrBuilding(S), MElmt(Peta, i, j)));
                int connectedTo;
                switch (curOwn)
                {
                case 0:
                    connectedTo = FindConnected(MElmt(Peta, i, j));
                    switch (connectedTo) {
                        case 0:
                            break;
                        case 1:
                            blue();
                            break;
                        case 2:
                            red();
                            break;
                        case 3:
                            magenta();
                            break;
                    }
                    printf(" ");
                    printf("%c", AElmt(ArrBuilding(S), MElmt(Peta, i, j)).Type);
                    printf(" ");
                    normal();
                    break;
                case 1:
                    idx = SearchIdx(Buildings(P(S, 1)), MElmt(Peta, i, j));
                    blue_bg(); printf("%d", idx);
                    if (idx < 10) printf(" ");
                    printf("%c", AElmt(ArrBuilding(S), MElmt(Peta, i, j)).Type);
                    normal();
                    break;
                case 2:
                    idx = SearchIdx(Buildings(P(S, 2)), MElmt(Peta, i, j));
                    red_bg(); printf("%d", idx);
                    if (idx < 10) printf(" ");
                    printf("%c", AElmt(ArrBuilding(S), MElmt(Peta, i, j)).Type);
                    normal();
                    break;
                }
            }
        }
        green();
        printf("%c", 186);
        normal();
        printf("\n");

        // left indent
        printf("    ");
        if (i == REff(Peta)) {
            green();
            printf("%c", 200);
            for (int j = 2; j <= 4*CEff(Peta); j++) {
                if (j % 4 == 1) printf("%c", 207);
                else printf("%c", 205);
            }
            printf("%c", 188);
            normal();
        }
        else {
            green();
            printf("%c", 199);
            // normal();
            for (int j = 2; j <= 4*CEff(Peta); j++) {
                if (j % 4 == 1) {
                    printf("%c", 197);
                } else printf("%c", 196);
            }
            // magenta();
            printf("%c", 182);
            normal();
        }
        printf("\n");
    }
}

void PrintPetaAttackable(int id)
{
    List neighbourList = NeighbourList(id);
    
    // Left indent
    printf("    ");
    
    // Col Number
    for (int j = 1; j <= CEff(Peta); j++) {
        if (j < 10) {
            printf(" ");
        }
        printf(" ");
        yellow();
        printf("%d", j);
        normal();
        printf(" ");
    } printf("\n");

    // Left indent
    printf("    ");

    // Border
    green();
    printf("%c", 201);
    for (int j = 2; j <= 4*CEff(Peta); j++) {
        if (j % 4 == 1) printf("%c", 209);
        else printf("%c", 205);
    }
    printf("%c", 187);
    printf("\n");
    normal();
    
    for (int i = 1; i <= REff(Peta); i++)
    {
        // Row Number
        if (i < 10) {
            printf(" ");
        }
        printf(" ");
        yellow();
        printf("%d", i);
        normal();
        printf(" ");

        // Print contents
        for (int j = 1; j <= CEff(Peta); j++)
        {   
            green();
            if (j == 1) {
                printf("%c", 186);
            } else printf("%c", 179);
            normal();

            if (MElmt(Peta, i, j) == 0)
            {
                printf("   ");
            }
            else
            {   
                int idx = 0;
                idx = SearchIdx(neighbourList, MElmt(Peta, i, j));
                if (idx != 0) {
                    reverse();
                    printf("%d", idx);
                    if (idx < 10) printf(" ");
                    printf("%c", AElmt(ArrBuilding(S), MElmt(Peta, i, j)).Type);
                    normal();
                } else {
                    int curOwn = OwnerID(AElmt(ArrBuilding(S), MElmt(Peta, i, j)));
                    int connectedTo;
                    switch (curOwn)
                    {
                    case 0:
                        connectedTo = FindConnected(MElmt(Peta, i, j));
                        switch (connectedTo) {
                            case 0:
                                break;
                            case 1:
                                blue();
                                break;
                            case 2:
                                red();
                                break;
                            case 3:
                                magenta();
                                break;
                        }
                        printf(" ");
                        printf("%c", AElmt(ArrBuilding(S), MElmt(Peta, i, j)).Type);
                        printf(" ");
                        normal();
                        break;
                    case 1:
                        blue_bg();
                        if (MElmt(Peta, i, j) == id) {
                            printf("A");
                        }
                        printf(" ");
                        printf("%c", AElmt(ArrBuilding(S), MElmt(Peta, i, j)).Type);
                        if (MElmt(Peta, i, j) != id) {
                            printf(" ");
                        }
                        normal();
                        break;
                    case 2:
                        red_bg();
                        if (MElmt(Peta, i, j) == id) {
                            printf("A");
                        }
                        printf(" ");
                        printf("%c", AElmt(ArrBuilding(S), MElmt(Peta, i, j)).Type);
                        if (MElmt(Peta, i, j) != id) {
                            printf(" ");
                        }
                        normal();
                        break;
                    }
                }
            }
        }
        green();
        printf("%c", 186);
        normal();
        printf("\n");

        // left indent
        printf("    ");
        if (i == REff(Peta)) {
            green();
            printf("%c", 200);
            for (int j = 2; j <= 4*CEff(Peta); j++) {
                if (j % 4 == 1) printf("%c", 207);
                else printf("%c", 205);
            }
            printf("%c", 188);
            normal();
        }
        else {
            green();
            printf("%c", 199);
            // normal();
            for (int j = 2; j <= 4*CEff(Peta); j++) {
                if (j % 4 == 1) {
                    printf("%c", 197);
                } else printf("%c", 196);
            }
            // magenta();
            printf("%c", 182);
            normal();
        }
        printf("\n");
    }
}

void PrintPetaMoveable(int id)
{
    List ourList = OurList(id);
    
    // Left indent
    printf("    ");
    
    // Col Number
    for (int j = 1; j <= CEff(Peta); j++) {
        if (j < 10) {
            printf(" ");
        }
        printf(" ");
        yellow();
        printf("%d", j);
        normal();
        printf(" ");
    } printf("\n");

    // Left indent
    printf("    ");

    // Border
    green();
    printf("%c", 201);
    for (int j = 2; j <= 4*CEff(Peta); j++) {
        if (j % 4 == 1) printf("%c", 209);
        else printf("%c", 205);
    }
    printf("%c", 187);
    printf("\n");
    normal();
    
    for (int i = 1; i <= REff(Peta); i++)
    {
        // Row Number
        if (i < 10) {
            printf(" ");
        }
        printf(" ");
        yellow();
        printf("%d", i);
        normal();
        printf(" ");

        // Print contents
        for (int j = 1; j <= CEff(Peta); j++)
        {   
            green();
            if (j == 1) {
                printf("%c", 186);
            } else printf("%c", 179);
            normal();

            if (MElmt(Peta, i, j) == 0)
            {
                printf("   ");
            }
            else
            {   
                int idx = 0;
                idx = SearchIdx(ourList, MElmt(Peta, i, j));
                if (idx != 0) {
                    reverse();
                    printf("%d", idx);
                    if (idx < 10) printf(" ");
                    printf("%c", AElmt(ArrBuilding(S), MElmt(Peta, i, j)).Type);
                    normal();
                } else {
                    int curOwn = OwnerID(AElmt(ArrBuilding(S), MElmt(Peta, i, j)));
                    int connectedTo;
                    switch (curOwn)
                    {
                    case 0:
                        connectedTo = FindConnected(MElmt(Peta, i, j));
                        switch (connectedTo) {
                            case 0:
                                break;
                            case 1:
                                blue();
                                break;
                            case 2:
                                red();
                                break;
                            case 3:
                                magenta();
                                break;
                        }
                        printf(" ");
                        printf("%c", AElmt(ArrBuilding(S), MElmt(Peta, i, j)).Type);
                        printf(" ");
                        normal();
                        break;
                    case 1:
                        blue_bg();
                        if (MElmt(Peta, i, j) == id) {
                            printf("M");
                        }
                        printf(" ");
                        printf("%c", AElmt(ArrBuilding(S), MElmt(Peta, i, j)).Type);
                        if (MElmt(Peta, i, j) != id) {
                            printf(" ");
                        }
                        normal();
                        break;
                    case 2:
                        red_bg();
                        if (MElmt(Peta, i, j) == id) {
                            printf("M");
                        }
                        printf(" ");
                        printf("%c", AElmt(ArrBuilding(S), MElmt(Peta, i, j)).Type);
                        if (MElmt(Peta, i, j) != id) {
                            printf(" ");
                        }
                        normal();
                        break;
                    }
                }
            }
        }
        green();
        printf("%c", 186);
        normal();
        printf("\n");

        // left indent
        printf("    ");
        if (i == REff(Peta)) {
            green();
            printf("%c", 200);
            for (int j = 2; j <= 4*CEff(Peta); j++) {
                if (j % 4 == 1) printf("%c", 207);
                else printf("%c", 205);
            }
            printf("%c", 188);
            normal();
        }
        else {
            green();
            printf("%c", 199);
            // normal();
            for (int j = 2; j <= 4*CEff(Peta); j++) {
                if (j % 4 == 1) {
                    printf("%c", 197);
                } else printf("%c", 196);
            }
            // magenta();
            printf("%c", 182);
            normal();
        }
        printf("\n");
    }
}

void PrintBuildingExtra(Building B) {
    PrintBuildingType(B);
    printf(" ");
    if (Row((B).Pos) < 10) printf(" ");
    TulisPoint((B).Pos); 
    if (Col(B.Pos) < 10) printf(" ");
    printf(" | Lv. %d |", Level(B)); 
    printf(" ");
    if (Troop(B) < 10) printf(" ");
    printf("%d", Troop(B));
    if (Troop(B) < 100) printf(" ");
    printf(" ");
    if (OwnerID(B) == CurPlayerID(S)) {
        printf("|");
        if (!HasAttacked(B)) {
            if (OwnerID(B) == 1) {
                blue();
            } else if (OwnerID(B) == 2) {
                red();
            }
        }
        printf(" A ");
        if (!HasAttacked(B)) {
            normal();
        }
        printf("|");
        if (!HasMoved(B)) {
            if (OwnerID(B) == 1) {
                blue();
            } else if (OwnerID(B) == 2) {
                red();
            }
        }
        printf(" M");
        if (!HasMoved(B)) {
            normal();
        }
    }
}

void PrintPlayerBuildings(int curPlayerID)
{
    printf("Building List:\n");
    addressList cur = LFirst(Buildings(P(S, curPlayerID)));
    int sz = LNbElmt(Buildings(P(S, curPlayerID)));
    for (int i = 1; i <= sz; i++) {
        if (i < 10) printf(" ");
        printf("%d. ", i);
        PrintBuildingExtra(AElmt(ArrBuilding(S), LInfo(cur)));
        printf("\n");
        cur = LNext(cur);
    }
}

void PrintNeighbourBuilding(int BuildID)
{
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
        P = Next(P);
    }
    if (cnt == 1)
    {
        printf("NONE\n");
    }
}

List NeighbourList(int BuildID) {
    adrNode Pn = SearchNode(G, BuildID);
    adrSuccNode P = Trail(Pn);
    List ret;
    LCreateEmpty(&ret);
    Building Cur = AElmt(ArrBuilding(S), BuildID);
    while (P != NilGraph)
    {
        Building B = AElmt(ArrBuilding(S), Id(Succ(P)));
        if (OwnerID(B) != OwnerID(Cur))
        {
            AddBuilding(&ret, Id(Succ(P)));
        }
        P = Next(P);
    }
    return ret;
}

List OurList(int BuildID) {
    adrNode Pn = SearchNode(G, BuildID);
    adrSuccNode P = Trail(Pn);
    List ret;
    LCreateEmpty(&ret);
    Building Cur = AElmt(ArrBuilding(S), BuildID);
    while (P != NilGraph)
    {
        Building B = AElmt(ArrBuilding(S), Id(Succ(P)));
        if (OwnerID(B) == OwnerID(Cur))
        {
            AddBuilding(&ret, Id(Succ(P)));
        }
        P = Next(P);
    }
    return ret;
}

void PrintOurBuilding(int BuildID)
{
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
        printf("NONE\n");
    }
}

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

void SavePrintGame(FILE *file, Matrix Peta, Matrix AdjMat, State S, Stack UndoStack) {
    // SavePrintMatrix(file, Peta);
    fprintf(file, "%d %d\n", REff(Peta), CEff(Peta));
    SavePrintState(file, S, AdjMat);
    // SavePrintStack(file, UndoStack);
    fprintf(file, "#");
    fclose(file);
}
