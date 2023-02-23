//
//  Ex2.c
//  TME3
//
//  Created by Bogouslavsky Illia on 09/12/2022.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NB_VALEURS 50
#define VMIN -20
#define VMAX 20
//générateur de nombre aléatoire compris entre 2 bornes
int valeur_aleatoire(int min, int max){
    int val = rand();
    if (val < min || val > max){
        while (val < min || val > max) {
            val = rand() % (max - min + 1) + min;
        }
    }
    printf("%i\n", val);
    return val;
}
//compteur de nombre en fonction de leur signe
void pos_neg_zero(int val, int *pos, int *neg, int *zero){
    if (val > 0) {
        *pos += 1;
    }else if(val == 0){
        *zero += 1;
    } else {
        *neg += 1;
    }
    printf("%i positif, %i négatif, %i zero\n", *pos, *neg, *zero);
}

int main(){
    /* initialisation du générateur de nombres aléatoires */
    //srand(time(NULL));
    int val;
    int i = 0;
    int pos = 0;
    int neg = 0;
    int zero = 0;
    while (i < NB_VALEURS) {
        val = valeur_aleatoire(VMIN, VMAX);
        pos_neg_zero(val, &pos, &neg, &zero);
        i++;
    }
    return 0;
}

