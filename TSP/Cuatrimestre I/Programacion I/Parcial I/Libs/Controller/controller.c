#include "controller.h"
#include "../Entidades/usuario.h"
#include "../Entidades/producto.h"
#include "../ArrayList/ArrayList.h"
#include "../Validaciones/libs_Validaciones.h"

void controller_altaUsuario(ArrayList* usuarios)
{
    int continua;
    char buffer[100];
    char bufferNombre[100];
    char bufferPW[100];
    int bufferID;
    sUsuario* auxUSuario = malloc(sizeof(sUsuario));

    if(auxUSuario != NULL)
    {
        continua = validarDatoAlfabetico(buffer, "Ingrese nombre: ", "(!) Invalido", 3, 0, 50);
        if(continua == 0)
        {
            strcpy(bufferNombre, buffer);
            continua = validarDatoAlfanumerico(buffer, "Ingrese PW: ", "(!) Invalida (solo caracteres alfanumericos)", 3, 0, 20);
            if(continua == 0)
            {
                strcpy(bufferPW, buffer);
                bufferID = usuario_getNewID(usuarios);
                if(bufferID > 0)
                {
                    al_add(usuarios,auxUSuario);
                    altaUsuario(usuarios, bufferNombre, bufferPW, bufferID, indexVacio);
                }

            }
            else
                printf("(!) Ha agotado todos sus intentos \n");
        }
        else
            printf("(!) Ha agotado todos sus intentos \n");
    }
    else
        printf("(!) No hay lugar donde agregar otro usuario \n");
}
/*
void controller_modificarUsuario(ArrayList* usuarios)
{
    int continua;
    int idBuscar;
    int indexModificar;
    char buffer[51];
    char bufferNombre[51];
    char bufferPW[21];

    printf("Ingrese el ID del usuario que desea modificar: ");
    scanf("%d", &idBuscar);

    indexModificar = usuario_findByID(usuarios, idBuscar);
    printf("Index obtenido: '%d' \n", indexModificar);
    if(indexModificar != -1)
    {
        continua = validarDatoAlfabetico(buffer, "Ingrese nuevo nombre: ", "(!) Invalido", 3, 0, 50);
        if(continua == 0)
        {
            strcpy(bufferNombre, buffer);
            continua = validarDatoAlfanumerico(buffer, "Ingrese nueva PW: ", "(!) Invalido", 3, 0, 20);
            if(continua == 0)
            {
                strcpy(bufferPW, buffer);
                modificarUsuario(usuarios, bufferNombre, bufferPW, indexModificar);
                printf("Los datos se han actualizado exitosamente! \n");
            }
            else
                printf("(!) Ha agotado todos sus intentos \n");
        }
        else
            printf("(!) Ha agotado todos sus intentos \n");
    }
    else
        printf("(!) ID inexistente \n");
}

void controller_bajaUsuario(ArrayList* usuarios)
{
    int continua;
    int idBorrar;

    printf("Ingrese el ID del usuario que desea borrar: ");
    scanf("%d", &idBorrar);
    continua = usuario_findByID(usuarios, idBorrar);

    if(continua == 0)
    {
        bajaUsuario(usuarios, idBorrar);
    }
}

void controller_publicarProducto(ArrayList* productos, ArrayList* usuarios)
{
    int continua;
    int indexVacio;
    char buffer[100];
    char bufferNombre[100];
    float bufferPrecio;
    int bufferStock;
    int bufferID;
    int bufferUserID;

    printf("Ingrese su ID de usuario: ");
    scanf("%d", &bufferUserID);

    continua = usuario_findByID(usuarios, bufferUserID);
    if(continua != -1)
    {
        indexVacio = producto_getIndexVacio(productos);
        if(indexVacio > 0)
        {
            continua = validarDatoAlfabetico(buffer, "Ingrese nombre: ", "(!) Invalido", 3, 0, 50);
            if(continua == 0)
            {
                strcpy(bufferNombre, buffer);
                continua = validarDatoNumerico(buffer, "Ingrese precio: ", "(!) Invalido", 3, 0, 20);
                if(continua == 0)
                {
                    bufferPrecio = atof(buffer);
                    continua = validarDatoNumerico(buffer, "Ingrese stock: ", "(!) Invalido", 3, 0, 20);
                    if(continua == 0)
                    {
                        bufferStock = atoi(buffer);
                        if(continua == 0)
                        {
                            bufferID = producto_getNewID(productos);
                            if(bufferID >= 0)
                                publicarProducto(productos, bufferNombre, bufferPrecio, bufferStock, bufferID, bufferUserID, indexVacio);
                        }
                        else
                            printf("(!) Ha agotado todos sus intentos \n");
                    }
                    else
                        printf("(!) Ha agotado todos sus intentos \n");
                }
                else
                    printf("(!) Ha agotado todos sus intentos \n");
            }
            else
                printf("(!) Ha agotado todos sus intentos \n");
        }
        else
            printf("(!) No hay lugar donde agregar otro producto \n");
    }
    else
        printf("(!) No es un ID de usuario existente \n");
}

void controller_modificarPublicacion(ArrayList* productos, ArrayList* usuarios)
{
    int continua;
    int idModificar;
    int indexModificar;
    char buffer[100];
    char bufferNombre[100];
    char bufferPW[100];

    printf("Ingrese el ID del usuario que desea modificar: ");
    scanf("%d", &idModificar);

    indexModificar = usuario_findByID(usuarios, idModificar);
    if(indexModificar != -1)
    {
        continua = validarDatoAlfabetico(buffer, "Ingrese nuevo nombre: ", "(!) Invalido", 3, 0, 50);
        if(continua == 0)
        {
            strcpy(bufferNombre, buffer);
            continua = validarDatoAlfanumerico(buffer, "Ingrese nueva PW: ", "(!) Invalido", 3, 0, 20);
            if(continua == 0)
            {
                strcpy(bufferPW, buffer);
                modificarUsuario(usuarios, bufferNombre, bufferPW, indexModificar);
                printf("Los datos se han actualizado exitosamente! \n");
            }
            else
                printf("(!) Ha agotado todos sus intentos \n");
        }
        else
            printf("(!) Ha agotado todos sus intentos \n");
    }
    else
        printf("(!) ID inexistente \n");
}

void controller_cancelarPublicacion(sProducto* productos, sUsuario* usuarios)
{
    int continua;
    int idBorrar;

    printf("Ingrese el ID del usuario que desea borrar: ");
    scanf("%d", &idBorrar);

    continua = usuario_findByID(usuarios, idBorrar);

    if(continua == 0)
    {
        bajaUsuario(usuarios, idBorrar);
    }
}

void controller_comprarProducto(sProducto* productos, sUsuario* usuarios)
{
    int continua;
    int indexProducto;
    int indexUsuario;
    int idProducto;
    int idUsuario;

    printf("Ingrese el ID del producto que desea comprar: ");
    scanf("%d", &idProducto);

    indexProducto = producto_findByID(productos, idProducto);

    if(indexProducto != -1)
    {
        idUsuario = productos[indexProducto].idUsuario;
        indexUsuario = usuario_findByID(usuarios, idUsuario);
        continua = comprarProducto(productos, indexProducto);
        if(continua == 0)
        {
            printf("Compra exitosa! \n");
            calificarUsuario(usuarios, indexUsuario);
        }
        else
            printf("(!) No fue posible efectuar su compra \n");
    }
    else
        printf("(!) ID Inexistente \n");
}

void controller_listarPublicacionesDeUsuario(sProducto* productos, sUsuario* usuarios)
{
    int idUsuario;
    int continua;

    printf("Ingrese ID del usuario: ");
    scanf("%d", &idUsuario);
    continua = usuario_findByID(usuarios, idUsuario);
    if(continua == 0)
    {
        continua = listarPublicacionesDeUsuario(productos, idUsuario);
        if(continua == -1)
            printf("Este usuario no tiene publicaciones para mostrar");
    }
    else
        printf("No se ha encontrado el ID que busca");
}

void controller_listarPublicaciones(sProducto* productos, sUsuario* usuarios)
{
    int i;
    int idUsuario;
    int indexUsuario;
    char nombreDeUsuario[21];
    int lengthProductos = 1;
    for(i = 0; i < lengthProductos; i++)
    {
        if(productos[i].isEmpty == 0)
        {
            printf("ID de producto: %d \n", productos[i].id);
            printf("Nombre:         %s \n", productos[i].nombre);
            printf("Precio:         $%.2f \n", productos[i].precio);
            printf("Vendidos:       %d \n", productos[i].vendidos);
            printf("Stock:          %d \n", productos[i].stock);
            idUsuario = productos[i].idUsuario;
            indexUsuario = usuario_findByID(usuarios, idUsuario);
            strcpy(nombreDeUsuario, usuarios[indexUsuario].nombre);
            printf("Publicado por:  %s \n", nombreDeUsuario);
            printf("---------------------------------------------\n");
        }
    }
}

void controller_listarUsuarios(sUsuario* usuarios)
{
    int check;

    check = listarUsuarios(usuarios);

    if(check == -1)
        printf("No hay usuarios para mostrar, cargue los datos de al menos uno para realizar esta accion \n");
}
*/
