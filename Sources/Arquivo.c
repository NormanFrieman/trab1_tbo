#include "../Headers/Arquivo.h"


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
    int Contagem = 0;
    int Contagem_Cord;
    int Tamanho = 10;
    char* Nome;
    int* Coordenadas;
    Ponto* P = Inicia(Tamanho);
    while(getline(&Linha, &Tamanho, Entrada) != -1){
        if(Contagem == Tamanho){
            P = Realocca(P, &Tamanho);
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
        Inicia_Unico(&P[Contagem], Nome, Coordenadas);
        Inicia_Distacia(&P[Contagem]);
        Contagem++;
    }
    for(int i = 0; i < Contagem; i++){
        for(int k = i + 1; k < Contagem; k++){
            if(Retorna_Numero_Cord(P[i]) == Retorna_Tamanho_Dist(P[i])){
                Realloca_Distacia(P[i]);
            }
            if(Retorna_Numero_Cord(P[k]) == Retorna_Tamanho_Dist(P[k])){
                Realloca_Distacia(P[k]);
            }
            
        }
    }
    fclose(Entrada);
    free(Linha);
}

void Imprimir(Ponto* P){

}
