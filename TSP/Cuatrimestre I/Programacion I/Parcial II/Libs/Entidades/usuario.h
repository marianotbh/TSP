#include <stdio.h>
#include <stdlib.h>

struct
{
    char nombre[50];
    char passWord[20];
    int reputacion;
    int ventas;
    int id;
    int isEmpty;
}typedef sUsuario;

int usuario_getNewID(sUsuario* usuarios);
int usuario_findByID(sUsuario* usuarios, int id);

void altaUsuario(sUsuario* usuario, char* nombre, char* passWord, int id);
void modificarUsuario(sUsuario* usuarios,  char* nombre, char* passWord, int index);
void bajaUsuario(sUsuario* usuarios, int idBorrar);
void calificarUsuario(sUsuario* usuarios, int indexUsuario);

int listarUsuarios(sUsuario* usuarios);

