/* ADT Bangunan */
#ifndef BANGUNAN_H
#define BANGUNAN_H

#include "boolean.h"

#define Nil 0

typedef int Pemain; 
typedef char Jenis;
typedef struct { 
    Jenis J;
    Pemain P;
    int L;
    int A;
    int M;
    int U;
} BANGUNAN;

/* ************  SELEKTOR   ************ */
#define Jenis(B) (B).J
#define Kepemilikan(B) (B).P
#define Level(B) (B).L
#define Pasukan(B) (B).A
#define Maksimum(B) (B).M
#define PasukanAwal(B) (B).U

/* ************  PROTOTYPE  ************ */
/* ************ KONSTRUKTOR ************ */
BANGUNAN SetBangunan (Jenis J, Pemain P);
void MakeCastle (BANGUNAN *B);
void MakeTower (BANGUNAN *B);
void MakeFort (BANGUNAN *B);
void MakeVillage (BANGUNAN *B);
boolean IsPertahanan (BANGUNAN B);
void SetKepemilikan (BANGUNAN *B, Pemain P);
boolean IsKepemilikan (BANGUNAN B, Pemain P);
void TambahPasukanAuto (BANGUNAN *B);
void TambahPasukanManual (BANGUNAN *B, int Pasukan);
void SerangBangunan (BANGUNAN *B1, BANGUNAN *B2, int Pasukan);
void LevelUp (BANGUNAN *B);
void SetMaksimum (BANGUNAN *B);

/* ************   TESTING   ************ */
void PrintStatus (BANGUNAN B);

#endif