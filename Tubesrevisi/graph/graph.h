//ADT Graph

#ifndef graph_H
#define graph_H

#include "../boolean/boolean.h"
#include "../listlinier/listlinier.h"
#include <stdio.h>
#include <stdlib.h>

#define Nil NULL
typedef List adrSuccNode;
typedef struct tadrNode *adrNode;
typedef struct tadrNode {
    int infonode;
    adrNode Next;
    adrSuccNode Trail;
} GNode;


typedef struct {
	adrNode First;
} Graph;

extern Graph GRAPH;
//Selektor
#define infoN(P) (P)->infonode
#define Trail(P) (P)->Trail
#define NextN(P) (P)->Next

//Konstruktor
adrNode AlokGNode(int X);
/*I.S: Sembarang
  F.S: Mengalokasikan node.*/

void DealokGNode(adrNode P);
/*I.S: Sembarang
  F.S: Node terdealokasi.*/

void CreateGraph (Graph *G);
/*I.S: Sembarang
  F.S: Graph baru terbuat.*/

adrNode SearchGNode(Graph G, int X);
/*I.S: Graph 
  F.S: Mengembalikan address dari node dimana C ditemukan.*/

boolean SearchEdge(Graph G, int prec, int succ);
/*Input: Graph, prec dan succ
  Output: Boolean true jika setelah pencarian node ..*/

void InsertGNode(Graph *G,int X);
/*I.S: Sembarang
  F.S: integer dimasukkan ke dalma graf.*/

void InsertEdge(Graph *G,int prec,int succ);
/*I.S: Sembarang
  F.S: ..*/

#endif