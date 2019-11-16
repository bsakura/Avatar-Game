/* ADT SKILL*/
#include "bangunan.h"
#include "listlinier.h"
#include "skill.h"
#include "boolean.h"
#include "arraydin.h"
#include "console.h"
void InstantUpgrade()
//Seluruh bangunan yang dimiliki pemain akan naik 1 level.
//Pemain tidak akan mendapat skill ini selain dari daftar skill awal.
{
    a = First(GetListP(TURN));
    while(a != NULL)
    {
        LevelUp(Bangunan(A,info(a)));
    }
}

void Shield(Pemain P);//BONUS
//Seluruh bangunan yang dimiliki oleh pemain akan memiliki pertahanan selama 2
//turn. Apabila skill ini digunakan 2 kali berturut-turut, durasi tidak akan bertambah,
//namun menjadi nilai maksimum.
//Pemain mendapat skill ini jika setelah sebuah lawan menyerang, bangunan pemain
//berkurang 1 menjadi sisa 2.

void ExtraTurn(Pemain P);
//Setelah giliran pengaktifan skill ini berakhir, pemain selanjutnya tetap pemain
//yang sama.
//Pemain mendapat skill ini jika Fort pemain tersebut direbut lawan.

void AttackUp(Pemain P);//BONUS
//Pada giliran ini, setelah skill ini diaktifkan, pertahanan bangunan musuh tidak akan
//mempengaruhi penyerangan.
//Pemain mendapat skill ini jika pemain baru saja menyerang Tower lawan dan
//jumlah towernya menjadi 3.

boolean CriticalHit(Pemain P);//BONUS
//Pada giliran ini, setelah skill diaktifkan, jumlah pasukan pada bangunan yang
//melakukan serangan tepat selanjutnya hanya berkurang ½ dari jumlah
//seharusnya.
//Pemain mendapat skill ini jika lawan baru saja mengaktifkan skill Extra Turn.

void InstantReinforcement()
//Seluruh bangunan mendapatkan tambahan 5 pasukan.
//Pemain mendapat skill ini di akhir gilirannya bila semua bangunan yang ia miliki
//memiliki level 4.
//DENGAN ASUMSI KALO UDAH MAX GA NAMBAH LAGI PASUKANNYA
{
    address a;
    a = First(GetListP(TURN));
    while(a!=NULL)
        if(Pasukan(Bangunan(A, Info(a))) < Maksimum(Bangunan(A, Info(a))))
            {
                TambahPasukanManual(Bangunan(A,info(a)), 5);
            }
        }
        a = Next(a);
    }
}

void Barrage()
//Jumlah pasukan pada seluruh bangunan musuh akan berkurang sebanyak 10
//pasukan.
//Pemain mendapat skill ini jika lawan baru saja bertambah bangunannya menjadi
//10 bangunan.
{
    address a;
    a = First(GetListP(ENEMY()));
    while(a!=NULL)
    {
        if(Pasukan(Bangunan(A, (Info(a)))) >= 10){
            TambahPasukanManual(Bangunan(A,info(a)), -10);
        }else{
            Pasukan(Bangunan(A, (Info(a)))) = 0;
        }
        
        a = Next(a);
    }
}