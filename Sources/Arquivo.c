#include "../Headers/Arquivo.h"

void Ler(char* Arquivo, Ponto* P){
    FILE* Entrada = fopen(Arquivo, "r");
    char* Linha;
    size_t Tamanho = 256;
    Linha = (char*)malloc(Tamanho*sizeof(char));
    while(getline(&Linha, &Tamanho, Entrada) != -1){
        printf("%s\n",Linha);
    }
    fclose(Entrada);
    free(Linha);
}

void Imprimir(Ponto* P){

}
