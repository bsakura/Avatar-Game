/*ADT SKILL*/

#ifndef SKILL_H
#define SKILL_H

#include "boolean.h"
#include "bangunan.h"
#include "arraydin.h"

extern boolean Atk_up, Crit;

void useSkill();

void InstantUpgrade();
//Seluruh bangunan yang dimiliki pemain akan naik 1 level.
//Pemain tidak akan mendapat skill ini selain dari daftar skill awal.

void Shield();//BONUS
//Seluruh bangunan yang dimiliki oleh pemain akan memiliki pertahanan selama 2
//turn. Apabila skill ini digunakan 2 kali berturut-turut, durasi tidak akan bertambah,
//namun menjadi nilai maksimum.
//Pemain mendapat skill ini jika setelah sebuah lawan menyerang, bangunan pemain
//berkurang 1 menjadi sisa 2.

void ExtraTurn();
//Setelah giliran pengaktifan skill ini berakhir, pemain selanjutnya tetap pemain
//yang sama.
//Pemain mendapat skill ini jika Fort pemain tersebut direbut lawan.

void AttackUp();//BONUS
//Pada giliran ini, setelah skill ini diaktifkan, pertahanan bangunan musuh tidak akan
//mempengaruhi penyerangan.
//Pemain mendapat skill ini jika pemain baru saja menyerang Tower lawan dan
//jumlah towernya menjadi 3.

void CriticalHit();//BONUS
//Pada giliran ini, setelah skill diaktifkan, jumlah pasukan pada bangunan yang
//melakukan serangan tepat selanjutnya hanya berkurang ½ dari jumlah
//seharusnya.
//Pemain mendapat skill ini jika lawan baru saja mengaktifkan skill Extra Turn.

void InstantReinforcement();
//Seluruh bangunan mendapatkan tambahan 5 pasukan.
//Pemain mendapat skill ini di akhir gilirannya bila semua bangunan yang ia miliki
//memiliki level 4.

void Barrage();
//Jumlah pasukan pada seluruh bangunan musuh akan berkurang sebanyak 10
//pasukan.
//Pemain mendapat skill ini jika lawan baru saja bertambah bangunannya menjadi
//10 bangunan.

#endif