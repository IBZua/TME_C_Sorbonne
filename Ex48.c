//
//  Ex48.c
//  TME9
//
//  Created by Bogouslavsky Illia on 25/01/2023.
//

#include "Ex48.h"

int Inclus_rec(element_t *ensemble1, element_t *ensemble2){
    //on vérifie que aucun des ensembles n'est vide
    if(ensemble1 == NULL || ensemble2 == NULL){
        if (ensemble1 == NULL) {
            return 1;
        } else {
            return 0;
        }
    }
    //si les premieres valeurs sont egales
    if(ensemble1->valeur == ensemble2->valeur){
        //si la frequence de val dans ensemble1 > ensemble2
        if (ensemble1->frequence > ensemble2->frequence) {
            return 0;
        } else {
            //tant que la liste n'est pas fini
            if (ensemble2->suivant != NULL && ensemble1->suivant != NULL) {
                ensemble1 = ensemble1->suivant;
                ensemble2 = ensemble2->suivant;
                return Inclus_rec(ensemble1, ensemble2);
            } else {
                if (ensemble1->suivant == NULL) {
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    }else{
        if (ensemble1->valeur < ensemble2->valeur) {
            return 0;
        } else {
            ensemble2 = ensemble2->suivant;
            return Inclus_rec(ensemble1, ensemble2);
        }
    }
}

element_t *UnionME(element_t *ensemble1, element_t *ensemble2){
    //on vérifie que les deux ensembles ne sont pas vide
    if(ensemble1 == NULL && ensemble2 == NULL){
        return NULL;
    }
    //on cree l'ensemble resultant de l'union
    element_t *ensembleU = NULL;
    //si l'un des 2 ensemble est vide
    if(ensemble1 == NULL || ensemble2 == NULL){
        if (ensemble1 == NULL) {
            while (ensemble2 != NULL) {
                ensembleU = Ajout_tete_ensemble(ensembleU, ensemble2->valeur, ensemble2->frequence);
                ensemble2 = ensemble2->suivant;
            }
            return ensembleU;
        } else {
            ensembleU = Ajout_tete_ensemble(ensembleU,ensemble1->valeur, ensemble1->frequence);
            while (ensemble1 != NULL && ensemble1->suivant != NULL) {
                ensembleU = Ajout_tete_ensemble(ensembleU, ensemble1->suivant->valeur, ensemble1->suivant->frequence);
                ensemble1 = ensemble1->suivant;
            }
            return ensembleU;
        }
    }
    //on parcourt le reste des ensemble tant que l'un des deux n'est pas fini
    while (ensemble1 != NULL && ensemble2 != NULL) {
        //si les valeurs sont egales
        if (ensemble1->valeur == ensemble2->valeur) {
            ensembleU = Ajout_tete_ensemble(ensembleU, ensemble1->valeur, ensemble1->frequence+ensemble2->frequence);
            ensemble1 = ensemble1->suivant;
            ensemble2 = ensemble2->suivant;
            //si val ensemble1 < val ensemble2
        } else if (ensemble1->valeur < ensemble2->valeur) {
            ensembleU = Ajout_tete_ensemble(ensembleU, ensemble1->valeur, ensemble1->frequence);
                ensemble1 = ensemble1->suivant;
            //si val ensemble2 < val ensemble1
        } else {
            ensembleU = Ajout_tete_ensemble(ensembleU, ensemble2->valeur, ensemble2->frequence);
            ensemble2 = ensemble2->suivant;
        }
    }
    //si les deux ensembles sont fini
    if(ensemble1 == NULL && ensemble2 == NULL){
        return ensembleU;
    }
    //si l'ensemble1 est fini en premier
    if(ensemble1 == NULL){
        while (ensemble2 != NULL) {
            ensembleU = Ajout_tete_ensemble(ensembleU, ensemble2->valeur, ensemble2->frequence);
            ensemble2 = ensemble2->suivant;
        }
        return ensembleU;
    }
    //si l'ensemble2 est fini en premier
    else {
        while (ensemble1 != NULL) {
            ensembleU = Ajout_tete_ensemble(ensembleU, ensemble1->valeur, ensemble1->frequence);
            ensemble1 = ensemble1->suivant;
        }
        return ensembleU;
    }
}
