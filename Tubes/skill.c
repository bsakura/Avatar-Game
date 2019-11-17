/* ADT SKILL*/
#include "bangunan.h"
#include "listlinier.h"
#include "skill.h"
#include "boolean.h"
#include "arraydin.h"
#include "console.h"
#include "queue.h"

//SYARAT SYARAT SKILL BELOM ADA
//CRIT SAMA ATK UP MASIH BELOM BERES DI COMMAND.C (masalah shield dkk)
//CRIT NON-AKTIFIN SHIELD SAMA ATK UP SIAPA?
//ATK UP SATU SERANGAN AJA ATO ENGGA?
//CRIT SAMA ATK UP BISA DIGABUNG DALAM SATU TURN APA ENGGA (sekarang diset bisa)
//KURANG KURANGAN KALO PAKE CRIT KAGA PAHAM GUA

void useSkill(){
    Kata skill;
    switch (TURN)
    {
    case 1:
        DelQueue(&Skill1,&skill);
        break;
    
    default:
        DelQueue(&Skill2,&skill);
        break;
    }
    
    //CetakKata(skill);
    if (CMPKATATabChar(skill, "IU")){
        InstantUpgrade();
    }else if (CMPKATATabChar(skill, "Shield")){
        Shield();
    }else if (CMPKATATabChar(skill, "ET")){
        ExtraTurn();
    }else if (CMPKATATabChar(skill, "AU")){
        AttackUp();
    }else if (CMPKATATabChar(skill, "CH")){
        CriticalHit();
    }else if (CMPKATATabChar(skill, "IR")){
        InstantReinforcement();
    }else{//Barrage
        Barrage();
    }
}

void InstantUpgrade()
//Seluruh bangunan yang dimiliki pemain akan naik 1 level.
//Pemain tidak akan mendapat skill ini selain dari daftar skill awal.
{
    address a = First(GetListP(TURN));
    while(a != NULL)
    {
        LevelUp(&(Bangunan(A,Info(a))));
        a=Next(a);
    }
}

void Shield(Pemain P){}//BONUS
//Seluruh bangunan yang dimiliki oleh pemain akan memiliki pertahanan selama 2
//turn. Apabila skill ini digunakan 2 kali berturut-turut, durasi tidak akan bertambah,
//namun menjadi nilai maksimum.
//Pemain mendapat skill ini jika setelah sebuah lawan menyerang, bangunan pemain
//berkurang 1 menjadi sisa 2.

void ExtraTurn(Pemain P){
//Setelah giliran pengaktifan skill ini berakhir, pemain selanjutnya tetap pemain
//yang sama.
//Pemain mendapat skill ini jika Fort pemain tersebut direbut lawan.
    Extra_turn = true;
}

void AttackUp()//BONUS
//Pada giliran ini, setelah skill ini diaktifkan, pertahanan bangunan musuh tidak akan
//mempengaruhi penyerangan.
//Pemain mendapat skill ini jika pemain baru saja menyerang Tower lawan dan
//jumlah towernya menjadi 3.
{
    Atk_up = true;
}

void CriticalHit()//BONUS
//Pada giliran ini, setelah skill diaktifkan, jumlah pasukan pada bangunan yang
//melakukan serangan tepat selanjutnya hanya berkurang ½ dari jumlah
//seharusnya.
//Pemain mendapat skill ini jika lawan baru saja mengaktifkan skill Extra Turn.
{
    Crit = true;
}

void InstantReinforcement()
//Seluruh bangunan mendapatkan tambahan 5 pasukan.
//Pemain mendapat skill ini di akhir gilirannya bila semua bangunan yang ia miliki
//memiliki level 4.
//DENGAN ASUMSI KALO UDAH MAX GA NAMBAH LAGI PASUKANNYA
{
    address a;
    a = First(GetListP(TURN));
    while(a!=NULL){
        if(Pasukan(Bangunan(A, Info(a))) < Maksimum(Bangunan(A, Info(a))))
            {
                TambahPasukanManual(&(Bangunan(A,Info(a))), 5);
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
            TambahPasukanManual(&(Bangunan(A,Info(a))), -10);
        }else{
            SetPasukan(&(Bangunan(A, (Info(a)))),0);
        }
        
        a = Next(a);
    }
}