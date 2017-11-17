#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/

void parseDat(ArrayList* lista);
void listarEmpleados(ArrayList* lista);
void ordenarPorNombre(ArrayList* lista);
int compare(void* pAuxA, void* pAuxB);
void agregarEmpleado(ArrayList* lista);
int getNewID(ArrayList* lista);

int main()
{
    ArrayList* lista;
    lista = al_newArrayList();
    int opcion = 0;
    char seguir = 's';

    parseDat(lista);

    do
    {
        printf("Elija: \n");
        printf("1 = Listar empleados \n");
        printf("2 = Ordenar por nombre \n");
        printf("3 = Agregar un elemento \n");
        printf("4 = Eliminar un elemento \n");
        printf("5 = Listar (desde/hasta) \n");
        printf("6 = Salir \n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                listarEmpleados(lista);
                break;
            case 2:
                ordenarPorNombre(lista);
                break;
            case 3:
                agregarEmpleado(lista);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                seguir = 'n';
                break;
            default:
                break;
        }

    }while(seguir == 's');

    return 0;
}

void parseDat(ArrayList* lista)
{
    char bufferID[10];
    char bufferName[51];
    char bufferLastName[51];
    char bufferIsEmpty[10];

    FILE* pData;
    if((pData = fopen("data.csv","r")) == NULL)
        exit(1);

    int len = al_len(lista);
    printf("El size es: %d \n",len);


    while(!(feof(pData)))
    {
        Employee* aux = (Employee*) malloc(sizeof(Employee));
        fscanf(pData,"%[^,],%[^,],%[^,],%[^\n]",bufferID,bufferName,bufferLastName,bufferIsEmpty);

        aux->id = atoi(bufferID);
        strcpy(aux->name, bufferName);
        strcpy(aux->lastName, bufferLastName);
        if(strcmp(bufferIsEmpty, "true") == 0)
            aux->isEmpty = 1;
        else
            aux->isEmpty = 0;

        al_add(lista,(void*)aux);
    }

    len = al_len(lista);
    printf("El size es: %d \n",len);

    fclose(pData);
}

void listarEmpleados(ArrayList* lista)
{
    int i;
    int cant = al_len(lista);
    Employee* pAux;



    for(i = 0; i < cant; i++)
    {
        pAux = (Employee*)al_get(lista,i);
        if( pAux->isEmpty == 0 )
        {
            printf("Nombre:   %s \n", pAux->name);
            printf("Apellido: %s \n", pAux->lastName);
            printf("ID:       %d \n", pAux->id);
            printf("--------------------------------\n");
        }
    }
}

void ordenarPorNombre(ArrayList* lista)
{
    if( al_sort(lista, compare, 1) == 1)
        printf("Lista ordenada \n");
    else
        printf("Bum \n");
}

int compare(void* pAuxA, void* pAuxB)
{
    int retorno;
    Employee* pA;
    Employee* pB;

    pA = (Employee*)pAuxA;
    pB = (Employee*)pAuxB;

    if(strcmp(pA->name, pB->name) < 0)
        retorno = -1;
    else if(strcmp(pA->name, pB->name) > 0)
        retorno = 1;
    else
        retorno = 0;

    return retorno;
}

void agregarEmpleado(ArrayList* lista)
{
    char bufferName[51];
    char bufferLastName[51];

    Employee* aux = (Employee*) malloc(sizeof(Employee));

    printf("Ingrese nombre: ");
    scanf("%s",bufferName);
    fflush(stdin);
    strcpy(aux->name, bufferName);
    printf("Ingrese apellido: ");
    scanf("%s",bufferLastName);
    fflush(stdin);
    strcpy(aux->lastName, bufferLastName);

    aux->id = getNewID(lista);
    aux->isEmpty = 0;

    al_add(lista,(void*)aux);
}

int getNewID(ArrayList* lista)
{
    int i;
    int cant = al_len(lista);
    Employee* pAux;
    int maxID = 0;

    for(i = 0; i < cant; i++)
    {
        pAux = (Employee*)al_get(lista,i);
        if( pAux->id > maxID )
        {
            maxID = pAux->id;
        }
    }

    return maxID+1;
}

