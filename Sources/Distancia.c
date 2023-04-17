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
    printf("%.2f\n",sqrt(Soma));
    return sqrt(Soma);
}

int Compara_Distancia(const void* V1, const void* V2){
    const Distancia* D1 = V1;
    const Distancia* D2 = V2;
    return D1->Distancia*100 - D2->Distancia*100;
}

void Organiza_Distancia(Distancia* D, int N){
    qsort(D,N-1,sizeof(Distancia),Compara_Distancia);
}

void Imprime_Distancias(Distancia* D, int N){
    for(int i = 0; i < N - 1; i++){
       printf("Nome: %s -> Distancia: %.2f \n", D[i].Nome_Ponto, D[i].Distancia); 
    }
    printf("\n");
}

void Libera_Distancia(Distancia* D, int N){
    for(int i = 0; i < N; i++){
        free(D[i].Nome_Ponto);
    }
    free(D);
}