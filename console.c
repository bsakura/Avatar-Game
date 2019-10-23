#include "console.h"
#include <stdio.h>
#include "listlinier.h"

void outln(){
    printf("\n");
}
void CetakMap(MATRIKS M){
    int i,j;
    for (i=1;i<=NKolEff(M) +2; i++){
        printf("*");
    }
    outln();
    for (i=1;i<=NBrsEff(M); i++){
        printf("*");
        for (j=1; j<=NKolEff(M);j++){
            printf("%c", jenis(Elmt(M,i,j)));
        }
        outln();
    }
    for (i=1;i<=NKolEff(M) +2; i++){
        printf("*");
    }
    outln();
}

void CetakCommand(){
    printf("ENTER COMMAND: ");
    //BELUM BACANYA 
}
void CetakSkill(Queue Q){
    printf("Skill Available: ");
    //CetakKata(InfoHead(Q));
    //BELUM BACANYA 
}

void CetakBangunanP(List P){
        address a;
        a= First(L);
        int index = 1;
        do{
            printf("%d. ", index);
            Cetak1Bangunan(Info(a));
            index++;
            a= Next(a);        
        }
        while (Next(a)!= Nil);
}

void Cetak1Bangunan(BANGUNAN B){
    switch (jenis(B))
    {
    case C:
        printf("Castle ")
        TulisPOINT(lokasi(B));
        printf(" %d lv. %d", jumpas(B), level(B));
        ountln();
        break;
    case T:
        printf("Tower ")
        TulisPOINT(lokasi(B));
        printf(" %d lv. %d", jumpas(B), level(B));
        ountln();
        break;
    case F:
        printf("Fort ")
        TulisPOINT(lokasi(B));
        printf(" %d lv. %d", jumpas(B), level(B));
        ountln();
        break;
    default:
        printf("Village ")
        TulisPOINT(lokasi(B));
        printf(" %d lv. %d", jumpas(B), level(B));
        ountln();
        break;
    }
}