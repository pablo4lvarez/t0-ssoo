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

void send_sigkill_to_children() {
    printf("Enviando SIGKILL a los procesos hijos restantes...\n");
    for (int i = 0; i < *process_count; i++) {
        if (processes[i].pid > 0) {
            kill(processes[i].pid, SIGKILL);
        }
    }
}

void lrexit_command() {
    printf("\nEjecutando lrexit de forma normal...\n");
    int start_time = time(NULL);
    int elapsed_time = 0;

    while (elapsed_time < 10) {
        int status;
        pid_t pid = waitpid(-1, &status, WNOHANG);

        if (pid > 0) {
            for (int i = 0; i < *process_count; i++) {
                if (processes[i].pid == pid) {
                    processes[i].pid = -1; 
                    printf("Proceso hijo con PID %d terminó con estado %d\n", pid, WEXITSTATUS(status));
                    break;
                }
            }
        } else if (pid == 0) {
            printf("Sin hijos terminados...\n");
            sleep(1);
        } else if (pid < 0) {
            break;
        }

        elapsed_time = time(NULL) - start_time;
    }
    send_sigkill_to_children();
    while (wait(NULL) > 0);
    free(processes);
    free(process_count);
    exit(0);
}



void handle_sigint(int sig) {
    printf("\nRecibida señal SIGINT. Ejecutando lrexit...\n");
    lrexit_command(processes, process_count); 
}
