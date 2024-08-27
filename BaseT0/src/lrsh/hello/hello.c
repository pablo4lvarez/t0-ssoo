#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // Para fork()
#include <sys/wait.h> // Para wait()

#include "hello.h"

void hello_command() {
    printf("Hello World!\n");
}
