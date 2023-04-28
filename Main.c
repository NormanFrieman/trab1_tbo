#include "Headers/Arquivo.h"
#include "Headers/Distancia.h"

int main(int argc, char* argv[]){
    Entrada* info = Ler(argv[1]);

    //Imprime_Pontos(info->P, info->Contagem, info->Dimensao);
    //Imprime_Distancias(info->D, info->P, ((info->Contagem * (info->Contagem - 1))/ 2) + 1);
    //printf("T1\n");
    Une(info->D, info->P, info->Contagem, atoi(argv[2]));
    //printf("T2\n");
    //Imprime_Pontos(info->P, info->Contagem, info->Dimensao);

    Imprime(argv[3], info->P, info->Contagem);

    Libera_Ponto(info->P, info->Contagem);
    free(info->D);
    free(info);

    return 0;
}