#include "melodias.h"

int parseMelodias(ArrayList* this)
{
    FILE* pf_melodia;
    s_Melodia* auxNota;
    int readCheck;
    char skip[100];
    int retorno = -1;

    if((pf_melodia = fopen("melodia.txt","r")) == NULL)
    {
        printf("(!) Error de lectura \n");
        exit(1);
    }

    fscanf(pf_melodia,"%s\n",skip);
    while(!(feof(pf_melodia)))
    {
        auxNota = (s_Melodia*) malloc(sizeof(s_Melodia));
        readCheck = fscanf(pf_melodia,"%c;%d;%d\n",&auxNota->nombre,&auxNota->duration,&auxNota->volume);
        if(readCheck == 3)
        {
            al_add(this,auxNota);
        }
    }
    fclose(pf_melodia);
    return retorno;
}

void printMelodia(ArrayList* this, int index)
{
    if(this == NULL || index > al_len(this) || index < 0)
    {
        printf("Error \n");
        exit(1);
    }
    s_Melodia* auxMelodia;
    auxMelodia = al_get(this,index);
    printf("%c --",auxMelodia->nombre);
    printf("%d --",auxMelodia->freq);
    printf("%d --",auxMelodia->volume);
    printf("%d \n",auxMelodia->duration);
}

