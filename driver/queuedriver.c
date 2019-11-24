#include "../Tubesrevisi/queue.c"
#include "../Tubesrevisi/mesinkata.c"
#include "../Tubesrevisi/input.c"
#include "../Tubesrevisi/console.c"
#include <stdio.h>

int main () {
	Queue Q1, Q2;
	int maxelq, i;
	scanf("%d", &maxelq);
	CreateEmptyQueue (&Q1, maxelq);
	CreateEmptyQueue (&Q2, maxelq);
	if (IsEmptyQueue (Q2)) {
		printf("!\n");
	}
	for (i = 1; i <= maxelq; i++) {
		AddQueue(&Q1, TabCHartoKata("T"));
	}
	if (IsFullQueue (Q1)) {
		printf("%d\n", NBElmtQueue(Q1));
	}
	CopyQueue(Q1, &Q2);
	for (i = 1; i <= maxelq; i++) {
		CetakKata(InfoHead(Q2));
		printf("\n");
	}
	DeAlokasiQueue(&Q2);
	for (i = 1; i <= maxelq; i++) {
		CetakKata(InfoHead(Q2));
		printf("\n");
	}
	return 0;
}