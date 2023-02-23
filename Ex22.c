//
//  Ex22.c
//  TME3
//
//  Created by Bogouslavsky Illia on 14/12/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NBTOURS 10
#define NBLANCERS 2
#define NBQUILLES 10

/* Il sera probablement nÈcessaire de modifier les parametres et valeur de retour des fonctions
  lancer, lancer_aleatoire, score et jeu */

/* Les declarations actuelles permettent de compiler et d'executer le programme */

int lancer(int *nb_quilles_debout){
    printf("Il reste %i quilles debout\nCombien de quilles avez vous renversez ?\n",*nb_quilles_debout);
    int nb_quilles_renverse;
    scanf("%i",&nb_quilles_renverse);
    return nb_quilles_renverse;
}

int lancer_aleatoire(void){
    return 0;
}
/*Mets à jour le score apres chaque lance, scoreL le score du lance, scoreT le score total ,scoreP le score du lance precedent, spare et strike les variable de spare et strike*/
void score(int *tourB, int *scoreTPP, int *scoreTP, int *scoreT, int* scoreL, int *scoreP, int *spareP, int *strikeP){
    if (*strikeP > 0) {
        //*scoreTPP += *scoreTP;
        printf("score tour-2 = %i\n",*scoreTPP);
        //*scoreTP += *scoreL;
        printf("score tour-1 = %i\n",*scoreTP);
        *scoreT += *scoreL + *scoreTP + *scoreTPP;
        printf("score temporaire = %i\n",*scoreT);
        *strikeP -= 1;
    } else {
        //si on a un spare
        if (*spareP == 1 && *tourB == 0) {
            //on ajoute au score temporaire le score du lancer
            *scoreTP += *scoreL;
            printf("score tour-1 = %i\n",*scoreTP);
            //le score total est celui du score temporaire + lance
            *scoreT = *scoreL + *scoreTP;
            printf("score temporaire = %i\n",*scoreT);
            //le spare a ete effectue
            *spareP -= 1;
        }
        else{
            *scoreT = *scoreT + *scoreL;
            if(*scoreT == NBQUILLES){
                *spareP = 1;
            }
        }
    }
}

void tour(int *tourB, int *scoreTPP, int *scoreTP, int *scoreT, int *strike, int *spare){
    int nb_quilles_debout = 10;
    int scoreP;
    int scoreL = lancer(&nb_quilles_debout);
    //si tour bonue
    if (*tourB == 1) {
        //si strike
        if (*strike > 0) {
            *scoreTP = scoreL;
            *scoreTPP = 0;
            score(tourB, scoreTPP, scoreTP, scoreT, &scoreL, &scoreP, spare, strike);
        }else{
            //si spare
            score(tourB, scoreTPP, scoreTP, scoreT, &scoreL, &scoreP, spare, strike);
        }
    }else{
        //on maj le score
        score(tourB, scoreTPP, scoreTP, scoreT, &scoreL, &scoreP, spare, strike);
        if (scoreL == 10) {
            *strike += 2;
            *scoreTP = scoreL;
            *scoreTPP = *scoreTP;
        } else {
            //on stock l'ancien lance
            scoreP = scoreL;
            //on maj le nombre de quilles
            nb_quilles_debout = 10-scoreL;
            //nouveau lance
            scoreL = lancer(&nb_quilles_debout);
            //on maj le score
            score(tourB, scoreTPP, scoreTP, scoreT, &scoreL, &scoreP, spare, strike);
            //si spare
            if (scoreL + scoreP == 10) {
                //on active la variable
                *spare = 1;
                //on stock le score temporaire
                *scoreTP = *scoreT;
            }
        }
    }
}

int jeu(void) {
    //tour numero
    int tourN = 1;
    //tour bonus 1 si oui 0 si non
    int tourB = 0;
    //score total
    int scoreT = 0;
    //score tour precedent
    int scoreTP = 0;
    int scoreTPP = 0;
    int strike = 0;
    int spare = 0;
    while (tourN <= NBTOURS) {
        printf("tour %i\n",tourN);
        tour(&tourB,&scoreTPP,&scoreTP,&scoreT,&strike,&spare);
        printf("score tour-1 = %i\n",scoreTP);
        printf("tour %i \nscore = %i\n",tourN, scoreT);
        tourN += 1;
        //printf("tourN += 1 -> %i\n",tourN);
    }
    if (strike > 0) {
        printf("tour bonus\n");
        tourB = 1;
        tour(&tourB,&scoreTPP,&scoreTP,&scoreT,&strike,&spare);
        printf("score final == %i\n",scoreT);
        return scoreT;
    } else {
        //si spare lance bonus
        if (spare == 1) {
            tourB = 1;
            tour(&tourB,&scoreTPP,&scoreTP,&scoreT,&strike,&spare);
            printf("score final == %i\n",scoreT);
            return scoreT;
        } else {
            return scoreT;
        }
    }
    return 0;
}
int main() {
    srand(time(NULL));
    jeu();
    return 0;
}
