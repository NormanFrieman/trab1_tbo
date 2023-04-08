#ifndef PONTO_H_
#define PONTO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct ponto Ponto;

int Retorna_Tamanho_Cord(Ponto* P);
int Retorna_Numero_Dista(Ponto* P);
Ponto* Inicia(int N);
void Inicia_Unico(Ponto* P, char* N, int* D);
void Inicia_Distacias(Ponto* P, int D);
Ponto* Realloca(Ponto* P, int* N);
void Prenche(Ponto* P, int N);






#endif /*PONTO_H_*/