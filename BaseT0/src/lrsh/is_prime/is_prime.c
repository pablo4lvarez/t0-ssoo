#include <stdio.h>
#include <stdlib.h>

#include "is_prime.h"

int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void is_prime_command(char *num_str) {
    pid_t pid = fork();
    if (pid == 0) {
        // Proceso hijo
        int num = atoi(num_str);
        if (is_prime(num)) {
            printf("%d es primo\n", num);
        } else {
            printf("%d no es primo\n", num);
        }
        exit(EXIT_SUCCESS);
    } else if (pid < 0) {
        perror("Error en fork");
    } else {
        wait(NULL);
    }
}
