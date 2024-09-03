#include <stdio.h>
#include <stdlib.h>
#include "Priority.h"


liste maximum(liste L, int time){
    liste tmp = L;
    liste max = L;

    if(max->arrival > time) {
        return NULL;
    }
    else{

        while(tmp != NULL){
            if((tmp->priority > max->priority )&& (tmp->arrival <= time) ){
                max = tmp;
                tmp = tmp->next;
            }else{
                tmp = tmp->next;
            }

        }
    }
    return max;

}


struct exec* PR (liste L, int n) {

    struct exec* E=NULL;
    struct process pp;
    int time = 0;
    liste moez = NULL;
    int total = L->arrival + sumExecution(L);
    int stop = 0;
    while (stop < n ) {
        printf("time: %d\n",time);
        moez = maximum(L, time);

        printf("\nelli bch yekhdem:\n");
        printList(moez);
        printf("\n");

        if (moez != NULL) {
            struct exec * e = (struct exec*)malloc(sizeof(struct exec));
            e->id = moez->pid;
            e->start = time;
            moez->execution--;
            time++;
            e->end = time;
            /* printf( "%d %d",e->id,e->end);*/

            E = addExec2(E,e->id, e->start, e->end);

            if(moez->execution == 0) {
                stop++;
                L = deleteProcess(L, moez);
            }
        }
        else {time++;
            printf("d5ltw9et");
        }

    }
    return E;
}
