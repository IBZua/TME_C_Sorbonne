//
//  Ex40.c
//  TME8
//
//  Created by Bogouslavsky Illia on 21/01/2023.
//

#include "Ex40-41.h"

cellule_t * creerListe(int n) {
/* cree une liste de n entiers saisi par l'utilisateur
  renvoie l'adresse du premier element de la liste */
  int i;
  //val la valeur ajouter à la liste
  int val;
  //tete de la liste
  cellule_t *tete=NULL;
  //variable intermediaire qui sert a l'ajout de nouveau element et au stockage de l'ancienne liste
  cellule_t *ptr;
  
  printf("Saisie des %d elements de la liste\n",n);
  for (i=0; i < n; i++) {
    printf("Element %d :",n-i);
    scanf("%d",&val);
    ptr=malloc(sizeof(cellule_t));
    //la valeur de la donne de ptr est celle de val
    ptr->donnee = val;
    //la donnee suivant est le reste de la liste
    ptr->suivant = tete;
    //la tete de la liste = a la liste temporaire
    tete = ptr;
  }
  return tete;
}

void AfficherListeInt(cellule_t *liste){
    cellule_t *cellule = liste;
    while (cellule != NULL) {
        printf("%i\n",cellule->donnee);
        cellule = cellule->suivant;
    }
}

int nb_occurences(int val, cellule_t *liste){
    cellule_t *cellule = liste;
    int i = 0;
    while (cellule != NULL) {
        if(cellule->donnee == val){
            i += 1;
        }
        cellule = cellule->suivant;
    }
    return i;
}

int tous_plus_grand(int val,cellule_t *liste){
    cellule_t *cellule = liste;
    while (cellule != NULL) {
        if(cellule->donnee < val){
            return 0;
        }
        cellule = cellule->suivant;
    }
    return 1;
}

cellule_t* Maximum(cellule_t *liste){
    cellule_t *cellule = liste;
    int valMax = cellule->donnee;
    cellule_t *cellule_max = cellule;
    while (cellule->suivant != NULL) {
        if(cellule->suivant->donnee > valMax){
            valMax = cellule->suivant->donnee;
            cellule_max = cellule;
        }
        cellule = cellule->suivant;
    }
    return cellule_max;
}

int Renvoyer_val_element_pos(int pos, cellule_t* liste){
    cellule_t *cellule = liste;
    int i = 1;
    while (cellule != NULL) {
        if(i == pos){
            return cellule->donnee;
        }
        i += 1;
        cellule = cellule->suivant;
    }
    return 0;
}

cellule_t *Concatener_it(cellule_t *liste1, cellule_t *liste2, cellule_t *listTemp){
    if (liste1 == NULL || liste2 == NULL) {
        if (liste2 == NULL) {
            return liste1;
        } else {
            if (liste1 == NULL) {
                return liste2;
            } else {
                return NULL;
            }
        }
    } else {
        if (listTemp->suivant == NULL) {
            listTemp->suivant = liste2;
            return liste1;
        } else {
            listTemp = listTemp->suivant;
        }
        return Concatener_it(liste1,liste2,listTemp);
    }
}

int nb_maximum(cellule_t *liste){
    int occ = 1;
    int max = liste->donnee;
    cellule_t *cellule = liste;
    while (cellule->suivant != NULL) {
        if (max < cellule->suivant->donnee) {
            max = cellule->suivant->donnee;
            occ = 1;
        } else {
            if(max == cellule->suivant->donnee){
                occ += 1;
            }
        }
        cellule = cellule->suivant;
    }
    return occ;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //initialisation
    int val,pos,occ,el,Bool;
    printf("Saisissez la valeur de val\n");
    scanf("%i",&val);
    cellule_t *ma_liste = creerListe(5);
    cellule_t *ma_liste2 = creerListe(5);
    cellule_t *listTemp = ma_liste;
    //appel des fonction
    AfficherListeInt(ma_liste);
    occ = nb_occurences(val,ma_liste);
    printf("il y a %i occurence de %i\n",occ,val);
    Bool = tous_plus_grand(val,ma_liste);
    if(Bool == 1){
        printf("tout les elements de la liste sont plus grand que %i\n",val);
    }else{
        printf("certains elements de la liste sont inférieur que %i",val);
    }
    printf("la plus grande valeur de la liste est: %i\n",Maximum(ma_liste)->donnee);
    printf("Saisissez la valeur de la position dans liste que vous voulez verifier\n");
    scanf("%i",&pos);
    el = Renvoyer_val_element_pos(pos,ma_liste);
    printf("l'element a la position %i est %i\n",pos,el);
    ma_liste = Concatener_it(ma_liste,ma_liste2,listTemp);
    AfficherListeInt(ma_liste);
    printf("il y a %i occurrence de la valeur max\n",nb_maximum(ma_liste));
    return 0;
}
