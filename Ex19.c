//
//  Ex4.c
//  TME3
//
//  Created by Bogouslavsky Illia on 09/12/2022.
//
#include <stdio.h>

/* min_max met à jour ces deux valeurs en fonction de celle de l'entier */
void min_max(int entier, int* min, int* max){
    if (entier < *min) {
        *min = entier;
    }
    if (entier > *max) {
        *max = entier;
    }
}
/*stats calcule le plus grand, le plus petit et la moyenne de quatre entiers en ne prenant en compte les valeurs que tant qu’elles sont strictement positives.
 Si le premier entier est négatif ou nul, le minimum, le maximum et la moyenne seront égaux à -1*/
void stats(int V1, int V2, int V3, int V4, int* min, int* max, float* moyenne){
    if (V1 > 0) {
        *min = V1;
        *max = V1;
        if (V2 > 0) {
            min_max(V2, min, max);
            if (V3 > 0) {
                min_max(V3, min, max);
                if (V4 > 0) {
                    min_max(V4, min, max);
                    *moyenne = (V1+V2+V3+V4)/4.0;
                } else {
                    *moyenne = (V1+V2+V3)/3.0;
                }
            } else {
                *moyenne = (V1+V2)/2.0;
            }
        } else {
            *moyenne = V1;
        }
    } else{
        *min = -1;
        *max = -1;
        *moyenne = -1;
    }
}

int main(){
    int min;
    int max;
    float moyenne;
    //min_max(3,&min,&max);
    stats(2,7,5,9,&min,&max,&moyenne);
    printf("\nmoyenne = %f min = %i max = %i\n", moyenne, min, max);
    stats(2,7,-5,-9,&min,&max,&moyenne);
    printf("\nmoyenne = %f min = %i max = %i\n", moyenne, min, max);
    stats(2,7,-5,9,&min,&max,&moyenne);
    printf("\nmoyenne = %f min = %i max = %i\n", moyenne, min, max);
    stats(2,-7,-5,9,&min,&max,&moyenne);
    printf("\nmoyenne = %f min = %i max = %i\n", moyenne, min, max);
    stats(-2,7,5,9,&min,&max,&moyenne);
    printf("\nmoyenne = %f min = %i max = %i\n", moyenne, min, max);
    return 0;
}
