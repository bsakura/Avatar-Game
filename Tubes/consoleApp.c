#include "console.h"
#include "consoleApp.h"
#include <stdio.h>
#include "listlinier.h"
#include "input.h"
#include "matriks.h"
#include "bangunan.h"
#include "boolean.h"
#include "pcolor.h"
#include "arraydin.h"
#include "mesinkata.h"
#include "point.h"
#include "stackt.h"
#include "queue.h"
#include "graph.h"
TabInt A;
List L1, L2;
MATRIKS Map;
Kata STDIN;
Queue Skill1, Skill2;
Stack Undo;
Graph GRAPH;
void CetakMap(){
    int i,j;
    for (i=1;i<=NKolEff(Map) +2; i++){
        printf("*");
    }
    outln();
    for (i=1;i<=NBrsEff(Map); i++){
        printf("*");
        for (j=1; j<=NKolEff(Map);j++){
            if (Elmt(Map,i,j) ==0){
                printf(" ");
            }else{ 
                switch (Kepemilikan(Bangunan(A,Elmt(Map,i,j))))
                {
                case 1:
                    print_blue(Jenis(Bangunan(A,Elmt(Map,i,j))));
                    break;
                case 2:
                    print_red(Jenis(Bangunan(A,Elmt(Map,i,j))));
                    break;
                default:
                    printf("%c", Jenis(Bangunan(A,Elmt(Map,i,j))));
                    break;
                }
                
            }
        }
        printf("*");
        outln();
    }
    for (i=1;i<=NKolEff(Map) +2; i++){
        printf("*");
    }
    outln();
}

void CetakCommand(){
    Kata STDIN;
    printf("ENTER COMMAND: ");
    set(false);

    STARTKATA();
    STDIN = CKata; 
    ADVKATA();
    
}


void CetakTurn(){
    printf("Player %d", TURN);
    outln();
    PrintListBangunan(GetListP(TURN));
    printf("Skill Available: ");
    CetakKata(InfoHead(GetQueueP(TURN)));
    outln();
    CetakCommand();
    
}
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
void Adjust(){
        //Kamus
        int N, x, y, i,j;
        char C;
        POINT P;
        BANGUNAN B;
        
        TURN = 1;
        CreateGraph(&GRAPH);
        // printf("%d", TURN);
        // NextTurn();
        // printf("%d", TURN);
        i = 1;

        set(true);
        STARTKATA();
        NBrsEff(Map) = toInt(CKata);
        // printf("%d", NBrsEff(M));
        // CetakKata(CKata);
        // outln();
        // printf("%d", toInt(CKata));
        // outln();
        ADVKATA();
        NKolEff(Map) = toInt(CKata);
        // printf("%d",NKolEff(M));
        ADVKATA();
        MakeMATRIKS(NBrsEff(Map), NKolEff(Map),&Map);
        N = toInt(CKata);
        MakeEmpty(&A, N);
        ADVKATA();
        C= toChar(CKata);
        ADVKATA();
        x= toInt(CKata);
        ADVKATA();
        y= toInt(CKata);
        P = MakePOINT(x,y);
        B = SetBangunan(C,1, P);
        Bangunan(A, i) = B;
        Elmt(Map,x,y) = i;
        InsertGNode(&GRAPH,i);
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
        Elmt(Map,x,y) = i;
        InsertGNode(&GRAPH,i);
        ADVKATA();
        for (i=3; i <= N; i++){
            C= toChar(CKata);
            ADVKATA();
            x= toInt(CKata);
            ADVKATA();
            y= toInt(CKata);
            P = MakePOINT(x,y);
            B = SetBangunan(C,0, P);
            Neff(A)= i;
            Bangunan(A, i) = B;
            Elmt(Map,x,y) = i;
            InsertGNode(&GRAPH,i);
            //A[i] = B;
            //M[lokasi(B).x][lokasi(B).y]=B;
            ADVKATA();
        }
        for (i=1; i<=N; i++){   
            for(j=1; j<=N; j++){
                if(toInt(CKata)==1){
                    InsertEdge(&GRAPH,i,j);
                }
                ADVKATA();
            }
        }
        CreateEmpty(&L1);
        // PrintInfo(L1);
        ListBangunan(&L1,1);
        //PrintInfo(L1);
        //PrintListBangunan(L1);
        // for (i = 1; i<= N; i++) {
        //     PrintStatus(Bangunan(A, i));
        //     outln();
        // }
        CreateEmpty(&L2);
        ListBangunan(&L2,2);
        //PrintListBangunan(L2);
        //CreateEmpty(&LS);
        //ListBangunanSerang(&LS,1);
        //PrintListBangunan(LS);
        //TulisMATRIKS(Graph);
        //outln();
        CreateEmptyQueue(&Skill1,20);
        CreateEmptyQueue(&Skill2,20);
        AddQueue(&Skill1, TabCHartoKata("IU"));
        AddQueue(&Skill2, TabCHartoKata("IU"));
    }

void StartGame(){
    Adjust();
    CetakMap();
    CetakTurn();
}
int main(){
    StartGame();
    
    return 0;
}