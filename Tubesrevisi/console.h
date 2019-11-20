#ifndef CONSOLE_H
#define CONSOLE_H

#include "mesinkata.h"

extern int TURN;
extern boolean ENDTURN, Extra_turn, ENDGAME,NEED, newG;;
void ReadGraph();
int ENEMY();
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
char* KatatoTabChar(Kata K);
#endif