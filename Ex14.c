//
//  Ex14.c
//  TME2
//
//  Created by Bogouslavsky Illia on 08/01/2023.
//
#include <stdio.h>
float prixEntree(int adultes, int enfants){
    float prixAdutle = 22.7;
    float prixEnfant = 10.75;
    float prixFamille = 57.8;
    float prixSR = prixAdutle*adultes+prixEnfant*enfants;
    float prixAR;
    int forfaitFamille = 0;
    while (adultes > 1 && enfants > 1) {
        adultes -= 2;
        enfants -= 3;
        forfaitFamille += 1;
    }
    if (adultes < 0){
        adultes = 0;
        if (enfants < 0) {
            enfants = 0;
            prixAR = forfaitFamille*prixFamille + prixAdutle*adultes+prixEnfant*enfants;
        }else{
            prixAR = forfaitFamille*prixFamille + prixAdutle*adultes+prixEnfant*enfants;
        }
    }else{
        if (enfants < 0) {
            enfants = 0;
            prixAR = forfaitFamille*prixFamille + prixAdutle*adultes+prixEnfant*enfants;
        }else{
            prixAR = forfaitFamille*prixFamille + prixAdutle*adultes+prixEnfant*enfants;
        }
    }if(prixSR <= prixAR){
        printf("Pour %i adultes et %i enfants, le montant a payé est de %.2f\n", adultes, enfants, prixSR);
        return prixSR;
    }else{
        printf("Pour %i adultes et %i enfants, le montant a payé est de %.2f\n", adultes, enfants, prixAR);
        return prixAR;
    }
}
int main(){
    prixEntree(2,1);
    prixEntree(2,2);
    prixEntree(2,3);
    prixEntree(6,3);
    prixEntree(1,3);
    prixEntree(5,7);
    prixEntree(6,8);
    prixEntree(10,0);
    prixEntree(0,4);
}
