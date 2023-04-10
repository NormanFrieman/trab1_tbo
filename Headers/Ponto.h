#ifndef PONTO_H_
#define PONTO_H_

#include "Distancia.h"

typedef struct{
    char* Nome;
    int* Coordenadas;
    Distancia* Distancias;
    int Tamanho_Cord;
    int Numero_Dista;
}Ponto;

char* Retorna_Nome(Ponto* P);
Distancia* Retorna_Distancia(Ponto* P);
int Retorna_Tamanho_Cord(Ponto* P);
int Retorna_Numero_Dista(Ponto* P);
Ponto* Inicia(int N);
void Inicia_Unico(Ponto* P, char* N, int* D, int Di);
void Adiciona_Distancias(Ponto* P, char* Nome, float N);
float Calcula(Ponto* P1, Ponto* P2, int D);
Ponto* Realloca(Ponto* P, int* N);
void Imprime_Unico(Ponto* P, int D, int N);
void Imprime(Ponto* P, int N, int D);
void Imprime_Cordenadas(Ponto* P, int D);
void Prenche(Ponto* P, int N);






#endif /*PONTO_H_*/