#include <stdio.h>
#include "console.h"
#include "input.h"
#include <stdlib.h>
int TURN;

int ENEMY(){
    //Algoritma
    switch (TURN)
    {
    case 1:
        return 2;
        break;
    
    default:
        return 1;
    }
}
void NextTurn()
/*I.S: Giliran pemain.
  F.S. Giliran pemain berganti.*/
{
    //Algoritma
    switch (TURN)
    {
    case 1:
        TURN = 2;
        break;
    
    default:
        TURN = 1;
    }
}
void outln()
/*I.S: Sembarang
  F.S: Mencetak enter*/
{
    //Algoritma
    printf("\n");
}

int toInt(Kata K)
/*Input: Kata.
  Output: k=Kata diubah menjadi integer.*/
{
    //Kamus Lokal
    int i, kali, res;
    //Algoritma
    res=0;
    kali = 1;
    for (i= K.Length; i>= 1; i--){
        res += ((int) K.TabKata[i] -'0')* kali;
        kali *= 10;
    }   
    return res;
}

void CetakKata(Kata K)
/*I.S: Sembarang.
  F.S: Mencetak kata.*/
{
    //Kamus Lokal
    int i;
    //Algoritma
    for(i=1; i<= K.Length; i++){
        printf("%c", K.TabKata[i]);
    }
}
char toChar(Kata K)
/*Input: Kata
  Output: Mengubah kata menjadi character.*/
{
    //Algoritma
    return K.TabKata[1];
}

boolean CMPKata(Kata K1, Kata K2)
/*Input: Kata
  Output: Mengembalikan true jika panjang kedua kata sama*/
{
    //Algoritma
    if (K1.Length!=K2.Length){
        return false;
    }else{
        for(int i=1; i<= K1.Length ; i++){
            if (K1.TabKata[i]!= K2.TabKata[i]){
                return false;
            }
        }
    }
    return true;
}

int lengthTabChar(char* str)
/*Input: String
  Output: Panjang karakter string.*/
{
    //Kamus Lokal
    int count=0;
    //Algoritma
    while (str[count]!='\0')
    {
        count++;
    }
    return count;
    
}

Kata TabCHartoKata(char* str)
/*Input: String
  OutputL Mengubah karakter string menjadi kata.*/
{
    //Kamus Lokal
    Kata K;
    int count=0;
    //Algoritma
    while (str[count]!='\0')
    {
        K.TabKata[count+1]=str[count];
        count++;
    }
    K.Length=count;
    return K;
}

boolean CMPKATATabChar(Kata K, char* str)
/*Input: Kata dan String Karakter.
  Output: Boolean true jika...*/
{
    //Algoritma
	for(int i = 1; i<=K.Length ; i++){
		if (K.TabKata[i] != str[i-1])
			return false;
	}
	return true;
}

void CopyKata(Kata *K1,Kata K2)
/*I.S: Kata
  F.S: Menyalin kata.*/
{
    //Algoritma
    *K1 =K2;
} 

// int main(){
//     char* c= "MOVE";
//     Kata K= TabCHartoKata(c);
//     CetakKata(K);
//     return 0;
// }