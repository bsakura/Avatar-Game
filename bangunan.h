
#include "point.h"

typedef struct {
	char jenis;
	int pemilik;
    int jumpas;
    int level; 
    int A;
    int M;
    int P;
    int U;
    POINT lokasi;
} BANGUNAN;

#define jenis(B)   (B).jenis
#define pemilik(B)   (B).pemilik
#define jumpas(B)   (B).jumpas
#define level(B)   (B).level
#define lokasi(B)   (B).lokasi


void MakeBangunan(BANGUNAN *B,char jenis, int pemilik);