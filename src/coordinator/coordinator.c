#include "coordinator.h"
#include "../utility/utility.h"

void PrintSkills() {
    int aw = Head(Skills(P(S, CurPlayerID(S))));
    int sz = QNbElmt(Skills(P(S, CurPlayerID(S))));
    int mx = MaxEl(Skills(P(S, CurPlayerID(S))));
    for (int i = 1; i <= sz; i++) {
        if (i != 1) printf(" ");

        int cur = aw + i - 1;
        if (cur > mx) cur -= mx;
        if (cur == aw) {
            if (CurPlayerID(S) == 1) {
                printf("%s", BLUE);
            } else {
                printf("%s", RED);
            }
        }
       PrintKata(Skills(P(S, CurPlayerID(S))).T[cur]);
        if (cur == aw) {
            printf("%s", NORMAL);
        }
        if (i < sz) {
            printf(" |");
        }
    }
    printf("\n");
}

void PrintPlayerStatus() {
    printf("Player ");    
    if (CurPlayerID(S) == 1) {
        printf("%s", BLUE);
    } else {
        printf("%s", RED);
    }
    PrintKata(Username(P(S, CurPlayerID(S))));
    printf("%s", NORMAL);
    printf(" // ");

    if (PShield(P(S, CurPlayerID(S)))) {
        if (CurPlayerID(S) == 1) {
            printf("%s", BLUE);
        } else {
            printf("%s", RED);
        }
    }
    printf("S");
    if (PShield(P(S, CurPlayerID(S)))) {
        printf("%s", NORMAL);
    }

    printf(" ");
    if (PTurn(P(S, CurPlayerID(S))) - 1 > 0) {
        if (CurPlayerID(S) == 1) {
            printf("%s", BLUE);
        } else {
            printf("%s", RED);
        }
    }
    printf("%d", PTurn(P(S, CurPlayerID(S))) - 1);
    if (PTurn(P(S, CurPlayerID(S))) - 1 > 0) {
        printf("%s", NORMAL);
    }

    printf(" ");
    if (PAttackUp(P(S, CurPlayerID(S)))) {
        if (CurPlayerID(S) == 1) {
            printf("%s", BLUE);
        } else {
            printf("%s", RED);
        }
    }
    printf("AU");
    if (PAttackUp(P(S, CurPlayerID(S)))) {
        printf("%s", NORMAL);
    }

    printf(" ");
    if (PCriticalHit(P(S, CurPlayerID(S)))) {
        if (CurPlayerID(S) == 1) {
            printf("%s", BLUE);
        } else {
            printf("%s", RED);
        }
    }
    printf("CH");
    if (PCriticalHit(P(S, CurPlayerID(S)))) {
        printf("%s", NORMAL);
    }
    printf("\n");
}

void PrintStatus() {
    clear();
    PrintPeta();
    PrintPlayerStatus();
    PrintPlayerBuildings(CurPlayerID(S));
    printf("Skill Available: ");
    if (QIsEmpty(Skills(P(S, CurPlayerID(S))))) {
        printf("None\n");
    } else {
        PrintSkills();
    }
    if (CurPlayerID(S) == 1) {
        printf("%s", BLUE);
    } else {
        printf("%s", RED);
    }
    printf("COMMANDS: ATTACK | LEVEL_UP | SKILL | MOVE | UNDO | SAVE | END_TURN | EXIT\n");
    printf("%s", NORMAL);
}

void DoGame() {
    Kata command;
    char effCommand[50];
    boolean loop = true;
    do {
        PrintStatus();
        printf(">>> ENTER COMMAND: ");
        InputKata(&command);
        KataToArrChar(command, effCommand);
        if (IsStrEQ(effCommand, "ATTACK")) {
            SPush(&UndoStack, S);
            State St = InfoTop(UndoStack);
            if(Attack(CurPlayerID(S)) == 0) getSkills(St, S);
            else SPop(&UndoStack, &S);
            loop = IsWinGame();
            ADV();
        } else if (IsStrEQ(effCommand, "LEVEL_UP")) {
            SPush(&UndoStack, S);
            if (LevelUp(CurPlayerID(S)) == 0) {
                getInstantReinforcement(S);
            } else {
                SPop(&UndoStack, &S);
            }
            ADV();
        } else if (IsStrEQ(effCommand, "SKILL")) {
            SPush(&UndoStack, S);
            if (Skill(CurPlayerID(S)) == 0) {
                State St = InfoTop(UndoStack);
                getSkills(St, S);
                SCreateEmpty(&UndoStack);
            }
            else SPop(&UndoStack, &S);
            ADV();
        } else if (IsStrEQ(effCommand, "UNDO")) {
            Undo();
            ADV();
        } else if (IsStrEQ(effCommand, "SAVE")) {
            Save();
            ADV();
        } else if (IsStrEQ(effCommand, "MOVE")) {
            SPush(&UndoStack, S);
            if(Move(CurPlayerID(S)) == 1) SPop(&UndoStack, &S);
            ADV();
        } else if (IsStrEQ(effCommand, "EXIT")) {
            printf("Press enter to confirm your exit ");
            ADV();
        } else if (IsStrEQ(effCommand, "END_TURN")) {
            EndTurn(CurPlayerID(S));
        } else {
            printf("Command tidak valid.\n");
            ADV();
        }
    } while (!IsStrEQ(effCommand, "EXIT")  && loop);
}

boolean IsWinGame(){
    boolean loop = true;
    if(LIsEmpty(Buildings(P(S, 1)))){
        clear();
        printf("Selamat "); PrintKata(Username(P(S, 2))); printf(" memenangkan pertandingan dunia Avatar!!\n");
        loop = false;
    } else if(LIsEmpty(Buildings(P(S, 2)))){
        clear();
        printf("Selamat "); PrintKata(Username(P(S, 1))); printf(" memenangkan pertandingan dunia Avatar!!\n");
        loop = false;
    }
    return loop;    
}

void StartGame() {
    Kata username1, username2;
    printf("Masukkan Username Player 1: "); InputKata(&username1);
    printf("Masukkan Username Player 2: "); InputKata(&username2);
    Username(P(S, 1)) = username1;
    Username(P(S, 2)) = username2;
    QAdd(&Skills(P(S, 1)), InstantUpgrade);
    QAdd(&Skills(P(S, 2)), InstantUpgrade);

    CurPlayerID(S) = 1;
    PTurn(P(S, 1)) = 1;
    DoGame();
}

