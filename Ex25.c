//
//  Ex25.c
//  TME4
//
//  Created by Bogouslavsky Illia on 26/01/2023.
//

#include <stdio.h>

void placeElt(int tab[], int i){
    int j;
    int val = tab[i];
    for (j = i; tab[j] < tab[j-1]; j--) {
        tab[j] = tab[j-1];
        tab[j-1] = val;
        printf("tab[%i] = %i\n",j,tab[j]);
    }
}

int main(int argc, const char * argv[]) {
    int tab[4] = {3,4,6,1};
    //int nbEl = 4;
    placeElt(tab, 3);
    return 0;
}
