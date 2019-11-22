// #ifndef LIBRARY_H
// #define LIBRARY_H

#include "../adt/building/building.h"
#include "../adt/player/player.h"
#include "../adt/arraydin/arraydin.h"
#include "../adt/graph/graph.h"
#include "../adt/matrix/matrix.h"
#include "../adt/state/state.h"
#include "../adt/stack/stack.h"
#include "../adt/mesinkata/mesinkata.h"
#include "../adt/pcolor/pcolor.h"
#include "../utility/utility.h"

extern Building CASTLE[5];
extern Building TOWER[5];
extern Building FORT[5];
extern Building VILLAGE[5];

extern State S;
extern Stack UndoStack, RedoStack;
extern Matrix Peta, AdjMat;
extern Graph G;
extern Kata InstantUpgrade;
extern Kata Shield;
extern Kata ExtraTurn;
extern Kata AttackUp;
extern Kata CriticalHit;
extern Kata InstantReinforcement;
extern Kata Barrage;

// /** ======================================== SETUPS  ========================================  **/
void MakeAllBase();

Building GetBase(Building B, int Level);

void InitKamusSkill();

void LoadInit();
void LoadSaved();
/** ======================================== ----  ========================================  **/

/** ======================================== PRINT  ========================================  **/
void PrintPeta();
void PrintBuildingExtra(Building B);
void PrintPlayerBuildings(int curPlayerID); // mencetak semua building pemain
void PrintNeighbourBuilding(int BuildID); // mencetak semua building yang tetangga dan dimiliki oleh pemilik yg sama
void PrintOurBuilding(int BuildID); // mencetak building yang tetangga dan dimiliki oleh pemain yg berbeda
/** ======================================== ----  ========================================  **/

/** ======================================== NEIGHBOURHOOD TOOLS  ========================================  **/
int GGetNeighbourNthInfo(Graph G, infotypeGraph X, int n);

int GGetOurNthInfo(Graph G, infotypeGraph X, int n);

int NeighbourDegree(Graph G, infotypeGraph X);

int OurDegree(Graph G, infotypeGraph X);
/** ======================================== ----  ========================================  **/

/** ======================================== MEKANISME  ========================================  **/
void RegenTroop();
// }
// /** ======================================== ----  ========================================  **/

void SavePrintGame(FILE *file, Matrix Peta, Matrix AdjMat, State S, Stack UndoStack);