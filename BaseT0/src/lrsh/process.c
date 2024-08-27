#include <sys/types.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "process.h"

void add_process(pid_t pid, const char* name, Process* processes ,int* process_count) {
    printf("Adding process %d\n", pid);
    if (*process_count < 16) {
        processes[*process_count].pid = pid;
        processes[*process_count].name = calloc(strlen(name) + 1, sizeof(char));
        printf("Name: %s\n", name);
        strcpy(processes[*process_count].name, name);
        processes[*process_count].start_time = time(NULL);
        processes[*process_count].exit_code = -1; // Aún no ha terminado
        (*process_count)++;
        printf("Process Count: %d\n", *process_count);
    }
}

void update_process_exit_code(pid_t pid, int exit_code, Process* processes ,int* process_count) {
    for (int i = 0; i < *process_count; i++) {
        if (processes[i].pid == pid) {
            processes[i].exit_code = exit_code;
            processes[i].end_time = time(NULL);
            break;
        }
    }
}