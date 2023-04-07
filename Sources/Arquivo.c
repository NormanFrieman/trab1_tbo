#include "../Headers/Arquivo.h"

char* Obter_Info(char* Linha, int N){
    char* tok;
    for (tok = strtok(Linha, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n")) 
    {
        if (!--N) {
            printf("%s",tok);
            free(Linha);
            return tok;
        }
    }
    return NULL;
}

int Contar_Dimemsao(char* Linha){
    char* tok;
    int Contagem = 0;
    for (tok = strtok(Linha, ","); tok && *tok; tok = strtok(NULL, ",\n")){
        Contagem++;
    }
    return Contagem - 1;
}

void Ler(char* Arquivo, Ponto* P){
    FILE* Entrada = fopen(Arquivo, "r");
    char* Linha;
    size_t Tamanho = 256;
    Linha = (char*)malloc(Tamanho*sizeof(char));
    int Dimensao = -1;
    while(getline(&Linha, &Tamanho, Entrada) != -1){
        if(Dimensao == -1){
            Dimensao = Contar_Dimemsao(strdup(Linha));
            printf("Numero Dimenções: %d\n", Dimensao);
        }
        printf("\n");
        for(int i = 1; i <= Dimensao + 1; i++){
            Obter_Info(strdup(Linha), i);
        }
    }
    fclose(Entrada);
    free(Linha);
}

void Imprimir(Ponto* P){

}
