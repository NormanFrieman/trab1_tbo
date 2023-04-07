#include "../Headers/Arquivo.h"

char* Obter_Info(char* line, int num){
    char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n")) 
    {
        if (!--num) {
            printf("%s\n",tok);
            free(line);
            return tok;
        }
    }
    return NULL;
}

void Ler(char* Arquivo, Ponto* P){
    FILE* Entrada = fopen(Arquivo, "r");
    char* Linha;
    size_t Tamanho = 256;
    Linha = (char*)malloc(Tamanho*sizeof(char));
    while(getline(&Linha, &Tamanho, Entrada) != -1){
        Obter_Info(strdup(Linha), 1);
        Obter_Info(strdup(Linha), 2);
        Obter_Info(strdup(Linha), 3);
    }
    fclose(Entrada);
    free(Linha);
}

void Imprimir(Ponto* P){

}
