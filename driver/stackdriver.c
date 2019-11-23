
#include <stdio.h>
#include "../Tubesrevisi/stackt.h"
#include <stdlib.h>


void PrintSum(Stack S)
{
    int i;

    for (i = Top(S); i > 0; i--){
        printf("%d",S.T[i]);
    }
}

int main(void){
	

	Stack Sum;
	

	infotype El1, El2;
	content temp;
	

	CreateEmpty(&Sum);
	int i;
	for (i=0; i<5; i++) {
		scanf("%d", &temp);
	    Push(&Sum, temp);
	} 
	PrintSum(Sum);
	printf("\n");
	
	return 0;
}