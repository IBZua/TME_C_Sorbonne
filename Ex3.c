//
//  Ex3.c
//  TME1
//
//  Created by Bogouslavsky Illia on 17/12/2022.
//

#include <stdio.h>
int alternative(int n1, int n2, int n3) {
    int res ;
    if (n1 > 8) {
        res = 3;
    } else {
        if (n3 == 20) {
            res = 2;
        } else {
            if ((n2 >= 10) && (n3 >= 10)) {
                res = 1;
            } else {
                res = 0;
            }
        }
    }
    printf("%i\n", res);
    return res;
}
int main(){
    alternative(9,0,0);
    alternative(7,10,20);
    alternative(7,10,10);
    alternative(5,5,20);
    alternative(5,10,5);
    return 0;
}
