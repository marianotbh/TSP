#include <stdio.h>
#include <stdlib.h>

int getMin(int array[],int cantidad)
{
    int i, min;

    for(i=0;i<cantidad;i++)
    {
        if((array[i] < min) || i == 0)
        {
            min = array[i];
        }
    }
    return min;
}

int compactar(int array[],int indice,int size)
{
    int i;
    for(i=indice;i<size-1;i++)
    {
        array[i] = array[i+1];
    }
    /*
    for(;indice<size-1;indice++)
        array[i] = array[i+1];
    */
    return size-1;
}

void devolverOrdenado(int array[], int cantidad, int arrayOrdenado[])
{
    int i;

    for (i=0;i<cantidad;i++)
    {
        buffer = getMinIndex(array, cantidad);
        printf("Buffer: %d \n",buffer);
        if (buffer<array[j] || i==0)
        {
            for(j=0;j<cantidad;j++)
            {
                ordenado[j] = buffer;
                compactar(array,j,cantidad);
                break;
            }
        }
    }
}

