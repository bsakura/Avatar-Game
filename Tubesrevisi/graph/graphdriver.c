#include "graph.c"
#include "../listlinier/listlinier.c"

int main () {
    Graph G;
    adrNode P;
    int i, X;
    CreateGraph(&G);
    for (i = 1; i <= 3; i++) {
        scanf(" %d", &X);
        InsertGNode(&G, X);
    }
    P = SearchGNode(G, 5);
    if (P != Nil) {
        printf("%d\n", infoN(P));
    }
    InsertEdge(&G, 2, 9);
    P = G.First;
    while (P != Nil) {
        printf("%d\n", infoN(P));
        P = NextN(P);
    }
    return 0;
}