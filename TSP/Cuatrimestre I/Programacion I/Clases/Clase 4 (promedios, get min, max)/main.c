#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaProm.h"
#define QTY 100

int main()
{
    int operacion;
    int promedio[QTY];
    int promedioMas[QTY];
    int maximo[QTY];
    int minimo[QTY];

    printf("Que desea hacer? \n 1 = Promedio \n 2 = Obtener Minimo \n 3 = Obtener Maximo \n");
    scanf("%d",&operacion);

    switch(operacion)
    {
        case 1:
            printf("El promedio es %f",prom(promedio,QTY,"PROM: Ingrese un numero:\n"));
            break;
        case 2:
            printf("El minimo es %d",getMin(minimo,QTY,"MIN: Ingrese un numero:\n"));
            break;
        case 3:
            printf("El maximo es %d",getMax(maximo,QTY,"MAX: Ingrese un numero:\n"));
            break;
        case 4:
            printf();
            break;
        default:
            printf("No es una opcion valida \n");
            main();
    }
    return 0;
}
