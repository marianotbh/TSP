#include <stdio.h>
#include <stdlib.h>

int validarInt(char mensaje[],char mensajeError[],int minimo,int maximo)
{
    int buffer;
    printf(mensaje);
    scanf("%d",&buffer);
    while(buffer < minimo || buffer > maximo)
    {
        printf(mensajeError);
        scanf("%d",&buffer);
    }
    return buffer;
}

int validarFloat(char mensaje[],char mensajeError[],float minimo,float maximo)
{
    float buffer;
    printf(mensaje);
    scanf("%f",&buffer);
    while(buffer < minimo || buffer > maximo)
    {
        printf(mensajeError);
        scanf("%f",&buffer);
    }
    return buffer;
}

int validarChar(char mensaje[],char mensajeError[],char minimo,char maximo)
{
    char buffer;
    printf(mensaje);
    scanf("%c",&buffer);
    while(buffer < minimo || buffer > maximo)
    {
        printf(mensajeError);
        scanf("%c",&buffer);
    }
    return buffer;
}
