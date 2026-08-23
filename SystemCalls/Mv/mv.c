#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char* argv[]) {

    if (argc != 3) {
        printf(">>> Erro!\n>>> Modo de uso: ./mv <local_origem> <local_destino>\n");
        return 1;
    }

    int moverArquivo = rename(argv[1], argv[2]);

    if (moverArquivo == -1) {
        if (errno == ENOENT) {
            printf(">>> O caminho não existe.\n");
        } else {
            printf(">>> Erro inesperado ao mover\n");
        }
    }
    return 0;
}