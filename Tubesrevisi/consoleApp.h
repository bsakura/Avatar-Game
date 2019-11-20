#ifndef CONSOLEAPP_H
#define CONSOLEAPP_H

#include "matriks.h"
void CetakMap();
/*I.S: Sembarang
  F.s: Mencetak map ke layar.*/

void outln();
/*I.S: Sembarang
  F.S: Mencetak enter.*/

void CetakCommand();
/*I.S: Sembarang
  F.S: Mencetak player sesuai giliran, skill yang tersedia, lalu menerima input command.*/

void CetakTurn();
/*I.S: Sembarang
  F.S: Mencetak giliran dengan mencetak command jika giliran dan game belum berakhir*/

void StartGame();
/*I.S: Sembarang
  F.S: Memulai game.*/

void Adjust();
/*I.S: Sembarang
  F.S: Mengatur graf, player, dan dasar permainan*/

void setstd();
/*I.S: Sembarang
  F.S: Mengebalikan kondisi standard.*/

void MakeMap();
/*I.S: Sembarang
  F.S: Membuat map.*/

void newA();

void BacaBangunan(int i ,int X);
/*I.S: Sembarang
  F.S: Memvaca bangunan pada koordinat*/
#endif