/* File : stackt.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#include "stackt.h"
#include "../boolean/boolean.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElS */
/* jadi indeksnya antara 1.. MaxElS+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
    Top(*S) = Nill;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S){
/* Mengirim true jika Stack kosong: lihat definisi di atas */
    return (Top(S)==Nill);
}

boolean IsFullStack (Stack S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
    return (Top(S)==MaxElS);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, content X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

    Top(*S)++;
    
    InfoTop(*S)=X;
}
    
/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, content* X){
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    *X = InfoTop(*S);
    Top(*S)--;
}
void CreateContent(content *C,TabInt T,Player P1, Player P2, List LA, List LB ){
/* F.S Membuat content baru dari elemen elemennya*/
    (*C).T = T;
    (*C).P1 = P1;
    (*C).P2 = P2;
    (*C).LA = LA;
    (*C).LB = LB;    
}