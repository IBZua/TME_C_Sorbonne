//
//  Ex43.c
//  TME9
//
//  Created by Bogouslavsky Illia on 21/01/2023.
//

#include "Ex43.h"
/* Retourne un pointeur sur le premier element de valeur val, retourne NULL si aucun ÈlÈment n'a la valeur val */
element_t *Recherche_val(element_t *ensemble, int val) {
    element_t* res = ensemble;
    while(res != NULL){
        if(res->valeur == val){
            return res;
        }
        res = res ->suivant;
    }
    return NULL;
}

/* Ajoute l'element val en tete de l'ensemble s'il n'apparait pas dans l'ensemble, augmente sa frequence de 1 sinon */
element_t *Ajout_tete_ensemble(element_t *ensemble, int val, int freq) {
    element_t *nouvelleEnsemble;
    element_t *valR = Recherche_val(ensemble,val);
    if(valR != NULL){
        nouvelleEnsemble = ensemble;
        valR->frequence += freq;
        return nouvelleEnsemble;
    }else{
        nouvelleEnsemble = malloc(sizeof(element_t));
        nouvelleEnsemble->valeur = val;
        nouvelleEnsemble->frequence = freq;
        nouvelleEnsemble->suivant = ensemble;
        return nouvelleEnsemble;
    }
}

//CodeRunner
element_t* ajout_suivant(element_t* ensemble, int val, int freq) {
    element_t *nouvelleEnsemble = malloc(sizeof(element_t));
    nouvelleEnsemble->valeur = val;
    nouvelleEnsemble->frequence = freq;
    if(ensemble != NULL){
        nouvelleEnsemble->suivant = ensemble->suivant;
        ensemble->suivant = nouvelleEnsemble;
    }
    return nouvelleEnsemble;
}

/* Affche tous les elements d'un ensemble avec leur frequence */
void Affiche_ensemble(element_t *ensemble) {
    element_t *ptr = ensemble;
  
    while (ptr != NULL) {
        printf("val : %d, frequence : %d\n",ptr->valeur,ptr->frequence);
        ptr=ptr->suivant;
    }
    printf("\n");
}

/* Saisie des n elements d'un ensemble */
element_t * Creation_ensemble(int n) {
    element_t *ensemble=NULL;
  
    int i = 0;
    int val;
  
    for (i=0; i < n; i++) {
        printf("Saisie d'un entier: ");
        scanf("%d",&val);
        ensemble=Ajout_tete_ensemble(ensemble,val,1);
    }
    return ensemble;
}
