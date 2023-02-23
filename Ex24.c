//
//  Ex24.c
//  TME4
//
//  Created by Bogouslavsky Illia on 18/12/2022.
//

#include <stdio.h>
void initialisateurTab(int tab[],int taille, int nbEl){
    int i = 0;
    int j = 0;
    while (i < nbEl) {
        tab[i] = j;
        i += 1;
        j += 2;
    }
}
int indiceInsert(int tab[], int taille, int nbEl, int el){
    int i = 0;
    if (nbEl == taille) {
        i = -1;
    } else {
        while (tab[i] < el) {
            i += 1;
        }
        if (tab[i] == el) {
            printf("L'element %i est deja present !\n", el);
            i = -1;
        }
    }
    printf("l'indice est %i\n",i);
    return i;
}
int insertElt(int tab[], int taille, int *nbEl, int el){
    int indice = indiceInsert(tab,taille, *nbEl, el);
    int i = 0;
    int tabbis[taille];
    if (indice == -1) {
        return 0;
    }else{
        while (i < indice){
            tabbis[i] = tab[i];
            printf("tabbis [%i] = %i\n",i,tabbis[i]);
            i += 1;
        }
        tabbis[indice] = el;
        printf("tabbis [%i] = %i\n",i,tabbis[i]);
        *nbEl += 1;
        i += 1;
        while (i < *nbEl) {
            tabbis[i] = tab[i-1];
            printf("tabbis [%i] = %i\n",i,tabbis[i]);
            i += 1;
        }
    }
    return 1;
}

int main(){
    int taille = 10;
    int tab[10];
    int nbEl = 8;
    initialisateurTab(tab,10, nbEl);
    int i = 0;
    while (i < taille-1) {
        printf("i = %i      %i\n",i, tab[i]);
        i += 1;
    }
    indiceInsert(tab,taille, nbEl, 3);
    insertElt(tab, taille, &nbEl, 3);
    insertElt(tab, taille, &nbEl, 3);
}

