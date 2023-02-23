//
//  Ex32.c
//  TME6
//
//  Created by Bogouslavsky Illia on 12/01/2023.
//
#include <stdio.h>
#include "val_aleatoire.h"
int *tabGen(int tab[], int taille){
    int i;
    for (i = 0; i < taille; i++) {
        tab[i] = valeur_aleatoire(0,9);
        printf("%i ",tab[i]);
    }
    printf("\n");
    return tab;
}
int *tabTrieGen(int tab[], int taille){
    int i;
    for (i = 0; i < taille; i++) {
        tab[i] = i;
        printf("%i ",tab[i]);
    }
    printf("\n");
    return tab;
}
int iteration(int el, int tab[], int taille){
    int i;
    for (i = 0; i < taille; i++) {
        if (tab[i] == el) {
            printf("Trouvée !\n");
            return 1;
        }
    }
    printf("Absent !\n");
    return 0;
}
int rechercher(int i, int el, int tab[], int taille){
    if (tab[i] != el && i < taille) {
        i += 1;
        return rechercher(i, el, tab, taille);
    } else {
        if (tab[i] == el) {
            printf("Trouvée !\n");
            return 1;
        } else {
            printf("Absent !\n");
            return 0;
        }
    }
}
int iterationTrie(int el, int tab[], int taille){
    int i;
    for (i = 0; tab[i] <= el && i < taille; i++) {
        if (tab[i] == el) {
            printf("Trouvée !\n");
            return 1;
        }
    }
    printf("Absent !\n");
    return 0;
}
int rechercherTrie(int i, int el, int tab[], int taille){
    if (tab[i] < el && i < taille) {
        i += 1;
        return rechercher(i, el, tab, taille);
    } else {
        if (tab[i] == el) {
            printf("Trouvée !\n");
            return 1;
        } else {
            printf("Absent !\n");
            return 0;
        }
    }
}
int main(){
    int taille = 8;
    int tab[taille];
    tab[taille] = *tabGen(tab,taille);
    iteration(9,tab,taille);
    iteration(0,tab,taille);
    rechercher(0,9,tab,taille);
    rechercher(0,0,tab,taille);
    int tabTrie[taille];
    tabTrie[taille] = *tabTrieGen(tabTrie,taille);
    iterationTrie(0,tabTrie,taille);
    iterationTrie(9,tabTrie,taille);
    rechercherTrie(0,0,tabTrie,taille);
    rechercherTrie(0,9,tabTrie,taille);
    return 0;
}
