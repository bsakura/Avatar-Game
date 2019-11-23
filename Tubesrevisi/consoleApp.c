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
#include "command.h"
#include "player.h"


TabInt A;
List L1, L2, LMove, LAtk;
MATRIKS Map;
Kata STDIN;
Stack Undo;
Graph GRAPH;
boolean Extra_turn,ENDTURN,ENDGAME, NEED;

void CetakMap()
/*I.S: Sembarang
  F.s: Mencetak map ke layar.*/
{
    //Kamus lokal
    int i,j;
    //Algoritma
    for (i=GetFirstIdxKol(Map);i<=GetLastIdxKol(Map) +2; i++){
        printf("*");
    }
    outln();
    for (i=GetFirstIdxBrs(Map);i<=GetLastIdxBrs(Map); i++){
        printf("*");
        for (j=GetFirstIdxKol(Map); j<=GetLastIdxKol(Map);j++){
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
    for (i=GetFirstIdxKol(Map);i<=GetLastIdxKol(Map) +2; i++){
        printf("*");
    }
    outln();
}

void setstd()
/*I.S: Sembarang
  F.S: Mesin kar operasi ke STDIN.*/
{
    set(false);
    STARTKATA();
    STDIN = CKata;
}

void CetakCommand()
/*I.S: Sembarang
  F.S: Mencetak player sesuai giliran, skill yang tersedia, lalu menerima input command.*/
{
    //Algoritma
    CetakMap();
    printf("Player %d", TURN);
    outln();
    PrintListBangunan(GetListP(TURN));
    printf("Skill Available: ");
    infoSkill(TURN);
    outln();
    printf("ENTER COMMAND: ");
    if(NEED){
        char C;
        fscanf(stdin,"%c",&C);
    }
    NEED =false;
    setstd();
    Command();
    EndKata =true;
    
}


void CetakTurn()
/*I.S: Sembarang
  F.S: Mencetak giliran dengan mencetak command jika giliran dan game belum berakhir*/
{
    //Kamus Lokal
    content con;
    TabInt T;
    Player P1,P2;
    List LA,LB;
    //Algoritma
    CreateEmpty(&LMove);
    CreateEmpty(&LAtk);
    CopyList(&LA, LMove);
    CopyList(&LB, LAtk);
    CreateEmptyStack(&Undo);
    CopyTab(A, &T);
    CopyPlayer(&P1, Player1);
    CopyPlayer(&P2, Player2);
    CreateContent(&con, T, P1, P2, LA,LB);
    Push(&Undo,con);
    SetatkP(TURN, false);
    SetCritP(TURN, false);
    if (getShield(TURN)>0){
        SetShieldP(TURN, getShield(TURN)-1);
    }
    ENDTURN = false;
    while(!ENDTURN &&!ENDGAME){
        CetakCommand();
    }
}

void Adjust()
/*I.S: Sembarang
  F.S: Mengatur graf, player, dan dasar permainan*/
{
    //Algoritma
    //Config
    TURN = 1;
    ENDGAME = false;
    Extra_turn =false;
    ENDTURN = false;
    NEED = true;
    CreateGraph(&GRAPH);
    CreateEmpty(&L1);
    CreateEmpty(&L2);
    MakePlayer(&Player1, 1);
    MakePlayer(&Player2, 2);

    //Mulai Baca File
    set(true);
    STARTKATA();
    NBrsEff(Map) = toInt(CKata);
    ADVKATA();
    NKolEff(Map) = toInt(CKata);
    ADVKATA();
    MakeMATRIKS(NBrsEff(Map), NKolEff(Map),&Map);
    newA();
    ReadGraph();
    MakeMap();
    ListBangunan(&L1,1);
    ListBangunan(&L2,2);
    AddSkill(1, TabCHartoKata("IU"));
    AddSkill(2, TabCHartoKata("IU"));
}


void newA()

{
    
    //Kamus Lokal
    int N, i;
    char C;
    //Algoritma
    N = toInt(CKata);
    MakeEmpty(&A, N);
    i = GetFirstIdx(A);
    ADVKATA();
    // Baca Bangunan Player 1
    BacaBangunan(i, 1);
    i++;
    // Baca Bangunan Player 1
    BacaBangunan(i,2);
    i++;
    //Baca Bangunan Lainnya
    for (; i <= N; i++){
        BacaBangunan(i,0);
    }

}

void BacaBangunan(int i ,int X)
/*I.S: Sembarang
  F.S: Memvaca bangunan pada koordinat*/
{
    //Kamus Lokal
    int x, y;
    char C;
    BANGUNAN B;
    POINT P;
    //Algoritma
    C= toChar(CKata);
    ADVKATA();
    x= toInt(CKata);
    ADVKATA();
    y= toInt(CKata);
    P = MakePOINT(x,y);
    B = SetBangunan(C,X, P);
    Neff(A)= i;
    Bangunan(A, i) = B;
    ADVKATA();
}
void ReadGraph()
/*I.S: Sembarang
  F.S: Membaca graf*/
{
    //Kamus Lokal
    int i,j;
    //Algoritma
    for (i=1 ; i<= NbElmtTab(A); i++){
        InsertGNode(&GRAPH,i);
    }
    for (i=1; i<=NbElmtTab(A); i++){   
        for(j=1; j<=NbElmtTab(A); j++){
            if(toInt(CKata)==1){
               InsertEdge(&GRAPH,i,j);
             }
            ADVKATA();
        }
    }
}
void MakeMap()
/*I.S: Sembarang
  F.S: Membuat map.*/
{
    //Kamus Lokal
    int i;
    //Algoritma
    for (i =1; i<= NbElmtTab(A); i++){
        int x;
        int y;
        x =  Absis(lokasi(Bangunan(A,i)));
        y = Ordinat(lokasi(Bangunan(A,i)));
        Elmt(Map,x,y) = i;
    }
}


void newGame(){
//Proses memulai new Game
    Adjust();
    StartGame();
}

void StartGame()
/*I.S: Sembarang
  F.S: Memulai game.*/
{
    //Algoritma
    do{
        TambahPasukan();
        CetakTurn();
        if(!Extra_turn){
            NextTurn();
        }else{
            Extra_turn = false;
        }
    }while(!ENDGAME);
    //PrintListBangunan(L1);
}

void Load(){
/*Proses Melanjutkan permainan yang sudah disimpan*/
    //Kamus
    int i, N;
    content con;
    TabInt T;
    Player P1,P2;
    List LA,LB;
    //Algoritma
    ENDGAME = false;
    ENDTURN = false;
    NEED = true;
    CreateGraph(&GRAPH);
    CreateEmpty(&L1);
    CreateEmpty(&L2);
    CreateEmpty(&LAtk);
    CreateEmpty(&LMove);
    MakePlayer(&Player1, 1);
    MakePlayer(&Player2, 2);
    set(true);
    STARTKATA();
    TURN = toInt(CKata);
    ADVKATA();
    Extra_turn = tobool(CKata);
    ADVKATA();
    NBrsEff(Map) = toInt(CKata);
    ADVKATA();
    NKolEff(Map) = toInt(CKata);
    ADVKATA();
    MakeMATRIKS(NBrsEff(Map), NKolEff(Map),&Map);
    //load A
    N = toInt(CKata);
    MakeEmpty(&A, N);
    Neff(A) = N;
    ADVKATA();
    for (i = GetFirstIdx(A); i <= GetLastIdx(A); i++)
    {
        loadBangunan(i);
    }
    MakeMap();
    ListBangunan(&L1,1);
    ListBangunan(&L2,2);
    loadgraph();
    loadPlayer(1);
    loadPlayer(2);
    outln();
    loadList(&LMove);
    loadList(&LAtk);
    
    CopyList(&LA, LMove);
    CopyList(&LB, LAtk);
    CreateEmptyStack(&Undo);
    CopyTab(A, &T);
    CopyPlayer(&P1, Player1);
    CopyPlayer(&P2, Player2);
    CreateContent(&con, T, P1, P2, LA,LB);
    Push(&Undo,con);
    while(!ENDTURN &&!ENDGAME){
        CetakCommand();
    }
    if(!Extra_turn){
        NextTurn();
    }else{
        Extra_turn = false;
    }
    if(!ENDGAME){
        StartGame();
    }
}   


void loadBangunan(int i){
/*Baca bangunan dari file load*/
    char C;
    int P, AA, M, PA, L, x, y;
    C = toChar(CKata);
    ADVKATA();
    P = toInt(CKata);
    ADVKATA();
    AA = toInt(CKata);
    ADVKATA();
    M = toInt(CKata);
    ADVKATA();
   
    PA = toInt(CKata);
    ADVKATA();

    L= toInt(CKata);
    ADVKATA();

    x = toInt(CKata);
    ADVKATA();
    y = toInt(CKata);
    ADVKATA();
     
    MakeBangunan(&Bangunan(A,i), C, P, AA, M, PA, L, x, y);
}

void loadgraph(){
/*Baca graph dari file load*/
    adrNode N;
    int i;
    for (i=1 ; i<= NbElmtTab(A); i++){
        InsertGNode(&GRAPH,i);
    }
    N = GRAPH.First;
    for (i=1; i<=NbElmtTab(A); i++){   
        while (toChar(CKata)!='.')
        {
            InsVLast(&(Trail(N)), toInt(CKata));
            ADVKATA();
        }
        N = NextN(N);
        ADVKATA();
    }
}

void loadPlayer(int X){
/*Baca Player dari file load*/
    while(toChar(CKata) != '.'){
        AddSkill(X, CKata);
        ADVKATA();
    }
    ADVKATA();
    SetatkP(X, tobool(CKata));
    ADVKATA();
    SetCritP(X, tobool(CKata));
    ADVKATA();
    SetShieldP(X, toInt(CKata));
    ADVKATA();
}

void loadList(List *L){
/*Baca List dari file load*/
    while (toChar(CKata)!= '.')
    {
        InsVLast(L, toInt(CKata));
        ADVKATA();
    }
    ADVKATA();
}