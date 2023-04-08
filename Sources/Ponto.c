#include "../Headers/Ponto.h"

struct ponto
{
    char* Nome;
    int* Coordenadas;
    float* Distancias;
    int Tamanho_Cord;
    int Numero_Dista;
};

int Retorna_Tamanho_Cord(Ponto* P){
    return P->Tamanho_Cord;
}

int Retorna_Numero_Dista(Ponto* P){
    return P->Numero_Dist
}

Ponto* Inicia(int N){
    Ponto* P = (Ponto*)malloc(N*sizeof(Ponto));
    return P;
}

void Inicia_Unico(Ponto* P, char* N, int* D){
    P->Nome = N;
    P->Coordenadas = D;
    P->Tamanho_Cord = 10;
    P->Numero_Dist = 0;
}

void Inicia_Distacias(Ponto* P){
    P->Distancias = (float*)malloc(P->Tamanho_Cord*sizeof(float));
}

void Realloca_Distancia(Ponto* P, int D){
    P = (Ponto*)realloc(P, D*sizeof(Ponto));
}

void Calcula_Distacia(Ponto* P, int D){
    for(int i = 0; i < D; i++){

    }
}

Ponto* Realloca(Ponto* P, int* N){
    *N *= 2;
    P = (Ponto*)realloc(P,*N*sizeof(Ponto));
    return P;
}

void Prenche(Ponto* P, int N){

}
