//
//  Ex30.c
//  TME5
//
//  Created by Bogouslavsky Illia on 11/01/2023.
//

#include <stdio.h>
#include "val_aleatoire.h"
#define MIN 4
#define MAX 8

int initTab(int brut[]){
    int taille = valeur_aleatoire(MIN,MAX);
    int i;
    for (i = 0; i < taille-1; i++) {
        brut[i] = valeur_aleatoire(0,1);
    }
    brut[taille-1] = -1;
    return taille;
}
void afficheTab(int tab[], int taille){
    int i;
    for (i = 0; i < taille; i++) {
        printf("%i", tab[i]);
    }
    printf("\n");
}
int compress_tab(int tab_brut[], int tab_compress[]){
    //i l'indice de parcourt du tableau brut
    //j l'indice de parcourt du tableau compresse qui represente aussi sa taille
    //rep le nombre de repetition du i-eme bit
    int i;
    int j = 0;
    int rep = 0;
    //on parcourt le tableau brut
    for (i = 0; tab_brut[i] != -1; i++) {
        //si le i-eme et le i-eme+1 sont identique on les comptes
        if (tab_brut[i] == tab_brut[i+1]) {
            while(tab_brut[i] == tab_brut[i+1]){
                rep += 1;
                i += 1;
            }
            //on ecrit ici le nombre de repetition du bit puis on reset la variable rep
            tab_compress[j] = rep+1;
            j += 1;
            rep = 0;
            //on ecrit le bit en qestion
            tab_compress[j] = tab_brut[i];
            j += 1;
        //si le i-eme et le i-eme+1 ne sont pas identique on ecrit le bit directement
        }else{
            tab_compress[j] = tab_brut[i];
            j += 1;
        }
    }
    //on rajoute -1 le bit de fin
    tab_compress[j] = tab_brut[i];
    j += 1;
    return j;
}
int decompress_tab(int tab_brut[], int tab_compress[]){
    //i l'indice de parcourt du tableau compresse
    //j l'indice de parcourt du tableau brut qui represente aussi sa taille
    //rep l'indice de repetition du i-eme+1 bit
    int i;
    int j = 0;
    int rep = 0;
    //on parcourt le tableau compresse
    for (i = 0; tab_compress[i] != -1; i++) {
        //si la i-eme donnee est > 1, c'est un indice de compression
        if (tab_compress[i] > 1) {
            rep = tab_compress[i];
            //on ecrit le i-eme+1 bit le nombre de repetition
            while(rep > 0){
                tab_brut[j] = tab_compress[i+1];
                j += 1;
                rep -= 1;
            }
            //on passe l'indice de compression et le bit compresse
            i += 1;
        //si la i-eme donnee est <= 1 c'est un bit, on l'ecrit directement
        }else{
            tab_brut[j] = tab_compress[i];
            j += 1;
        }
    }
    tab_brut[j] = tab_compress[i];
    j += 1;
    return j;
}
int comparateur(int tab1[], int tab2[],int taille1,int taille2){
    int i;
    int compression1 = 0;
    int compression2 = 0;
    //on verifie si les 2 tableaux sont compresse
    for (i = 0; i < taille1; i++) {
        if (tab1[i] > 1) {
            compression1 = 1;
        }
    }
    for (i = 0; i < taille2; i++) {
        if (tab2[i] > 1) {
            compression2 = 1;
        }
    }
    //si les 2 ont le meme etat de compression on les compare
    if (compression1 == compression2) {
        for (i = 0; i < taille1; i++) {
            if (tab1[i] != tab2[i]) {
                printf("les tableaux sont differents !\n");
                return 1;
            }
        }
        printf("les tableaux sont identiques !\n");
        return 0;
    }else {
        if (compression1 == 0) {
            int tab_compress[taille1];
            taille1 = compress_tab(tab1,tab_compress);
            for (i = 0; i < taille1; i++) {
                //si un element est different return 1
                if (tab_compress[i] != tab2[i]) {
                    printf("les tableaux sont differents !\n");
                    return 1;
                }
            }
            printf("les tableaux sont identiques !\n");
            return 0;
        } else {
            int tab_compress[taille2];
            taille2 = compress_tab(tab1,tab_compress);
            for (i = 0; i < taille2; i++) {
                //si un element est different return 1
                if (tab_compress[i] != tab2[i]) {
                    printf("les tableaux sont differents !\n");
                    return 1;
                }
            }
            printf("les tableaux sont identiques !\n");
            return 0;
        }
    }
}

//CodeRunner
int compare_tab(int tab1[], int tab2[]) {
    int i;
    for (i = 0; tab1[i] != -1 && tab2[i] != -1; i++) {
        if (tab1[i] != tab2[i]) {
            return -1;
        }
    }
    if(tab1[i] == -1 && tab2[i] != -1){
        return -1;
    }
    if(tab2[i] == -1 && tab1[i] != -1){
        return -1;
    }
    return 0;
}
//CodeRunner
void compress_tabCR(int tab_brut[], int tab_compress[]) {
    //i l'indice de parcourt du tableau brut
    //j l'indice de parcourt du tableau compresse qui represente aussi sa taille
    //rep le nombre de repetition du i-eme bit
    int i;
    int j = 0;
    int rep = 0;
    //on parcourt le tableau brut
    for (i = 0; tab_brut[i] != -1; i++) {
        //si le i-eme et le i-eme+1 sont identique on les comptes
        if (tab_brut[i] == tab_brut[i+1]) {
            while(tab_brut[i] == tab_brut[i+1]){
                rep += 1;
                i += 1;
            }
            //on ecrit ici le nombre de repetition du bit puis on reset la variable rep
            tab_compress[j] = rep+1;
            j += 1;
            rep = 0;
            //on ecrit le bit en qestion
            tab_compress[j] = tab_brut[i];
            j += 1;
        //si le i-eme et le i-eme+1 ne sont pas identique on ecrit le bit directement
        }else{
            tab_compress[j] = tab_brut[i];
            j += 1;
        }
    }
    //on rajoute -1 le bit de fin
    tab_compress[j] = tab_brut[i];
}

int main(){
    int brut[MAX];
    int brut2[MAX];
    int taille = initTab(brut);
    int taille2 = initTab(brut2);
    int tab_compress[taille];
    afficheTab(brut,taille);
    afficheTab(brut2,taille2);
    int tailleK = compress_tab(brut,tab_compress);
    afficheTab(tab_compress,tailleK);
    taille = decompress_tab(brut,tab_compress);
    afficheTab(brut,taille);
    comparateur(tab_compress,tab_compress,tailleK,tailleK);
    comparateur(brut,brut,taille,taille);
    comparateur(brut,brut2,taille,taille2);
    comparateur(brut,tab_compress,taille,tailleK);
    comparateur(brut2,tab_compress,taille2,tailleK);
    comparateur(tab_compress,brut2,tailleK,taille2);
    return 0;
}
