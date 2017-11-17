#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Validaciones/validaciones.h"

struct
{
    char nombre[50];
    char passWord[20];
    float reputacion;
    int ventas;
    int id;
    int isEmpty;
}typedef sUsuario;

void usuario_init(sUsuario* usuarios, int lengthUsuarios);

int usuario_getIndexVacio(sUsuario* usuarios, int lengthUsuarios);
int usuario_getNewID(sUsuario* usuarios, int lengthUsuarios);
int usuario_findByID(sUsuario* usuarios, int lengthUsuarios, int id);

void altaUsuario(sUsuario* usuarios, int lengthUsuarios, char* nombre, char* passWord, int id, int index);
void modificarUsuario(sUsuario* usuarios, int lengthUsuarios, char* nombre, char* passWord, int index);
void bajaUsuario(sUsuario* usuarios, int lengthUsuarios, int idBorrar);
void calificarUsuario(sUsuario* usuarios, int lengthUsuarios, int indexUsuario);

int listarUsuarios(sUsuario* usuarios, int lengthUsuarios);

