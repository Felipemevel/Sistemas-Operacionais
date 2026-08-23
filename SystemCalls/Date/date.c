#include <unistd.h>
#include <time.h>
#include <stdio.h>

int main() {
    time_t data;
    data = time(NULL);
    char* dataFormatada = ctime(&data);

    printf(">>> %s", dataFormatada);

    return 0;
}