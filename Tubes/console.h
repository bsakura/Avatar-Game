#ifndef CONSOLE_H
#define CONSOLE_H

#include "mesinkata.h"

extern int TURN;
void NextTurn();
void outln();
int toInt(Kata K);
void CetakKata(Kata K);
char toChar(Kata K);
boolean CMPKata(Kata K1, Kata K2);
#endif