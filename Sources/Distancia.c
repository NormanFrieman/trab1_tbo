#include "../Headers/Distancia.h"

Distancia* Inicia_Distacias(int N) {
    Distancia* D = (Distancia*)malloc(N * sizeof(Distancia));
    return D;
}

Distancia* Realloca_Distancia(Distancia* D, int N) {
    D = (Distancia*)realloc(D, N * sizeof(Distancia));
    return D;
}

void Adiciona_Distancia(Distancia* D, Ponto *P, int indexP1, int indexP2) {
    D->indexP1 = indexP1;
    D->indexP2 = indexP2;

    D->Distancia = Calcula_Distancia(P[indexP1].Coordenadas, P[indexP2].Coordenadas, P[indexP1].Tamanho_Cord);
}

double Calcula_Distancia(double* P1, double* P2, int D) {
    double Soma = 0;
    for (int i = 0; i < D; i++) {
        Soma += pow(P2[i] - P1[i],2);
        // Soma += (pow(P1[i],2) + pow(P2[i],2));
    }
    
    return sqrt(Soma);
}

int Compara_Distancia(const void* V1, const void* V2) {
    const Distancia* D1 = V1;
    const Distancia* D2 = V2;
    return D1->Distancia*100 - D2->Distancia*100;
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