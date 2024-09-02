#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int lrexec_command(char** input, int* process_count) {
    char *exec_args = input[1];
    execvp(exec_args, &input[1]);

    if (errno == ENOENT) {
        (*process_count)--;
        fprintf(stderr, "Error: el ejecutable '%s' no existe.\n", exec_args);
    } else {
        (*process_count)--; 
        perror("Error al ejecutar el comando");
    }

    exit(EXIT_FAILURE);
}