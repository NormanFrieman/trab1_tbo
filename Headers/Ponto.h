#ifndef PONTO_H_
#define PONTO_H_

typedef struct {
    int ID;
    int PontoPai;
    char* Nome;
    float* Coordenadas;
    int Tamanho_Cord;
    int Tamanho;
    int Exibido;
} Ponto;

Ponto* Inicia_Ponto(int N);

void Inicia_Unico(Ponto* P, char* Nome, float* Coordenadas, int Dimensao, int ID);

Ponto* Realloca_Ponto(Ponto* P, int N);

int Procura(int PontoPaiP1, Ponto* P);

int Connectado(Ponto* P1, Ponto* P2, Ponto* P);

void Uniao(Ponto* P1, Ponto* P2, Ponto* P);

void Procura_Ramo(int N, int I, int Index, int Tamanho,  Ponto* P, FILE* Saida);

void Imprime(char* Arquivo, Ponto* P, int Contagem);

void Libera_Ponto(Ponto* P, int Contagem);

#endif /*PONTO_H_*/