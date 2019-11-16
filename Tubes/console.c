#include <stdio.h>
#include "console.h"
#include "input.h"
#include <stdlib.h>
int TURN;

int ENEMY(){
    switch (TURN)
    {
    case 1:
        return 2;
        break;
    
    default:
        return 1;
    }
}
void NextTurn(){
    switch (TURN)
    {
    case 1:
        TURN = 2;
        break;
    
    default:
        TURN = 1;
    }
}
void outln(){
    printf("\n");
}
int toInt(Kata K){
    int i, kali, res;
    res=0;
    kali = 1;
    for (i= K.Length; i>= 1; i--){
        res += ((int) K.TabKata[i] -'0')* kali;
        kali *= 10;
    }   
    return res;
}

void CetakKata(Kata K){
    int i;
    for(i=1; i<= K.Length; i++){
        printf("%c", K.TabKata[i]);
    }
}
char toChar(Kata K){
    return K.TabKata[1];
}

boolean CMPKata(Kata K1, Kata K2){
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

int lengthTabChar(char* str){
    int count=0;
    while (str[count]!='\0')
    {
        count++;
    }
    return count;
    
}

boolean CMPKATATabChar(Kata K, char* str){
	for(int i = 1; i<=K.Length ; i++){
		if (K.TabKata[i] != str[i-1])
			return false;
	}
	return true;
}