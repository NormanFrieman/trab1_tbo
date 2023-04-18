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
} Entrada;

int Contar_Dimemsao(char* Linha);

Entrada* Ler(char* Arquivo);

#endif /*ARQUIVO_H_*/