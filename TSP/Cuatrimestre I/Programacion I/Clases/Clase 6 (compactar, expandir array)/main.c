#include <stdio.h>
#include <stdlib.h>
#include "func.h"

#define MAX 100


int main(){
    int i=5;
//    char respuesta;
//    int buffer;

    int edad[MAX] = {22,11,55,33,66};
    int sizeEdad = 5;

    /*for(i = 0 ; i < sizeEdad ; i++)
        printf("%d\n",edad[i]);

    espaciar(edad,sizeEdad,2);

    for(i = 0 ; i < sizeEdad+1 ; i++)
        printf("\n%d",edad[i]); */

    ordenar(edad,sizeEdad);

    for(i = 0 ; i < sizeEdad ; i++)
        printf("\n%d",edad[i]);

    return 0;
}
