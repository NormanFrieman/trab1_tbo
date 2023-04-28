#ifndef DISTANCIA_H_
#define DISTANCIA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "../Headers/Ponto.h"

typedef struct {
    int indexP1;
    int indexP2;
    float Distancia;
} Distancia;

Distancia* Realloca_Distancia(Distancia* D, int N);

Distancia* Inicia_Distacias(int N);

void Adiciona_Distancia(Distancia* D, Ponto *P, int indexP1, int indexP2);

float Calcula_Distancia(int* P1, int* P2, int D);

int Compara_Distancia(const void* V1, const void* V2);

void Une(Distancia* D, Ponto* P, int Contagem, int k);

void Organiza_Distancia(Distancia* D, int N);

void Imprime_Distancias(Distancia* D, Ponto* P, int N);

// void Libera_Distancia(Distancia* D, int N);

#endif /*DISTANCIA_H_*/