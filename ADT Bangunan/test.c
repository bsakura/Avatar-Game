#include "boolean.h"
#include "bangunan.h"
#include "bangunan.c"
#include <stdio.h>
#include <stdlib.h>

int main () {
    int i;
    BANGUNAN C, F, T1, T2, V;
    Pemain P1, P2;
    P1 = 1;
    P2 = 2;
    CreateBuilding(&C);
    MakeCastle(&C);
    PrintStatus(C);
    SetKepemilikan(&T1, P1);
    SetKepemilikan(&T2, P2);
    MakeTower(&T1);
    MakeTower(&T2);
    PrintStatus(T1);
    PrintStatus(T2);
    for (i = 1; i <= 5; i++) {
        TambahPasukanAuto(&T2);
        LevelUp(&T2);
    }
    TambahPasukanManual(&T1, 50);
    PrintStatus(T1);
    PrintStatus(T2);
    TambahPasukanManual(&T2, 25);
    PrintStatus(T2);
    SerangBangunan(&T1, &T2, 24);
    PrintStatus(T1);
    PrintStatus(T2);
    SerangBangunan(&T1, &T2, 26);
    PrintStatus(T1);
    PrintStatus(T2);
    return 0;
}