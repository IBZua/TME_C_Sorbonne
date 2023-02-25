//
//  Ex44.c
//  TME9
//
//  Created by Bogouslavsky Illia on 22/01/2023.
//

#include "Ex44.h"


element_t *Supprime_total_element_ensemble(element_t *ensemble, int val){
    //le nouvel ensemble qui va stocker les valeur de l'ensemble - la valeur val
    element_t *nouvelleEnsemble = ensemble;
    //si l'ensemble est vide
    if(ensemble == NULL){
        return NULL;
    }
    //si le premier element est val on skip
    if (nouvelleEnsemble->valeur == val) {
        return nouvelleEnsemble->suivant;
    }
    else{
        //on parcourt l'ensemble jusqu'à la position de val ou la fin
        while (nouvelleEnsemble->suivant != NULL && nouvelleEnsemble->suivant->valeur != val) {
            printf("test\n");
            Affiche_ensemble(nouvelleEnsemble);
            nouvelleEnsemble = nouvelleEnsemble->suivant;
        }
        Affiche_ensemble(nouvelleEnsemble);
        //si l'ensemble est fini on renvoie l'ensemble
        if(nouvelleEnsemble->suivant == NULL){
            return ensemble;
        }
        //sinon ça veut dire que la prochaine valeur est val
        else{
            if(nouvelleEnsemble->suivant->suivant == NULL){
                nouvelleEnsemble->suivant = NULL;
                return ensemble;
            }
            //on saute donc cette valeur
            printf("la prochaine valeur est val\n");
            nouvelleEnsemble->suivant = nouvelleEnsemble->suivant->suivant;
            return ensemble;
        }
        return ensemble;
    }
}

element_t *Supprime_element_ensemble(element_t *ensemble, int val){
    element_t *nouvelleEnsemble = ensemble;
    if (nouvelleEnsemble->valeur == val) {
        if (nouvelleEnsemble->frequence > 1) {
            nouvelleEnsemble->frequence -= 1;
        } else {
            return nouvelleEnsemble->suivant;
        }
        return nouvelleEnsemble;
    }
    while (nouvelleEnsemble->suivant != NULL && nouvelleEnsemble->suivant->valeur != val) {
        nouvelleEnsemble = nouvelleEnsemble->suivant;
    }if(nouvelleEnsemble->suivant == NULL){
        return ensemble;
    }else if(nouvelleEnsemble->suivant->valeur == val){
        if (nouvelleEnsemble->suivant->frequence > 1) {
            nouvelleEnsemble->suivant->frequence -= 1;
        } else {
            nouvelleEnsemble->suivant = nouvelleEnsemble->suivant->suivant;
            return ensemble;
        }
        return ensemble;
        }
    return ensemble;
}
