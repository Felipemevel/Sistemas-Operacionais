#include <dirent.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char* argv[]) {

    if (argc > 2) {
        printf(">>> Erro!\n>>>Modo de Uso: ./ls <diretorio>\n");
        return 1;
    }

    char* diretorio;
    if (argc == 1) {
        diretorio = ".";
    } else {
        diretorio = argv[1];
    }

    DIR* diretorio_ = opendir(diretorio);
    struct dirent* item;
    while ((item = readdir(diretorio_)) != NULL) {
        printf(">>> %s\n", item->d_name);
    }
    closedir(diretorio_);

    return 0;
}