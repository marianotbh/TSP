#include "producto.h"

void producto_init(sProducto* productos, int lengthProductos)
{
    int i;
    for(i = 0; i < lengthProductos; i++)
    {
        productos[i].isEmpty = 1;
        productos[i].vendidos = 0;
    }
}

void publicarProducto(sProducto* productos, int lengthProductos, char* nombre, float precio, int stock, int id, int userID, int index)
{
    strcpy(productos[index].nombre, nombre);
    productos[index].precio = precio;
    productos[index].stock = stock;
    productos[index].id = id;
    productos[index].idUsuario = userID;
    productos[index].isEmpty = 0;
}

void modificarPublicacion(sProducto* productos, int lengthProductos, char* nombre, float precio, int stock, int index)
{
    strcpy(productos[index].nombre, nombre);
    productos[index].precio = precio;
    productos[index].stock = stock;
}

void cancelarPublicacion(sProducto* productos, int lengthProductos, int indexBorrar)
{
    printf(" INDEX : %d", indexBorrar);
    printf(" ID de producto: %d \n", productos[indexBorrar].id);
    printf(" Nombre:         %s \n", productos[indexBorrar].nombre);
    printf(" Precio:         %.2f \n", productos[indexBorrar].precio);
    printf(" Vendidos:       %d \n", productos[indexBorrar].vendidos);
    printf(" Stock:          %d \n", productos[indexBorrar].stock);
    productos[indexBorrar].isEmpty = 1;
}

int comprarProducto(sProducto* productos, int lengthProductos, int indexComprar)
{
    int retorno = -1;

    if(productos[indexComprar].stock > 0)
    {
        productos[indexComprar].stock--;
        productos[indexComprar].vendidos++;
        retorno = 0;
    }

    return retorno;

}

int producto_getIndexVacio(sProducto* productos, int lengthProductos)
{
    int i;
    int retorno = -1;

    for(i = 0; i < lengthProductos; i++)
    {
        if(productos[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

int producto_getNewID(sProducto* productos, int lengthProductos)
{
    int i;
    int maxID = -1;

    for(i = 0; i < lengthProductos; i++)
    {
        if(productos[i].id > maxID && productos[i].isEmpty == 0)
            maxID = productos[i].id;
    }

    return maxID+1;
}

int producto_findByID(sProducto* productos, int lengthProductos, int id)
{
    int i;
    int retorno = -1;

    for(i = 0; i < lengthProductos; i++)
    {
        if(productos[i].id == id && productos[i].isEmpty == 0)
        {
            retorno = i;
        }
    }

    return retorno;
}

int listarPublicacionesDeUsuario(sProducto* productos, int lengthProductos, int idUsuario)
{
    int i;
    int retorno = -1;

    for(i = 0; i < lengthProductos; i++)
    {
        if(productos[i].idUsuario == idUsuario && productos[i].isEmpty == 0)
        {
            printf(" ID de producto: %d \n", productos[i].id);
            printf(" Nombre:         %s \n", productos[i].nombre);
            printf(" Precio:         %.2f \n", productos[i].precio);
            printf(" Vendidos:       %d \n", productos[i].vendidos);
            printf(" Stock:          %d \n", productos[i].stock);
            printf("---------------------------------------------\n");
            retorno = 0;
        }
    }

    return retorno;
}

int listarProductos(sProducto* productos, int lengthProductos)
{
    int i;
    int retorno = -1;

    for(i = 0; i < lengthProductos; i++)
    {
        if(productos[i].isEmpty == 0)
        {
            retorno = 0;
            printf(" Producto: %s \n", productos[i].nombre);
            printf(" Precio:   %f \n", productos[i].precio);
            printf(" Stock:    %d \n", productos[i].stock);
            printf(" ID:       %d \n", productos[i].id);
            printf("---------------------------------------------\n");
        }
    }

    return retorno;
}
