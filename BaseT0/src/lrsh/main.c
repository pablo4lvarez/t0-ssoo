#include <signal.h>
#include "process.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "../input_manager/manager.h"
#include "./hello/hello.h"
#include "./sum/sum.h"
#include "./is_prime/is_prime.h"
#include "./lrlist/lrlist.h"
#include "./lrexec/lrexec.h"
#include "process.h"
#include "./lrexit/lrexit.h"


Process* processes;
int* process_count;

void sigchld_handler(int sig) {
    int status;
    pid_t pid;

    while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
        int exit_code = WIFEXITED(status) ? WEXITSTATUS(status) : -1;
        update_process_exit_code(pid, exit_code, processes, process_count);
    }
}


int main(int argc, char const *argv[]) {
    processes = calloc(16, sizeof(Process));
    process_count = calloc(1, sizeof(int));

  
    struct sigaction sa;
    sa.sa_handler = sigchld_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    if (sigaction(SIGCHLD, &sa, NULL) == -1) {
        perror("Error en sigaction");
        exit(EXIT_FAILURE);
    }


    signal(SIGINT, handle_sigint);

    while (1) {
        char** input = read_user_input();

        if (input[0] == NULL) {
            free_user_input(input);
            continue;
        }

        if (strcmp(input[0], "lrlist") == 0) {
            lrlist_command(processes, *process_count);
            free_user_input(input);
            continue;
        }

        if (strcmp(input[0], "lrexit") == 0) {
            lrexit_command(processes, process_count);  
            break;  
        }

        pid_t pid = fork();

        if (pid < 0) {
            perror("Error al crear el proceso");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            if (strcmp(input[0], "hello") == 0) {
                hello_command();
                exit(EXIT_SUCCESS);
            } else if (strcmp(input[0], "sum") == 0) {
                sum_command(input[1], input[2]);
                exit(EXIT_SUCCESS);
            } else if (strcmp(input[0], "is_prime") == 0) {
                is_prime_command(input[1]);
                exit(EXIT_SUCCESS);
            } else if (strcmp(input[0], "lrexec") == 0) {
                lrexec_command(input, process_count);
                exit(EXIT_SUCCESS);
            } else {
                fprintf(stderr, "Comando no reconocido: %s\n", input[0]);
            }
            free_user_input(input);
            exit(0); 
        } else {
            if (strcmp(input[0], "hello") == 0 || strcmp(input[0], "sum") == 0 || strcmp(input[0], "is_prime") == 0) {
                add_process(pid, input[0], processes, process_count);
            } else if (strcmp(input[0], "lrexec") == 0) {
                char* name = &input[1][2];
                add_process(pid, name, processes, process_count);
            }
        }
    }

    free(processes);
    free(process_count);
    return 0;
}
