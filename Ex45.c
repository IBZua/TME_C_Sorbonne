//
//  Ex45.c
//  TME9
//
//  Created by Bogouslavsky Illia on 23/01/2023.
//

#include "Ex45.h"

element_t *Ajout_ensemble_trie(element_t *ensemble,int val, int freq){
    //si l'ensemble est vide
    if(ensemble == NULL){
        //le nouvelle element de l'ensemble
        element_t *ensembleN = malloc(sizeof(element_t));
        ensembleN->valeur = val;
        ensembleN->frequence = freq;
        ensembleN->suivant = ensemble;
        return ensembleN;
    }
    //si val est la premiere valeur de l'ensemble
    if(ensemble->valeur == val || ensemble->valeur > val){
        if (ensemble->valeur == val) {
            ensemble->frequence += freq;
            return ensemble;
        } else {
            //le nouvelle element de l'ensemble
            element_t *ensembleN = malloc(sizeof(element_t));
            ensembleN->valeur = val;
            ensembleN->frequence = freq;
            ensembleN->suivant = ensemble;
            return ensembleN;
        }
    }
    //l'ensemble parcourut
    element_t *ensembleP = ensemble;
    while(ensembleP->suivant != NULL && ensembleP != NULL){
        //si on trouve l'element ou que le prochaine element > val
        if(ensembleP->suivant->valeur == val || ensembleP->suivant->valeur > val){
            if (ensembleP->suivant->valeur == val) {
                ensembleP->suivant->frequence += freq;
                return ensemble;
            } else {
                //le nouvelle element de l'ensemble
                element_t *ensembleN = malloc(sizeof(element_t));
                ensembleN->valeur = val;
                ensembleN->frequence = freq;
                ensembleN->suivant = ensembleP->suivant;
                ensembleP->suivant = ensembleN;
                return ensemble;
            }
        }
        ensembleP = ensembleP->suivant;
    }
    //si tout les elements sont < val
    //le nouvelle element de l'ensemble
    element_t *ensembleN = malloc(sizeof(element_t));
    ensembleN->valeur = val;
    ensembleN->frequence = freq;
    ensembleN->suivant = NULL;
    ensembleP->suivant = ensembleN;
    return ensemble;
}

element_t *Supprime_total_element_ensemble_trie(element_t *ensemble, int val){
    //si l'ensemble est vide
    if(ensemble == NULL){
        return NULL;
    }
    //si val est le 1er element de l'ensemble
    if(ensemble->valeur == val){
        return ensemble->suivant;
    }
    //ensemble parcourut
    element_t* ensembleP = ensemble;
    //si val n'est pas le premier element on le cherche dans le reste de l'ensemble
    while (ensembleP->suivant != NULL && ensemble != NULL) {
        //si on trouve val
        if(ensembleP->suivant->valeur == val){
            ensembleP->suivant = ensembleP->suivant->suivant;
            return ensemble;
        }
        ensembleP = ensembleP->suivant;
    }
    //si val est le dernier element
    if(ensembleP->valeur == val){
        ensembleP = NULL;
    }
    return ensemble;
}

element_t *Supprime_element_ensemble_trie(element_t *ensemble, int val){
    //si l'ensemble est vide
    if(ensemble == NULL){
        return NULL;
    }
    //si val est le 1er element de l'ensemble
    if(ensemble->valeur == val){
        if(ensemble->frequence > 1){
            ensemble->frequence -= 1;
            return ensemble;
        }else{
            return ensemble->suivant;
        }
    }
    //ensemble parcourut
    element_t* ensembleP = ensemble;
    //si val n'est pas le premier element on le cherche dans le reste de l'ensemble
    while (ensembleP->suivant != NULL && ensemble != NULL) {
        //si on trouve val
        if(ensembleP->suivant->valeur == val){
            if(ensembleP->suivant->frequence > 1){
                ensembleP->suivant->frequence -= 1;
                return ensemble;
            }else{
                ensembleP->suivant = ensembleP->suivant->suivant;
                return ensemble;
            }
        }
        ensembleP = ensembleP->suivant;
    }
    //si val est le dernier element
    if(ensembleP->valeur == val){
        if(ensembleP->frequence > 1){
            ensembleP->frequence -= 1;
        }else{
            ensembleP = NULL;
        }
    }
    return ensemble;
}
