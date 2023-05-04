#include "../Headers/Distancia.h"

Distancia* Inicia_Distacias(int N) {
    Distancia* D = (Distancia*)malloc(N * sizeof(Distancia));
    return D;
}

void Adiciona_Distancia(Distancia* D, Ponto *P, int indexP1, int indexP2, int Dimensao) {
    D->indexP1 = indexP1;
    D->indexP2 = indexP2;

    D->Distancia = Calcula_Distancia(P[indexP1].Coordenadas, P[indexP2].Coordenadas, Dimensao);
}

Distancia* Calcula_Distancias(Ponto* P, int Contagem, int Dimensao) {
    int auxD = 0;
    int QuantD = (Contagem * (Contagem - 1))/ 2;

    Distancia* D = Inicia_Distacias(QuantD);

    for (int i = 1; i < Contagem; i++) {
        for (int j = 0; j < i; j++) {
            Adiciona_Distancia(&D[auxD], P, j, i, Dimensao);
            auxD++;
        }
    }

    return D;
}

double Calcula_Distancia(double* P1, double* P2, int D) {
    double Soma = 0;
    for (int i = 0; i < D; i++) {
        Soma += pow(P2[i] - P1[i],2);
    }
    
    return sqrt(Soma);
}

int Compara_Distancia(const void* V1, const void* V2) {
    const Distancia* D1 = V1;
    const Distancia* D2 = V2;
    return D1->Distancia - D2->Distancia;
}

void Organiza_Distancia(Distancia* D, int N) {
    qsort(D, N, sizeof(Distancia), Compara_Distancia);
}


void Kruskel(Distancia* D, Ponto* P, int QuantD, int Contagem, int k) {
    int Conexoes = 0;

    for (int i = 0; i < QuantD && Conexoes <= Contagem - k - 1; i++) {
        int conectado = Conectado(&P[D[i].indexP1], &P[D[i].indexP2], P);

        if (!conectado) {

            Uniao(&P[D[i].indexP1], &P[D[i].indexP2], P);
            Conexoes++;
        }
    }
}