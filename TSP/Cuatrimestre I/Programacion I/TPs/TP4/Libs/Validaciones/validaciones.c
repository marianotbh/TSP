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

int isnumber(char* aux, int isDecimal)
{
    int i = 0;
    int iPunto = 0;
    int retorno = -1;

    do
    {
        if( (isdigit(aux[i]) != 0) || ((aux[i] == '.') && (iPunto <= 1)) )
        {
            if(isDecimal == 1)
            {
                if(aux[i] == '.')
                {
                    iPunto++;
                }
            }
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
    int retorno = -1;

    do
    {
        printf(mensaje);
        scanf("%s", buffer);
        fflush(stdin);
        if( (istext(buffer) != 0) || (strlen(buffer) > strMaxLen) || (strlen(buffer) < strMinLen) )
        {
            printf("%s, le quedan %d intentos \n", mensajeError, iError);
            iError--;
        }
        else
        {
            retorno = 0;
            break;
        }
    }while(retorno == -1 && iError >= 0);

    return retorno;
}

int validarDatoNumerico(char* buffer, char* mensaje, char* mensajeError, int iError, int isDecimal, int strMinLen, int strMaxLen)
{
    int retorno = -1;

    do
    {
        printf(mensaje);
        scanf("%s", buffer);
        fflush(stdin);
        if( (isnumber(buffer, isDecimal) != 0) || (strlen(buffer) > strMaxLen) || (strlen(buffer) < strMinLen) )
        {
            printf("%s, le quedan %d intentos \n", mensajeError, iError);
            iError--;
        }
        else
        {
            retorno = 0;
            break;
        }
    }while(retorno == -1 && iError >= 0);

    return retorno;
}

int validarDatoAlfanumerico(char* buffer, char* mensaje, char* mensajeError, int iError, int strMinLen, int strMaxLen)
{
    int retorno = -1;

    do
    {
        printf(mensaje);
        scanf("%s", buffer);
        fflush(stdin);
        if( (isalphanum(buffer) != 0) || (strlen(buffer) > strMaxLen) || (strlen(buffer) < strMinLen))
        {
            printf("%s, le quedan %d intentos \n", mensajeError, iError);
            iError--;
        }
        else
        {
            retorno = 0;
            break;
        }
    }while(retorno == -1 && iError >= 0);

    return retorno;
}


