#include <stdio.h>
#include <stdlib.h>

#include "sum.h"

void sum_command(char *num1_str, char *num2_str) {
    pid_t pid = fork();
    if (pid == 0) {
        // Proceso hijo
        double num1 = atof(num1_str);
        double num2 = atof(num2_str);
        printf("%.2f\n", num1 + num2);
        exit(EXIT_SUCCESS);
    } else if (pid < 0) {
        perror("Error en fork");
    } else {
        wait(NULL);
    }
}