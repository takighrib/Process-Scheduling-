#include <stdio.h>
#include <stdlib.h>
#include "SRT.h"

liste minimum(liste L, int time){
    liste tmp = L;
    liste min = L;

    if(min->arrival > time) {
        return NULL;
    }
    else{

        while(tmp != NULL){
            if((tmp->execution < min->execution )&& (tmp->arrival <= time) ){
                min = tmp;
                tmp = tmp->next;
            }else{
                tmp = tmp->next;
            }

        }
    }
    return min;

}


struct exec* SRT (liste L, int n) {

    struct exec* E=NULL;
    struct process pp;
    int time = 0;
    liste m = NULL;
    int total = L->arrival + sumExecution(L);
    int stop = 0;
    while (stop < n ) {
        printf("time: %d\n",time);
        m = minimum(L, time);

        printf("\nelli bch yekhdem:\n");
        printList(m);
        printf("\n");

        if (m != NULL) {
            struct exec * e = (struct exec*)malloc(sizeof(struct exec));
            e->id = m->pid;
            e->start = time;
            m->execution--;
            time++;
            e->end = time;
            /* printf( "%d %d",e->id,e->end);*/

            E = addExec2(E,e->id, e->start, e->end);

            if(m->execution == 0) {
                stop++;
                L = deleteProcess(L, m);
            }
        }
        else {
            time++;
        }

    }
    return E;
}
