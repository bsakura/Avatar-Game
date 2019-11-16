//ADT Graph

#ifndef graph_H
#define graph_H

#include "boolean.h"
#include "listlinier.h"

typedef struct List adrSuccNode;
typedef struct tadrNode *adrNode;
typedef struct tadrNode {
    int infonode;
    adrNode Next;
    adrSuccNode Trail;
} GNode;

typedef struct {
  adrNode FirstN;
} Graph;

//Selektor
#define infoN(P) (P)->infonode
#define Trail(P) (P)->Trail
#define NextN(P) (P)->Next
#define FirstN(G) (G)->FirstN
//Konstruktor
adrNode AlokGNode(int X);
void DealokGNode(adrNode P);
void CreateGraph (Graph *G);
boolean SearchGNode(Graph G, int X);
boolean SearchEdge(Graph G, int prec, int succ);
void InsertGNode(Graph *G,int X);
void InsertEdge(Graph *G,int prec,int succ);



#endif