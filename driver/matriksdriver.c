#include "../Tubesrevisi/matriks.c"
#include <stdio.h>

void print_bool(boolean B){

    if (B) {
        printf("true");
    }
    else {
        printf("false");
    }
}

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