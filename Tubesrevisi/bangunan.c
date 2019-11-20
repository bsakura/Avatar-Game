/* ADT Bangunan */

#include "boolean.h"
#include "bangunan.h"
#include "point.h"

BANGUNAN SetBangunan (Jenis J, Pemain P, POINT lokasi) 
/* Input: Jenis bangunan yang diinginkan, pemain, dan point
   Output: Bangunan sudah ditentukan kepemilikan, level, dan jenisnya.*/
{
    BANGUNAN B;
    Kepemilikan(B) = P;
    Level(B) = 1;
    if (J == 'C') {
        MakeCastle(&B);
    }
    else if (J == 'T') {
        MakeTower(&B);
    }
    else if (J == 'F') {
        MakeFort(&B);
    }
    else if (J == 'V') {
        MakeVillage(&B);
    }
    lokasi(B) = lokasi;
    return B;
}

void CopyBangunan(BANGUNAN *B, BANGUNAN Bin)
/*I.S: Sembarang
  F.S: Bangunan disalin.*/
{
    *B = Bin;
}

void MakeCastle (BANGUNAN *B) 
/*I.S. Bangunan
  F.S. Castle terbentuk. */
{
    Jenis(*B) = 'C';
    SetMaksimum(B);
    // if (Kepemilikan(*B) ==0) {
        PasukanAwal(*B) = 40;
        Pasukan(*B) = PasukanAwal(*B);
    // }
    // else {
    //     PasukanAwal(*B) =0;
    //     Pasukan(*B) =0;
    // }
}

void MakeTower (BANGUNAN *B) 
/*I.S. Bangunan
  F.S. Tower terbentuk. */
{
    Jenis(*B) = 'T';
    SetMaksimum(B);
    //if (Kepemilikan(*B) ==0) {
        PasukanAwal(*B) = 30;
        Pasukan(*B) = PasukanAwal(*B);
    //}
    // else {
    //     PasukanAwal(*B) =0;
    //     Pasukan(*B) =0;
    // }
}

void MakeFort (BANGUNAN *B)
/*I.S. Bangunan
  F.S. Fort terbentuk. */ 
{
    Jenis(*B) = 'F';
    SetMaksimum(B);
    // if (Kepemilikan(*B) ==0) {
        PasukanAwal(*B) = 80;
        Pasukan(*B) = PasukanAwal(*B);
    // }
    // else {
    //     PasukanAwal(*B) =0;
    //     Pasukan(*B) =0;
    // }
}

void MakeVillage (BANGUNAN *B) 
/*I.S. Bangunan
  F.S. Fort terbentuk. */
{
    Jenis(*B) = 'V';
    SetMaksimum(B);
    // if (Kepemilikan(*B) ==0) {
        PasukanAwal(*B) = 20;
        Pasukan(*B) = PasukanAwal(*B);
    //}
    // else {
    //     PasukanAwal(*B) =0;
    //     Pasukan(*B) =0;
    // }
}

boolean IsPertahanan (BANGUNAN B) 
/*Input: Bangunan sembarang.
  Output: Boolean true jika bangunan berjenis T dan jika F namun level diatas tiga.*/
{
    if (Jenis(B) == 'T') {
        return true;
    }
    else if (Jenis(B) == 'F') {
        if (Level(B) >= 3) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

void SetKepemilikan (BANGUNAN *B, Pemain P) 
/*I.S: Bangunan sembarang
  F.S: Bangunan dimiliki oleh pemain pada input.*/
{
    Kepemilikan(*B) = P;
}

boolean IsKepemilikan (BANGUNAN B, Pemain P) 
/*Input: Bangunan dan pemain
  Output: True jika benar bangunan dimiliki oleh pemain pada input.*/
{
    if (Kepemilikan(B) == P) {
        return true;
    }
    else {
        return false;
    }
}

void TambahPasukanAuto (BANGUNAN *B) 
/*I.S.: Bangunan
  F.S.: Jumlah pasukkan pada bangunan bertambah sesuai dengan level secara automatis bergantung jenis bangunan.*/

{
    int PasukanAwal, Selisih;
    PasukanAwal = Pasukan(*B);
    if (Level(*B) == 1) {
        if (Jenis(*B) == 'C') {
            Pasukan(*B) += 10;
        }
        else if (Jenis(*B) == 'T') {
            Pasukan(*B) += 5;
        }
        else if (Jenis(*B) == 'F') {
            Pasukan(*B) += 10;
        }
        else if (Jenis(*B) == 'V') {
            Pasukan(*B) += 5;
        }
    }
    else if (Level(*B) == 2) {
        if (Jenis(*B) == 'C') {
            Pasukan(*B) += 15;
        }
        else if (Jenis(*B) == 'T') {
            Pasukan(*B) += 10;
        }
        else if (Jenis(*B) == 'F') {
            Pasukan(*B) += 20;
        }
        else if (Jenis(*B) == 'V') {
            Pasukan(*B) += 10;
        }
    }
    else if (Level(*B) == 3) {
        if (Jenis(*B) == 'C') {
            Pasukan(*B) += 20;
        }
        else if (Jenis(*B) == 'T') {
            Pasukan(*B) += 20;
        }
        else if (Jenis(*B) == 'F') {
            Pasukan(*B) += 30;
        }
        else if (Jenis(*B) == 'V') {
            Pasukan(*B) += 15;
        }
    }
    else if (Level(*B) == 4) {
        if (Jenis(*B) == 'C') {
            Pasukan(*B) += 25;
        }
        else if (Jenis(*B) == 'T') {
            Pasukan(*B) += 30;
        }
        else if (Jenis(*B) == 'F') {
            Pasukan(*B) += 40;
        }
        else if (Jenis(*B) == 'V') {
            Pasukan(*B) += 20;
        }
    }
    Selisih = Pasukan(*B) - PasukanAwal;
    if (Pasukan(*B) > Maksimum(*B)) {
        Pasukan(*B) -= Selisih;
    }
}

void TambahPasukanManual (BANGUNAN *B, int Pasukan) 
/*I.S.: Bangunan dan pasukan
  F.S.: Pasukan ditambahkan secara manual.*/
{
    Pasukan(*B) += Pasukan;
}

void SerangBangunan (BANGUNAN *B1, BANGUNAN *B2, int Pasukan) 
/*I.S.: Bangunan 
  F.S.: Pasukan dari bangunan yang diserang berkurang dan jika pasukan habis, kepemilikan bangunan akan berubah.*/
{
    if (Pasukan <= Pasukan(*B1)) {
        Pasukan(*B1) -= Pasukan;
        if (IsPertahanan(*B2)) {
            Pasukan = (Pasukan * 3) / 4;
        }
        Pasukan(*B2) -= Pasukan;
        if (Pasukan(*B2) < 0) {
            Pasukan(*B2) *= -1;
            Level(*B2) = 1;
            SetMaksimum(B2);
            SetKepemilikan(B2, Kepemilikan(*B1));
        }
    }
}
void SerangBangunanCritHit (BANGUNAN *B1, BANGUNAN *B2, int Pasukan) 
{
    if (Pasukan <= Pasukan(*B1)) {
        Pasukan(*B1) -= Pasukan/2;
        if (IsPertahanan(*B2)) {
            Pasukan = (Pasukan * 3) / 4;
        }
        Pasukan(*B2) -= Pasukan;
        if (Pasukan(*B2) < 0) {
            Pasukan(*B2) *= -1;
            Level(*B2) = 1;
            SetMaksimum(B2);
            SetKepemilikan(B2, Kepemilikan(*B1));
        }
    }
}

void LevelUp (BANGUNAN *B) 
/*I.S.: Bangunan
  F.S.: Level dari bangunan ditingkatkan jikq mmemenuhi spesifikasi yang ditentukan.*/
{
    if (Level(*B) < 4) {
        Level(*B) += 1;
        SetMaksimum(B);
    }
}

void SetMaksimum (BANGUNAN *B) 
/*I.S.: Bangunan jenis sembarang
  F.S.: Pasukan bangunan ditingkatkan sesuai dengan jenis dan level dari bangunan.*/
{
    if (Jenis(*B) == 'C') {
        Maksimum(*B) = 40 + (20 * (Level(*B) - 1));
    }
    else if (Jenis(*B) == 'T') {
        Maksimum(*B) = 20 + (10 * (Level(*B) - 1));
    }
    else if (Jenis(*B) == 'F') {
        Maksimum(*B) = 20 + (20 * (Level(*B) - 1));
    }
    else {
        Maksimum(*B) = 20 + (10 * (Level(*B) - 1));
    }
}

void PrintStatus (BANGUNAN B) 
/*I.S.: Status sembarang, tidak kosong.
  F.S.: Program mencetak status ke layar.*/
{
    if (Jenis(B) == 'C') {
        printf("Castle ");
    }
    else if (Jenis(B) == 'T') {
        printf("Tower ");
    }
    else if (Jenis(B) == 'F') {
        printf("Fort ");
    }
    else if (Jenis(B) == 'V') {
        printf("Village ");
    }
    TulisPOINT(lokasi(B));
    printf(" %d", Pasukan(B));
    printf(" lv. %d", Level(B));
    //printf(" %d", Kepemilikan(B));
}

void SetPasukan(BANGUNAN *B, int Pas)
/*I.S: Bangunan 
  F.S: Bangunan dengan pasukan yang ditentukan.*/
{
    Pasukan(*B) = Pas;
}

void PrintJenisPoint(BANGUNAN B)
/*I.S.: Bangunan.
  F.S.: Program mencetak jenis point ke layar.*/
{
    if (Jenis(B) == 'C') {
        printf("Castle ");
    }
    else if (Jenis(B) == 'T') {
        printf("Tower ");
    }
    else if (Jenis(B) == 'F') {
        printf("Fort ");
    }
    else if (Jenis(B) == 'V') {
        printf("Village ");
    }
    TulisPOINT(lokasi(B));
}
void MakeBangunan(BANGUNAN *B, char J, int Pl, int A, int M, int PA, int L, int x, int y){
  POINT P;

  Jenis(*B) = J;
  Kepemilikan(*B)= Pl;
  Pasukan(*B)= A;
  Maksimum(*B) = M;
  PasukanAwal(*B) = PA;
  Level(*B) = L;
  P = MakePOINT(x,y);
  lokasi(*B) = P;
}


