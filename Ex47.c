//
//  Ex47.c
//  TME10
//
//  Created by Bogouslavsky Illia on 24/01/2023.
//

#include "Ex47.h"
//CodeRunner 10.1.1
int taille(element_t *ensemble){
    if(ensemble == NULL){
        return 0;
    }else if(ensemble->suivant == NULL){
        return ensemble->frequence;
    }else{
        ensemble->suivant->frequence += ensemble->frequence;
        ensemble = ensemble->suivant;
        return taille(ensemble);
    }
}
//CodeRunner 10.1.2
element_t* Supprime_frequence_inf_seuil(element_t* ensemble, int seuil) {
    //si l'ensemble est vide
    if(ensemble == NULL){
        return NULL;
    }
    //si le premier element de l'ensemble est < seuil
    if (ensemble->frequence < seuil) {
        element_t *tmp = ensemble->suivant;
        free(ensemble);
        ensemble = tmp;
        return Supprime_frequence_inf_seuil(ensemble, seuil);
    }
    //si ce n'est pas le dernier element de l'ensemble, on le parcourt jusqu'à ce qu'il le soit
    ensemble->suivant = Supprime_frequence_inf_seuil(ensemble->suivant, seuil);
    return ensemble;
}
