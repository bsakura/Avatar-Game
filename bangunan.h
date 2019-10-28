
#ifndef BANGUNAN_H
#define BANGUNAN_H
#include "point.h"
#include "boolean.h"
typedef struct {
	char jenis;
	int pemilik;
    int jumpas;
    int level; 
    int A;
    int M;
    boolean P;
    int U;
    POINT lokasi;
} BANGUNAN;

#define jenis(B)   (B).jenis
#define pemilik(B)   (B).pemilik
#define jumpas(B)   (B).jumpas
#define level(B)   (B).level
#define lokasi(B)   (B).lokasi
#define A(B)   (A).lokasi
#define M(B)   (M).lokasi
#define P(B)   (P).lokasi
#define U(B)   (U).lokasi

void MakeBangunan(BANGUNAN *B,char jenis, int pemilik);

void SetAMP(BANGUNAN *B, int A, int M, boolean P);
void AddPas(BANGUNAN *B, int X);
void AutoAddPas(BANGUNAN *B);
void Level_Up(BANGUNAN *B);
void Level_UpC(BANGUNAN *B);
void Level_UpT(BANGUNAN *B);
void Level_UpF(BANGUNAN *B);
void Level_UpV(BANGUNAN *B);

#endif