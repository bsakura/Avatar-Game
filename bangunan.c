#include "bangunan.h"


void MakeBangunan(BANGUNAN *B,char jenis, int pemilik, POINT lok){
    jenis(*B)= jenis;
    pemilik(*B) = pemilik;
    level(*B)= 1;
    lokasi(*B) = lok;
    switch (jenis(*B))
    {
    case 'C':
        A(*B) = 10;
        M(*B) = 40;
        P(*B) = false;
        U(*B) = 40;
        break;
    case 'T':
        A(*B) = 5;
        M(*B) = 20;
        P(*B) = true;
        U(*B) = 30;
        break;
    case 'F':
        A(*B) = 10;
        M(*B) = 20;
        P(*B) = false;
        U(*B) = 80;
        break;
    default:
        A(*B) = 5;
        M(*B) = 20;
        P(*B) = false;
        U(*B) = 20;
        break;
    } 
}

void SetAMP(BANGUNAN *B, int A, int M, boolean P){}
    P(*B) = ; 
}

void AddPas(BANGUNAN *B, int X){
    jumpas(*B) += X;
}

void AutoAddPas(BANGUNAN *B){
    if (P(*B)> M(*B)){
        AddPas(B, A(*B));
    }
}

void Level_Up(BANGUNAN *B){
    switch (jenis(*B))
    {
    case 'C':
        Level_UpC(B);
        break;
    case 'T':
        Level_UpT(B);
        break;
    case 'F':
        Level_UpF(B);
        break;  
    default:
        Level_UpV(B);
        break;
    }
}
void Level_UpC(BANGUNAN *B){
    switch (level(*B))
    {
    case 1:
        level(*B) +=1;
        SetAMP(B, 15, 60, false);
        break;
    case 2:
        level(*B) +=1;
        SetAMP(B, 20, 80, false);
        break;  
    default:
        level(*B) +=1;
        SetAMP(B, 25, 100, false);
        break;
    }
}
void Level_UpT(BANGUNAN *B){
    switch (level(*B))
    {
    case 1:
        level(*B) +=1;
        SetAMP(B, 10, 30, true);
        break;
    case 2:
        level(*B) +=1;
        SetAMP(B, 20, 40, true);
        break;  
    default:
        level(*B) +=1;
        SetAMP(B, 30, 50, true);
        break;
    }
}
void Level_UpF(BANGUNAN *B){
    switch (level(*B))
    {
    case 1:
        level(*B) +=1;
        SetAMP(B, 20, 40, false);
        break;
    case 2:
        level(*B) +=1;
        SetAMP(B, 30, 60, true);
        break;  
    default:
        level(*B) +=1;
        SetAMP(B, 40, 80, false);
        break;
    }
}
void Level_UpV(BANGUNAN *B){
    switch (level(*B))
    {
    case 1:
        level(*B) +=1;
        SetAMP(B, 10, 30, false);
        break;
    case 2:
        level(*B) +=1;
        SetAMP(B, 15, 40, false);
        break;  
    default:
        level(*B) +=1;
        SetAMP(B, 20, 50, false);
        break;
    }
}
