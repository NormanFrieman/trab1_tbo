#include "../Headers/Arquivo.h"


int Contar_Dimemsao(char* Linha){
    char* tok;
    int Contagem = 0;
    for (tok = strtok(Linha, ","); tok && *tok; tok = strtok(NULL, ",\n")){
        Contagem++;
    }
    free(Linha);
    return Contagem - 1;
}

void Ler(char* Arquivo, Ponto* P){
    FILE* Entrada = fopen(Arquivo, "r");
    char* Linha;
    size_t T = 256;
    Linha = (char*)malloc(T*sizeof(char));
    int Dimensao = -1;
    int Contagem = 0;
    int Contagem_Cord;
    int Tamanho = 10;
    char* Nome;
    int* Coordenadas;
    char* tok;
    P = (Ponto*)malloc(Tamanho*sizeof(Ponto));
    while(getline(&Linha, &T, Entrada) != -1){
        if(Contagem == Tamanho){
            printf("%d\n",Tamanho);
            P = Realloca(P, &Tamanho);
        }
        if(Dimensao == -1){
            Dimensao = Contar_Dimemsao(strdup(Linha));
            Coordenadas = (int*)malloc(Dimensao*sizeof(int));
        }
        Contagem_Cord = 0;
        for(tok = strtok(Linha, ","); tok && *tok; tok = strtok(NULL, ",\n")){
            if(Contagem_Cord == 0){
                Nome = strdup(tok);
                Contagem_Cord++;
            }else{
                Coordenadas[Contagem_Cord - 1] = atoi(tok);
                Contagem_Cord++;
            }
        }
        Inicia_Unico(&P[Contagem], Nome, Coordenadas, Dimensao);
        free(Nome);
        Contagem++;
    }
    Prenche(P, Contagem, Dimensao);
    for(int i = 0; i < Contagem; i++){
        //Imprime_Unico(&P[i], Dimensao, Contagem);
    }
    Libera_Ponto(P, Contagem);
    fclose(Entrada);
    free(tok);
    free(Coordenadas);
    free(Linha);
}

void Imprimir(Ponto* P){

}
