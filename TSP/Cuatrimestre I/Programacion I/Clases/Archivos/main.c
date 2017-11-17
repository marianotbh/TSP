#include <stdio.h>
#include <stdlib.h>

/*
id,first_name,last_name,is_empty
1,Eric,Knight,false
*/

struct{
    char id[40];
    char nombre[40];
    char apellido[40];
    char isEmpty[40];
}typedef sPersona;

int main()
{
    FILE* pData;
    sPersona* pPersonas = (sPersona*)malloc(sizeof(sPersona));
    sPersona* pAux = (sPersona*)malloc(sizeof(sPersona));

    pData = fopen("data.csv","r");

    if(pData != NULL)
        printf("Todo bien \n");
    else
        printf(":0( \n");

    int i = 0;
    while(!feof(pData))
    {
        fscanf(pData,"%[^,],%[^,],%[^,],%[^\n]",(pPersonas+i)->id,(pPersonas+i)->nombre,(pPersonas+i)->apellido,(pPersonas+i)->isEmpty);
        pAux = realloc(pPersonas,sizeof(sPersona)*(i+1));

        if(pAux == NULL)
            break;
        else
            pPersonas = pAux;

        printf("%s -- %s -- %s -- %s \n",(pPersonas+i)->id,(pPersonas+i)->nombre,(pPersonas+i)->apellido,(pPersonas+i)->isEmpty);
        i++;
    }

    return 0;
}
