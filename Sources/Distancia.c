#include "../Headers/Distancia.h"



Distancia* Inicia_Distacias(int N){
    Distancia* D = (Distancia*)malloc(N*sizeof(Distancia));
    return D;
}

Distancia* Realloca_Distancia(Distancia* D, int N){
    D = (Distancia*)realloc(D, N*sizeof(Distancia));
    return D;
}

void Adiciona_Distancia(Distancia* D, char* Nome, float N){
    D->Nome_Ponto = strdup(Nome);
    D->Distancia = N;

}

float Calcula_Distancia(int* P1, int* P2, int D){
    float Soma = 0;
    for(int i = 0; i < D; i++){
        Soma += (pow(P1[i],2) + pow(P2[i],2));
    }
    return sqrt(Soma);
}

void Imprime_Distancias(Distancia* D, int N){
    for(int i = 0; i < N; i++){
       printf("Nome: %s -> Distancia: %.2f ", D[i].Nome_Ponto, D[i].Distancia); 
    }
}