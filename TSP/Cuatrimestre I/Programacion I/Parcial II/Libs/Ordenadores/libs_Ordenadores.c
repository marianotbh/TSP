#include <stdio.h>
#include <stdlib.h>

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

void insertionSort(int array[], int size)
{
	int i,j;
	int auxiliar;
	for(i = 1; i < size; i++) {
		auxiliar = array[i];
		j = i;
		while(j > 0 && auxiliar < array[j - 1]) {
			array[j] = array[j - 1];
			j--;
		}
		array[j] = auxiliar;
	}
}

void bubbleSort2(int array[], int size)
{
    int i;
    int auxiliar;
    int s = 1;

    while(s)
    {
        s = 0;
        for (i = 1; i < size; i++)
        {
            if (array[i] < array[i - 1])
            {
                auxiliar = array[i];
                array[i] = array[i - 1];
                array[i - 1] = auxiliar;
                s = 1;
            }
        }
    }
}

void quickSort(int array[], int size)
{
  int pivot;
  int i, j;
  int auxiliar;

  if (size < 2) return;

  pivot = array[size / 2];

  for (i = 0, j = size - 1; ; i++, j--)
  {
    while (array[i] < pivot) i++;
    while (array[j] > pivot) j--;

    if (i >= j) break;

    auxiliar =  array[i];
    array[i] =  array[j];
    array[j] =  auxiliar;
  }

  quickSort(array, i);
  quickSort(array + i, size - i);
}

void selectionSort(int array[], int size)
{
    int i;
    int indiceMinimo;
    int auxiliar;

    for(i=0;i<size;i++)
    {
        indiceMinimo = calcularIndiceMinimo(array+i,size-i) + i;
        auxiliar = array[i];
        array[i] = array[indiceMinimo];
        array[indiceMinimo] = auxiliar;
    }

}

