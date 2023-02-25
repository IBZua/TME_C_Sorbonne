//
//  Ex47.c
//  TME10
//
//  Created by Bogouslavsky Illia on 24/01/2023.
//

#include "Ex47.h"

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

element_t *Supprime_frequence_inf_seuil(element_t *ensemble, int seuil){
    //si l'ensemble est vide
    if(ensemble == NULL){
        return NULL;
    }
    //si le premier element de l'ensemble est < seuil
    if (ensemble->frequence < seuil) {
        printf("la freq du premier element %d est %i < seuil\n", ensemble->valeur, ensemble->frequence);
        return Supprime_frequence_inf_seuil(ensemble->suivant, seuil);
    }
    //l'ensemble que l'on utilisera pour parcourir l'ensemble de base
    element_t *ensembleP = ensemble;
    //si ce n'est pas le dernier element de l'ensemble, on le parcourt jusqu'à ce qu'il le soit
    while (ensembleP->suivant != NULL) {
        //si prochain element freq < seuil, le prochain element sera celui d'apres
        printf("la freq de %d est %d\n", ensembleP->suivant->valeur, ensembleP->suivant->frequence);
        if(ensembleP->suivant->frequence < seuil){
            printf("on doit supprimer %i\n", ensembleP->suivant->valeur);
            ensembleP->suivant = ensembleP->suivant->suivant;
        }else{
            ensembleP = ensembleP->suivant;
        }
    }
    return ensemble;
}
