#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/Ponto.h"

Ponto* Inicia_Ponto(int N) {
    Ponto* P = (Ponto*)malloc(N * sizeof(Ponto));
    return P;
}

void Inicia_Unico(Ponto* P, char* Nome, double* Coordenadas, int ID) {
    int* pointer = (int*)malloc(sizeof(int));
    *pointer = ID;

    P->ID = pointer;
    P->PontoPai = pointer;
    P->Tamanho = 1;
    P->Nome = strdup(Nome);
    P->Coordenadas = Coordenadas;
    P->Exibido = 0;
}

Ponto* Realloca_Ponto(Ponto* P, int N) {
    Ponto* NovoP = (Ponto*)realloc(P, N * sizeof(Ponto));
    return NovoP;
}

int* Procura(int* PontoPaiP1, Ponto* P){
    while(PontoPaiP1 != P[*PontoPaiP1].PontoPai){
        P[*PontoPaiP1].PontoPai = P[*P[*PontoPaiP1].PontoPai].PontoPai;
        PontoPaiP1 = P[*PontoPaiP1].PontoPai;
    }
    return PontoPaiP1;
}

int Conectado(Ponto* P1, Ponto* P2, Ponto* P) {
    return Procura(P1->PontoPai, P) == Procura(P2->PontoPai, P);
}

void Uniao(Ponto* P1, Ponto* P2, Ponto* P) {
    int* Raiz1 = Procura(P1->PontoPai, P);
    int* Raiz2 = Procura(P2->PontoPai, P);
    
    if (P[*Raiz1].Tamanho > P[*Raiz2].Tamanho) {
        P[*Raiz1].PontoPai = Raiz2;
        P[*Raiz2].Tamanho += P[*Raiz1].Tamanho;
    } else {
        P[*Raiz2].PontoPai = Raiz1;
        P[*Raiz1].Tamanho += P[*Raiz2].Tamanho;
    }
}

int Compara_Ponto(const void* V1, const void* V2) {
    Ponto* P1 = (Ponto*)V1;
    Ponto* P2 = (Ponto*)V2;
    
    char* Nome1 = P1->Nome;
    char* Nome2 = P2->Nome;

    int lengthP1 = strlen(Nome1);
    int lengthP2 = strlen(Nome2);

    for (int i = 0; i < lengthP1 && i < lengthP2; i++) {
        if (Nome1[i] == Nome2[i])
            continue;

        return Nome1[i] - Nome2[i];
    }

    return 0;
}

void Organiza_Ponto(Ponto* P, int N) {
    qsort(P, N, sizeof(Ponto), Compara_Ponto);

    for (int i = 0; i < N; i++) {
        *P[i].ID = i;
    }
}

void Libera_Ponto(Ponto* P, int Contagem) {
    for (int i = 0; i < Contagem; i++) {
        free(P[i].Nome);
        free(P[i].Coordenadas);
        free(P[i].ID);
    }
    free(P);
}
