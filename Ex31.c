//
//  Ex31.c
//  TME5
//
//  Created by Bogouslavsky Illia on 18/01/2023.
//

#include "val_aleatoire.h"
#include "cini.h"

#define N       4
#define COEFX  50    /* coefficients d'echelle */
#define COEFY  38
#define DX    250    /* position dans la fenetre */
#define DY    420

/* fonction calcule_bornes_sup */
void calcule_bornes_sup(int pourcentage[], int taille){
    /* A COMPLETER */
    int i;
    int val = 0;
    for (i = 0; i < taille; i++) {
        if (i == 0) {
            pourcentage[i] = pourcentage[i] - 1;
        }else{
            pourcentage[i] = val + pourcentage[i];
        }
        val = pourcentage[i];
        printf("pourcentage = %i   i = %i\n",pourcentage[i],i);
    }
}
/* fonction tire_non_equi */
      /* A COMPLETER */
int tire_non_equi(int tab_bornes[], int taille){
    //on genere une valeur aleatoire
    int val_tire = valeur_aleatoire(0,99);
    int i;
    //on partour le tableau de bornes
    for (i = 0; i < taille;  i++) {
        //si la valeur tire est <= a la borne du tableau on renvoie i
        if(val_tire <= tab_bornes[i]){
            printf("val_tire = %i   i = %i\n",val_tire,i);
            return i;
        }
    }
    printf("val_tire = %i   i = %i\n",val_tire,i);
    return i;
}

int main() {
    //Test Q1,2,3
    /*
    int i,val;
    int tab_bornes[4] = {17,28,50,5};
    int tab_stock[4] = {0};
    calcule_bornes_sup(tab_bornes,4);
    tire_non_equi(tab_bornes,4);
    for (i = 0; i < 10000; i++) {
        val = tire_non_equi(tab_bornes,4);
        switch (val) {
            case 1:
                tab_stock[1] += 1;
                break;
            case 2:
                tab_stock[2] += 1;
                break;
            case 3:
                tab_stock[3] += 1;
                break;
                
            default:
                tab_stock[0] += 1;
                break;
        }
    }
    printf("[%i],[%i],[%i],[%i]\n",tab_stock[0],tab_stock[1],tab_stock[2],tab_stock[3]);*/
    //
    float tab_A[N] = {0.5,  0.2, -0.15,  0.85};    /* les coefficients a_i */
    float tab_B[N] = {0,   -0.26, 0.28,  0.04};    /* les coefficients b_i */
    float tab_C[N] = {0,    0.23, 0.26, -0.04};    /* les coefficients c_i */
    float tab_D[N] = {0.16, 0.22, 0.24,  0.85};    /* les coefficients d_i */
    float tab_E[N] = {0,    0,    0,     0};       /* les coefficients e_i */
    float tab_F[N] = {0,    1.6,  0.44,  1.6};     /* les coefficients f_i */
   
    int tab_P[N] = {1, 7, 7, 85};  /* pourcentages de chaque transformation */
   
    char *couleurs[N] = {"lime green", "fuchsia", "yellow", "turquoise"};

    /* Definition de variables supplementaires si necessaire */
    //les coordonnes initiales
    float x = 0;
    float y = 0;
    //noT le numéro de la transformation
    int noT;
    /* Calcul des bornes des intervalles */
   
         /* A COMPLETER */
    calcule_bornes_sup(tab_P, N);
    CINI_open_window(500, 500, "feuille");
    do {
        /* Choix du numero de la transformation a appliquer */
        /* A COMPLETER */
        //on assigne le numéro de la transformation
        noT = tire_non_equi(tab_P, N);
        
        /* Calcul du point a tracer (coordonnees x et y) */
        /* A COMPLETER */
        CINI_draw_pixel(DX + x*COEFX, DY - y*COEFY, couleurs[noT]);
        x = x*tab_A[noT] + y*tab_B[noT] + tab_E[noT];
        y = x*tab_C[noT] + y*tab_D[noT] + tab_F[noT];
        
    } while (! CINI_key_down());

    return 0;
}

