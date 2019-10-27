#include "boolean.h"
#include "bangunan.h"
#include "bangunan.c"
#include <stdio.h>
#include <stdlib.h>

int main () {
    int i;
    BANGUNAN C, T1, T2;
    Pemain P1, P2;
    P1 = 1;
    P2 = 2;
    C = SetBangunan('C', Nil);
    PrintStatus(C);
    T1 = SetBangunan('T', 1);
    T2 = SetBangunan('T', 2);
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