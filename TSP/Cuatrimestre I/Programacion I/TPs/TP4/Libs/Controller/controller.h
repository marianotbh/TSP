#include "../ArrayList/arrayList.h"
#include "../Entidades/usuario.h"
#include "../Entidades/producto.h"

//1
void controller_altaUsuario(ArrayList* this);
//2
void controller_modificarUsuario(ArrayList* this);
//3
void controller_bajaUsuario(ArrayList* this);
//4
void controller_publicarProducto(ArrayList* products, ArrayList* users);
//5
void controller_modificarPublicacion(ArrayList* products, ArrayList* users);
//6
void controller_cancelarPublicacion(ArrayList* products, ArrayList* users);
//7
void controller_comprarProducto(ArrayList* products, ArrayList* users);
//8
void controller_listarPublicacionesDeUsuario(ArrayList* products, ArrayList* users);
//9
void controller_listarPublicaciones(ArrayList* products, ArrayList* users);
//10
void controller_listarUsuarios(ArrayList* this);
