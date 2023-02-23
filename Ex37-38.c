//
//  Ex37.c
//  TME7
//
//  Created by Bogouslavsky Illia on 17/01/2023.
//

#include "cini.h"
#include <SDL2/SDL.h>

#define TAILLE_CASE 20
#define HAUTEUR 22
#define LARGEUR 10
#define VIDE 8 /* n'importe quelle valeur qui n'est pas un indice du tableau des couleurs */

/*-------------   INSERER ICI LES DEFINITIONS DE TYPES   --------------*/
//une case est defini par sa colone et sa ligne
struct une_case {
  int colonne;
  int ligne;
};
//une piece est defini par sa position(ligne et colonne) dans le tableau, 4 cases et un type(OIJ...)
struct piece {
  int pos_ligne, pos_colonne;
  struct une_case la_piece[4];
  int type;
};

/*-------------------   INSERER ICI LES FONCTIONS   -------------------*/
/* Affiche une piece */
//prend en parametre la piece(tetromino) et le tableau de couleur
void afficher_piece(struct piece tetromino, char* couleur) {
    //i l'indice de la case de la piece affichee
    int i;
    //les coordonnees de la case du tetromino à afficher
    int ligne_deb,colonne_deb;

    for (i=0; i < 4; i++) {
        //(la position de la piece + la position la i-ème case de la piece)*la taille d'une case
        ligne_deb = (tetromino.pos_ligne + tetromino.la_piece[i].ligne)*TAILLE_CASE;
        colonne_deb = (tetromino.pos_colonne + tetromino.la_piece[i].colonne)*TAILLE_CASE;
        CINI_fill_rect(colonne_deb,ligne_deb,TAILLE_CASE,TAILLE_CASE,couleur);
    }
}

/* Initialisation d'une piece, elle se trouve initialement en haut et au milieu du plateau */
void initialiser(struct piece* p_tetromino, struct une_case tab[4], int indice) {
    int i;
    //on place la piece au milieu
    p_tetromino->pos_colonne=LARGEUR/2;
    //l'ordonnée à 0
    p_tetromino->pos_ligne=0;
    //on assigne les coordonnes pour chaque case de i
    for (i=0; i < 4; i++) {
        p_tetromino->la_piece[i]=tab[i];
    }
    //on assigne le type de piece en fonction de l'indice passé en parametre
    p_tetromino->type=indice;
}

/* Afficher toutes les pieces, permet de tester si les pieces sont bien declarees */
void afficher_toutes_pieces (char* color[], struct une_case tab_pieces[7][4]){
    int i;
    int lig = 0;
    struct piece tetromino;

    //tant que les 7 pieces n'ont pas été affiche
    for (i=0; i < 7; i++) {
        //on initialise la piece
        initialiser(&tetromino,tab_pieces[i],i);
        //on positionne la piece 3 ligne plus bas
        tetromino.pos_ligne=lig;
        lig = lig + 3;
        //on affiche la piece
        afficher_piece(tetromino,color[tetromino.type]);
  }
}

/* Affiche chaque case du plateau en fonction de la couleur correspondant a son contenu. Toute case vide sera affichee de la couleur de la fenetre */
void afficher_plateau(int plateau[HAUTEUR][LARGEUR], char *color[]){
    int ligne;
    int colonne;
    //on l'affiche
    for(ligne = 0; ligne < HAUTEUR; ligne+=1) {
        for(colonne = 0;colonne < LARGEUR; colonne+=1) {
            if(plateau[ligne][colonne] != VIDE){
                int val = plateau[ligne][colonne];
                printf("\nligne = %i colonne = %i\ncouleur n°%i\n",ligne,colonne,val);
                CINI_fill_rect(colonne*TAILLE_CASE,ligne*TAILLE_CASE,TAILLE_CASE,TAILLE_CASE,color[val]);
            }
            printf(" %i",plateau[ligne][colonne]);
        }
        printf("\n");
    }
}

int descendre(int plateau[HAUTEUR][LARGEUR],struct piece* tetromino){
    //k l'indice de la case de la piece affichee
    int k;
    //les coordonnees de la case du tetromino à afficher
    int ligne_case,colonne_case;
    //on parcourt toutes les cases du tetromino pour verifier s'il peut descendre
    for (k = 0;k < 4;k++) {
        //(la position de la piece + la position la i-ème case de la piece)
        ligne_case = (tetromino->pos_ligne + tetromino->la_piece[k].ligne);
        colonne_case = (tetromino->pos_colonne + tetromino->la_piece[k].colonne);
        //Si le tetromino ne peut pas descendre
        if (ligne_case == HAUTEUR-1 || plateau[ligne_case+1][colonne_case] != VIDE) {
            printf("\n return 1\n");
            for (k = 0;k < 4;k++) {
                //(la position la k-ème case de la piece)
                ligne_case = (tetromino->pos_ligne + tetromino->la_piece[k].ligne);
                colonne_case = (tetromino->pos_colonne + tetromino->la_piece[k].colonne);
                plateau[ligne_case][colonne_case] = tetromino->type;
            }
            return 1;
        }
    }
    //s'il peut desecendre
    tetromino->pos_ligne += 1;
    printf("\n return 0\n");
    return 0;
}
void decaler_gauche(int plateau[HAUTEUR][LARGEUR],struct piece* tetromino){
  //k l'indice de la case de la piece affichee
  int k;
  //les coordonnees de la case du tetromino à afficher
  int ligne_case,colonne_case;
  //on parcourt toutes les cases du tetromino pour verifier s'il peut aller a gauche
  for (k = 0;k < 4;k++) {
      //(la position de la piece + la position la i-ème case de la piece)
      ligne_case = (tetromino->pos_ligne + tetromino->la_piece[k].ligne);
      colonne_case = (tetromino->pos_colonne + tetromino->la_piece[k].colonne);
      //Si le tetromino ne peut pas aller a gauche
      if (colonne_case == 0 || plateau[ligne_case][colonne_case-1] != VIDE) {
          k = 5;
      }
  }
    if (k == 4) {
        tetromino->pos_colonne -= 1;
    }
}
void decaler_droite(int plateau[HAUTEUR][LARGEUR],struct piece* tetromino){
  //k l'indice de la case de la piece affichee
  int k;
  //les coordonnees de la case du tetromino à afficher
  int ligne_case,colonne_case;
  //on parcourt toutes les cases du tetromino pour verifier s'il peut aller a gauche
  for (k = 0;k < 4;k++) {
      //(la position de la piece + la position la i-ème case de la piece)
      ligne_case = (tetromino->pos_ligne + tetromino->la_piece[k].ligne);
      colonne_case = (tetromino->pos_colonne + tetromino->la_piece[k].colonne);
      //Si le tetromino ne peut pas aller a droite
      if (colonne_case+1 == LARGEUR || plateau[ligne_case][colonne_case+1] != VIDE) {
          k = 5;
      }
  }
    if (k == 4) {
        tetromino->pos_colonne += 1;
    }
}
void rotation_gauche(int plateau[HAUTEUR][LARGEUR],struct piece* tetromino){
    //k l'indice de la case de la piece
    int k;
    int ligne_case,colonne_case;
    //une piece de transition pour verifier si la rotation est possible
    struct piece temp;
    temp.type = tetromino->type;
    //on parcourt toutes les cases du tetromino et cree la piece temporaire
    for (k = 0;k < 4;k++) {
        printf("y = %i ",tetromino->la_piece[k].ligne);
        printf("x = %i\n", tetromino->la_piece[k].colonne);
        temp.la_piece[k].ligne =-tetromino->la_piece[k].colonne;
        printf("y' = %i ",temp.la_piece[k].ligne);
        temp.la_piece[k].colonne = tetromino->la_piece[k].ligne;
        printf("x' = %i\n", temp.la_piece[k].colonne);
    }
    //on verifie a l'aide de la piece temporaire si la rotation est possible
    for (k = 0; k < 4; k++) {
        ligne_case = (tetromino->pos_ligne + temp.la_piece[k].ligne);
        colonne_case = (tetromino->pos_colonne + temp.la_piece[k].colonne);
        if (colonne_case > LARGEUR || plateau[ligne_case][colonne_case] != VIDE || ligne_case >= HAUTEUR-1) {
            printf("\nDEPASSEMENT\n");
            k = 5;
        }
    }
    if (k == 4) {
        printf("\nROTATION REUSSI\n");
        for (k = 0;k < 4;k++) {
            tetromino->la_piece[k].ligne = temp.la_piece[k].ligne;
            tetromino->la_piece[k].colonne = temp.la_piece[k].colonne;
        }
    }
}
void rotation_droite(int plateau[HAUTEUR][LARGEUR],struct piece* tetromino){
    //k l'indice de la case de la piece
    int k;
    int ligne_case,colonne_case;
    //une piece de transition pour verifier si la rotation est possible
    struct piece temp;
    temp.type = tetromino->type;
    //on parcourt toutes les cases du tetromino et cree la piece temporaire
    for (k = 0;k < 4;k++) {
        printf("y = %i ",tetromino->la_piece[k].ligne);
        printf("x = %i\n", tetromino->la_piece[k].colonne);
        temp.la_piece[k].ligne = tetromino->la_piece[k].colonne;
        printf("y' = %i ",temp.la_piece[k].ligne);
        temp.la_piece[k].colonne = -tetromino->la_piece[k].ligne;
        printf("x' = %i\n", temp.la_piece[k].colonne);
    }
    //on verifie a l'aide de la piece temporaire si la rotation est possible
    for (k = 0; k < 4; k++) {
        ligne_case = (tetromino->pos_ligne + temp.la_piece[k].ligne);
        colonne_case = (tetromino->pos_colonne + temp.la_piece[k].colonne);
        if (colonne_case > LARGEUR || colonne_case < 0|| plateau[ligne_case][colonne_case] != VIDE || ligne_case >= HAUTEUR-1) {
            printf("\nDEPASSEMENT\n");
            k = 5;
        }
    }
    if(k == 4){
        //on parcourt toutes les cases du tetromino et on modifie les coordonnees
        for (k = 0;k < 4;k++) {
            tetromino->la_piece[k].ligne = temp.la_piece[k].ligne;
            tetromino->la_piece[k].colonne = temp.la_piece[k].colonne;
        }
    }
}
void supprimer_lignes(int plateau[HAUTEUR][LARGEUR]){
    int i = HAUTEUR-1;
    int k;
    int j = 0;
    //on parcourt le tableau depuis le bas
    while(i > 0){
        //on compte le nombre de case remplis sur la ligne
        while (plateau[i][j] != VIDE && j < LARGEUR) {
            j++;
        }
        //si la ligne est remplis
        if(j == LARGEUR){
            printf("ALLIGNEMENT TROUVE\n");
            //On la remplace jusqu'à l'avant derniere ligne par celle du dessus
            while (i > 0) {
                for (j = 0; j < LARGEUR; j++) {
                    plateau[i][j] = plateau[i-1][j];
                    printf(" %i ",plateau[i][j]);
                }
                printf("\n i = %i",i);
                i -= 1;
            }
            //on reprend la recherche au dernier alignement trouvé
            i = HAUTEUR-1;
            j = 0;
        }
        else{
            i -= 1;
        }
    }
}
void hard_drop(int plateau[HAUTEUR][LARGEUR],struct piece* tetromino){
    descendre(plateau, tetromino);
}
int partie_perdue(int plateau[HAUTEUR][LARGEUR]){
    int i;
    for (i = 0; i < LARGEUR; i++) {
        if (plateau[0][i] != VIDE) {
            return 1;
        }
    }
    return 0;
}
/*---------------------------------------------------------------------*/
int main() {
   /*---------------------   les declarations   ---------------------*/
   int indice;    /* l'indice (type) de la piece jouee */
   int touche;   /* identifie la frappe du joueur */

   char* color[] = {"light salmon","fuchsia","lime green","white","yellow","cyan","grey"};
   
   /* (a completer) */
   /*--------------------  les initialisations  ---------------------*/
   srand(time(NULL));
    //on initialise les 7 types de pieces
    struct une_case tab_pieces[7][4] = {
        /*O*/{{0, 0}, {0, 1}, {1, 0}, {1, 1}},
        /*I*/{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
        /*L*/{{0, 0}, {0, 1}, {0, 2}, {1, 2}},
        /*J*/{{1, 0}, {1, 1}, {1, 2}, {0, 2}},
        /*Z*/{{0, 0}, {1, 0}, {1, 1}, {2, 1}},
        /*S*/{{0, 1}, {1, 1}, {1, 0}, {2, 0}},
        /*T*/{{0, 0}, {1, 0}, {2, 0}, {1, 1}} };
    struct piece tetromino;
    //on initialise le plateau de jeu
    int plateau[HAUTEUR][LARGEUR];
    int i = 0;
    int j = 0;
    while (i < HAUTEUR) {
        while (j < LARGEUR){
            plateau[i][j] = VIDE;
            j += 1;
        }
        j = 0;
        i+=1;
    }
    //declaration de la variable de fin
    int fin;
   /* (a completer) */

   /*----------------------  ouverture de la fenÍtre graphique -------*/

   CINI_open_window(LARGEUR*TAILLE_CASE,HAUTEUR*TAILLE_CASE,"black");
   
   /* Affichage de test des pieces */
   /* Instruction a mettre en commentaire pour la suite */
   //afficher_toutes_pieces(color,tab_pieces);
   
   /*----------------------  la boucle de jeu  ----------------------*/

   do {
       afficher_plateau(plateau, color);
       indice = rand()%7;
       initialiser(&tetromino, tab_pieces[indice], indice);
       afficher_piece(tetromino,color[tetromino.type]);
            
      do {
          touche = CINI_loop_until_keyup();
          afficher_piece(tetromino,color[tetromino.type]);             /* "efface" la piece en l'affichant en noir ... */
          CINI_fill_window("black");
          afficher_plateau(plateau, color);
         // printf("val de la case avant =  %i\n",plateau[tetromino.pos_ligne][LARGEUR/2]);
         descendre(plateau,&tetromino);
          //printf("val de la case %i\n",plateau[tetromino.pos_ligne][LARGEUR/2]);

         switch (touche) {
            case SDLK_LEFT:
                 decaler_gauche(plateau,&tetromino);
                 break;
            case SDLK_RIGHT:
                 decaler_droite(plateau,&tetromino);
               break;
            case SDLK_d:
               rotation_gauche(plateau,&tetromino);
               break;
            case SDLK_g:
                 rotation_droite(plateau,&tetromino);
               break;
            case SDLK_SPACE:
               hard_drop(plateau,&tetromino);
               break;
            default:
               break;
         }
          afficher_piece(tetromino,color[tetromino.type]);
          /* ... avant de la reafficher apres modification */
      } while ( (touche != SDLK_DOWN) && (touche != SDLK_ESCAPE) ) ;
            
      /* on supprime les lignes completes si elles existent */
      supprimer_lignes(plateau);
       //on verifie si la partie est fini
       fin = partie_perdue(plateau);

   } while (touche != SDLK_ESCAPE && fin != 1) ;
      
   return 0;
}
