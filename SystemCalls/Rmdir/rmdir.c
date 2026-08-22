#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf(">>> Erro!\n>>>Modo de uso: ./rmdir <nome_diretorio>\n");
        return 1;
    }

    char* nomeDiretorio = argv[1];
    int removerDiretorio = rmdir(nomeDiretorio);

    if (removerDiretorio == -1) {
        if (errno == ENOTEMPTY) {
            printf(">>> O diretório não está vazio!\n");
        } else {
            printf(">>> Erro inesperado ao remover diretório.\n");
        }
    }

    return 0;
}
