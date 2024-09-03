#include <stdio.h>
#include <stdlib.h>
#include "RR.h"

liste ajouterP(liste L ,int time,liste p) {
    if (L == NULL) {
        L = p;
        return L;
    }

    liste tmp1 = L;
    liste tmp2 = NULL;

    while (tmp1 != NULL && tmp1->arrival <= time) {
        tmp2 = tmp1;
        tmp1 = tmp1->next;
    }

    if (tmp2 != NULL) {
        tmp2->next = p;
        p->next = tmp1;
    } else {
        tmp1 = L;
        while (tmp1->next != NULL) {
            tmp1 = tmp1->next;
        }
        tmp1->next = p;
        p->next = NULL;
    }

    return L;
}


struct exec* RR (liste L, int quantum) {

    struct exec* E=NULL;
    struct process pp;
    int total = sumExecution(L);
    int i=0;
    int time = 0;
    liste unfinishedList = NULL;
    queue Q = createQueue();

    while (time < total) {

        liste tmp = L;
        while (tmp != NULL) {
            if (tmp->arrival <= time) {
                enqueueProcess(Q,tmp);
                L = deleteProcess(L,tmp);
            }
            tmp = tmp->next;
        }

        tmp = unfinishedList;
        liste tmp2;

        while (tmp != NULL) {
            enqueueProcess(Q,tmp);
            tmp2 = tmp;
            tmp=tmp->next;
            deleteProcess(unfinishedList,tmp2);
        }


        if (isEmpty(Q)) {
            time++;
        }
        else {
            liste m;
            while(! isEmpty(Q)) {
                pp = dequeueProcess(Q);
                struct exec* e = (struct exec*)malloc(sizeof(struct exec));
                e->id = pp.pid;
                e->start = time;
                if (pp.execution <= quantum) {
                    time+=pp.execution;
                    pp.execution = 0;
                }
                else {
                    time+=quantum;
                    pp.execution-=quantum;
                    m = createProcess(pp.pid,pp.arrival,pp.execution,pp.priority);
                    ajouterP(L,time,m);
                }

                e->end = time;
                E = addExec(E,e);
                i++;
            }
        }
        printf("\ntime: %d",time);

    }
    printf("\n\n");

    return E;
}
