#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int istext(char* aux)
{
    int i = 0;
    int retorno = -1;

    do
    {
        if(isalpha(aux[i]) != 0)
        {
            retorno = 0;
            i++;
        }
        else
        {
            retorno = -1;
            break;
        }
    }while(aux[i] != '\0');

    return retorno;
}

int isnumber(char* aux)
{
    int i, iPunto = 0;
    int retorno = -1;

    do
    {
        if(aux[i] == '.')
        {
            retorno = 0;
            iPunto++;
            i++;
        }
        else if( (isdigit(aux[i]) != 0) && iPunto <= 1)
        {
            retorno = 0;
            i++;
        }
        else
        {
            retorno = -1;
            break;
        }
    }while(aux[i] != '\0');

    return retorno;
}

int isalphanum(char* aux)
{
    int i = 0;
    int retorno = -1;

    do
    {
        if(isalpha(aux[i]) != 0)
        {
            retorno = 0;
            i++;
        }
        else if(isdigit(aux[i]) != 0)
        {
            retorno = 0;
            i++;
        }
        else
        {
            retorno = -1;
            break;
        }
    }while(aux[i] != '\0');

    return retorno;
}

int validarDatoAlfabetico(char* buffer, char* mensaje, char* mensajeError, int iError, int strMinLen, int strMaxLen)
{
    int i;
    int retorno = -1;

    printf(mensaje);
    scanf("%s",buffer);
    for(i = 0; i < iError; i++)
    {
        if( (istext(buffer) != 0) || (strlen(buffer) > strMaxLen) || (strlen(buffer) < strMinLen) )
        {
            printf("%s, le quedan %d intentos \n", mensajeError, iError-i);
            scanf("%s", buffer);
        }
        else
        {
            retorno = 0;
            break;
        }
    }

    return retorno;
}

int validarDatoNumerico(char* buffer, char* mensaje, char* mensajeError, int iError, int strMinLen, int strMaxLen)
{
    int i;
    int retorno = -1;

    printf(mensaje);
    scanf("%s",buffer);

    for(i = 0; i < iError; i++)
    {
        if( (isnumber(buffer) != 0) || (strlen(buffer) > strMaxLen) || (strlen(buffer) < strMinLen) )
        {
            printf("%s, le quedan %d intentos \n", mensajeError, iError-i);
            scanf("%s", buffer);
        }
        else
        {
            retorno = 0;
            break;
        }
    }

    return retorno;
}

int validarDatoAlfanumerico(char* buffer, char* mensaje, char* mensajeError, int iError, int strMinLen, int strMaxLen)
{
    int i;
    int retorno = -1;

    printf(mensaje);
    scanf("%s",buffer);

    for(i = 0; i < iError; i++)
    {
        if( (isalphanum(buffer) != 0) || (strlen(buffer) > strMaxLen) || (strlen(buffer) < strMinLen))
        {
            printf("%s, le quedan %d intentos \n", mensajeError, iError-i);
            scanf("%s", buffer);
        }
        else
        {
            retorno = 0;
            break;
        }
    }

    return retorno;
}


