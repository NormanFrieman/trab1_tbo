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

float Calcula_Distancia(int* P1, int* P2, int D) {
    float Soma = 0;
    for (int i = 0; i < D; i++) {
        Soma += (pow(P1[i],2) + pow(P2[i],2));
    }
    
    return sqrt(Soma);
}

int Compara_Distancia(const void* V1, const void* V2) {
    const Distancia* D1 = V1;
    const Distancia* D2 = V2;
    return D1->Distancia*100 - D2->Distancia*100;
}

void Organiza_Distancia(Distancia* D, int N) {
    qsort(D, N - 1, sizeof(Distancia), Compara_Distancia);
}

void Imprime_Distancias(Distancia* D, Ponto* P, int N) {
    for (int i = 0; i < N - 1; i++) {
        printf("[Ponto %s -> Ponto %s] Distancia: %.2f\n", P[D[i].indexP1].Nome, P[D[i].indexP2].Nome, D[i].Distancia);
    }
    printf("\n");
}

// void Libera_Distancia(Distancia* D, int N) {
//     for(int i = 0; i < N; i++) {
//         free(D[i].Nome_Ponto);
//     }
//     free(D);
// }