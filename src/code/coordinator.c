#include "../header/coordinator.h"
#include "../header/utility.h"

void PrintStatus() {
    clear();

    PrintPeta();
    printf("Player ");
    PrintKata(Username(P(S, CurPlayerID(S))));
    printf("\n");
    PrintPlayerBuildings(CurPlayerID(S));
    printf("Skill Available: ");
    if (QIsEmpty(Skills(P(S, CurPlayerID(S))))) {
        printf("None\n");
    } else {
        PrintKata(InfoHead(Skills(P(S, CurPlayerID(S)))));
        printf("\n");
    }
}

void StartGame() {
    Kata command;
    char effCommand[50];
    do {
        PrintStatus();
        printf(">>> ENTER COMMAND: ");
        InputKata(&command);
        KataToArrChar(command, effCommand);
        if (IsStrEQ(effCommand, "ATTACK")) {
            SPush(&UndoStack, S);
            State St = InfoTop(UndoStack);
            Attack(CurPlayerID(S));
            getSkills(St, S);
            ADV();
        } else if (IsStrEQ(effCommand, "LEVEL_UP")) {
            SPush(&UndoStack, S);
            State St = InfoTop(UndoStack);
            LevelUp(CurPlayerID(S));
            getSkills(St, S);
            ADV();
        } else if (IsStrEQ(effCommand, "SKILL")) {
            SCreateEmpty(&UndoStack);
            State St = InfoTop(UndoStack);
            Skill(CurPlayerID(S));
            getSkills(St, S);
            ADV();
        } else if (IsStrEQ(effCommand, "UNDO")) {
            Undo();
            ADV();
        } else if (IsStrEQ(effCommand, "SAVE")) {
            ADV();
        } else if (IsStrEQ(effCommand, "MOVE")) {
            SPush(&UndoStack, S);
            Move(CurPlayerID(S));
            ADV();
        } else if (IsStrEQ(effCommand, "EXIT")) {
            ADV();
        } else if (IsStrEQ(effCommand, "END_TURN")) {
            EndTurn(CurPlayerID(S));
        } else {
            printf("Command tidak valid.\n");
            ADV();
        }
    } while (!IsStrEQ(effCommand, "EXIT"));
}

void AvatarWW() {
    // double sz = (double)sizeof(UndoStack)/1000000;
    // printf("\tsize of undostack %d bytes | %lf MB\n", sizeof(UndoStack), sz);
    // printf("\tstack maxel is %d\n", SMaxEl);
    // ADV();
    Kata username1, username2;
    printf("Masukkan Username Player 1: "); InputKata(&username1);
    printf("Masukkan Username Player 2: "); InputKata(&username2);
    Username(P(S, 1)) = username1;
    Username(P(S, 2)) = username2;

    QAdd(&Skills(P(S, 1)), InstantUpgrade);
    QAdd(&Skills(P(S, 2)), InstantUpgrade);

    CurPlayerID(S) = 1;
    StartGame();
}