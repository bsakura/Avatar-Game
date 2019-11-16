#include "graph.h"
#include "boolean.h"
//Konstruktor
#include "listlinier.h"
adrNode AlokGNode(int X){
  adrNode P;
  P = (GNode *) malloc (sizeof(GNode));
  infoN(P)=X;
  adrSuccNode L;
  CreateEmpty(&L);
  Trail(P)= L;
  NextN(P)=Nil;
  return P;
}


void DealokGNode(adrNode P){
  free(P);
}

void CreateGraph (Graph *G){
  (*G).First =Nil;
}

//Fungsi/prosedur lain
adrNode SearchGNode(Graph G, int X){
  adrNode P;
  P=G.First;
  while (P != Nil && infoN(P)!=X){
    P=NextN(P);
  }
  return P;
}

boolean SearchEdge(Graph G, int prec, int succ){
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

void InsertGNode(Graph *G,int X){
  adrNode P;
  adrNode P1;
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

void InsertEdge(Graph *G,int prec,int succ){
  adrNode Pprec,Psucc;
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


