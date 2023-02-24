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
int recherche_rec_aux(int tab[], int taille, int i, int el){
    if (tab[i] != el && i < taille) {
        i += 1;
        return recherche_rec_aux(tab, taille, i, el);
    } else {
        if (tab[i] == el) {
            printf("Trouvée !\n");
            return i;
        } else {
            printf("Absent !\n");
            return -1;
        }
    }
}
int recherche_rec(int tab[], int taille, int el){
    if (taille == 0) {
        return -1;
    } else if (tab[taille-1] == el) {
            printf("Trouvée !\n");
            return taille-1;
    } else {
        printf("Absent !\n");
        return recherche_rec(tab, taille-1, el);
    }
}
int rechercher_it(int tab[], int taille, int el){
    int i;
    for (i = 0; i < taille; i++) {
        if (tab[i] == el) {
            return i;
        }
    }
    return -1;
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
        return recherche_rec_aux(tab, taille, i, el);
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
    recherche_rec_aux(tab,taille,0,9);
    recherche_rec_aux(tab,taille,0,0);
    int tabTrie[taille];
    tabTrie[taille] = *tabTrieGen(tabTrie,taille);
    iterationTrie(0,tabTrie,taille);
    iterationTrie(9,tabTrie,taille);
    rechercherTrie(0,0,tabTrie,taille);
    rechercherTrie(0,9,tabTrie,taille);
    return 0;
}
