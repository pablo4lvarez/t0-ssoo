
#include <stdio.h>
#include <time.h>
#include <unistd.h>  // Para fork()
#include "lrlist.h"

void lrlist_command(Process* processes, int process_count) {
    printf("PID\tNombre\t\tTiempo de Ejecución\tExit Code\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < process_count; i++) {
        double time_elapsed = (double)(processes[i].end_time - processes[i].start_time);
        printf("%d\t%s\t%lf segundos\t\t%d\n",
            processes[i].pid,
            processes[i].name,
            time_elapsed,
            processes[i].exit_code);
    }
}