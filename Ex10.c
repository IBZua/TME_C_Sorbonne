//
//  Ex10.c
//  TME2
//
//  Created by Bogouslavsky Illia on 17/01/2023.
//

#include <stdio.h>
#include "cini.h"

void carre(int longueur, int x, int y){
    CINI_open_window(1000, 800, "Carre");
    int i;
    for (i = 0; i < longueur; i++) {
        CINI_draw_pixel(x, i+y, "blue");
        CINI_draw_pixel(i+x, y, "red");
        CINI_draw_pixel(longueur+x, i+y, "green");
        CINI_draw_pixel(i+x, longueur+y, "yellow");
    }
    CINI_loop();
}

void carre_remontant(int longueur, int x, int y){
    CINI_open_window(1000, 800, "Carre");
    int i;
    while (x > 0 && y > 0) {
        for (i = 0; i < longueur; i++) {
            CINI_draw_pixel(x, i+y, "blue");
            CINI_draw_pixel(i+x, y, "red");
            CINI_draw_pixel(longueur+x, i+y, "green");
            CINI_draw_pixel(i+x, longueur+y, "yellow");
        }
        x -= 5;
        y -= 5;
    }
    CINI_loop();
}
int main(){
    int longueur,x,y;
    printf("Saisissez la longueur d'un coté du carré\n");
    scanf("%i",&longueur);
    printf("Saisissez les coordonnées x et y du carré\n");
    scanf("%i",&x);
    scanf("%i",&y);
    carre_remontant(longueur, x, y);
}
