#pragma once
#include <sys/types.h>
#include "../process.h"

void lrexit_command(Process* processes, int* process_count); 
void handle_sigint(int sig);
void send_sigkill_to_children(Process* processes, int* process_count);
void send_sigint_to_children(Process* processes, int* process_count);

