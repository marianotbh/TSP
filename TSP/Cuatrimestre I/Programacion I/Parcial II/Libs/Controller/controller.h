#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ArrayList/ArrayList.h"

//1
void controller_altaUsuario(ArrayList* usuarios);
//2
void controller_modificarUsuario(ArrayList* usuarios);
//3
void controller_bajaUsuario(ArrayList* usuarios);
//4
void controller_publicarProducto(ArrayList* productos, ArrayList* usuarios);
//5
void controller_modificarPublicacion(ArrayList* productos, ArrayList* usuarios);
//6
void controller_cancelarPublicacion(ArrayList* productos, ArrayList* usuarios);
//7
void controller_comprarProducto(ArrayList* productos, ArrayList* usuarios);
//8
void controller_listarPublicacionesDeUsuario(ArrayList* productos, ArrayList* usuarios);
//9
void controller_listarPublicaciones(ArrayList* productos, ArrayList* usuarios);
//10
void controller_listarUsuarios(ArrayList* usuarios);

