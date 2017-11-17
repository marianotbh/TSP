#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ATENDIDO 1
#define PENDIENTE 0

struct
{
    char dni[8];
    int turno;
    int estado;
} typedef Cliente;

int turnoUrgente(Cliente array[],int size);
int turnoRegular(Cliente array[],int size);

void menu()
{
    int pointer;
    int sizeU = 0, sizeR = 0;
    char continua = 's';
    Cliente urgentes[sizeR];
    Cliente regulares[sizeU];

    do
    {
        printf("Elija una opcion: \n");
        printf("1 = Turno urgente \n");
        printf("2 = Turno regular \n");
        printf("3 = Proximo cliente \n");
        printf("4 = Listar \n");
        printf("5 = Informar \n");
        printf("6 = Salir \n");

        scanf("%d",&pointer);

        switch(pointer)
        {
        case 1:
            sizeU = turnoUrgente(urgentes,sizeU);
            break;
        case 2:
            sizeR = turnoRegular(regulares,sizeR);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            continua == 'n';
            break;
        }
        system("cls");
    }while(continua == 's');
}

int turnoUrgente(Cliente array[],int size)
{
    int i;
    for( i = 0 ; i <= size ; i++)
    {
        char buffer[9];
        printf("Ingrese DNI: \n");
        fflush(stdin);
        scanf("%s",buffer);
        strcpy(array[size].dni,buffer);
        array[size].turno = i;
        array[size].estado = PENDIENTE;
    }
    return size;
}
int turnoRegular(Cliente array[],int size)
{
    int i;
    for( i = 0 ; i < size+1 ; i++)
    {
        char buffer[9];
        printf("Ingrese DNI: \n");
        fflush(stdin);
        scanf("%s",buffer);
        strcpy(array[size].dni,buffer);
        array[size].turno = i;
        array[size].estado = PENDIENTE;
    }
    return size;
}

/*
void mostrar(Cliente array[], int size)
{
    int i;
    for(i = 0; i < size ; i++)
    {
        printf("\n%s-%d-%d",array[i].dni,array[i].turno,array[i].estado);
    }
    printf("\n----------------------------------------------\n");
}

void bubleSort(Empleado array[], int size)
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
