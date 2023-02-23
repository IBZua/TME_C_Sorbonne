//
//  Ex3.c
//  TME3
//
//  Created by Bogouslavsky Illia on 09/12/2022.
//
#include <stdio.h>

void echange(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}
void tri(int* a, int* b){
    if (*a >= *b) {
        echange(a, b);
    }
}
void tri_3(int* a, int* b, int* c){
    tri(a,c);
    tri(b,c);
    tri(a,b);
    printf("après tri3 a = %i  b = %i c = %i\n\n", *a, *b, *c);
}

int main(){
    int a = 112;
    int b = 22;
    int c = 3;
    //echange(&a,&b);
    //tri(&a,&b);
    tri_3(&a,&b,&c);
    tri_3(&b,&c, &a);
    tri_3(&c,&a,&b);
    tri_3(&c,&b,&a);
    return 0;
}
