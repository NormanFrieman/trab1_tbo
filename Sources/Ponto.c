#include "../Headers/Ponto.h"


char* Retorna_Nome(Ponto* P){
    return P->Nome;
}

Distancia* Retorna_Distancia(Ponto* P){
    return P->Distancias;
}

int Retorna_Tamanho_Cord(Ponto* P){
    return P->Tamanho_Cord;
}

int Retorna_Numero_Dista(Ponto* P){
    return P->Numero_Dista;
}

Ponto* Inicia(int N){
    Ponto* P = (Ponto*)malloc(N*sizeof(Ponto));
    return P;
}

void Inicia_Unico(Ponto* P, char* N, int* D, int Di){
    P->Nome = strdup(N);
    P->Coordenadas = (int*)malloc(Di*sizeof(int));
    for(int i = 0; i < Di; i++){
        P->Coordenadas[i] = D[i];
        //printf("%d - %d ",P->Coordenadas[i], D[i]);
    }
    P->Tamanho_Cord = 10;
    P->Numero_Dista = 0;
    P->Distancias = Inicia_Distacias(10);
}

float Calcula(Ponto* P1, Ponto* P2, int D){
    return Calcula_Distancia(P1->Coordenadas, P2->Coordenadas, D);
}

void Adiciona_Distancias(Ponto* P, char* Nome, float N){
    Adiciona_Distancia(&P->Distancias[P->Numero_Dista],Nome, N);
}

Ponto* Realloca(Ponto* P, int* N){
    *N *= 2;
    P = (Ponto*)realloc(P,*N*sizeof(Ponto));
    return P;
}

void Imprime(Ponto* P, int N, int D){
    for(int i = 0; i < N; i++){
        Imprime_Unico(&P[i], D, N);
    }
}

void Imprime_Unico(Ponto* P, int D, int N){
    printf("Nome: %s\n",P->Nome);
    printf("Coordenadas:");
    Imprime_Cordenadas(P, D);
    Imprime_Distancias(P->Distancias, N);
    printf("\n");
}

void Imprime_Cordenadas(Ponto* P, int D){
    for(int i = 0; i < D; i++){
        printf(" %d",P->Coordenadas[i]);
    }
}

void Prenche(Ponto* P, int N){

}
