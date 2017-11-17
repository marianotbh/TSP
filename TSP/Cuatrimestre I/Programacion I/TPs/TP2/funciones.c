#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

void falsificar(EPersona array[],int len)
{
    strcpy(array[0].nombre,"mari");
    array[0].edad = 21;
    array[0].dni = 21212121;
    array[0].estado = 1;

    strcpy(array[1].nombre,"lau");
    array[1].edad = 23;
    array[1].dni = 23232323;
    array[1].estado = 1;

    strcpy(array[15].nombre,"agu");
    array[15].edad = 15;
    array[15].dni = 15151515;
    array[15].estado = 1;

    strcpy(array[3].nombre,"marito");
    array[3].edad = 50;
    array[3].dni = 50505050;
    array[3].estado = 1;

    strcpy(array[5].nombre,"weni");
    array[5].edad = 25;
    array[5].dni = 25252525;
    array[5].estado = 1;
}

void inicializarFlags(EPersona array[],int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        array[i].estado = 0;
    }
}

int buscarLugarVacioEnArray(EPersona array[],int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        if(array[i].estado == 0)
            return i;
    }
    return -1;
}

void agregarPersona(EPersona array[],int len,int index)
{
    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%s",array[index].nombre);

    printf("Ingrese edad: ");
    fflush(stdin);
    scanf("%d",&array[index].edad);

    printf("Ingrese DNI: ");
    fflush(stdin);
    scanf("%d",&array[index].dni);

    array[index].estado = 1;
}

void borrarPersona(EPersona array[],int len,int index)
{
    for( ; index < len; index++)
    {
        strcpy(array[index].nombre,array[index+1].nombre);
        array[index].edad = array[index+1].edad;
        array[index].dni = array[index+1].dni;
        array[index].estado = array[index+1].estado;
    }
}

void grafico(EPersona array[],int len)
{
    int i,contadorMenores18 = 0,contadorEntre18y35 = 0,contadorMayores35 = 0;
    for(i = 0; i < len; i++)
    {
        if(array[i].estado == 1)
        {
            if(array[i].edad < 18)
                contadorMenores18++;
            else if(array[i].edad >= 18 && array[i].edad <= 35)
                contadorEntre18y35++;
            else
                contadorMayores35++;
        }
    }
    for(i = 0; i < len; i++)
    {
        if(array[i].estado == 1)
        {
            if(contadorMenores18 > i)
                printf("*\t");
            else if(contadorEntre18y35 > i)
                printf("*\t");
            else if(contadorMayores35 > i)
                printf("*\n");
        }
    }
    printf("<18\t19-35\t35>\n");
    printf("%d\t%d\t%d\n",contadorMenores18,contadorEntre18y35,contadorMayores35);
}

void bubbleSort(EPersona array[], int size, int orden)
{
    int i;
    int flagSwap = 1;
    EPersona aux;
    //si le paso uno, ordena de menor a mayor
    if(orden == 1)
    {
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
    }
    // si le paso otra cosa, ordena de mayor a menor
    else
    {
        while(flagSwap)
        {
            flagSwap = 0;
            for( ; size >= 0 ; size--)
            {
                if(strcmp(array[size].nombre,array[size-1].nombre) < 0)
                {
                    aux = array[size];
                    array[size] = array[size-1];
                    array[size-1] = aux;
                    flagSwap = 1;
                }
            }
        }
    }
}

void mostrarPersonas(EPersona array[],int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        if(array[i].estado == 1)
        {
            printf("\tNombre: %s \n",array[i].nombre);
            printf("\tEdad: %d \n",array[i].edad);
            printf("\tDNI: %d \n",array[i].dni);
            printf("--------------------------------------\n");
        }
    }
}

int isnumber(char* aux)
{
    int i=0;
    int retorno=0;

    if(aux[i] == '-') i++;

    while(aux[i] != '\0')
    {
        if(isdigit(aux[i]) != 0)
        {
            retorno = 0;
            break;
        }
        retorno = 1;
        i++;
    }
    return retorno;
}
