//
//  Ex44.c
//  TME9
//
//  Created by Bogouslavsky Illia on 22/01/2023.
//

#include "Ex44.h"

//CodeRunner 9.2.1
element_t *Supprime_total_element_ensemble(element_t *ensemble, int val){
    //si l'ensemble est vide
    if(ensemble == NULL){
        return NULL;
    }
    //si le premier element est val
    if (ensemble->valeur == val) {
        element_t *Stock = ensemble->suivant;
        free(ensemble);
        ensemble = Stock;
        return ensemble;
    }
    else{
        //l'ensemble dont on va se servir pour parcourir l'ensemble initiale
        element_t *ensembleP = ensemble;
        //l'ensemble qui va stocker la valeur precedent
        element_t *precedent = NULL;
        //on parcourt l'ensemble jusqu'à la position de val ou la fin
        while (ensembleP != NULL) {
            if(ensembleP->valeur == val){
                element_t *Stock = ensembleP->suivant;
                free(ensembleP);
                precedent->suivant = Stock;
                return ensemble;
            }
            precedent = ensembleP;
            ensembleP = ensembleP->suivant;
        }
        //si l'ensemble est fini on renvoie l'ensemble
        return ensemble;
    }
}
//CodeRunner 9.2.2
element_t *Supprime_element_ensemble(element_t *ensemble, int val){
 //si l'ensemble est vide
    if(ensemble == NULL){
        return NULL;
    }
    if (ensemble->valeur == val) {
        if (ensemble->frequence > 1) {
            ensemble->frequence -= 1;
        } else {
            //si le premier element est val
            element_t *Stock = ensemble->suivant;
            free(ensemble);
            ensemble = Stock;
        }
        return ensemble;
    }
    //l'ensemble dont on va se servir pour parcourir l'ensemble initiale
    element_t *ensembleP = ensemble;
    //l'ensemble qui va stocker la valeur precedent
    element_t *precedent = NULL;
    while (ensembleP != NULL) {
        if (ensembleP->valeur == val) {
            if (ensembleP->frequence > 1) {
                ensembleP->frequence -= 1;
            } else {
                element_t *Stock = ensembleP->suivant;
                free(ensembleP);
                precedent->suivant = Stock;
                return ensemble;
            }
            return ensemble;
        }
        precedent = ensembleP;
        ensembleP = ensembleP->suivant;
    }
    //si l'ensemble est fini on renvoie l'ensemble
    return ensemble;
}
