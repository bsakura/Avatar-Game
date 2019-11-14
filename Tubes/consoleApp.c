#include "console.h"
#include "consoleApp.h"
#include <stdio.h>
#include "listlinier.h"
#include "input.h"
#include "matriks.h"
#include "bangunan.h"
#include "boolean.h"
#include "matriks1.h"
#include "pcolor.h"

void CetakMap(MATRIKS M){
    int i,j;
    for (i=1;i<=NKolEff(M) +2; i++){
        printf("*");
    }
    outln();
    for (i=1;i<=NBrsEff(M); i++){
        printf("*");
        for (j=1; j<=NKolEff(M);j++){
            if (Kepemilikan(Elmt(M,i,j))==0){
                printf("%c", Jenis(Elmt(M,i,j)));
            } else if  (Kepemilikan(Elmt(M,i,j))==1)
            {
                print_blue(Jenis(Elmt(M,i,j)));
            }
            else if(Kepemilikan(Elmt(M,i,j))==2){
                print_red(Jenis(Elmt(M,i,j)));
            }
            else{
                printf(" ");
            }
        }
        printf("*");
        outln();
    }
    for (i=1;i<=NKolEff(M) +2; i++){
        printf("*");
    }
    outln();
}

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
        int N, x, y, i,j;
        char C;
        POINT P;
        BANGUNAN B;
        ARRAYB A;
        List L1, L2, LS;
        i = 1;

        set(true);
        STARTKATA();
        NBrsEff(M) = toInt(CKata);
        printf("%d", NBrsEff(M));
        ADVKATA();
        NKolEff(M) = toInt(CKata);
        printf("%d",NKolEff(M));
        ADVKATA();
        MakeMATRIKS(NBrsEff(M), NKolEff(M),&M);
        N = toInt(CKata);
        NBBangunan(A) = N;
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
        Elmt(M,x,y) = B;
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
        Elmt(M,x,y) = B;
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
            Elmt(M,x,y) = B;
            //A[i] = B;
            //M[lokasi(B).x][lokasi(B).y]=B;
            ADVKATA();
        }
        MATRIKSS M1;
        MakeMATRIKSS( N, N, &M1 );

        for (i=1; i<=NBBangunan(A); i++){
            for(j=1; j<=NBBangunan(A);j++){
                Elmnt(M1,i,j)= toInt(CKata);
                ADVKATA();
            }
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
        TulisMATRIKSS(M1);
        outln();
        CetakMap(M);
    }

int main(){
    StartGame();
    return 0;
}