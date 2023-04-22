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

void Inicia_Unico(Ponto* P, char* Nome, int* Coordenadas, int Dimensao, int ID) {
    P->ID = ID;
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

void Connecta(Ponto* P1, Ponto* P2){
    if(P1->ID != P2->ID){
        P2->ID = P1->ID;
    }
}

int Compara_Index(const void* V1, const void* V2){
    Ponto* P1 = V1;
    Ponto* P2 = V2;
    return V1->ID - V2->ID;
}

void Organiza_Index(Ponto* P, int Contagem){
    qsort(P, Contagem, sizeof(Ponto), Compara_Index);
}

void Imprime(char Arquivo, Ponto* P, int Contagem){
    FILE* Saida = fopen(Arquivo, "w");
    Organiza_Index(P, Contagem);
    for(int i = 0; i < Contagem; i++){
        if(P[i+1] != NULL){
            if(P[i].ID != P[i+1].ID){
                fprintf(Saida,"%s","\n");
            }
        }
        fprintf(Saida,"%s ",P[i].Nome);
    }
    fclose(Saida);
}

void Libera_Ponto(Ponto* P, int Contagem) {
    for (int i = 0; i < Contagem; i++) {
        free(P[i].Nome);
        free(P[i].Coordenadas);
    }
    free(P);
}
