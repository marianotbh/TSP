#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct
{
    char nombre[20];
    int edad;
}typedef sPersona;

void bubleSort2(sPersona** punteros, int size);
void bubleSort3(sPersona** punteros, int size);

int main()
{
    sPersona* aPersonas;
    sPersona** pPunteros;
    sPersona** pPunteros2;
    char* nombres[] = {"pep","jua","bbb","jjj","zzz","ddd","fff","bbb","ggg","yyy"};
    int i;

    aPersonas = (sPersona *) malloc(sizeof(sPersona) * 10);
    pPunteros = (sPersona **) malloc(sizeof(sPersona *) * 10);
    pPunteros2 = (sPersona **) malloc(sizeof(sPersona *) * 10);

    //init edades
    for(i = 0; i < 10; i++)
    {
        aPersonas[i].edad = 50-i;
        strcpy(aPersonas[i].nombre, nombres[i]);
    }

    printf("PUNTEROS: \n");
    for(i = 0; i < 10; i++)
    {
        pPunteros[i] = &aPersonas[i];
        pPunteros2[i] = &aPersonas[i];
        printf("P: %p \t", pPunteros[i]);
        printf("N: %s \t", aPersonas[i].nombre);
        printf("E: %d \n", aPersonas[i].edad);
    }

    bubleSort2(pPunteros, 10);


    printf("Punteros ordenados por edad: \n");
    for(i = 0; i < 10; i++)
    {
        printf("P: %p \t", pPunteros[i]);
        printf("E: %d \n", pPunteros[i]->edad);
    }

    bubleSort3(pPunteros, 10);

    printf("Punteros ordenados por nombre: \n");
    for(i = 0; i < 10; i++)
    {
        printf("P: %p \t", pPunteros[i]);
        printf("N: %s \n", pPunteros[i]->nombre);
    }

    return 0;
}

void bubleSort3(sPersona** punteros, int size)
{
    int i;
    sPersona* aux;
    int s = 1;

    while(s)
    {
        s = 0;
        for (i = 0; i < size-1; i++)
        {
            if( (strcmp(punteros[i]->nombre, punteros[i+1]->nombre)) > 0 )
            {
                aux = punteros[i];
                punteros[i] = punteros[i+1];
                punteros[i+1] = aux;
                s = 1;
            }
        }
    }
}

void bubleSort2(sPersona** punteros, int size)
{
    int i;
    sPersona* aux;
    int s = 1;

    while(s)
    {
        s = 0;
        for (i = 0; i < size-1; i++)
        {
            if(punteros[i]->edad > punteros[i+1]->edad)
            {
                aux = punteros[i];
                punteros[i] = punteros[i+1];
                punteros[i+1] = aux;
                s = 1;
            }
        }
    }
}

