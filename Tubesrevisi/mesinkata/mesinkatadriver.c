#include "mesinkata.h"
#include "../console/console.h"
#include "../boolean/boolean.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
	//membaca kata pertama pada file newgame.txt dan mencetaknya langsung
	newG = true;
	set(true);
	STARTKATA();
	printf("%d", toInt(CKata));
	outln();
	//membaca STDIN dan mencetaknya langsung
	set(false);
	STARTKATA();
	CetakKata(CKata);
	return 0;
}