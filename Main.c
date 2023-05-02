#include <time.h>
#include "Headers/Arquivo.h"
#include "Headers/Distancia.h"

int main(int argc, char* argv[]){
    clock_t start, stop;
    start = clock();

    Entrada* info = Ler(argv[1]);
    
    stop = clock();

    double time_taken = ((double) stop - start) / CLOCKS_PER_SEC;
    printf("Ler: %.3f\n", time_taken);

    // ######################

    start = clock();

    Kruskel(info->D, info->P, info->QuantD, info->Contagem, atoi(argv[2]));

    stop = clock();

    time_taken = ((double) stop - start) / CLOCKS_PER_SEC;
    printf("Kruskel: %.3f\n", time_taken);

    // ######################
    
    start = clock();
    
    Imprime(argv[3], info->P, info->Contagem);

    stop = clock();

    time_taken = ((double) stop - start) / CLOCKS_PER_SEC;
    printf("Imprime: %.3f\n", time_taken);
    
    // ######################
    
    Libera_Ponto(info->P, info->Contagem);
    free(info->D);
    free(info);

    return 0;
}