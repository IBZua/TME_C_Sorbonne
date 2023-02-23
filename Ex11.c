//
//  Ex11.c
//  TME2
//
//  Created by Bogouslavsky Illia on 08/01/2023.
//
#include <stdio.h>
int jours(int contamine, int populationTotale, float tauxInfection){
    int i = 0;
    float infecte = 1;
    float tauxInfecte = infecte/populationTotale*100;
    while (tauxInfecte < tauxInfection) {
        infecte += infecte*contamine;
        tauxInfecte = infecte/populationTotale*100;
        i += 1;
    }
    printf("Le taux d'infecté est atteint au bout de %i jours\n",i);
    return i;
}

float pourcentage(int contamine, int populationTotale, int jours){
    int i = 0;
    float infecte = 1;
    float tauxInfecte = infecte/populationTotale*100;
    while (i < jours) {
        infecte += infecte*contamine;
        tauxInfecte = infecte/populationTotale*100;
        i += 1;
    }
    if(tauxInfecte > 100){
        tauxInfecte = 100;
    }
    printf("Le taux d'infecté au bout de %i jours est de %.2f\n",i,tauxInfecte);
    return tauxInfecte;
}

int main(int argc, const char * argv[]) {
    //Ex11
    jours(5,10000,10);
    jours(5,10000,25);
    jours(5,10000,50);
    jours(5,10000,100);
    pourcentage(5,10000,2);
    pourcentage(5,10000,3);
    pourcentage(5,10000,4);
    pourcentage(5,10000,5);
    pourcentage(5,10000,6);
}
