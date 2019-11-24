#include "bangunan.c"
#include "../point/point.c"
#include <stdio.h>
#include <stdlib.h>

int main () {
    BANGUNAN B, BCopy;
    char C;
    int x, y;
    scanf("%c", &C);
    scanf("%d %d", &x, &y);
    B = SetBangunan (C, 1, MakePOINT(x, y)); 
    CopyBangunan(&BCopy, B);
    if (IsPertahanan (B)) {
        printf("!\n");
    }
    SetKepemilikan (&BCopy, 2); 
    if (IsKepemilikan (B, 1)) {
        printf("Milik pemain 1\n");
    } 
    if (IsKepemilikan (BCopy, 2)) {
        printf("Milik pemain 2\n");
    }
    PrintStatus(B); printf("\n");
    PrintJenisPoint(BCopy); printf("\n");
    TambahPasukanAuto (&B); 
    TambahPasukanManual (&B, -100000); 
    TambahPasukanManual (&BCopy, 100000); 
    PrintStatus(B); printf("\n");
    PrintStatus(BCopy); printf("\n");
    SetPasukan(&B, 100000);
    LevelUp (&B);
    PrintStatus(B);
    return 0;
}