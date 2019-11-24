#include "graph.h"
#include "../boolean/boolean.h"
#include "../listlinier/listlinier.h"
#include <stdio.h>
#include <stdlib.h>

//Konstruktor
adrNode AlokGNode(int X)
/*I.S: Sembarang
  F.S: Mengalokasikan node.*/
{
  //Kamus Lokal
  adrNode P;
  //Algoritma
  P = (GNode *) malloc (sizeof(GNode));
  infoN(P)=X;
  adrSuccNode L;
  CreateEmpty(&L);
  Trail(P)= L;
  NextN(P)=Nil;
  return P;
}


void DealokGNode(adrNode P)
/*I.S: Sembarang
  F.S: Node terdealokasi.*/
{
  //Algoritma
  free(P);
}

void CreateGraph (Graph *G)
/*I.S: Sembarang
  F.S: Graph baru terbuat.*/
{
  //Algoritma
  (*G).First =Nil;
}

//Fungsi/prosedur lain
adrNode SearchGNode(Graph G, int X)
/*I.S: Graph 
  F.S: Mengembalikan address dari node dimana C ditemukan.*/
{
  //Algoritma
  adrNode P;
  P=G.First;
  while (P != Nil && infoN(P)!=X){
    P=NextN(P);
  }
  return P;
}

boolean SearchEdge(Graph G, int prec, int succ)
/*Input: Graph, prec dan succ
  Output: Boolean true jika setelah pencarian node ..*/
{
  //Algoritma
  adrNode P;
  P=SearchGNode(G,prec);
  if (P!=Nil){
    adrSuccNode Psucc;
    Psucc=Trail(P);
    return (Search(Psucc, succ)!=Nil);
  }
  else{
    return false;
  }
}

void InsertGNode(Graph *G,int X)
/*I.S: Sembarang
  F.S: integer dimasukkan ke dalma graf.*/
{
  //Kamus Lokal
  adrNode P;
  adrNode P1;
  //Algoritma
  P=(*G).First;
  if (P!=Nil){
    while (NextN(P) != Nil){
      P=NextN(P);
    }
    P1=AlokGNode(X);
    NextN(P)=P1;
  }
  else{
    P1=AlokGNode(X);
    (*G).First =P1;
  }
}

void InsertEdge(Graph *G,int prec,int succ)
/*I.S: Sembarang
  F.S: ..*/
{
  //Kamus Lokal
  adrNode Pprec,Psucc;
  //Algoritma
  Pprec=SearchGNode(*G,prec);
  Psucc=SearchGNode(*G,succ);
  if (Pprec==Nil){
    InsertGNode(G,prec);
  }
  if (Psucc==Nil){
    InsertGNode(G,succ);
  }
  if (!SearchEdge(*G,prec,succ)){
      InsVLast(&(Trail(Pprec)),succ);
      InsVLast(&(Trail(Psucc)),prec);
    }
}


