//
//  Ex33.c
//  TME6
//
//  Created by Bogouslavsky Illia on 13/01/2023.
//

#include <stdio.h>

int est_deb(int i, char chaine1[], char chaine2[]){
    if (chaine1[i] == chaine2[i] && chaine1[i+1] != '\0') {
        i += 1;
        return est_deb(i,chaine1,chaine2);
    } else {
        if (chaine1[i+1] == '\0') {
            return 1;
        } else {
            return 0;
        }
    }
}
int est_incluse(int i, int j, char chaine1[], char chaine2[]){
    if (chaine1[i] == chaine2[j] && chaine1[i+1] != '\0' && chaine2[j+1] != '\0') {
        i += 1;
        j += 1;
        return est_incluse(i,j,chaine1,chaine2);
    } else {
        if (chaine1[i+1] == '\0') {
            return 1;
        } else {
            if (chaine2[j+1] == '\0') {
                return 0;
            } else {
                i = 0;
                j += 1;
                return est_incluse(i,j,chaine1,chaine2);
            }
        }
    }
}
void afficheur_est_deb(int k){
    if (k == 0) {
        printf("La premiere chaine n'est pas le début de la seconde !\n");
    } else {
        printf("La premiere chaine est le début de la seconde !\n");
    }
}
void afficheur_est_incluse(int k){
    if (k == 0) {
        printf("La premiere chaine n'est pas incluse dans la seconde !\n");
    } else {
        printf("La premiere chaine est incluse dans la seconde !\n");
    }
}

int main(){
    char chaine1[] = "alpha";
    char chaine2[] = "alphabet";
    char chaine3[] = "alpaga";
    int k = est_deb(0,chaine1,chaine2);
    afficheur_est_deb(k);
    k = est_deb(0,chaine3,chaine2);
    afficheur_est_deb(k);
    k = est_incluse(0,0,"abe","alphabet");
    afficheur_est_incluse(k);
    k = est_incluse(0,0,"beta","alphabet");
    afficheur_est_incluse(k);
    return 0;
}
