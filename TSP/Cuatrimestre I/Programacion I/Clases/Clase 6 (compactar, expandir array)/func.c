#include <stdio.h>
#include <stdlib.h>


int compactar(int array[], int size, int indice)
{
    for ( ; indice<size-1; indice++)
        array[indice] = array[indice+1];
    return size - 1;
}

int espaciar(int array[],int size,int indice)
{
    for ( ; size+1>indice; size--)
    {
        array[size+1] = array[size];
    }
    return size + 1;
}

int calcularIndiceMinimo(int array[], int size)
{
    int indice=1;
    int minimo = array[0];
    int indiceMinimo = 0;
    for ( ;indice < size; indice++)
    {
       if(array[indice] < minimo)
       {
           minimo = array[indice];
           indiceMinimo = indice;
       }

    }
    return indiceMinimo;
}

void nadiaSort(int array[], int size,int arrayOrdenado[])
{
    int i;
    int indiceMinimo;
    int sizeInicial = size;
    for(i=0;i<sizeInicial;i++)
    {
        indiceMinimo = calcularIndiceMinimo(array,size);
        arrayOrdenado[i] = array[indiceMinimo];
        size = compactar(array,size,indiceMinimo);
    }
}

void ordenar(int array[],int size)
{
    int i, buffer;

    for(i=1;i<size+1;i++)
    {
        if(array[i] < array[i-1])
        {
            buffer = array[i];
            printf("%d\n",buffer);
            espaciar(array,size,i-1);
            compactar(array,size,i+1);
            array[i-1] = buffer;
        }
    }
}

float promedio(int edad[], int cantidad){

    float retornoPromedio;
    int i, suma=0;

    for(i=0;i<cantidad;i++){
        suma=suma+edad[i];
    }
    retornoPromedio=(float)suma/cantidad;

    return retornoPromedio;
}
