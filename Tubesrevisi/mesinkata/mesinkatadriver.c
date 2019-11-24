#include "mesinkata.c"
#include "../boolean/boolean.h"
#include "../console/console.c"
#include "../input/input.c"
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
