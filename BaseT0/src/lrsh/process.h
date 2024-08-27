#pragma once

#include <sys/types.h>

typedef struct {
    int pid;  // or pid_t if it's available after including the correct header
    char* name;
    int exit_code;
    double start_time;
    double end_time;
} Process;

void update_process_exit_code(pid_t pid, int exit_code, Process* processes ,int* count);

void add_process(pid_t pid, const char* name, Process* processes ,int* count);