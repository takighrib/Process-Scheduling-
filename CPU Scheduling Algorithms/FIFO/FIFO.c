#include <stdio.h>
#include <stdlib.h>
#include "FIFO.h"

struct exec* FIFO(liste L) {
    struct exec* GanttChart = NULL;
    struct exec* tail = NULL;

    int count = 0;
    struct process* temp = L;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    bubbleSort(&L, count);

    printf("\033[1;34m \tExecution Details: \033[0m\n");

    int currentTime = L->arrival;

    while (L != NULL) {
        struct exec* newEntry = (struct exec*)malloc(sizeof(struct exec));
        newEntry->id = L->pid;
        newEntry->start = currentTime;
        newEntry->end = currentTime + L->execution;
        newEntry->next = NULL;

        if (GanttChart == NULL) {
            GanttChart = newEntry;
            tail = newEntry;
        } else {
            tail->next = newEntry;
            tail = newEntry;
        }

        printf("\tP%d started at %d, ended at %d\n", L->pid, newEntry->start, newEntry->end);

        currentTime += L->execution;
        L = L->next;
    }

    printf("\n");

    return GanttChart;
}
