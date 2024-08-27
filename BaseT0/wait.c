#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Para la función sleep

int main(int argc, char *argv[]) {
    // Verificar si se han pasado dos argumentos
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <arg1> <arg2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Imprimir los argumentos recibidos
    printf("Argumento 1: %s\n", argv[1]);
    printf("Argumento 2: %s\n", argv[2]);

    // Esperar 2 segundos
    printf("Esperando 2 segundos...\n");
    sleep(2);

    // Mensaje final
    printf("Tiempo de espera terminado.\n");

    return EXIT_SUCCESS;
}
