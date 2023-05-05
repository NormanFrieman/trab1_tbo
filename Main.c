#include <time.h>
#include "Headers/Arquivo.h"
#include "Headers/Distancia.h"

void exibirTempo(char* nomeFuncao, clock_t start, clock_t stop) {
    double time_taken = ((double) stop - start) / CLOCKS_PER_SEC;
    printf("%s: %.3f\n", nomeFuncao, time_taken);
}

int main(int argc, char* argv[]){
    clock_t start, stop;
    start = clock();

    // Ler coordenadas do arquivo de entrada
    Entrada* info = Ler(argv[1]);
    
    stop = clock();
    exibirTempo("Ler", start, stop);

    ///////////////////////////////////

    start = clock();

    // Calcula a distância entre todos os pontos, salvando os resultados em um vetor
    info->D = Calcula_Distancias(info->P, info->Contagem, info->Dimensao);

    stop = clock();

    exibirTempo("Calcula_Distancias", start, stop);

    ///////////////////////////////////

    start = clock();

    // Organiza as distância em ordem crescente
    Organiza_Distancia(info->D, info->QuantD);

    stop = clock();

    exibirTempo("Organiza_Distancia", start, stop);

    ///////////////////////////////////

    start = clock();

    // Realiza o algoritmo de kruskel
    Kruskel(info->D, info->P, info->QuantD, info->Contagem, atoi(argv[2]));

    stop = clock();

    exibirTempo("Kruskel", start, stop);

    ///////////////////////////////////

    start = clock();

    // Organiza os pontos por nome, em ordem crescente
    Organiza_Ponto(info->P, info->Contagem);

    stop = clock();

    exibirTempo("Organiza_Ponto", start, stop);

    ///////////////////////////////////
    
    start = clock();
    
    // Salva em um arquivo as conexões existentes entre os pontos
    Imprime(argv[3], info->P, info->Contagem);

    stop = clock();

    exibirTempo("Imprime", start, stop);
    
    ///////////////////////////////////
    
    Libera_Ponto(info->P, info->Contagem);
    free(info->D);
    free(info);

    return 0;
}