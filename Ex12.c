//
//  Ex12.c
//  TME2
//
//  Created by Bogouslavsky Illia on 08/01/2023.
//

#include "stdio.h"
#include <cini.h>

int position(int a, int b, int x, int y){
    int pos;
    if (a*x+b-y == 0) {
        pos = 0;
    } else {
        if (a*x+b-y < 0) {
            pos = -1;
        } else {
            pos = 1;
        }
    }
    return pos;
}

void affiche(int pos, int a, int b, int x, int y, int hauteur, int largeur){
    CINI_open_window(largeur, hauteur, "graph");
    int i = 0;
    while (i < hauteur && i < largeur) {
        CINI_draw_pixel(i, a*i+b, "white");
        i += 1;
    }
    switch (pos) {
        case 1:
            CINI_draw_pixel(x, y, "red");
            break;
        case 0:
            CINI_draw_pixel(x, y, "black");
            break;
        case -1:
            CINI_draw_pixel(x, y, "blue");
            break;
            
        default:
            break;
    }
    CINI_loop();
}
 int main(){
     //Ex12
     int a, b, x, y, hauteur, largeur;
     printf("Saisissez a\n");
     scanf("%i",&a);
     printf("Saisissez b\n");
     scanf("%i",&b);
     printf("Saisissez x\n");
     scanf("%i",&x);
     printf("Saisissez y\n");
     scanf("%i",&y);
     printf("Saisissez hauteur\n");
     scanf("%i",&hauteur);
     printf("Saisissez largeur\n");
     scanf("%i",&largeur);
     int pos = position(a,b,x,y);
     affiche(pos, a, b, x, y, hauteur, largeur);
     return 0;
 }

