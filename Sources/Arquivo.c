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
    int DistQuant = 0;
    int DistQuantOld = 0;
    int Contagem = 0;
    char* Nome;
    int* Coordenadas;
    char* tok;
    
    Ponto* P = Inicia_Ponto(1);
    Distancia* D = Inicia_Distacias(1);
    
    while (getline(&Linha, &T, input) != -1) {
        if (Dimensao == -1) {
            Dimensao = Contar_Dimemsao(strdup(Linha));
        }
        Coordenadas = (int*)malloc(Dimensao * sizeof(int));

        int i;
        for(tok = strtok(Linha, ","), i = 0; tok && *tok; tok = strtok(NULL, ",\n"), i++) {
            if (i == 0) {
                Nome = strdup(tok);
            } else {
                Coordenadas[i-1] = atoi(tok);
            }
        }
        
        Inicia_Unico(&P[Contagem], Nome, Coordenadas, Dimensao, Contagem);
        free(Nome);

        if (Contagem > 0) {
            for (int j = 0; j < Contagem; j++, DistQuantOld++) {
                Adiciona_Distancia(&D[DistQuantOld], P, j, Contagem);
            }
        }

        Contagem++;

        // Soma-se +1 na variável Contagem pois o número de pontos é igual ao número de linhas do arquivo + 1
        DistQuant = (((Contagem+1) * ((Contagem+1) - 1))/ 2) + 1;

        P = Realloca_Ponto(P, Contagem + 1);
        D = Realloca_Distancia(D, DistQuant + 1);
    }
    
    Entrada* info = (Entrada*)malloc(sizeof(Entrada));
    info->Dimensao = Dimensao;
    info->Contagem = Contagem;
    info->P = P;
    info->D = D;
    info->QuantD = DistQuantOld;
    Organiza_Distancia(info->D, DistQuantOld);

    fclose(input);
    free(tok);
    free(Linha);

    return info;
}


