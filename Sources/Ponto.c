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
    //printf("Nome: %s\n",P->Nome);
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

void Realloca_Distancias(Ponto* P, int N){
    Realloca_Distancia(P->Distancias, N);
}

void Modifica_Tamanho(Ponto* P, int N){
    P->Tamanho_Cord = N;
}

void Adiciona_Distancias(Ponto* P, char* Nome, float N){
    //printf("T1 - %d\n", P->Numero_Dista);
    Adiciona_Distancia(&P->Distancias[P->Numero_Dista],Nome, N);
    P->Numero_Dista++;
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
    printf("Coordenadas: ");
    Imprime_Cordenadas(P, D);
    printf("\nDistancias: \n");
    Imprime_Distancias(P->Distancias, N);
    printf("\n");
}

void Imprime_Cordenadas(Ponto* P, int D){
    for(int i = 0; i < D; i++){
        printf(" %d",P->Coordenadas[i]);
    }
}

void Prenche(Ponto* P, int N, int D){
    float Distancia;
    for(int i = 0; i < N; i++){
        for(int k = i + 1; k < N; k++){
            if(P[i].Tamanho_Cord < N){
                P[i].Distancias = Realloca_Distancia(P[i].Distancias, N);
                P[i].Tamanho_Cord = N;
            }
            if(P[k].Tamanho_Cord < N){
                P[k].Distancias = Realloca_Distancia(P[k].Distancias, N);
                P[k].Tamanho_Cord = N;
            }
            printf("T1 - %d () %d\n", P[i].Numero_Dista, P[k].Numero_Dista);
            Distancia = Calcula_Distancia(P[i].Coordenadas, P[k].Coordenadas, D);
            Adiciona_Distancia(&P[i].Distancias[P[i].Numero_Dista], P[k].Nome, Distancia);
            Adiciona_Distancia(&P[k].Distancias[P[k].Numero_Dista], P[i].Nome, Distancia);
            P[i].Numero_Dista++;
            P[k].Numero_Dista++;
        }
        Imprime_Unico(&P[i], D, N);
    }
}
