/* ADT Bangunan */

#include "boolean.h"
#include "bangunan.h"

void MakeEmpty (ARRAYB *A, int N) {
    //Kamus Lokal
    int i;
    //Algoritma
    for (i = 1; i <= NBBangunan(*A); i++) {
        Jenis(Bangunan(*A, i)) = 'X';
        Kepemilikan(Bangunan(*A, i)) = 0; 
        Level(Bangunan(*A, i)) = 0;
        Pasukan(Bangunan(*A, i)) = 0;
        Maksimum(Bangunan(*A, i)) = 0;
        PasukanAwal(Bangunan(*A, i)) = 0;
    }
}

BANGUNAN SetBangunan (Jenis J, Pemain P, POINT lokasi) 
/* Input: Jenis bangunan yang diinginkan, pemain, dan point
   Output: Bangunan sudah ditentukan kepemilikan, level, dan jenisnya.*/
{
    //Kamus Lokal
    BANGUNAN B;
    //Algoritma
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

void MakeCastle (BANGUNAN *B) 
/*I.S. Bangunan
  F.S. Castle terbentuk. */
{
    //Kamus Lokal
    //Algoritma
    Jenis(*B) = 'C';
    SetMaksimum(B);
    if (Kepemilikan(*B) ==0) {
        PasukanAwal(*B) = 40;
        Pasukan(*B) = PasukanAwal(*B);
    }
    else {
        PasukanAwal(*B) =0;
        Pasukan(*B) =0;
    }
}

void MakeTower (BANGUNAN *B) 
/*I.S. Bangunan
  F.S. Tower terbentuk. */
{
    //Kamus Lokal
    //Algoritma
    Jenis(*B) = 'T';
    SetMaksimum(B);
    if (Kepemilikan(*B) ==0) {
        PasukanAwal(*B) = 30;
        Pasukan(*B) = PasukanAwal(*B);
    }
    else {
        PasukanAwal(*B) =0;
        Pasukan(*B) =0;
    }
}

void MakeFort (BANGUNAN *B) 
/*I.S. Bangunan
  F.S. Fort terbentuk. */
  {
    //Kamus Lokal
    //Algoritma
    Jenis(*B) = 'F';
    SetMaksimum(B);
    if (Kepemilikan(*B) ==0) {
        PasukanAwal(*B) = 80;
        Pasukan(*B) = PasukanAwal(*B);
    }
    else {
        PasukanAwal(*B) =0;
        Pasukan(*B) =0;
    }
}

void MakeVillage (BANGUNAN *B) 
/*I.S. Bangunan
  F.S. Fort terbentuk. */
{
    //Kamus Lokal
    //Algoritma
    Jenis(*B) = 'V';
    SetMaksimum(B);
    if (Kepemilikan(*B) ==0) {
        PasukanAwal(*B) = 20;
        Pasukan(*B) = PasukanAwal(*B);
    }
    else {
        PasukanAwal(*B) =0;
        Pasukan(*B) =0;
    }
}

boolean IsPertahanan (BANGUNAN B) 
/*Input: Bangunan sembarang.
  Output: Boolean true jika bangunan berjenis T dan jika F namun level diatas tiga.*/
{
    //Kamus Lokal
    //Algoritma
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
    //Kamus Lokal
    //Algoritma
    Kepemilikan(*B) = P;
}

boolean IsKepemilikan (BANGUNAN B, Pemain P) 
/*Input: Bangunan dan Pemain
  Output: Boolean true jika bangunan merupakan milik pemain.*/
{
    //Kamus Lokal
    //Algoritma
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
    //Kamus Lokal
    int PasukanAwal, Selisih;
    //Algoritma
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
    //Kamus Lokal
    //Algoritma
    Pasukan(*B) += Pasukan;
}

void SerangBangunan (BANGUNAN *B1, BANGUNAN *B2, int Pasukan) 
/*I.S.: Bangunan 
  F.S.: Pasukan dari bangunan yang diserang berkurang dan jika pasukan habis, kepemilikan bangunan akan berubah.*/
{
    //Kamus Lokal
    //Algoritma
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

void LevelUp (BANGUNAN *B) 
/*I.S.: Bangunan
  F.S.: Level dari bangunan ditingkatkan jikq mmemenuhi spesifikasi yang ditentukan.*/
{
    //Kamus Lokal
    //Algoritma
    if (Pasukan(*B) >= (Maksimum(*B) / 2)) {
        if (Level(*B) < 4) {
            Level(*B) += 1;
            Pasukan(*B) -= (Maksimum(*B) / 2);
            SetMaksimum(B);
        }
    }
}

void SetMaksimum (BANGUNAN *B) 
/*I.S.: Bangunan jenis sembarang
  F.S.: Pasukan bangunan ditingkatkan sesuai dengan jenis dan level dari bangunan.*/
{
    //Kamus Lokal
    //Algoritma
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
    //Kamus Lokal
    //Algoritma
    if (Jenis(B) == 'C') {
        printf("Castle");
    }
    else if (Jenis(B) == 'T') {
        printf("Tower");
    }
    else if (Jenis(B) == 'F') {
        printf("Fort");
    }
    else if (Jenis(B) == 'V') {
        printf("Village");
    }
    printf(" %d", Pasukan(B));
    printf(" lv. %d", Level(B));
}