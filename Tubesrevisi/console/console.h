#ifndef CONSOLE_H
#define CONSOLE_H

#include "../mesinkata/mesinkata.h"
#include "../boolean/boolean.h"
extern int TURN;
extern boolean ENDTURN, Extra_turn, ENDGAME,NEED, newG;


int ENEMY();
/* I.S Giliran Pemain
F. S Untuk mendapatkan nomor pemain yang sedang tidak mendapatkan giliran*/
void NextTurn();
/*I.S: Giliran pemain.
  F.S. Giliran pemain berganti.*/
void outln();
/*I.S: Sembarang
  F.S: Mencetak enter*/
int toInt(Kata K);
/*Input: Kata.
  Output: k=Kata diubah menjadi integer.*/
void CetakKata(Kata K);
/*I.S: Sembarang.
  F.S: Mencetak kata.*/
char toChar(Kata K);
/*Input: Kata
  Output: Mengubah kata menjadi character.*/
boolean CMPKata(Kata K1, Kata K2);
/*Input: Kata
  Output: Mengembalikan true jika panjang kedua kata sama*/
boolean CMPKATATabChar(Kata K, char* str);
/*Input: Kata dan String Karakter.
  Output: Boolean true jika...*/
Kata TabCHartoKata(char* str);
/*Input: String
  OutputL Mengubah karakter string menjadi kata.*/

boolean tobool(Kata K);
/*Input: Kata
  Output: Mengubah kata menjadi boolean 0 1.*/
#endif