#include <stdio.h>
#include <stdlib.h>
#include "MultiLevel.h"
#include "../../Queue/QueueManipulation.h"


int priorityOcc(liste L, int n) {
    int occ=1;

    priorityBubbleSort(&L,n);
    liste tmp=L;
    while (tmp->next != NULL) {
        if (tmp->priority != (tmp->next)->priority) {
            occ++;
        }
        tmp=tmp->next;
    }
    return occ;
}

void afficherTab(liste* T, int taille) {
    for (int i = 0; i < taille; i++) {
        printf("tableau %d:\n", i);
        printList(T[i]);
        printf("\n");
    }
}



liste* fillTable(liste L, int priorityOcc) {
    liste* t = malloc(priorityOcc * sizeof(liste));
    int pr;
    liste tmp = L;

    for (int i = 0; i < priorityOcc; ++i) {
        if (tmp == NULL) {
            t[i] = NULL;
            continue;
        }

        pr = tmp->priority;
        liste p = NULL, process;

        while (tmp != NULL && tmp->priority == pr) {
            process = createProcess(tmp->pid, tmp->arrival, tmp->execution, tmp->priority);
            p = addProcessEnd(p, process);
            printList(p);
            tmp = tmp->next;
        }

        t[i] = p;
        if (tmp != NULL) {
            pr = tmp->priority;
        }
    }

    return t;
}



void deleteFirstNodeAtIndex(liste* t, int index) {
    if (t[index] == NULL) {
        // La liste à l'indice index est déjà vide, rien à supprimer
        return;
    }

    // Conserver une référence au premier nœud
    liste firstNode = t[index];

    // Mettre à jour le tableau pour pointer vers le deuxième nœud
    t[index] = t[index]->next;

    // Libérer la mémoire du premier nœud
    free(firstNode);
}



int MultiLevel(liste L, int n) {
    printf("dkhal\n \n,");

    // Assuming the definition of printList function

    struct exec* E = NULL;
    int time = 0;
    int total = L->arrival + sumExecution(L);
    int stop = 0;
    int nbPriority = priorityOcc(L, n);

    liste* tab;
    tab = fillTable(L, nbPriority);
    printf("Nb priority : %d\n", nbPriority);
//    afficherTab(tab, nbPriority) ;


       /* int i = 0;*/

//        for(int i=0; i<2;i++){
//            printf("%d",i);
//            if (tab[i]->arrival <= time) {
//                printf("taaaa");
//                if (tab[i]->execution != 0) {
//                    tab[i]->execution--;
//                    printf("%d ",tab[i]->execution);
//                    time++;
//                } else {
//                    printf("temp %d", time);
//                    deleteFirstNodeAtIndex(tab, i);
//                    // NOTE: Vous avez utilisé 'return 0;' ici, cela sortira de la fonction ou du programme.
//                    // Si cela n'est pas l'intention, vous devriez peut-être utiliser 'break;' à la place.
//                    break;
//                }
//
//            }
//            time++;
//        }





    return 0;
}