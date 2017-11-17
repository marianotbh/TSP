#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Validaciones/validaciones.h"

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

void producto_init(sProducto* productos, int lengthProductos);

int producto_getIndexVacio(sProducto* productos, int lengthProductos);
int producto_getNewID(sProducto* productos, int lengthProductos);
int producto_findByID(sProducto* productos, int lengthProductos, int id);

void publicarProducto(sProducto* productos, int lengthProductos, char* nombre, float precio, int stock, int id, int userID, int index);
void modificarPublicacion(sProducto* productos, int lengthProductos, char* nombre, float precio, int stock, int index);
void cancelarPublicacion(sProducto* productos, int lengthProductos, int idBorrar);

int comprarProducto(sProducto* productos, int lengthProductos, int indexComprar);
int listarPublicacionesDeUsuario(sProducto* productos, int lengthProductos, int idUsuario);
int listarPublicaciones(sProducto* productos, int lengthProductos);
