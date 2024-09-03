#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Queue/QueueManipulation.h"
#include "CPU Scheduling Algorithms/FIFO/FIFO.h"
#include "GanttChart/GanttChart.h"
#include "CPU Scheduling Algorithms/RR/RR.h"
#include "CPU Scheduling Algorithms/SRT/SRT.h"
#include "CPU Scheduling Algorithms/Priority/Priority.h"
#include "CPU Scheduling Algorithms/Multilevel/MultiLevel.h"


typedef struct {
    int min;
    int max;
} Interval;

int generateRandomNumber(Interval interval) {
    return interval.min + rand() % (interval.max - interval.min + 1);
}

void generateProcess(int processNumber, Interval arrivalInterval, Interval executionInterval, Interval priorityInterval, FILE *file) {
    srand(time(NULL));

    for (int i = 0; i < processNumber; i++) {
        int arrival_time = generateRandomNumber(arrivalInterval);
        int execution_time = generateRandomNumber(executionInterval);
        int priority = generateRandomNumber(priorityInterval);

        fprintf(file, "Process %d: Arrival Time %d, Execution Time %d, Priority %d\n", i + 1, arrival_time, execution_time, priority);
    }
}


int main() {

    int processNumber, choice;
    Interval arrivalTimeInterval, executionTimeInterval, priorityInterval;
    srand(time(0));

    printf("\033[1;34m --------------------------------------------------------------------- \033[0m\n");
    printf("\033[1;34m |                         Process Scheduler                         |\033[0m\n");
    printf("\033[1;34m --------------------------------------------------------------------- \033[0m\n\n");

    do {
        printf("1- Please type the number of process you want to simulate: ");
        scanf("%d", &processNumber);
    } while (processNumber <= 0);
    printf("\n");

    printf("2- Now choose the interval of Arrival Time of your process:\n");
    do{
        printf("\tMin: ");
        scanf("%d", &arrivalTimeInterval.min);
    } while (arrivalTimeInterval.min < 0);
    do {
        printf("\tMax: ");
        scanf("%d", &arrivalTimeInterval.max);
    } while (arrivalTimeInterval.max <= arrivalTimeInterval.min);
    printf("\n");

    printf("3- Next choose the interval of Execution Time of your process:\n");
    do {
        printf("\tMin: ");
        scanf("%d", &executionTimeInterval.min);
    } while (executionTimeInterval.min < 0);
    do {
        printf("\tMax: ");
        scanf("%d", &executionTimeInterval.max);
    } while (executionTimeInterval.max < executionTimeInterval.min);
    printf("\n");

    printf("4- Finally, choose the interval of Priority of your process:\n");
    do {
        printf("\tMin: ");
        scanf("%d", &priorityInterval.min);
    } while (priorityInterval.min < 0);
    do {
        printf("\tMax: ");
        scanf("%d", &priorityInterval.max);
    } while (priorityInterval.max < priorityInterval.min);
    printf("\n");


    FILE *file = fopen("test.txt", "w");
    if (file == NULL) {
        perror("Error when opening file");
        exit(1);
    }

    generateProcess(processNumber, arrivalTimeInterval, executionTimeInterval, priorityInterval, file);
    printf("Process File generated successfully !\n\n\n");
    fclose(file);
    system("gedit test.txt &");


    liste L = NULL;
    L = collectProcesses(L);
     bubbleSort(&L, processNumber);

     printf("\033[38;2;3;174;198m Sorted list of processes based on arrival time:\033[0m\n");
     printList(L);


    do {
        printf("\nMenu: Scheduling Algorithms \n");
        printf("\033[1;34m \t\t[1] FIFO  \033[0m\n");
        printf("\033[38;2;249;16;16m \t\t[2] Round Robin \033[0m\n");
        printf("\033[38;2;2;156;142m \t\t[3] SRT  \033[0m\n");
        printf("\033[38;2;138;43;226m \t\t[4] Priority  \033[0m\n");
        printf("\033[38;2;255;207;1m \t\t[5] MultiLevel  \033[0m\n");
        printf("\t\t[0] Quit\n\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        printf("\n");
        printf("\n********************************************************************************************************************************************************\n");

        liste L3 = NULL;
        L3 = collectProcesses(L3);
        bubbleSort(&L3, processNumber);


        switch (choice) {
            case 1: {
                printf("\033[1;34m 1- FIFO Scheduling: \033[0m\n\n");

                struct exec *E_FIFO = FIFO(L3);
                displayGanttChart(E_FIFO);

                printf("\n********************************************************************************************************************************************************\n");
                break;
            }
            case 2: {
                printf("\n\033[38;2;249;16;16m 2- Round Robin Scheduling: \033[0m\n\n");
                int quantum;
                printf("Enter the time quantum for Round Robin: ");
                scanf("%d", &quantum);

                struct exec *E_RR = RR(L3, quantum);
                displayGanttChart(E_RR);

                printf("\n********************************************************************************************************************************************************\n");
                break;
            }
            case 3: {
                printf("\n\033[38;2;2;156;142m 3- SRT Scheduling: \033[0m\n\n");

                struct exec *E_SRT = SRT(L3, processNumber);
                displayGanttChart(E_SRT);

                printf("\n********************************************************************************************************************************************************\n");
                break;
            }
            case 4: {
                printf("\033[38;2;138;43;226m 4- Priority Scheduling: \033[0m\n");

                struct exec *E_PR = PR(L3, processNumber);
                displayGanttChart(E_PR);

                printf("\n********************************************************************************************************************************************************\n");
                break;
            }
            case 5: {
                printf("\033[38;2;255;207;1m 5- MultiLevel Scheduling: \033[0m\n");
                int x=0;
                // test multilevel
                printf("%d",MultiLevel(L3,processNumber));
                printf("\n********************************************************************************************************************************************************\n");
                break;
            }
            case 0: {
                // Quit
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    } while (choice != 0);

    return 0;

}