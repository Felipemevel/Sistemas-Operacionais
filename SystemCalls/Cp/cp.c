#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

    if (argc != 3) {
        printf(">>> Erro!\nModo de uso: ./cp <arquivo_original> <arquivo_copia>\n");
        return 1;
    }

    int arquivoOriginal = open(argv[1], O_RDONLY);
    int arquivoCopia = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char buffer[4096];
    int bytes_lidos;

    if (arquivoOriginal == -1) {
        if (errno == ENOENT) {
            printf(">>> O arquivo original não existe.\n");
            return 1;
        }
    }

    while ((bytes_lidos = read(arquivoOriginal, buffer, 4096)) > 0) {
        write(arquivoCopia, buffer, bytes_lidos);
    }

    return 0;
}
