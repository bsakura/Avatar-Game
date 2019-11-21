/* File: point.c */
/* Tanggal: 28 Agustus 2016 */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */
/* Nama : Naufal Arfananda Ghifari*/
/*NIM : 13518096 */

#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "point.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y) {
/* Membentuk sebuah POINT dari komponen-komponennya */
    POINT P;
    /* ALGORITMA */
    Absis (P) = X;
    Ordinat (P) = Y;
    return P;
}
/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */

void TulisPOINT (POINT P){
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
    printf("(%0.0f,%0.0f)", Absis(P), Ordinat(P));
}

