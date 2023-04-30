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

float Calcula_Distancia(float* P1, float* P2, int D) {
    float Soma = 0;
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

// <<<<<<< HEAD
// void Une(Distancia* D, Ponto* P, int Contagem, int k){
//     for(int i = 0; i < Contagem*10; i++){
//         Uniao(&P[D[i].indexP1], &P[D[i].indexP2], P);
//     }   
void Kruskel(Distancia* D, Ponto* P, int Contagem, int k) {
    int Conexoes = 0;
    
    for (int i = 0; i < Contagem && Conexoes < Contagem - k - 1; i++) {
        if (!Connectado(&P[D[i].indexP1], &P[D[i].indexP2], P)) {
            Uniao(&P[D[i].indexP1], &P[D[i].indexP2], P);
            Conexoes++;
        }
    }
}