#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int lrexec_command(char** input) {
    char *exec_args = &input[1];
    execvp(exec_args[0], exec_args);
    exit(EXIT_FAILURE);
}