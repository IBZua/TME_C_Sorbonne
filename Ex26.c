//
//  Ex26.c
//  TME4
//
//  Created by Bogouslavsky Illia on 26/01/2023.
//
#include <stdlib.h>
#include <stdio.h>

int *fusion(int tab1[], int tab2[], int taille1, int taille2){
    //le tableau resultant de la fusion
    int *tabF = malloc(sizeof(taille1)+sizeof(taille2));
    int i = 0;
    int j = 0;
    int k = 0;
    //tant que l'un des deux tableaux n'est pas fini on compare leurs valeurs
    while (i < taille1 && j < taille2) {
        //si la valeur du tableau 1 est < a celle du tableau 2
        if (tab1[i] < tab2[j]) {
            tabF[k] = tab1[i];
            i += 1;
        } else {
            tabF[k] = tab2[j];
            j += 1;
        }
        printf("tabF[%i] = %i\n", k, tabF[k]);
        k += 1;
    }
    //si le tableau 1 n'est pas fini on ajoute toutes ses valeurs
    while (i < taille1 ) {
        tabF[k] = tab1[i];
        i += 1;
        k += 1;
    }
    //si le tableau 2 n'est pas fini on ajoute toutes ses valeurs
    while (j < taille2) {
        tabF[k] = tab2[j];
        j += 1;
        k += 1;
    }
    return tabF;
}

int main(int argc, const char * argv[]) {
    int tab1[4] = {2,4,6,8};
    int tab2[4] = {3,5,6,7};
    fusion(tab1, tab2, 4, 4);
    return 0;
}
