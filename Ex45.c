//
//  Ex45.c
//  TME9
//
//  Created by Bogouslavsky Illia on 23/01/2023.
//

#include "Ex45.h"
//CodeRunner 9.3.1
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

//CodeRunner 9.3.2
element_t *Supprime_total_element_ensemble_trie(element_t *ensemble, int val){
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
    //ensemble parcourut
    element_t* ensembleP = ensemble;
    //l'ensemble qui va stocker la valeur precedent
    element_t *precedent = NULL;
    //on cherche dans le reste de l'ensemble tant que valeur <= val
    while (ensembleP != NULL && ensembleP->valeur <= val) {
        //si on trouve val
        if(ensembleP->valeur == val){
            element_t *Stock = ensembleP->suivant;
            free(ensembleP);
            precedent->suivant = Stock;
            return ensemble;
        }
        precedent = ensembleP;
        ensembleP = ensembleP->suivant;
    }
    return ensemble;
}
//CodeRunner 9.3.3
element_t *Supprime_element_ensemble_trie(element_t *ensemble, int val){
    //si l'ensemble est vide
    if(ensemble == NULL){
        return NULL;
    }
    //si val est le 1er element de l'ensemble
    if(ensemble->valeur == val){
        if(ensemble->frequence > 1){
            ensemble->frequence -= 1;
        }else{
            element_t *Stock = ensemble->suivant;
            free(ensemble);
            ensemble = Stock;
        }
        return ensemble;
    }
    //ensemble parcourut
    element_t* ensembleP = ensemble;
    //l'ensemble qui va stocker la valeur precedent
    element_t *precedent = NULL;
    //on cherche dans le reste de l'ensemble tant que valeur <= val
    while (ensembleP != NULL && ensembleP->valeur <= val) {
        //si on trouve val
        if(ensembleP->valeur == val){
            if(ensembleP->frequence > 1){
                ensembleP->frequence -= 1;
            }else{
                element_t *Stock = ensembleP->suivant;
                free(ensembleP);
                precedent->suivant = Stock;
            }
            return ensemble;
        }
        precedent = ensembleP;
        ensembleP = ensembleP->suivant;
    }
    return ensemble;
}
