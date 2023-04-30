#include "Headers/Arquivo.h"
#include "Headers/Distancia.h"

int main(int argc, char* argv[]){
    Entrada* info = Ler(argv[1]);

    Kruskel(info->D, info->P, info->QuantD, info->Contagem, atoi(argv[2]));

    Imprime(argv[3], info->P, info->Contagem);

    Libera_Ponto(info->P, info->Contagem);
    free(info->D);
    free(info);

    return 0;
}