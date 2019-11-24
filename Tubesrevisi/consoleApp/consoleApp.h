#ifndef CONSOLEAPP_H
#define CONSOLEAPP_H

#include "../matriks/matriks.h"

void CetakMap();
/*I.S: Sembarang
  F.s: Mencetak map ke layar.*/


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
  F.S: Mesin kar operasi ke STDIN.*/

void MakeMap();
/*I.S: Sembarang
  F.S: Membuat map.*/

void newA();
/*Membuat TabInt A dari new Gamw*/

void ReadGraph();
/*I.S: Sembarang
  F.S: Membaca graf*/

void BacaBangunan(int i ,int X);
/*I.S: Sembarang
  F.S: Memvaca bangunan pada koordinat*/

void Load();
/*Proses Melanjutkan permainan yang sudah disimpan*/

void loadBangunan();
/*Baca bangunan dari file load*/

void loadgraph();
/*Baca graph dari file load*/
void loadPlayer();
/*Baca Player dari file load*/

void loadList();
/*Baca List dari file load*/

void newGame();
//Proses memulai new Game

#endif