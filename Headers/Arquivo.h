#ifndef ARQUIVO_H_
#define ARQUIVO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "Ponto.h"
#include "Distancia.h"

typedef struct {
    int Dimensao;
    int Contagem;
    Ponto* P;
    Distancia* D;
    int QuantD;
} Entrada;

int Contar_Dimemsao(char* Linha);

Entrada* Ler(char* Arquivo);

void Imprime(char* Arquivo, Ponto* P, int Contagem);

#endif /*ARQUIVO_H_*/