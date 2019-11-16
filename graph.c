#include "graph.h"
#include "boolean.h"
//Konstruktor
adrNode AlokGNode(int X){
  adrNode P;
  P = (GNode *) malloc (sizeof(GNode));
  infoN(P)=X
  Trail(P)=Nil;
  NextN(P)=Nil;
  return P;
}


void DealokGNode(adrNode P){
  free(P);
}

void CreateGraph (Graph *G){
  FirstN(*G)=Nil;
}

//Fungsi/prosedur lain
boolean SearchGNode(Graph G, int X){
  adrNode P;
  P=FirstN(G);
  while (P != Nil && infoN(P)!=X){
    P=NextN(P);
  }
  return P;
}

boolean SearchEdge(Graph G, int prec, int succ){
  adrNode P;
  SearchGNode(G,prec);
  if (P!=Nil){
    adrSuccNode Psucc;
    Psucc=Trail(P);
    return Search(Psucc, succ);
  }
  else{
    return Nil;
  }
}

void InsertGNode(Graph *G,int X){
  adrNode P;
  adrNode P1
  P=FirstN(*G);
  if (P!=Nil){
    while (NextN(P) != Nil){
      P=NextN(P);
    }
    NextN(P)=AlokGNode(X);
  }
  else{
    FirstN(*G)=AlokGNode(N);
  }
}

void InsertEdge(Graph *G,int prec,int succ){
  adrNode Pprec,Psucc;
  Pprec=SearchGNode(*G,prec);
  Psucc=SearchGNode(*G,succ);
  if (Pprec==Nil){
    InsertGNode(G,prec,Pprec);
  }
  if (Psucc==Nil){
    InsertGNode(G,succ,Psucc);
  }
  if (SearchEdge(*G,prec,succ)==Nil){
      InsVLast(Trail(Pprec),succ);
      InsVLast(Trail(Psucc),prec);
    }
}


