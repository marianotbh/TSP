#include <string.h>
#include "usuario.h"

void usuario_init(sUsuario* usuarios, int lengthUsuarios)
{
    int i;
    for(i = 0; i < lengthUsuarios; i++)
    {
        usuarios[i].isEmpty = 1;
        usuarios[i].ventas = 0;
        usuarios[i].reputacion = 0;
    }
}

void altaUsuario(sUsuario* usuarios, int lengthUsuarios, char* nombre, char* passWord, int id, int index)
{
    strcpy(usuarios[index].nombre, nombre);
    strcpy(usuarios[index].passWord, passWord);
    usuarios[index].id = id;
    usuarios[index].isEmpty = 0;
}

void modificarUsuario(sUsuario* usuarios, int lengthUsuarios, char* nombre, char* passWord, int index)
{
    strcpy(usuarios[index].nombre, nombre);
    strcpy(usuarios[index].passWord, passWord);
}

void bajaUsuario(sUsuario* usuarios, int lengthUsuarios, int indexBorrar)
{
    usuarios[indexBorrar].isEmpty = 1;
}

void calificarUsuario(sUsuario* usuarios, int lengthUsuarios, int indexUsuario)
{
    char buffer [10];
    int continua;
    continua = validarDatoNumerico(buffer, "Ingrese una calificacion del 1 al 10 para el vendedor: ", "No es una calificacion valida", 3, 1, 0, 2);
    if(continua == 0)
    {
        usuarios[indexUsuario].ventas++;
        usuarios[indexUsuario].reputacion = atoi(buffer);
    }
}

int usuario_getIndexVacio(sUsuario* usuarios, int lengthUsuarios)
{
    int i;
    int retorno = -1;

    for(i = 0; i < lengthUsuarios; i++)
    {
        if(usuarios[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

int usuario_getNewID(sUsuario* usuarios, int lengthUsuarios)
{
    int i;
    int maxID = -1;

    for(i = 0; i < lengthUsuarios; i++)
    {
        if(usuarios[i].id > maxID && usuarios[i].isEmpty == 0)
            maxID = usuarios[i].id;
    }
    return maxID+1;
}

int usuario_findByID(sUsuario* usuarios, int lengthUsuarios, int id)
{
    int i;
    int retorno = -1;

    for(i = 0; i < lengthUsuarios; i++)
    {
        if(usuarios[i].id == id && usuarios[i].isEmpty == 0)
        {
            retorno = i;
        }
    }

    return retorno;
}

int listarUsuarios(sUsuario* usuarios, int lengthUsuarios)
{
    int i;
    int retorno = -1;
    float calificacionPromedio;

    for(i = 0; i < lengthUsuarios; i++)
    {
        if(usuarios[i].isEmpty == 0)
        {
            retorno = 0;
            if(usuarios[i].ventas > 0)
                calificacionPromedio = usuarios[i].reputacion / usuarios[i].ventas;
            else
                calificacionPromedio = 0;
            printf(" Usuario:    %s \n", usuarios[i].nombre);
            printf(" Reputacion: %.1f \n", calificacionPromedio);
            printf(" ID:         %d \n", usuarios[i].id);
            printf("---------------------------------------------\n");
        }
    }
    return retorno;
}
