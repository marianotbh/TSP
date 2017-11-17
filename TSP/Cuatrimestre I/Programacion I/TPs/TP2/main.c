#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define LEN_PERSONAS 20

int main()
{
    char seguir='s';
    int opcion=0;
    int indexVacio;
    int buffer;

    EPersona personas[LEN_PERSONAS];
    inicializarFlags(personas,LEN_PERSONAS);
    falsificar(personas,LEN_PERSONAS);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);
        system("cls");

        switch(opcion)
        {
            case 1:
                indexVacio = buscarLugarVacioEnArray(personas,LEN_PERSONAS);
                agregarPersona(personas,LEN_PERSONAS,indexVacio);
                break;
            case 2:
                printf("A quien desea borrar? \n");
                fflush(stdin);
                scanf("%d",&buffer);
                borrarPersona(personas,LEN_PERSONAS,buffer);
                break;
            case 3:
                bubbleSort(personas,LEN_PERSONAS,1);
                mostrarPersonas(personas,LEN_PERSONAS);
                break;
            case 4:
                grafico(personas,LEN_PERSONAS);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
