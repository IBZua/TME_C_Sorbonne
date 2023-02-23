//
//  Ex1.c
//  TME4
//
//  Created by Bogouslavsky Illia on 09/12/2022.
//

#include "val_aleatoire.h"
#include <stdio.h>
void init_temp(float tab[]){
    int i;
    for (i = 1; i < 31; i++){
        tab[i] = valeur_aleatoire(-200, 300);
        printf("valeur %i = %f\n",i, tab[i]);
    }
}

float moy_temp(float tab[]){
    float sum = 0;
    int i;
    for (i = 1; i < 31; i++) {
        sum += tab[i];
    }
    float res = sum/30;
    printf("la temperature moyenne est de %.2f\n", res);
    return res;
}

float strict_neg(float tab[]){
    float sum = 0;
    int i;
    int j = 0;
    for (i = 1; i < 31; i++) {
        if (tab[i] < 0) {
            sum += tab[i];
            j += 1;
        }
    }
    float res = sum/j;
    if (j == 0) {
        printf("Aucune temperature au-dessous de zero\n");
        return 0;
    } else {
        printf("la moyenne des temperature negative est de %.2f\n", res);
        return res;
    }
}
int main(){
    float tab[31];
    init_temp(tab);
    moy_temp(tab);
    strict_neg(tab);
    return 0;
}
