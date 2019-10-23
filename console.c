#include "console.h"
#include <stdio.h>

outln(){
    printf("\n");
}
CetakMap(){
    int i,j;
    for (i=1;i<=NKolEff(M) +2; i++){
        printf("*");
    }
    outln();
    for (i=1;i<=NBrsEff(M); i++){
        printf("*");
        for (j=1; j<=NKolEff;j++){
            printf("%c", jenis(Elmt(M,i,j)));
        }
        outln();
    }
    for (i=1;i<=NKolEff(M) +2; i++){
        printf("*");
    }
    outln();
    
}