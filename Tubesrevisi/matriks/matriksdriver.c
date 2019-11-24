#include "matriks.c"
#include <stdio.h>
#include <stdlib.h>

int main(){
    MATRIKS M;
    int i, j, B, K;
    scanf("%d %d", &B, &K);
    MakeMATRIKS(B,K,&M);
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
            printf("%d ", Elmt(M, i, j));
        }
        printf("\n");
    }
    return 0;
}