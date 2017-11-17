#include "nota.h"

int parseNotas(ArrayList* this)
{
    FILE* pf_notas;
    s_Nota* auxNota;
    int readCheck;
    char skip[100];
    int retorno = -1;

    if((pf_notas = fopen("notas.txt","r")) == NULL)
    {
        printf("(!) Error de lectura \n");
        exit(1);
    }

    fscanf(pf_notas,"%s\n",skip);

    while(!(feof(pf_notas)))
    {
        auxNota = (s_Nota*) malloc(sizeof(s_Nota));
        readCheck = fscanf(pf_notas,"%c;%d\n",&auxNota->nombre,&auxNota->freq);
        if(readCheck == 2)
        {
            al_add(this,auxNota);
        }
        else
        {
            printf("Error de lectura de lineas \n");
            break;
        }
    }
    fclose(pf_notas);
    return retorno;
}
