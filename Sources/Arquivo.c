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
    size_t T = 256;
    Linha = (char*)malloc(T*sizeof(char));
    int Dimensao = -1;
    int Contagem = 0;
    int Contagem_Cord;
    int Tamanho = 100;
    char* Nome;
    int* Coordenadas;
    char* tok;
    P = (Ponto*)malloc(Tamanho*sizeof(Ponto));
    while(getline(&Linha, &T, Entrada) != -1){
        if(Contagem == Tamanho){
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
                //printf("%d - %d - %d\n",Contagem_Cord - 1 ,atoi(tok), Coordenadas[Contagem_Cord - 1]);
                Contagem_Cord++;
            }
        }
        Inicia_Unico(&P[Contagem], Nome, Coordenadas, Dimensao);
        //Imprime_Unico(&P[Contagem], Dimensao, 0);
        //printf("%d",Contagem);
        Contagem++;
    }
    for(int i = 0; i < Contagem; i++){
        Imprime_Unico(&P[i], Dimensao, 0);
    }
    float Distancia;
    for(int i = 0; i < Contagem; i++){
        for(int k = i + 1; k < Contagem; k++){
            if(Retorna_Numero_Dista(&P[i]) == Retorna_Tamanho_Cord(&P[i])){
                Realloca_Distancia(Retorna_Distancia(&P[i]), Contagem);
            }
            if(Retorna_Numero_Dista(&P[k]) == Retorna_Tamanho_Cord(&P[k])){
                Realloca_Distancia(Retorna_Distancia(&P[k]), Contagem);
            }
            Distancia = Calcula(&P[i], &P[k], Dimensao);
            Adiciona_Distancias(&P[i], Retorna_Nome(&P[k]), Distancia);
            Adiciona_Distancias(&P[k], Retorna_Nome(&P[i]), Distancia);
        }
    }
    for(int i = 0; i < Contagem; i++){
        //Imprime_Unico(&P[i], Dimensao, 0);
    }
    fclose(Entrada);
    free(Linha);
}

void Imprimir(Ponto* P){

}
