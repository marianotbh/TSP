#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Validaciones/libs_Validaciones.h"

struct
{
    char nombre[50];
    char passWord[20];
    int reputacion;
    int ventas;
    int id;
    int isEmpty;
}typedef sUsuario;

int usuario_getIndexVacio(sUsuario* usuarios);
int usuario_getNewID(sUsuario* usuarios);
int usuario_findByID(sUsuario* usuarios, int id);

void altaUsuario(sUsuario* usuarios, char* nombre, char* passWord, int id, int index);
void modificarUsuario(sUsuario* usuarios,  char* nombre, char* passWord, int index);
void bajaUsuario(sUsuario* usuarios, int idBorrar);
void calificarUsuario(sUsuario* usuarios, int indexUsuario);

int listarUsuarios(sUsuario* usuarios);

