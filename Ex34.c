//
//  Ex34.c
//  TME6
//
//  Created by Bogouslavsky Illia on 13/01/2023.
//
#include <stdio.h>
#include "val_aleatoire.h"
#define N 3
#define JOUEUR(tour,joueur) if (tour%2 == 0) \
                            joueur = 0;\
                            else \
                            joueur = 1;\
                            
#define JOUER(plateau,joueur,tour) printf("Joueur %i\n",joueur+1);\
                                jouer(plateau,joueur); \
                                afficher(plateau); \
                                tour += 1; \
                                i = partie_gagnee(plateau); \

void init(char plateau[][N]){
    int i,j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            plateau[i][j] = '_';
        }
    }
}
void afficher(char plateau[][N]){
    int i,j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf(" %c ",plateau[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int choisir_menu12q(void){
    int choix;
    printf("Séléctrionnez le mode de jeu\n 1. Partie à 2 joueurs\n 2. Partie contre l’ordinateur\n 3. quitter\n");
    scanf("%i",&choix);
    switch (choix) {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
        default:
            printf("Saisie incorrect !\n");
            return choisir_menu12q();
            break;
    }
}
void jouer (char plateau[N][N], int joueur){
    int i,j;
    printf("Où voulez vous placer votre pion ?\n(Saisissez les coordonnes colonne ligne)\n");
    scanf("%i %i",&i,&j);
    i -= 1;
    j -= 1;
    if (plateau[i][j] == '_') {
        if (joueur == 0) {
            plateau[i][j] = 'X';
        }else{
            plateau[i][j] = 'O';
        }
    } else {
        printf("La case est déjà occupé !\n");
        return jouer(plateau,joueur);
    }
}
void jouerOrdinateur(char plateau[N][N]){
    int i = valeur_aleatoire(0,2);
    int j = valeur_aleatoire(0,2);
    if (plateau[i][j] == '_') {
        plateau[i][j] = 'O';
    } else {
        return jouerOrdinateur(plateau);
    }
}
int partie_gagnee(char plateau[N][N]){
    int ligne = 0;
    int col = 0;
    int aligne = 0;
    //on parcourt une colonne
    while (ligne < 2) {
        switch (plateau[ligne][col]) {
            case '_':
                ligne = 2;
                break;
            case 'X':
                if (plateau[ligne][col] == plateau[ligne+1][col]) {
                    aligne = 1;
                    ligne += 1;
                } else {
                    aligne = 0;
                    ligne = 2;
                }
                break;
            case 'O':
                if (plateau[ligne][col] == plateau[ligne+1][col]) {
                    aligne = 1;
                    ligne += 1;
                } else {
                    aligne = 0;
                    ligne = 2;
                }
                break;
            default:
                break;
        }
    }
    //Si alignement trouvé return 1
    if (aligne == 1) {
        return aligne;
    } else {
        ligne = 0;
    }
    //Sinon on repart à la ligne 0
    //on parcourt une ligne
    while (col < 2) {
        switch (plateau[ligne][col]) {
            case '_':
                col = 2;
                break;
            case 'X':
                if (plateau[ligne][col] == plateau[ligne][col+1]) {
                    aligne = 1;
                    col += 1;
                } else {
                    aligne = 0;
                    col = 2;
                }
                break;
            case 'O':
                if (plateau[ligne][col] == plateau[ligne][col+1]) {
                    aligne = 1;
                    col += 1;
                } else {
                    aligne = 0;
                    col = 2;
                }
                break;
            default:
                break;
        }
    }
    if (aligne == 1) {
        return aligne;
    } else {
        ligne = 0;
        col = 0;
    }
    //on parcourt une diagonal de haut en bas
    while (col < 2 && ligne < 2) {
        switch (plateau[ligne][col]) {
            case '_':
                col = 2;
                break;
            case 'X':
                if (plateau[ligne][col] == plateau[ligne+1][col+1]) {
                    aligne = 1;
                    col += 1;
                    ligne += 1;
                } else {
                    aligne = 0;
                    col = 2;
                }
                break;
            case 'O':
                if (plateau[ligne][col] == plateau[ligne+1][col+1]) {
                    aligne = 1;
                    col += 1;
                    ligne += 1;
                } else {
                    aligne = 0;
                    col = 2;
                }
                break;
            default:
                break;
        }
    }
    if (aligne == 1) {
        return aligne;
    } else {
        ligne = 2;
        col = 0;
    }
    //on parcourt une diagonal de bas en haut
    while (col < 2 && ligne > 0) {
        switch (plateau[ligne][col]) {
            case '_':
                col = 2;
                break;
            case 'X':
                if (plateau[ligne][col] == plateau[ligne-1][col+1]) {
                    aligne = 1;
                    col += 1;
                    ligne -= 1;
                } else {
                    aligne = 0;
                    col = 2;
                }
                break;
            case 'O':
                if (plateau[ligne][col] == plateau[ligne-1][col+1]) {
                    aligne = 1;
                    col += 1;
                    ligne -= 1;
                } else {
                    aligne = 0;
                    col = 2;
                }
                break;
            default:
                break;
        }
    }
    return aligne;
}
void jouer_a(char plateau[N][N], int nb_joueurs){
    int i = partie_gagnee(plateau);
    int tour = 0;
    int joueur;
    switch (nb_joueurs) {
        case 1:
            while (i != 1 && tour < 9) {
                JOUEUR(tour,joueur);
                JOUER(plateau,joueur,tour);
            }
            break;
        case 2:
            printf("vous jouer contre l'ia\n");
            while (i != 1 && tour < 9) {
                JOUER(plateau,0,tour);
                printf("IA 1\n");
                jouerOrdinateur(plateau);
                afficher(plateau);
                i = partie_gagnee(plateau);
                tour += 1;
            }
            break;
        case 3:
            i = -1;
            break;
            
        default:
            break;
    }
    switch (i) {
        case 1:
            if (tour%2 - 1 == 0) {
                printf("joueur 1 a gagné\n");
            }else{
                printf("joueur 2 a gagné\n");
            }
            break;
        case -1:
            printf("fin de programme\n");
            
        default:
            printf("match nul\n");
            break;
    }
}
int main(){
    char plateau[N][N];
    init(plateau);
    afficher(plateau);
    int nb_joueurs = choisir_menu12q();
    jouer_a(plateau,nb_joueurs);
    return 0;
}
