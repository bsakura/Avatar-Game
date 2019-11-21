/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel dinamik */

#ifndef ARRAYDIN_H
#define ARRAYDIN_H

#include "boolean.h"
#include "bangunan.h"

/*  Kamus Umum */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
// typedef int IdxType; /* type indeks */
// typedef BANGUNAN ElType;  /* type elemen tabel */
typedef int IdxType;
typedef struct
{
  BANGUNAN *TI; /* memori tempat penyimpan elemen (container) */
  int Neff;   /* >=0, banyaknya elemen efektif */
  int MaxEl;  /* ukuran elemen */
} TabInt;
/* Indeks yang digunakan [IdxMin..MaxEl] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
   T.Neff  untuk mengetahui banyaknya elemen
   T.TI    untuk mengakses seluruh nilai elemen tabel
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: T.Neff = 0
  Definisi elemen pertama : T.TI[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** SELEKTOR ********** */
#define Neff(T) (T).Neff
#define TI(T) (T).TI
#define Bangunan(T, i) (T).TI[(i)]
#define MaxEl(T) (T).MaxEl

extern TabInt A;

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel);
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */


// /* ********** SELEKTOR (TAMBAHAN) ********** */
int MaxElement(TabInt T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
int NbElmtTab(TabInt T);
    /* Mengirimkan nila efektif  tabel */

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx(TabInt T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

void CopyTab(TabInt Tin, TabInt *Tout);
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */

#endif