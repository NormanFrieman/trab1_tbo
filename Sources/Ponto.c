#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/Ponto.h"

char* Retorna_Nome(Ponto* P) {
    return P->Nome;
}

int Retorna_Tamanho_Cord(Ponto* P) {
    return P->Tamanho_Cord;
}

Ponto* Inicia_Ponto(int N) {
    Ponto* P = (Ponto*)malloc(N * sizeof(Ponto));
    return P;
}

void Inicia_Unico(Ponto* P, char* Nome, int* Coordenadas, int Dimensao) {
    P->Nome = strdup(Nome);
    P->Coordenadas = Coordenadas;
    P->Tamanho_Cord = Dimensao;
}

void Modifica_Tamanho(Ponto* P, int N) {
    P->Tamanho_Cord = N;
}

Ponto* Realloca_Ponto(Ponto* P, int N) {
    Ponto* NovoP = (Ponto*)realloc(P, N * sizeof(Ponto));
    return NovoP;
}

void Imprime_Pontos(Ponto* P, int Contagem, int Dimensao) {
    for (int i = 0; i < Contagem; i++) {
        Imprime_Unico(&P[i], Dimensao);
    }
}

void Imprime_Unico(Ponto* P, int Dimensao) {
    printf("Nome: %s\n",P->Nome);
    printf("Coordenadas:");
    
    for (int i = 0; i < Dimensao; i++) {
        printf(" %d", P->Coordenadas[i]);
    }
    printf("\n");
}

void Libera_Ponto(Ponto* P, int Contagem) {
    for (int i = 0; i < Contagem; i++) {
        free(P[i].Nome);
        free(P[i].Coordenadas);
    }
    free(P);
}
