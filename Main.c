#include "Headers/Arquivo.h"

int main(int argc, char* argv[]){
    Ponto* P = Inicia(0);
    Ler(argv[1], P);
    free(P);
    return 0;
}