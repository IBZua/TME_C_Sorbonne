//
//  Ex9.c
//  TME2
//
//  Created by Bogouslavsky Illia on 17/12/2022.
//


#include "cini.h"

void diagonal(int coordonne){
     CINI_open_window(900, 700, "test");
     int i = 0;
     while (i < coordonne) {
         CINI_draw_pixel(i, i, "red");
         i += 1;
     }

     CINI_loop();
}

int main(){
    diagonal(500);
}
