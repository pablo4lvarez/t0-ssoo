#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // Para fork()
#include <sys/wait.h> // Para wait()

#include "sum.h"

void sum_command(char *num1_str, char *num2_str) {
    double num1 = atof(num1_str);
    double num2 = atof(num2_str);
    printf("%.2f\n", num1 + num2);
}