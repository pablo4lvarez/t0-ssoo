#include <stdio.h>
#include <stdlib.h>

#include "hello.h"

void hello_command() {
    pid_t pid = fork();
    if (pid == 0) {
        // Proceso hijo
        printf("Hello World!\n");
        exit(EXIT_SUCCESS);
    } else if (pid < 0) {
        // Error en fork
        perror("Error en fork");
    } else {
        // Proceso padre espera a que el hijo termine
        wait(NULL);
    }
}
