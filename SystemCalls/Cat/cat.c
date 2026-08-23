#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf(">>> Erro!\n>>> Modo de uso: ./cat <arquivo>\n");
        return 1;
    }

    int bytes_lidos;
    char buffer[4096];
    int arquivoLido = open(argv[1], O_RDONLY);

    if (arquivoLido == -1) {
        if (errno == ENOENT) {
            printf(">>> O arquivo não existe.\n");
            return 1;
        }
    }

    while ((bytes_lidos = read(arquivoLido, buffer, 4096)) > 0) {
        write(1, buffer, bytes_lidos);
    }

    return 0;
}