#ifndef PONTO_H_
#define PONTO_H_

typedef struct {
    int ID;
    int Posicao;
    char* Nome;
    int* Coordenadas;
    int Tamanho_Cord;
    int Tamanho;
} Ponto;

char* Retorna_Nome(Ponto* P);

int Retorna_Tamanho_Cord(Ponto* P);

Ponto* Inicia_Ponto(int N);

void Inicia_Unico(Ponto* P, char* Nome, int* Coordenadas, int Dimensao, int ID);

void Modifica_Tamanho(Ponto* P, int N);

Ponto* Realloca_Ponto(Ponto* P, int N);

void Imprime_Pontos(Ponto* P, int Contagem, int Dimensao);

void Imprime_Unico(Ponto* P, int Dimensao);

int Procura(int Id, Ponto* P);

void Connecta(Ponto* P1, Ponto* P2);

void Uniao(Ponto* P1, Ponto* P2, Ponto* P);

void Procura_Ramo(int N, int I, int Index, int Tamanho,  Ponto* P, FILE* Saida);

void Imprime(char* Arquivo, Ponto* P, int Contagem);

void Libera_Ponto(Ponto* P, int Contagem);

#endif /*PONTO_H_*/