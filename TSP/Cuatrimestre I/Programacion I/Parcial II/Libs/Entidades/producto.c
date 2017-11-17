#include "producto.h"
#include "../Validaciones/libs_Validaciones.h"

void publicarProducto(sProducto* productos, char* nombre, float precio, int stock, int id, int userID)
{
    strcpy(productos->nombre, nombre);
    productos->precio = precio;
    productos->stock = stock;
    productos->id = id;
    productos->idUsuario = userID;
    productos->isEmpty = 0;
}

void modificarProducto(sProducto* productos, char* nombre, float precio, int stock, int index)
{
    strcpy(productos[index].nombre, nombre);
    productos[index].precio = precio;
    productos[index].stock = stock;
}

void bajaProducto(sProducto* productos, int indexBorrar)
{
    productos[indexBorrar].isEmpty = 1;
}

int comprarProducto(sProducto* productos, int indexComprar)
{
    int retorno = -1;

    if(productos[indexComprar].stock > 0)
    {
        productos[indexComprar].stock--;
        productos[indexComprar].vendidos++;
        if(productos[indexComprar].stock == 0)
        {
            productos[indexComprar].isEmpty = 1;
        }
        retorno = 0;
    }
    else
        printf("Este producto no cuenta con mas stock");

    return retorno;

}
int producto_getNewID(sProducto* productos)
{
    int i;
    int maxID = -1;
    int lengthProductos = 1;

    for(i = 0; i < lengthProductos; i++)
    {
        if(productos[i].id > maxID && productos[i].isEmpty == 0)
            maxID = productos[i].id;
    }
    return maxID+1;
}

int producto_findByID(sProducto* productos, int id)
{
    int i;
    int retorno = -1;
    int lengthProductos = 5;

    for(i = 0; i < lengthProductos; i++)
    {
        if(productos[i].id == id && productos[i].isEmpty == 0)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int listarPublicacionesDeUsuario(sProducto* productos, int idUsuario)
{
    int i;
    int retorno = -1;
    int lengthProductos = 5;

    for(i = 0; i < lengthProductos; i++)
    {
        if(productos[i].idUsuario == idUsuario && productos[i].isEmpty == 0)
        {
            printf("ID de producto: %d \n", productos[i].id);
            printf("Nombre:         %s \n", productos[i].nombre);
            printf("Precio:         %.2f \n", productos[i].precio);
            printf("Vendidos:       %d \n", productos[i].vendidos);
            printf("Stock:          %d \n", productos[i].stock);
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
            printf("Producto: %s \nPrecio: %f \nStock: %d \nID: %d \n", productos[i].nombre, productos[i].precio, productos[i].stock, productos[i].id);
            printf("************************************************************************\n");
        }
    }
    return retorno;
}
