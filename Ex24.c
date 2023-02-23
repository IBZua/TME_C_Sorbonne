//
//  Ex24.c
//  TME4
//
//  Created by Bogouslavsky Illia on 18/12/2022.
//

#include <stdio.h>
#include <stdlib.h>
void initialisateurTab(int tab[],int taille, int nbEl){
    int i = 0;
    int j = 0;
    while (i < nbEl) {
        tab[i] = j;
        i += 1;
        j += 2;
    }
}
int indiceInsert(int tab[], int el, int nb, int taille){
    int i = 0;
    if (nb == taille) {
        printf("le tableau est plein\n");
        return -1;
    }
    while (i < taille) {
        if (tab[i] == el) {
            printf("l'element %i est déjà présent a l'indice = %i\n tab[%i] = %i\n", el, i, i, tab[i]);
            return -1;
        }else if (el < tab[i]){
            printf("l'indice est %i\n",i);
            return i;
        }
        i += 1;
    }
    printf("l'indice est %i\n",taille-1);
    return taille-1;
}
int insertElt(int tab[], int el, int nb, int taille) {
    int indice = indiceInsert(tab,el, nb, taille);
    int i = 0;
    int* tabbis = malloc(taille * sizeof(int));
    if (indice == -1) {
        return 0;
    }
    while (i < nb){
        tabbis[i] = tab[i];
        i += 1;
    }
    tab[indice] = el;
    nb = nb+1;
    if(indice+1 < nb){
        indice += 1;
        while (indice < nb) {
            tab[indice] = tabbis[indice-1];
            indice += 1;
        }
    }
    return 1;
}
void affiche_tab(int tab[], int taille) {
    int i;
    for (i = 0; i < taille; i++) {
        printf("%d  ", tab[i]);
    }
    printf("\n");
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
    int tab1[5] = {3, 5, 7, 9};
    indiceInsert(tab1, 1, 4, 5);
    indiceInsert(tab1, 6, 4, 5);
    indiceInsert(tab1,10,4,5);
    indiceInsert(tab1,7,4,5);
    indiceInsert(tab1,6,4,4);
    insertElt(tab1, 1, 4, 5);
    affiche_tab(tab1, 5);
    int tab2[5] = {3, 5, 7, 9};
    insertElt(tab2, 6, 4, 5);
    affiche_tab(tab2, 5);
}
