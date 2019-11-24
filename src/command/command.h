#ifndef COMMAND_H
#define COMMAND_H

#include "../library/library.h"

// Multiplier for attack
float GetMultiplier(int idAttack, int ownerAttack);

// Commands
int Attack(int PlayerID);
int LevelUpBuilding(Building *B);
int LevelUp(int PlayerID);
int Move(int PlayerID);
int Skill(int PlayerID);
void Undo();
void Redo();

// Load and save
int GetLoadedFilename(char *filename);
int Load();
void GetSavedFilename(char* filename, char* nameOnly);
void Save();
void EndTurn(int PlayerID);

#endif