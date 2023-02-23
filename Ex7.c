//
//  Ex7.c
//  TME1
//
//  Created by Bogouslavsky Illia on 17/12/2022.
//

#include <stdio.h>

int signeProduit(int a, int b){
    if (a == 0 || b == 0) {
        return 1;
    }
    if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
        return 0;
    }
    return -1;
}

int main(){
    int val;
    val = signeProduit(5,5);
    printf("%i\n", val);
    val = signeProduit(5,0);
    printf("%i\n", val);
    val = signeProduit(5,-5);
    printf("%i\n", val);
    val = signeProduit(-5,-5);
    printf("%i\n", val);
    return 0;
}
