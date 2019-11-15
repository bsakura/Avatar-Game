#include "console.h"
#include "consoleApp.h"
#include <stdio.h>
#include "listlinier.h"
#include "input.h"
#include "matriks.h"
#include "bangunan.h"
#include "boolean.h"
#include "arraydin.h"

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
        TURN =1 ;
        int N, x, y, i;
        char C;
        POINT P;
        BANGUNAN B;
        TabInt A;
        List L1, L2, LS;
        i = 1;
        set(true);
        STARTKATA();
        NBrsEff(M) = toInt(CKata);
        ADVKATA();
        NKolEff(M) = toInt(CKata);
        ADVKATA();
        N = toInt(CKata);
        Neff(A) = N;
        MakeEmpty(&A, NBBangunan(A));
        ADVKATA();
        C= toChar(CKata);
        ADVKATA();
        x= toInt(CKata);
        ADVKATA();
        y= toInt(CKata);
        P = MakePOINT(x,y);
        B = SetBangunan(C,1, P);
        Bangunan(A, i) = B;
        i++;
        ADVKATA();
        C= toChar(CKata);
        ADVKATA();
        x= toInt(CKata);
        ADVKATA();
        y= toInt(CKata);
        P = MakePOINT(x,y);
        B = SetBangunan(C,2, P);
        Bangunan(A, i) = B;
        ADVKATA();
        for (i=3; i <= N; i++){
            C= toChar(CKata);
            ADVKATA();
            x= toInt(CKata);
            ADVKATA();
            y= toInt(CKata);
            P = MakePOINT(x,y);
            B = SetBangunan(C,0, P);
            Bangunan(A, i) = B;
            //A[i] = B;
            //M[lokasi(B).x][lokasi(B).y]=B;
            ADVKATA();
        }
        CreateEmpty(&L1);
        ListBangunan(&L1, A, 1);
        PrintListBangunan(L1);
        printf("\n");
        CreateEmpty(&L2);
        ListBangunan(&L2, A, 2);
        PrintListBangunan(L2);
        printf("\n");
        CreateEmpty(&LS);
        ListBangunanSerang(&LS, A, 1);
        PrintListBangunan(LS);
    }