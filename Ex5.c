//
//  Ex5.c
//  TME1
//
//  Created by Bogouslavsky Illia on 17/12/2022.
//
#include <stdio.h>
#include <math.h>
int discriminant(int a, int b, int c){
    int delta = b*b - 4*a*c;
    printf("delta = %i\n", delta);
    return delta;
}

void affiche_racines(int a, int b, int c){
    int delta = discriminant(a, b, c);
    if (delta > 0) {
        float racine1 = (-b + sqrt(delta))/(2*a);
        float racine2 = (-b - sqrt(delta))/(2*a);
        printf("Le polynome possède deux racines, la racine: %f et la racine %f\n", racine1, racine2);
    } else {
        if (delta == 0) {
            float res = (-b + sqrt(delta))/(2*a);
            printf("Le polynome possède une racine double %f\n", res);
        } else {
            printf("Le polynome n'a pas de racines réels\n");
        }
    }
}
int main(){
    affiche_racines(4,4,1);
    affiche_racines(4,6,1);
    affiche_racines(-7,-5,-1);
    return 0;
}
