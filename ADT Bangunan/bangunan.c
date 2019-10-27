/* ADT Bangunan */

#include "boolean.h"
#include "bangunan.h"

void CreateBuilding (BANGUNAN *B) {
    Kepemilikan(*B) = Nil;
}

void MakeCastle (BANGUNAN *B) {
    Jenis(*B) = 'C';
    Level(*B) = 1;
    SetMaksimum(B);
    if (Kepemilikan(*B) == Nil) {
        PasukanAwal(*B) = 40;
        Pasukan(*B) = PasukanAwal(*B);
    }
    else {
        PasukanAwal(*B) = Nil;
        Pasukan(*B) = Nil;
    }
}

void MakeTower (BANGUNAN *B) {
    Jenis(*B) = 'T';
    Level(*B) = 1;
    SetMaksimum(B);
    if (Kepemilikan(*B) == Nil) {
        PasukanAwal(*B) = 30;
        Pasukan(*B) = PasukanAwal(*B);
    }
    else {
        PasukanAwal(*B) = Nil;
        Pasukan(*B) = Nil;
    }
}

void MakeFort (BANGUNAN *B) {
    Jenis(*B) = 'F';
    Level(*B) = 1;
    SetMaksimum(B);
    if (Kepemilikan(*B) == Nil) {
        PasukanAwal(*B) = 80;
        Pasukan(*B) = PasukanAwal(*B);
    }
    else {
        PasukanAwal(*B) = Nil;
        Pasukan(*B) = Nil;
    }
}

void MakeVillage (BANGUNAN *B) {
    Jenis(*B) = 'V';
    Level(*B) = 1;
    SetMaksimum(B);
    if (Kepemilikan(*B) == Nil) {
        PasukanAwal(*B) = 20;
        Pasukan(*B) = PasukanAwal(*B);
    }
    else {
        PasukanAwal(*B) = Nil;
        Pasukan(*B) = Nil;
    }
}

boolean IsPertahanan (BANGUNAN B) {
    if (Jenis(B) == 'C') {
        return false;
    }
    else if (Jenis(B) == 'T') {
        return true;
    }
    else if (Jenis(B) == 'F') {
        if (Level(B) >= 3) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

void SetKepemilikan (BANGUNAN *B, Pemain P) {
    Kepemilikan(*B) = P;
}

boolean IsKepemilikan (BANGUNAN B, Pemain P) {
    if (Kepemilikan(B) == P) {
        return true;
    }
    else {
        return false;
    }
}

void TambahPasukanAuto (BANGUNAN *B) {
    int PasukanAwal, Selisih;
    PasukanAwal = Pasukan(*B);
    if (Level(*B) == 1) {
        if (Jenis(*B) == 'C') {
            Pasukan(*B) += 10;
        }
        else if (Jenis(*B) == 'T') {
            Pasukan(*B) += 5;
        }
        else if (Jenis(*B) == 'F') {
            Pasukan(*B) += 10;
        }
        else if (Jenis(*B) == 'V') {
            Pasukan(*B) += 5;
        }
    }
    else if (Level(*B) == 2) {
        if (Jenis(*B) == 'C') {
            Pasukan(*B) += 15;
        }
        else if (Jenis(*B) == 'T') {
            Pasukan(*B) += 10;
        }
        else if (Jenis(*B) == 'F') {
            Pasukan(*B) += 20;
        }
        else if (Jenis(*B) == 'V') {
            Pasukan(*B) += 10;
        }
    }
    else if (Level(*B) == 3) {
        if (Jenis(*B) == 'C') {
            Pasukan(*B) += 20;
        }
        else if (Jenis(*B) == 'T') {
            Pasukan(*B) += 20;
        }
        else if (Jenis(*B) == 'F') {
            Pasukan(*B) += 30;
        }
        else if (Jenis(*B) == 'V') {
            Pasukan(*B) += 15;
        }
    }
    else if (Level(*B) == 4) {
        if (Jenis(*B) == 'C') {
            Pasukan(*B) += 25;
        }
        else if (Jenis(*B) == 'T') {
            Pasukan(*B) += 30;
        }
        else if (Jenis(*B) == 'F') {
            Pasukan(*B) += 40;
        }
        else if (Jenis(*B) == 'V') {
            Pasukan(*B) += 20;
        }
    }
    Selisih = Pasukan(*B) - PasukanAwal;
    if (Pasukan(*B) > Maksimum(*B)) {
        Pasukan(*B) -= Selisih;
    }
}

void TambahPasukanManual (BANGUNAN *B, int Pasukan) {
    Pasukan(*B) += Pasukan;
}

void SerangBangunan (BANGUNAN *B1, BANGUNAN *B2, int Pasukan) {
    if (Pasukan <= Pasukan(*B1)) {
        Pasukan(*B1) -= Pasukan;
        if (IsPertahanan(*B2)) {
            Pasukan = (Pasukan * 3) / 4;
        }
        Pasukan(*B2) -= Pasukan;
        if (Pasukan(*B2) < 0) {
            Pasukan(*B2) *= -1;
            Level(*B2) = 1;
            SetMaksimum(B2);
            SetKepemilikan(B2, Kepemilikan(*B1));
        }
    }
}

void LevelUp (BANGUNAN *B) {
    if (Pasukan(*B) >= (Maksimum(*B) / 2)) {
        if (Level(*B) < 4) {
            Level(*B) += 1;
            Pasukan(*B) -= (Maksimum(*B) / 2);
            SetMaksimum(B);
        }
    }
}

void SetMaksimum (BANGUNAN *B) {
    if (Jenis(*B) == 'C') {
        Maksimum(*B) = 40 + (20 * (Level(*B) - 1));
    }
    else if (Jenis(*B) == 'T') {
        Maksimum(*B) = 20 + (10 * (Level(*B) - 1));
    }
    else if (Jenis(*B) == 'F') {
        Maksimum(*B) = 20 + (20 * (Level(*B) - 1));
    }
    else {
        Maksimum(*B) = 20 + (10 * (Level(*B) - 1));
    }
}

/* ************   TESTING   ************ */
void PrintStatus (BANGUNAN B) {
    if (Jenis(B) == 'C') {
        printf("CASTLE\n");
    }
    else if (Jenis(B) == 'T') {
        printf("TOWER\n");
    }
    else if (Jenis(B) == 'F') {
        printf("FORT\n");
    }
    else {
        printf("VILLAGE\n");
    }
    printf("%d\n", Level(B));
    printf("%d\n", Pasukan(B));
    printf("%d\n", Maksimum(B));
    printf("%d\n", Kepemilikan(B));
    printf("\n");
}