#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf(">>> Erro!\n>>>Modo de uso: ./mkdir <nome_diretorio>\n");
        return 1;
    }

    char* nomeDiretorio = argv[1];
    int criarDiretorio = mkdir(nomeDiretorio, 0777);

    if (criarDiretorio == -1) {
        if (errno == EEXIST) {
            printf(">>> Esse nome já existe!\n");
        } else {
            printf(">>> Erro inesperado ao criar diretório.\n");
        }
    }
    return 0;
}
