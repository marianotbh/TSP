#include "controller.h"
#include "../Entidades/usuario.h"
#include "../Entidades/producto.h"
#include "../ArrayList/ArrayList.h"
#include "../Validaciones/libs_Validaciones.h"

void controller_altaUsuario(ArrayList* usuarios)
{
    char buffer[100];
    char bufferNombre[100];
    char bufferPW[100];
    int bufferID;
    sUsuario* auxUsuario = malloc(sizeof(sUsuario));

    if(auxUsuario != NULL)
    {
        if((validarDatoAlfabetico(buffer, "Ingrese nombre: ", "(!) Invalido", 3, 0, 50)) == 0)
        {
            strcpy(bufferNombre, buffer);
            if((validarDatoAlfanumerico(buffer, "Ingrese PW: ", "(!) Invalida (solo caracteres alfanumericos)", 3, 0, 20)) == 0)
            {
                strcpy(bufferPW, buffer);
                bufferID = usuario_getNewID((sUsuario*)usuarios->pElements);
                printf("ID obtenido: %d \n",bufferID);
                if(bufferID >= 0)
                {
                    altaUsuario(auxUsuario, bufferNombre, bufferPW, bufferID);
                    al_add(usuarios,auxUsuario);
                    printf("Usuario '%s' cargado con exito \n",auxUsuario->nombre);
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

void controller_modificarUsuario(ArrayList* usuarios)
{
    int idBuscar;
    int indexModificar;
    char buffer[51];
    char bufferNombre[51];
    char bufferPW[21];
    sUsuario* auxUsuario = (sUsuario*) malloc(sizeof(sUsuario));

    printf("Ingrese el ID del usuario que desea modificar: ");
    scanf("%d", &idBuscar);

    indexModificar = usuario_findByID((sUsuario*)(usuarios->pElements), idBuscar);
    printf("Index obtenido: '%d' \n", indexModificar);
    if(indexModificar != -1)
    {
        if((validarDatoAlfabetico(buffer, "Ingrese nuevo nombre: ", "(!) Invalido", 3, 0, 50)) == 0)
        {
            strcpy(bufferNombre, buffer);
            if((validarDatoAlfanumerico(buffer, "Ingrese nueva PW: ", "(!) Invalido", 3, 0, 20)) == 0)
            {
                strcpy(bufferPW, buffer);
                modificarUsuario(auxUsuario, bufferNombre, bufferPW, indexModificar);
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
    int idBorrar;

    printf("Ingrese el ID del usuario que desea borrar: ");
    scanf("%d", &idBorrar);
    if((usuario_findByID((sUsuario*)usuarios->pElements, idBorrar)) == 0)
    {
        bajaUsuario((sUsuario*)usuarios->pElements, idBorrar);
        printf("Usuario dado de baja con exito \n");
    }
}

void controller_publicarProducto(ArrayList* productos, ArrayList* usuarios)
{
    char buffer[100];
    char bufferNombre[100];
    float bufferPrecio;
    int bufferStock;
    int bufferID;
    int bufferUserID;
    sProducto* auxProducto = (sProducto*) malloc(sizeof(sProducto));

    printf("Ingrese su ID de usuario: ");
    scanf("%d", &bufferUserID);

    if((bufferUserID = usuario_findByID((sUsuario*)usuarios->pElements, bufferUserID)) != -1)
    {
        if(validarDatoAlfabetico(buffer, "Ingrese nombre: ", "(!) Invalido", 3, 0, 50) == 0)
        {
            strcpy(bufferNombre, buffer);
            if(validarDatoNumerico(buffer, "Ingrese precio: ", "(!) Invalido", 3, 0, 20) == 0)
            {
                bufferPrecio = atof(buffer);
                if(validarDatoNumerico(buffer, "Ingrese stock: ", "(!) Invalido", 3, 0, 20) == 0)
                {
                    bufferStock = atoi(buffer);
                    bufferID = producto_getNewID((sProducto*)productos->pElements);
                    if(bufferID >= 0)
                    {
                        publicarProducto(auxProducto, bufferNombre, bufferPrecio, bufferStock, bufferID, bufferUserID);
                        al_add(productos,auxProducto);
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
        printf("(!) No es un ID de usuario existente \n");
}

void controller_modificarPublicacion(ArrayList* productos, ArrayList* usuarios)
{
    int idModificar;
    int indexModificar;
    char buffer[100];
    char bufferNombre[100];
    char bufferPW[100];

    printf("Ingrese su ID de usuario: ");
    scanf("%d", &idModificar);

    if((indexModificar = usuario_findByID((sUsuario*)usuarios->pElements, idModificar)) != -1)
    {
        if(validarDatoAlfabetico(buffer, "Ingrese nuevo nombre: ", "(!) Invalido", 3, 0, 50) == 0)
        {
            strcpy(bufferNombre, buffer);
            if(validarDatoAlfanumerico(buffer, "Ingrese nueva PW: ", "(!) Invalido", 3, 0, 20) == 0)
            {
                strcpy(bufferPW, buffer);
                modificarUsuario((sUsuario*)usuarios->pElements, bufferNombre, bufferPW, indexModificar);
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

void controller_cancelarPublicacion(ArrayList* productos, ArrayList* usuarios)
{
    int idBorrar;

    printf("Ingrese el ID del producto que desea borrar: ");
    scanf("%d", &idBorrar);

    if(producto_findByID((sProducto*)productos->pElements, idBorrar) == 0)
    {
        bajaProducto((sProducto*)productos->pElements, idBorrar);
        printf("Producto dado de baja con exito \n");
    }
}

void controller_comprarProducto(ArrayList* productos, ArrayList* usuarios)
{
    int indexProducto;
    int indexUsuario;
    int idProducto;
    int idUsuario;
    sProducto* auxProducto;

    printf("Ingrese el ID del producto que desea comprar: ");
    scanf("%d", &idProducto);

    if((indexProducto = producto_findByID((sProducto*)productos->pElements, idProducto)) != -1)
    {
        auxProducto = al_get(productos,indexProducto);
        idUsuario = auxProducto->idUsuario;
        indexUsuario = usuario_findByID((sUsuario*)usuarios->pElements, idUsuario);
        if(comprarProducto((sUsuario*)usuarios->pElements, indexProducto) == 0)
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

void controller_listarPublicacionesDeUsuario(ArrayList* productos, ArrayList* usuarios)
{
    int idUsuario;

    printf("Ingrese ID del usuario: ");
    scanf("%d", &idUsuario);
    if(usuario_findByID(usuarios, idUsuario) == 0)
    {
        if(listarPublicacionesDeUsuario(productos->pElements, idUsuario) == -1)
            printf("Este usuario no tiene publicaciones para mostrar");
    }
    else
        printf("No se ha encontrado el ID que busca");
}

void controller_listarPublicaciones(ArrayList* productos, ArrayList* usuarios)
{
    int i;
    int idUsuario;
    int indexUsuario;
    char nombreDeUsuario[21];
    sProducto* auxProducto;
    sUsuario* auxUsuario;
    int lengthProductos = al_len(productos->pElements);
    for(i = 0; i < lengthProductos; i++)
    {
        auxProducto = al_get(productos,i);
        if(auxProducto->isEmpty == 0)
        {
            printf("ID de producto: %d \n", auxProducto->id);
            printf("Nombre:         %s \n", auxProducto->nombre);
            printf("Precio:         $%.2f \n", auxProducto->precio);
            printf("Vendidos:       %d \n", auxProducto->vendidos);
            printf("Stock:          %d \n", auxProducto->stock);
            idUsuario = auxProducto->idUsuario;
            indexUsuario = usuario_findByID(usuarios, idUsuario);
            auxUsuario = al_get(usuarios,indexUsuario);
            strcpy(nombreDeUsuario, auxUsuario->nombre);
            printf("Publicado por:  %s \n", nombreDeUsuario);
            printf("---------------------------------------------\n");
        }
    }
}

void controller_listarUsuarios(ArrayList* usuarios)
{
    if(listarUsuarios(usuarios) == -1)
        printf("No hay usuarios para mostrar, cargue los datos de al menos uno para realizar esta accion \n");
}

