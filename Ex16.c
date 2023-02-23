//
//  Ex1.c
//  TME3
//
//  Created by Bogouslavsky Illia on 09/12/2022.
//

#include <stdio.h>
void ma_fonction(int v1, int v2){
    int b;
    int *a = &b;
    b = 2*(v1 + v2);
    printf("a=%d, b=%d\n",*a,b);
}
int main(){
    ma_fonction(10,20);
}
