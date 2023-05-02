#include "../Headers/Arquivo.h"

int Contar_Dimemsao(char* Linha) {
    char* tok;
    int Contagem = 0;

    for (tok = strtok(Linha, ","); tok && *tok; tok = strtok(NULL, ",\n")) {
        Contagem++;
    }
    
    free(Linha);
    return Contagem - 1;
}

Entrada* Ler(char* Arquivo) {
    FILE* input = fopen(Arquivo, "r");

    char* Linha;
    size_t T = 256;

    Linha = (char*)malloc(T * sizeof(char));
    
    int Dimensao = -1;
    int Contagem = 0;
    char* Nome;
    double* Coordenadas;
    char* tok;
    char *eptr;

    Ponto* P = Inicia_Ponto(1);
    
    while (getline(&Linha, &T, input) != -1) {
        if (Dimensao == -1) {
            Dimensao = Contar_Dimemsao(strdup(Linha));
        }
        Coordenadas = (double*)malloc(Dimensao * sizeof(double));

        int i;
        for(tok = strtok(Linha, ","), i = 0; tok && *tok; tok = strtok(NULL, ",\n"), i++) {
            if (i == 0) {
                Nome = strdup(tok);
            } else {
                Coordenadas[i-1] = strtod(tok, &eptr);
            }
        }
        
        Inicia_Unico(&P[Contagem], Nome, Coordenadas, Contagem);
        free(Nome);


        Contagem++;

        P = Realloca_Ponto(P, Contagem + 1);
    }
    
    Entrada* info = (Entrada*)malloc(sizeof(Entrada));
    info->Dimensao = Dimensao;
    info->Contagem = Contagem;
    info->P = P;
    info->QuantD = (Contagem * (Contagem - 1))/ 2;

    fclose(input);
    free(tok);
    free(Linha);

    return info;
}


