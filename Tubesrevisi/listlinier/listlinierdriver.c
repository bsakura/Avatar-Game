#include "listlinier.c"
#include "../bangunan/bangunan.c"
#include "../point/point.c"
#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	List LIST;
	address P;
	int input, awal, akhir;
	CreateEmpty(&LIST);
	scanf(" %d",&input);
	while(input != -999) {		
		if ((input <= 100) && (input >= 0)){
			InsVFirst(&LIST, input);
		}
		else{
			InsVLast(&LIST, input);
		}
		scanf(" %d",&input);
	} 
	
	if (!IsEmpty(LIST)){
		printf("%d\n", NbElmt(LIST));
		PrintInfo(LIST);
		printf("\n");
		DelVFirst(&LIST, &awal);
		DelVLast(&LIST, &akhir);
		printf("%d %d\n", awal, akhir);
		PrintInfo(LIST);
		printf("\n");
	}
	else{
		printf("Daftar nilai kosong\n");
	}
	DelFirst(&LIST, &P);
	DelP(&LIST, 100);
	PrintInfo(LIST);
	return 0;
}