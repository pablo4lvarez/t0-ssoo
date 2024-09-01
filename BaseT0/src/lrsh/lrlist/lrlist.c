
#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include "lrlist.h"

void lrlist_command(Process* processes, int process_count) {
    printf("PID\tNombre\t\tTiempo de Ejecución\tExit Code\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < process_count; i++) {
        int time_elapsed = (int)(time(NULL) - processes[i].start_time);
        if (processes[i].exit_code != -1) {
            time_elapsed = (int)(processes[i].end_time - processes[i].start_time);
        }
        printf("%d\t%s\t%d segundos\t\t%d\n",
            processes[i].pid,
            processes[i].name,
            time_elapsed,
            processes[i].exit_code);
    }
}