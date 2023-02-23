//
//  Ex28.c
//  TME5
//
//  Created by Bogouslavsky Illia on 09/01/2023.
//

#include "val_aleatoire.h"
#include <stdio.h>
#define NB_AMIS 4
#define NB_JOURS 7
//initTab initialise un tableau à 0
void initTab(int tab[][NB_JOURS]){
    int i,j;
    for (i = 0; i < NB_JOURS; i++) {
        for (j = 0; j < NB_AMIS; j++) {
            tab[j][i] = 0;
        }
    }
}
//compt selectionne au hasard un des 4 amis et lui assigne un motant entre 30 et 50
void compt(int tab[][NB_JOURS], int taille){
    int i;
    for (i = 0; i < NB_JOURS; i++) {
        int selectionne = valeur_aleatoire(0,3);
        tab[selectionne][i] = valeur_aleatoire(30,50);
    }
}
//affiche le contenu du tableau pour les montant supérieur à 0
void affichTab(int tab[][NB_JOURS]){
    int i,j;
    for (i = 0; i < NB_JOURS; i++) {
        if (i == 0) {
        }
        for (j = 0; j < NB_AMIS; j++) {
            if (tab[j][i] != 0) {
                printf("Jour %i : %i paye %i\n",i+1,j,tab[j][i]);
            }
        }
    }
}
//affiche le montant à payer pour un des 4 amis
void solde(int tab[][NB_JOURS], int ami){
    int i;
    int sum = 0;
    for (i = 0; i < NB_JOURS; i++) {
        sum += tab[ami][i];
    }
    printf("Le montant à payer pour l'ami %i est de %i\n", ami, sum);
}

int main(){
    int tab[NB_AMIS][NB_JOURS];
    initTab(tab);
    compt(tab, NB_JOURS);
    affichTab(tab);
    solde(tab,0);
    solde(tab,1);
    solde(tab,2);
    solde(tab,3);
    return 0;
}
