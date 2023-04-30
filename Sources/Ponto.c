#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/Ponto.h"

Ponto* Inicia_Ponto(int N) {
    Ponto* P = (Ponto*)malloc(N * sizeof(Ponto));
    return P;
}

void Inicia_Unico(Ponto* P, char* Nome, float* Coordenadas, int Dimensao, int ID) {
    P->ID = ID;
    P->PontoPai = ID;
    P->Tamanho = 1;
    P->Nome = strdup(Nome);
    P->Coordenadas = Coordenadas;
    P->Tamanho_Cord = Dimensao;
    P->Exibido = 0;
}

Ponto* Realloca_Ponto(Ponto* P, int N) {
    Ponto* NovoP = (Ponto*)realloc(P, N * sizeof(Ponto));
    return NovoP;
}

int Procura(int PontoPaiP1, Ponto* P){
    while(PontoPaiP1 != P[PontoPaiP1].PontoPai){
        P[PontoPaiP1].PontoPai = P[P[PontoPaiP1].PontoPai].PontoPai;
        PontoPaiP1 = P[PontoPaiP1].PontoPai;
    }
    return PontoPaiP1;
}

int Connectado(Ponto* P1, Ponto* P2, Ponto* P) {
    return Procura(P1->PontoPai, P) == Procura(P2->PontoPai, P);
}

void Uniao(Ponto* P1, Ponto* P2, Ponto* P) {
    int Raiz1 = Procura(P1->PontoPai, P);
    int Raiz2 = Procura(P2->PontoPai, P);
    
    if (P[Raiz1].Tamanho < P[Raiz2].Tamanho) {
        P[Raiz1].PontoPai = Raiz2;
        P[Raiz2].Tamanho += P[Raiz1].Tamanho;
    } else {
        P[Raiz2].PontoPai = Raiz1;
        P[Raiz1].Tamanho += P[Raiz2].Tamanho;
    }
}

void Procura_Ramo(int N, int I, int Index, int Tamanho,  Ponto* P, FILE* Saida){
    int Cont = 0;
    for(int i = I; i < N; i++){
        if(P[i].PontoPai == Index){
            fprintf(Saida, "%s,", P[i].Nome);
            Procura_Ramo(N, i + 1, P[i].ID, P[i].Tamanho, P, Saida);
            Cont++;
            
            if(Cont == Tamanho){
                fprintf(Saida, "\n");
                return;
            } 
        }
    }
}

void Imprime(char* Arquivo, Ponto* P, int Contagem){
    FILE* Saida = fopen(Arquivo, "w");
    for (int i = 0; i < Contagem; i++) {
        int PontoPaiI = Procura(P[i].PontoPai, P);
        int exibiuPontos = 0;
        
        for (int j = 0; j < Contagem; j++) {
            int PontoPaiJ = Procura(P[j].PontoPai, P);
            
            if (PontoPaiI == PontoPaiJ && !P[j].Exibido) {
                P[j].Exibido = 1;

                if (!exibiuPontos) {
                    fprintf(Saida, "%s", P[j].Nome);
                    exibiuPontos = 1;
                } else {
                    fprintf(Saida, ",%s", P[j].Nome);
                }
            }

            if (exibiuPontos != 0 && j + 1 >= Contagem) {
                fprintf(Saida, "\n");
            }
        }
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
