//
//  Ex35.c
//  TME7
//
//  Created by Bogouslavsky Illia on 15/01/2023.
//

#include <stdio.h>
#define NB_PLANETES 8

typedef struct planete planete;
struct planete {
    char nom[10];
    float densite;
    float distanceSoleil;
    int satellites;
};
void affichePlanete(planete systemeSolaire[], int numPlanete){
    printf("planete: %s\n",systemeSolaire[numPlanete].nom);
    printf("densite: %f\n",systemeSolaire[numPlanete].densite);
    printf("distance: %f\n",systemeSolaire[numPlanete].distanceSoleil);
    printf("satellites: %i\n",systemeSolaire[numPlanete].satellites);
}
void afficheToutesPlanetes(planete systemeSolaire[]){
    int i;
    for (i = 0; i < NB_PLANETES; i++) {
        affichePlanete(systemeSolaire, i);
    }
}
void modifieDensite(planete systemeSolaire[]){
    float nouvelleVal;
    int numPlanete;
    printf("Quelle planete voulez-vous selectionner ?\n");
    scanf("%i",&numPlanete);
    printf("Quelle est sa densite ?\n");
    scanf("%f",&nouvelleVal);
    systemeSolaire[numPlanete].densite = nouvelleVal;
    printf("planete: %s\n",systemeSolaire[numPlanete].nom);
    printf("densite: %f\n",systemeSolaire[numPlanete].densite);
}
//CodeRunner
void affichePlaneteCR(planete systemeSolaire[], planete p){
    printf("%s : densite = %.2f, distance soleil = %.1f, nb satellites = %d\n", p.nom, p.densite,p.distanceSoleil,p.satellites);
}
int main(){
    int numPlanete;
    printf("Quelle planete voulez-vous selectionner ?\n");
    scanf("%i",&numPlanete);
    planete systemeSolaire[NB_PLANETES] ={{"Mercure", 5.42, 58, 0},{"Venus", 5.25, 108.2, 0},{"Terre", 5.52,149.6,1},{"Mars",3.94,227.9,2},{"Jupiter",1.314,778.3,16},{"Saturne",0.69,1427,17},{"Uranus",1.19,2869,15},{"Neptune",1.6,4496,2}};
    affichePlanete(systemeSolaire, numPlanete);
    afficheToutesPlanetes(systemeSolaire);
    modifieDensite(systemeSolaire);
    return 0;
}
