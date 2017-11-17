#include <stdio.h>
#include <stdlib.h>
#include "controller.h"

void init(ArrayList* melodias, ArrayList* notas)
{
    parseMelodias(melodias);
    parseNotas(notas);
    addFreq(melodias,notas);
}

void addFreq(ArrayList* melodias, ArrayList* notas)
{
    int iM;
    int iN;
    int sizeMelodias = al_len(melodias);
    int sizeNotas = al_len(notas);
    s_Melodia* auxMelodia;
    s_Nota* auxNota;

    for(iM = 0; iM < sizeMelodias; iM++)
    {
        auxMelodia = al_get(melodias,iM);
        for(iN = 0; iN < sizeNotas; iN++)
        {
            auxNota = al_get(notas,iN);
            if(auxMelodia->nombre == auxNota->nombre)
            {
                auxMelodia->freq = auxNota->freq;
            }
        }
    }
    al_deleteArrayList(notas);
}

void play(ArrayList* this)
{
    int i;
    int size = al_len(this);
    if(size == 0)
    {
        printf("Inicialice el programa antes de realizar esta accion \n");
    }
    else
    {
        printf("Nombre/Frecuencia/Volumen/Duracion\n");
        for(i = 0; i < size; i++)
        {
            printMelodia(this,i);
        }
    }
}

void ecualizar(ArrayList* this)
{
    int i;
    int size = al_len(this);
    s_Melodia* auxMelodia;

    if(size == 0)
    {
        printf("Inicialice el programa antes de realizar esta accion \n");
    }
    else
    {
        for(i = 0; i < size; i++)
        {
            auxMelodia = al_get(this,i);
            if(auxMelodia->freq > 250)
            {
                auxMelodia->freq = auxMelodia->freq * 1.30;
            }
            else if(auxMelodia->freq > 330)
            {
                auxMelodia->freq = auxMelodia->freq * 1.50;
            }
            if(auxMelodia->volume > 100)
            {
                auxMelodia->volume = 100;
            }
        }
    }
}

void correccion(ArrayList* this)
{
    FILE* pf_corregido = fopen("melodia_corregida.txt","w");
    s_Melodia* auxMelodia;
    int i;
    int size = al_len(this);

    if(pf_corregido == NULL)
    {
        printf("Error de apertura \n");
        exit(1);
    }
    fprintf(pf_corregido, "NOTA;FREQUENCIA;DURACION;VOLUMEN\n");
    for(i = 0; i < size; i++)
    {
        auxMelodia = al_get(this,i);
        if(auxMelodia->nombre == 'C')
        {
            auxMelodia->nombre = 'D';
        }
        else if(auxMelodia->nombre == 'D')
        {
            auxMelodia->nombre = 'E';
        }
        else if(auxMelodia->nombre == 'E')
        {
            auxMelodia->nombre = 'C';
        }
        fprintf(pf_corregido, "%c --- %d --- %d --- %d \n", auxMelodia->nombre, auxMelodia->freq, auxMelodia->duration, auxMelodia->volume);
    }

    fclose(pf_corregido);
}
