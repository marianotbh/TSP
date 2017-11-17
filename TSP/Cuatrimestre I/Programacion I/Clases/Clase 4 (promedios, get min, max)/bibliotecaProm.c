#include <stdio.h>
#include <stdlib.h>

float prom(int array[],int cantidad,char mensaje[])
{
    int i;
    float promedio = 0;
    char confirma;

    for(i=0;i<cantidad;i++)
    {
        printf(mensaje);
        scanf("%d",&array[i]);
        promedio = promedio + array[i];
        printf("Desea seguir ingresando? S/N \n");
        fflush(stdin);
        scanf("%c",&confirma);
        if(confirma != 's' && confirma != 'S')
        {
            break;
        }
        //system("cls");
    }
    promedio = promedio / i;
    return promedio;
}

int masProm(int array[],int cantidad,float promedio)
{
    int i;
    int mayor[];
    int menor[];
    for(i=0;i<cantidad;i++)
    {
        if(promedio > array[i] || i == 0)
        {
            menor[i] = array[i];
        }
        if(promedio < array[i] || i == 0)
        {
            mayor[i] = array[i];
        }
    }
}

int getMin(int max[],int cantidad,char mensaje[])
{
    int i, num, min;
    char confirma;

    for(i=0;i<cantidad;i++)
    {
        printf(mensaje);
        scanf("%d",&num);
        if(num < min || i == 0)
        {
            min = num;
        }
        printf("Desea seguir ingresando? S/N \n");
        fflush(stdin);
        scanf("%c",&confirma);
        if(confirma != 's' && confirma != 'S')
        {
            break;
        }
    }
    return min;
}

int getMax(int min[],int cantidad,char mensaje[])
{
    int i, num, max;
    char confirma;

    for(i=0;i<cantidad;i++)
    {
        printf(mensaje);
        scanf("%d",&num);
        if(num > max || i == 0)
        {
            max = num;
        }
        printf("Desea seguir ingresando? S/N \n");
        fflush(stdin);
        scanf("%c",&confirma);
        if(confirma != 's' && confirma != 'S')
        {
            break;
        }
    }
    return max;
}
