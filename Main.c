#include "Headers/Arquivo.h"
#include "Headers/Distancia.h"

int main(int argc, char* argv[]){
    Entrada* info = Ler(argv[1]);

    Imprime_Distancias(info->D, info->P, info->QuantD);
    Kruskel(info->D, info->P, info->Contagem, atoi(argv[2]));
    for (int i = 0; i < info->Contagem; i++) {
        printf("[P] Nome: %s, ID: %d, PontoPai: %d, Tamanho: %d\n", info->P[i].Nome, info->P[i].ID, info->P[i].PontoPai, info->P[i].Tamanho);
    }

    Imprime(argv[3], info->P, info->Contagem);

    Libera_Ponto(info->P, info->Contagem);
    free(info->D);
    free(info);

    return 0;
}