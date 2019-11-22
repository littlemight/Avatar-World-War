#ifndef COMMAND_H
#define COMMAND_H

#include "../library/library.h"

float GetMultiplier(int idAttack, int ownerAttack);
int Attack(int PlayerID);
int LevelUpBuilding(Building *B);
int LevelUp(int PlayerID);
int Move(int PlayerID);
int Skill(int PlayerID);
void Undo();
void Redo();
int GetLoadedFilename(char *filename);
int Load();
void GetSavedFilename(char* filename, char* nameOnly);
void Save();
void EndTurn(int PlayerID);

#endif