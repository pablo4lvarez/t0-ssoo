#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int lrexec_command(char** input) {
    // input[1] es el comando, y input[2], input[3], ... son los argumentos.
    char *exec_args = input[1]; // Nombre del ejecutable
    execvp(exec_args, &input[1]); // Ejecutar el comando con sus argumentos

    // Si execvp falla, se llega a esta línea
    perror("Error al ejecutar el comando");
    exit(EXIT_FAILURE);
}
