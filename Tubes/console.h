#ifndef CONSOLE_H
#define CONSOLE_H

#include "mesinkata.h"

extern int TURN;
void NextTurn();
void outln();
int toInt(Kata K);
void CetakKata(Kata K);
char toChar(Kata K);
#endif