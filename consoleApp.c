#include "console.h"
#include "consoleApp.h"
#include <stdio.h>
#include "listlinier.h"
#include "input.h"
#include "matriks.h"


// void CetakMap(MATRIKS M){
//     int i,j;
//     for (i=1;i<=NKolEff(M) +2; i++){
//         printf("*");
//     }
//     outln();
//     for (i=1;i<=NBrsEff(M); i++){
//         printf("*");
//         for (j=1; j<=NKolEff(M);j++){
//             printf("%c", jenis(Elmt(M,i,j)));
//         }
//         outln();
//     }
//     for (i=1;i<=NKolEff(M) +2; i++){
//         printf("*");
//     }
//     outln();
// }

// void CetakCommand(){
//     printf("ENTER COMMAND: ");
//     //BELUM BACANYA 
// }
// void CetakSkill(Queue Q){
//     printf("Skill Available: ");
//     //CetakKata(InfoHead(Q));
//     //BELUM BACANYA 
// }

// void CetakBangunanP(List P){
//         address a;
//         a= First(L);
//         int index = 1;
//         do{
//             printf("%d. ", index);
//             Cetak1Bangunan(Info(a));
//             index++;
//             a= Next(a);        
//         }
//         while (Next(a)!= Nil);
// }

// void Cetak1Bangunan(BANGUNAN B){
//     switch (jenis(B))
//     {
//     case C:
//         printf("Castle ")
//         TulisPOINT(lokasi(B));
//         printf(" %d lv. %d", jumpas(B), level(B));
//         ountln();
//         break;
//     case T:
//         printf("Tower ")
//         TulisPOINT(lokasi(B));
//         printf(" %d lv. %d", jumpas(B), level(B));
//         ountln();
//         break;
//     case F:
//         printf("Fort ")
//         TulisPOINT(lokasi(B));
//         printf(" %d lv. %d", jumpas(B), level(B));
//         ountln();
//         break;
//     default:
//         printf("Village ")
//         TulisPOINT(lokasi(B));
//         printf(" %d lv. %d", jumpas(B), level(B));
//         ountln();
//         break;
//     }
    void StartGame(){
        //Kamus
        MATRIKS M;
        int N, x, y, i;
        char C;
        POINT P;
        Bangunan B;
        set(true);
        STARTKATA();
        NBrsEff(M) = toInt(CKata);
        ADVKATA();
        NKolEff(M) = toInt(CKata);
        ADVKATA();
        N = toInt(CKata);
        ADVKATA();
        C= toChar(CKata);
        ADVKATA();
        x= toInt(CKata);
        ADVKATA();
        y= toInt(CKata);
        P = MakePOINT(x,y);
        B = SetBangunan(C,1, P);
        ADVKATA();
        C= toChar(CKata);
        ADVKATA();
        x= toInt(CKata);
        ADVKATA();
        y= toInt(CKata);
        P = MakePOINT(x,y);
        B = SetBangunan(C,2, P);
        ADVKATA();
        for (i=3; i <= N; i++){
            C= toChar(CKata);
            ADVKATA();
            x= toInt(CKata);
            ADVKATA();
            y= toInt(CKata);
            P = MakePOINT(x,y);
            B = SetBangunan(C,2, P);
            //A[i] = B;
            //M[lokasi(B).x][lokasi(B).y]=B;
            ADVKATA();
        }
    }
}