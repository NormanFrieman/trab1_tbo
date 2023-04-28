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
    P->Posicao = ID;
    P->Tamanho = 1;
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
    printf("Posição: %d\n", P->Posicao);
    printf("Id: %d\n", P->ID);
    printf("Coordenadas:");
    
    for (int i = 0; i < Dimensao; i++) {
        printf(" %d", P->Coordenadas[i]);
    }
    printf("\n");
}

int Procura(int Id, Ponto* P){
    while(Id != P[Id].Posicao){
        P[Id].Posicao = P[P[Id].Posicao].Posicao;
        Id = P[Id].Posicao;
    }
    return Id;
}

int Connectado(Ponto* P1, Ponto* P2, Ponto* P){
    return Procura(P1->Posicao, P) == Procura(P2->Posicao, P);
}

void Uniao(Ponto* P1, Ponto* P2, Ponto* P){
    int Raiz1 = Procura(P1->Posicao, P);
    int Raiz2 = Procura(P2->Posicao, P);
    if(Raiz1 == Raiz2){
        return;
    }
    if(P[Raiz1].ID > P[Raiz2].ID){
        P[Raiz1].Posicao = Raiz2;
        P[Raiz2].Tamanho += P[Raiz1].Tamanho;
    }else{
        P[Raiz2].Posicao = Raiz1;
        P[Raiz1].Tamanho += P[Raiz2].Tamanho;
    }
}

int Compara_Index(const void* V1, const void* V2){
    const Ponto* P1 = V1;
    const Ponto* P2 = V2;
    return P1->ID - P2->ID;
}

void Organiza_Index(Ponto* P, int Contagem){
    qsort(P, Contagem, sizeof(Ponto), Compara_Index);
}

void Procura_Ramo(int N, int I, int Index, int Tamanho,  Ponto* P, FILE* Saida){
    int Cont = 0;
    for(int i = I; i < N; i++){
        if(P[i].Posicao == Index){
            fprintf(Saida,"%s ",P[i].Nome);
            Procura_Ramo(N, i + 1, P[i].ID, P[i].Tamanho, P, Saida);
            Cont++;
            if(Cont == Tamanho){
                fprintf(Saida,"%s ","\n");
                return;
            } 
        }
    }
}

void Imprime(char* Arquivo, Ponto* P, int Contagem){
    FILE* Saida = fopen(Arquivo, "w");
    for(int i = 0; i < Contagem; i++){
        Procura_Ramo(Contagem, i, P[i].ID, P[i].Tamanho, P, Saida);
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
