//
//  Ex2.c
//  TME3
//
//  Created by Bogouslavsky Illia on 09/12/2022.
//

#include "val_aleatoire.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
