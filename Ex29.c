//
//  Ex29.c
//  TME5
//
//  Created by Bogouslavsky Illia on 11/01/2023.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//Affiche uniquement les lettres des chaines de caractere
void afficheLettres(char ch[], char listLettre[]){
    int i,j;
    for (i = 0; ch[i] != '\0'; i++) {
        for (j = 0; listLettre[j] != '\0'; j++) {
            if (listLettre[j] == ch[i]) {
                printf("%c", ch[i]);
            }
        }
    }
    printf("\n");
}
//Renvoie une chaine de caractere filtre
char *filtreLettres(char ch[], char listLettre[]){
    int i,j;
    int k = 0;
    char *chaineFiltre = malloc(strlen(ch)+1*sizeof(char));
    for (i = 0; ch[i] != '\0'; i++) {
        for (j = 0; listLettre[j] != '\0'; j++) {
            if (listLettre[j] == ch[i]) {
                chaineFiltre [k] = ch[i];
                k += 1;
            }
        }
    }
    printf("%s\n",chaineFiltre);
    return chaineFiltre;
}
//Filtre directement la chaine de caractere
void filtreLettresDirect(char ch[], char listLettre[]){
    int i,j,k;
    int lettreTrouve = 0;
    int dernierTrouve = 0;
    //On parcourt la chaine
    for (i = 0; ch[i] != '\0'; i++) {
        //On compare chaque caaractere de la chaine avec liste de lettre
        for (j = 0; listLettre[j] != '\0'; j++) {
            //Si on trouve une lettre, on stock sa position dans derniertrouve
            if (listLettre[j] == ch[i]) {
                lettreTrouve = 1;
                dernierTrouve = i;
                j = 53;
            }
        }
        //Si la lettre n'a pas ete trouve on decale "i" et toute la chaine de 1 caractere vers la gauche
        if (lettreTrouve == 0) {
            for (k = i; ch[k] != '\0'; k++) {
                ch[k] = ch[k+1];
            }
            i -= 1;
        }
        lettreTrouve = 0;
    }
    //On calcule ici la position de du marqueur de fin de chaine
    ch[i-(i-dernierTrouve)+1] = '\0';
    printf("%s\n",ch);
}

int main(){
    char listLettre[54] ="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char ch[] = "algorithme de compression%¨";
    afficheLettres(ch, listLettre);
    filtreLettres(ch, listLettre);
    filtreLettresDirect(ch, listLettre);
    return 0;
}
