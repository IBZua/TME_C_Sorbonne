//
//  Ex27.c
//  TME5
//
//  Created by Bogouslavsky Illia on 09/01/2023.
//

#include <stdio.h>
#include <string.h>
int compteMots(char ch1[]){
    int i;
    int nbMots;
    if (ch1[0] != ' '){
        nbMots = 1;
    }else{
        nbMots = 0;
    }
    for (i = 0; ch1[i] != '\0'; i++) {
        if (ch1[i] == ' ') {
            while (ch1[i] == ' ') {
                i++;
            }
            nbMots += 1;
        }
    }
    printf("il y a %i mots\n", nbMots);
    return nbMots;
}

int main(){
    char chaine[] = "un deux trois";
    compteMots(chaine);
    return 0;
}
