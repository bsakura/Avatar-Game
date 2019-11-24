/* ADT Bangunan */
#ifndef BANGUNAN_H
#define BANGUNAN_H

#include "../boolean/boolean.h"
#include "../point/point.h"

typedef int Pemain; 
typedef char Jenis;
typedef struct { 
    Jenis J;
    Pemain P;
    int L;
    int A;
    int M;
    int U;
    POINT lokasi;
} BANGUNAN;

/* ************  SELEKTOR   ************ */
#define Jenis(B) (B).J
#define Kepemilikan(B) (B).P
#define Level(B) (B).L
#define Pasukan(B) (B).A
#define Maksimum(B) (B).M
#define PasukanAwal(B) (B).U
#define lokasi(B) (B).lokasi

/* ************  PROTOTYPE  ************ */
/* ************ KONSTRUKTOR ************ */
BANGUNAN SetBangunan (Jenis J, Pemain P, POINT lokasi); 
/* Input: Jenis bangunan yang diinginkan, pemain, dan point
   Output: Bangunan sudah ditentukan kepemilikan, level, dan jenisnya.*/

void CopyBangunan(BANGUNAN *B, BANGUNAN Bin);
/*I.S: Sembarang
  F.S: Bangunan disalin.*/

void MakeCastle (BANGUNAN *B); 
/*I.S. Bangunan
  F.S. Castle terbentuk. */

void MakeTower (BANGUNAN *B); 
/*I.S. Bangunan
  F.S. Tower terbentuk. */

void MakeFort (BANGUNAN *B);
/*I.S. Bangunan
  F.S. Fort terbentuk. */ 

void MakeVillage (BANGUNAN *B); 
/*I.S. Bangunan
  F.S. Fort terbentuk. */

boolean IsPertahanan (BANGUNAN B); 
/*Input: Bangunan sembarang.
  Output: Boolean true jika bangunan berjenis T dan jika F namun level diatas tiga.*/

void SetKepemilikan (BANGUNAN *B, Pemain P); 
/*I.S: Bangunan sembarang
  F.S: Bangunan dimiliki oleh pemain pada input.*/

boolean IsKepemilikan (BANGUNAN B, Pemain P); 
/*Input: Bangunan dan pemain
  Output: True jika benar bangunan dimiliki oleh pemain pada input.*/

void TambahPasukanAuto (BANGUNAN *B); 
/*I.S.: Bangunan
  F.S.: Jumlah pasukkan pada bangunan bertambah sesuai dengan level secara automatis bergantung jenis bangunan.*/

void TambahPasukanManual (BANGUNAN *B, int Pasukan); 
/*I.S.: Bangunan dan pasukan
  F.S.: Pasukan ditambahkan secara manual.*/

void LevelUp (BANGUNAN *B); 
/*I.S.: Bangunan
  F.S.: Level dari bangunan ditingkatkan jikq mmemenuhi spesifikasi yang ditentukan.*/

void SetMaksimum (BANGUNAN *B); 
/*I.S.: Bangunan jenis sembarang
  F.S.: Pasukan bangunan ditingkatkan sesuai dengan jenis dan level dari bangunan.*/

void PrintStatus (BANGUNAN B); 
/*I.S.: Status sembarang, tidak kosong.
  F.S.: Program mencetak status ke layar.*/

void SetPasukan(BANGUNAN *B, int Pas);
/*I.S: Bangunan 
  F.S: Bangunan dengan pasukan yang ditentukan.*/

void PrintJenisPoint(BANGUNAN B);
/*I.S.: Bangunan.
  F.S.: Program mencetak jenis point ke layar.*/

void MakeBangunan(BANGUNAN *B, char J, int P, int A, int M, int PA ,int L, int x, int y);
/*I.S.: Bangunan.
  F.S.: Program Membuat bangunan dari komponennya.*/


#endif