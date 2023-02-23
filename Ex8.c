//
//  Ex8.c
//  TME1
//
//  Created by Bogouslavsky Illia on 17/12/2022.
//

#include <stdio.h>
float prixEntree(int adultes, int enfants){
    float prixAdutle = 22.7;
    float prixEnfant = 10.75;
    float prixFamille = 57.8;
    //PrixSR le prix Sans Reduction (tarif famille)
    float prixSR = prixAdutle*adultes+prixEnfant*enfants;
    adultes -= 2;
    enfants -= 3;
    //On declare la variable PrixAR qui contiendra le prix apres reduction
    float prixAR;
    if (adultes < 0){
        adultes = 0;
        if (enfants < 0) {
            enfants = 0;
            prixAR = prixFamille + prixAdutle*adultes+prixEnfant*enfants;
        }else{
            prixAR = prixFamille + prixAdutle*adultes+prixEnfant*enfants;
        }
    }else{
        if (enfants < 0) {
            enfants = 0;
            prixAR = prixFamille + prixAdutle*adultes+prixEnfant*enfants;
        }else{
            prixAR = prixFamille + prixAdutle*adultes+prixEnfant*enfants;
        }
    }
    //On compare le prix trouve avec et sans tarif famille et on renvoie le plus petit
    if(prixSR <= prixAR){
        printf("le montant a payé est de %.2f\n", prixSR);
        return prixSR;
    }else{
        printf("le montant a payé est de %.2f\n", prixAR);
        return prixAR;
    }
}
int main(){
    prixEntree(2,3);
    prixEntree(2,2);
    prixEntree(2,1);
    prixEntree(1,3);
}
