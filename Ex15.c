//
//  Ex15.c
//  TME2
//
//  Created by Bogouslavsky Illia on 18/01/2023.
//

#include <stdio.h>
#include "cini.h"
void triangles(int largeur, int hauteur, int epsilon){
    int xa = 0;
    int ya = hauteur;
    int xb = largeur;
    int yb = hauteur;
    int xc = largeur/2;
    int yc = 0;
    int xap;
    int yap;
    int xbp;
    int ybp;
    int xcp;
    int ycp;
    CINI_open_window(largeur, hauteur, "test");
    CINI_fill_window("white");
    CINI_draw_line(xa, ya, xb, yb, "green");
    CINI_draw_line(xa, ya, xc, yc, "red");
    CINI_draw_line(xc, yc, xb, yb, "black");
    int distance_a_b = (xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
    while (distance_a_b > epsilon){
        xap = (xb+9*xa)/10;
        yap = (yb+9*ya)/10;
        xbp = (xc+9*xb)/10;
        ybp = (yc+9*yb)/10;
        xcp = (xa+9*xc)/10;
        ycp = (ya+9*yc)/10;
        CINI_loop_until_keyup();
        CINI_draw_line(xap, yap, xbp, ybp, "green");
        CINI_draw_line(xap, yap, xcp, ycp, "red");
        CINI_draw_line(xcp, ycp, xbp, ybp, "black");
        xa = xap;
        ya = yap;
        xb = xbp;
        yb = ybp;
        xc = xcp;
        yc = ycp;
        distance_a_b = (xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
    }
    CINI_loop();
}
int main(int argc, const char * argv[]) {
    int hauteur;
    int largeur;
    int epsilon;
    printf("Saisissez hauteur\n");
    scanf("%i",&hauteur);
    printf("Saisissez largeur\n");
    scanf("%i",&largeur);
    printf("Saisissez epsilon\n");
    scanf("%i",&epsilon);
    triangles(largeur,hauteur,epsilon);
    return 0;
}
