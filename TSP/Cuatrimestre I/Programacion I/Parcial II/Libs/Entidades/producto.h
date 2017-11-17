#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct
{
    char nombre[50];
    float precio;
    int stock;
    int vendidos;
    int id;
    int idUsuario;
    int isEmpty;
}typedef sProducto;

int producto_getNewID(sProducto* productos);
int producto_findByID(sProducto* productos, int id);

void publicarProducto(sProducto* productos, char* nombre, float precio, int stock, int id, int userID);
void modificarProducto(sProducto* productos, char* nombre, float precio, int stock, int index);
void bajaProducto(sProducto* productos, int idBorrar);

int comprarProducto(sProducto* productos, int indexComprar);
int listarPublicacionesDeUsuario(sProducto* productos, int idUsuario);
int listarPublicaciones(sProducto* productos);
