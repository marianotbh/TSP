#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "arrayList.h"

void menu(void)
{
    ArrayList* melodias = al_newArrayList();
    ArrayList* notas = al_newArrayList();

    int opcion;
    char seguir = 's';

    do
    {
        printf("\nMENU: \n Que desea hacer? \n\n");
        printf("1 = Leer archivo \n");
        printf("2 = Reproducir \n");
        printf("3 = Ecualizar \n");
        printf("4 = Correccion \n");
        printf("5 = Salir \n\n");

        printf(" Elija una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);

        system("cls");

        switch(opcion)
        {
            case 1:
                init(melodias,notas);
                break;
            case 2:
                play(melodias);
                break;
            case 3:
                ecualizar(melodias);
                break;
            case 4:
                correccion(melodias);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("\n (!) Ingrese un numero del 1 al 11 \n");
                break;
        }
    }while(seguir == 's');
}
