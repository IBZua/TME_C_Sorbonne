//
//  Ex3.c
//  TME3
//
//  Created by Bogouslavsky Illia on 09/12/2022.
//

#include "Ex3.h"

void echange(int *a, int *b){
    //printf("avant échange a = %i et b = %i\n", *a, *b);
    int c = *a;
    *a = *b;
    *b = c;
    //printf("après échange a = %i et b = %i\n", *a, *b);
}
void tri(int* a, int* b){
    if (*a >= *b) {
        printf("le premier nombre = %i est supérieur au second nombre = %i\n", *a, *b);
        echange(a, b);
        printf("après tri le premier nombre = %i et le second nombre = %i\n", *a, *b);
    }else{
        printf("le premier nombre = %i est déjà inférieur au second nombre = %i\n", *a, *b);
    }
}
void tri_3(int* a, int* b, int* c){
    printf("nous vérifions si a est supérieur à b\n");
    tri(a,b);
    printf("nous vérifions si b est supérieur à c\n");
    tri(b,c);
    printf("nous vérifions si a est supérieur à c\n");
    tri(a,c);
    printf("nous vérifions si a est supérieur à b\n");
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
