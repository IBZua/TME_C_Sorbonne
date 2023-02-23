//
//  Ex21.c
//  TME3
//
//  Created by Bogouslavsky Illia on 10/12/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "val_aleatoire.h"
#define PIERRE 1
#define FEUILLE PIERRE+1
#define CISEAUX FEUILLE+1
#define NBESSAIS 3
#define POINTSGAGNANTS 3

  /* Il sera probablement nÈcessaire de modifier les parametres et valeur de retour des fonctions
    choix_ordinateur, choix_joueur, score et jeu */

  /* Les declarations actuelles permettent de compiler et d'executer le programme */

void affichage_objet(int obj){
  /* hypothËse : obj = PIERRE ou
     obj = FEUILLE ou obj = CISEAUX
   
   affiche le nom de l'objet correspondant ‡ obj */
  
  if (obj == PIERRE){
    printf("PIERRE\n");
  } else {
    if (obj == FEUILLE){
      printf("FEUILLE\n");
    } else {
      printf("CISEAUX\n");
    }
  }
}

void viderBuffer(void){
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int choix_ordinateur(void) {
    /* hypothËse : PIERRE < FEUILLE < CISEAUX
     toutes les valeurs comprises entre PIERRE et CISEAUX sont "valables"
     renvoie une valeur choisie alÈatoirement entre PIERRE et CISEAUX */
  
    return valeur_aleatoire(1,3);
}

int choix_joueur(void) {
    /* hypothËses : PIERRE < FEUILLE < CISEAUX
     renvoie la valeur choisie par le joueur
     vÈrifie qu'elle est comprise entre PIERRE et CISEAUX
     redemande la saisie si ce n'est pas le cas
     
     Si aprËs NBESSAIS le joueur n'a pas saisi de valeur valable,
     cette derniËre est tirÈe au sort */
    printf("saisissez 1, 2 ou 3 pour Pierre, Feuille ou Ciseaux\n");
    char choix[1];
    fgets(choix, 2, stdin);
    int val_joueur = strtol(choix, NULL, 10);
    int essai = 1;
    if (val_joueur != 1 && val_joueur != 2 && val_joueur != 3) {
        while(val_joueur != 1 && val_joueur != 2 && val_joueur != 3 && essai < 3) {
            printf("Votre choix est invalide\nessai n°%i\n", essai);
            essai += 1;
            viderBuffer();
            fgets(choix, 2, stdin);
            val_joueur = strtol(choix, NULL, 10);
            printf("Votre choix est : %i\n", val_joueur);
        }
    }if(essai == 3){
        printf("Votre choix est invalide\nessai n°%i\n", essai);
        return valeur_aleatoire(1,3);
    }
    return val_joueur;
}

void score_PFS(int* val_joueur, int* val_ordinateur, int* score_joueur, int* score_ordinateur){
  /* hypothËses : le coup du joueur et celui de l'ordinateur sont valables
                  (Ègaux ‡ PIERRE, FEUILLE ou CISEAUX)
   augmente de 1 le score du joueur si le coup du joueur est gagnant
   augmente de 1 le score de l'ordinateur si le coup de l'ordinateur est gagnant */
    if (*val_ordinateur == *val_joueur) {
        printf("Égalité!\n");
    } else {
        if (*val_ordinateur == 1 && *val_joueur == 2) {
            printf("Gagné!\n");
            *score_joueur = *score_joueur+1;
        } else {
            if (*val_ordinateur == 2 && *val_joueur == 3) {
                printf("Gagné!\n");
                *score_joueur += 1;
            } else {
                if (*val_ordinateur == 3 && *val_joueur == 1) {
                    printf("Gagné!\n");
                    *score_joueur += 1;
                } else {
                    printf("Perdu!\n");
                    *score_ordinateur += 1;
                }
            }
        }
    }
}

void pierreFeuilleCiseaux(void) {
  /* boucle de jeu, la partie s'arrÍte dËs qu'un des deux joueurs
   atteint POINTSGAGNANTS points */
    int val_joueur;
    int val_ordinateur;
    int score_joueur = 0;
    int score_ordinateur = 0;
    while (score_ordinateur < POINTSGAGNANTS && score_joueur < POINTSGAGNANTS) {
        val_joueur = choix_joueur();
        printf("Votre choix est : ");
        affichage_objet(val_joueur);
        val_ordinateur = choix_ordinateur();
        printf("Le choix de l'ia est : ");
        affichage_objet(val_ordinateur);
        viderBuffer();
        score_PFS(&val_joueur, &val_ordinateur, &score_joueur, &score_ordinateur);
        printf("Le score est de %i - %i\n",score_joueur,score_ordinateur);
    }
    if (score_ordinateur == POINTSGAGNANTS) {
        printf("Vous avez perdu !\n");
    }else{
        printf("Vous avez gagné !\n");
    }
}
int main() {
    srand(time(NULL));
    pierreFeuilleCiseaux();
    return 0;
}
