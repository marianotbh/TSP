#include <stdio.h>
#include <stdlib.h>

struct
{
    char dni[8];
    int turno;
    int estado;
} typedef Atencion;



int main()
{
    Atencion tramiteUrgente[10];
    Atencion tramiteRegular[10];



    int contUrgente=0, contUrgenteAtendido=0;
    int contRegular=0, contRegularAtendido=0;
    int minimoUrgente;
    int indiceMenor;
    int i, esElPrimero=0;
    char dni[8];
    char opcion;
    char seguir = 's';

     for(i=0;i<10;i++)
    {
        tramiteUrgente[i].estado=-1;
        tramiteRegular[i].estado=-1;
    }

    do
    {
        printf("1. T. URGENTE\n");
        printf("2. T. REGULAR\n");
        printf("3. ATENDER CLIENTE\n");
        printf("4. LISTAR\n");
        printf("5. LISTAR ORDENADO POR DNI\n");
        printf("6. SALIR\n");
        printf("Elija una opcion: ");
        fflush(stdin);
        scanf("%s",dni);
        switch(opcion)
        {
        case '1':
            printf("\nIngrese dni: ");
            fflush(stdin);
            scanf("%s",tramiteUrgente[contUrgente].dni);
            tramiteUrgente[contUrgente].turno = contUrgente;
            tramiteUrgente[contUrgente].estado = 0;

            contUrgente++;

            break;
        case '2':

            printf("\nIngrese dni: ");
            fflush(stdin);
            scanf("%s",tramiteRegular[contRegular].dni);
            tramiteRegular[contRegular].turno = contRegular;
            tramiteRegular[contRegular].estado = 0;
            contRegular++;
            break;

        case '3':

            if(esElPrimero==0 || contUrgente!=contUrgenteAtendido)//hay tramites urgentes
            {
                //busco el minimo
                minimoUrgente = contUrgente;
                for(i=0; i<10; i++)
                {
                    if((tramiteUrgente[i].estado == 0 && tramiteUrgente[i].turno < minimoUrgente))
                    {
                        minimoUrgente = tramiteUrgente[i].turno;
                        indiceMenor=i;

                    }
                }

                //obtengo el primer tramite a atender y lo atiendo:
                tramiteUrgente[indiceMenor].estado = 1;
                contUrgenteAtendido++;
                esElPrimero=1;
                 printf("MINIMO URGENTE %d", minimoUrgente);
                printf("\nURGENTE ATENDIDO %d", contUrgenteAtendido);

            }
            else
            {
                printf("Aca atiendo un regular");
            }
            break;

        case '4':

            printf("LISTADO DE URGENTES \n");
            for(i=0; i<10; i++)
            {
                if(tramiteUrgente[i].estado == 0)
                {
                    printf("%s\n", tramiteUrgente[i].dni);
                }
            }


            printf("LISTADO DE REGULARES \n");
            for(i=0; i<10; i++)
            {
                if(tramiteRegular[i].estado == 0)
                {
                    printf("%s\n", tramiteRegular[i].dni);
                }
            }


            break;
        case '6':
            seguir='n';
            break;
        }
        system("pause");
        system("cls");
    }
    while(seguir=='s');
    return 0;
}


/*void bubleSort(Empleado array[], int size)
{
    int i;
    int flagSwap = 1;
    Empleado aux;
    while(flagSwap)
    {
        flagSwap = 0;
        for(i = 0; i<size-1 ; i++)
        {
            if(strcmp(array[i].nombre,array[i+1].nombre) > 0)
            {
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                flagSwap = 1;
            }
        }
    }
}*/
