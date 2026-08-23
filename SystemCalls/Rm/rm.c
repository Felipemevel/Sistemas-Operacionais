#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf(">>>Erro!\n>>>Mode de uso: ./rm <nome_arquivo>\n");
        return 1;
    }

    int removerArquivo = unlink(argv[1]);

    if (removerArquivo == -1) {
        if (errno == EBUSY) {
            printf(">>> Não foi possível remover o arquivo pois ele está em uso.\n");
        } else {
            printf(">>> Erro inesperado ao remover arquivo\n");
        }
    }
    return 0;
}