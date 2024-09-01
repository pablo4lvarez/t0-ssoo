#pragma once

#include <sys/types.h>

typedef struct {
    int pid;  
    char* name;
    int exit_code;
    int start_time;
    int end_time;
} Process;

void update_process_exit_code(pid_t pid, int exit_code, Process* processes ,int* count);

void add_process(pid_t pid, const char* name, Process* processes ,int* count);