#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include "../process.h"

extern Process* processes;
extern int* process_count;

// Función para enviar SIGINT a todos los procesos hijos
void send_sigint_to_children() {
    for (int i = 0; i < *process_count; i++) {
        if (processes[i].pid > 0) {
            kill(processes[i].pid, SIGINT);
        }
    }
}

// Función para enviar SIGKILL a todos los procesos hijos restantes
void send_sigkill_to_children() {
  printf("Enviando SIGKILL a los procesos hijos restantes...\n");
    for (int i = 0; i < *process_count; i++) {
        if (processes[i].pid > 0) {
            kill(processes[i].pid, SIGKILL);
        }
    }
}

// Función que implementa lrexit
void lrexit_command() {
    printf("\nEjecutando lrexit de forma normal...\n");
    send_sigint_to_children();

    // Esperar hasta 10 segundos para que terminen los procesos hijos
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < 10) {
        printf("\nDentro del while de lrexit.\n");
        printf("Tiempo transcurrido: %ld\n", time(NULL) - start_time);

        int status;
        pid_t pid = waitpid(-1, &status, WNOHANG); // Espera no bloqueante
        if (pid > 0) {
            // Marca el proceso como terminado
            for (int i = 0; i < *process_count; i++) {
                if (processes[i].pid == pid) {
                    processes[i].pid = -1; // Marca el PID como terminado
                    printf("Proceso hijo con PID %d terminó con estado %d\n", pid, WEXITSTATUS(status));
                    break;
                }
            }
        } else if (pid == 0) {
            // Aún hay procesos vivos, continua esperando
            sleep(1);
        } else {
            // No quedan más procesos hijos
            break;
        }
    }

    // Si todavía quedan procesos activos, enviar SIGKILL
    send_sigkill_to_children();

    // Espera por los procesos que aún no han terminado
    while (wait(NULL) > 0);

    free(processes);
    free(process_count);
    exit(0);
}

// Manejador de señal para SIGINT (Ctrl + C)
void handle_sigint(int sig) {
    printf("\nRecibida señal SIGINT. Ejecutando lrexit...\n");
    lrexit_command();  // Llamar a lrexit para manejar la salida
}
