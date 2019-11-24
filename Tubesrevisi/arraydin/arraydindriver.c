#include "arraydin.c"
#include "../bangunan/bangunan.c"
#include "../point/point.c"
#include <stdio.h>
#include <stdlib.h>

void print_bool(boolean B){

    if (B) {
        printf("true");
    }
    else {
        printf("false");
    }
}

int main(){
    TabInt T1, T2;
    int maxel, x, y;
    char C;
    scanf(" %d", &maxel);
    MakeEmpty(&T1, maxel);
    scanf(" %c", &C);
    scanf(" %d %d", &x, &y);
    Neff(T1) = maxel - 1;
    printf("%d %d\n", NbElmtTab(T1), MaxElement(T1));
    for (int i=GetFirstIdx(T1); i<=GetLastIdx(T1); i++){
        Bangunan(T1, i) = SetBangunan (C, 1, MakePOINT(x, y));
        PrintStatus(Bangunan(T1, i)); printf("\n");
    }
    CopyTab(T1, &T2);
    printf("%d %d\n", NbElmtTab(T2), MaxElement(T2));
    for (int i=GetFirstIdx(T2); i<=GetLastIdx(T2); i++){
        LevelUp(&(Bangunan(T2, i)));
        PrintStatus(Bangunan(T2, i)); printf("\n");
    }
}