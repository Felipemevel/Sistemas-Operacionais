#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

struct memoria_compartilhada {
    char buffer[1024];
    int quantidade;
    int estado;
};

int main(int argc, char **argv) {

    const char * nome = "copy";
    const int SIZE = sizeof(struct memoria_compartilhada);
    void * ptr;
    int shm_fd;

    shm_fd = shm_open(nome, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SIZE);
    ptr = mmap(0, SIZE, PROT_WRITE | PROT_READ, MAP_SHARED, shm_fd, 0);

    struct memoria_compartilhada *memoria = ptr;

    const char * sourcefn = argv[1];
    const char * targetfn = argv[2];

    int s;

    pid_t produtor = fork();
    if (produtor == 0) {
        int source = open(sourcefn, O_RDONLY);
        int s;

        while (true) {
            while (memoria->estado != 0) {
                ;
            }

            s = read(source, memoria->buffer, 1024);

            memoria->quantidade = s;
            memoria->estado = 1;

            if (s == 0) {
                break;
            }
        }

        close(source);
    } else {
        int target = open(targetfn, O_WRONLY | O_CREAT, S_IRUSR|S_IWUSR);

        while (true) {
            while (memoria->estado != 1) {
                ;
            }
            if (memoria->quantidade == 0) {
                break;
            }

            write(target, memoria->buffer, memoria->quantidade);

            memoria->estado = 0;
        }

        close(target);
    }

    return 0;
}