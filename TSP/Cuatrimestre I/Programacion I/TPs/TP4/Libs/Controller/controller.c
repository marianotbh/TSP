#include "controller.h"
/*
1. ALTA DE USUARIO:​ Se piden los datos del usuario requeridos para que el
sistema pueda funcionar
*/
void controller_altaUsuario(ArrayList* this)
{
    int continua;
    int indexVacio;
    char buffer[50];
    char bufferNombre[21];
    char bufferPW[21];
    int bufferID;

    printf("\n 1. ALTA USUARIO: \n\n");

    indexVacio = usuario_getIndexVacio(this, al_len(this));

    if(indexVacio > 0)
    {
        continua = validarDatoAlfabetico(buffer, " Ingrese nombre: ", " (!) Invalido", 3, 0, 20);
        if(continua == 0)
        {
            strcpy(bufferNombre, buffer);
            continua = validarDatoAlfanumerico(buffer, " Ingrese PW: ", " (!) Invalida (solo caracteres alfanumericos)", 3, 0, 20);
            if(continua == 0)
            {
                strcpy(bufferPW, buffer);
                bufferID = usuario_getNewID(this, al_len(this));
                if(bufferID >= 0)
                {
                    altaUsuario(this, al_len(this), bufferNombre, bufferPW, bufferID, indexVacio);
                    printf(" El usuario se ha cargado con exito! \n");
                }
            }
            else
                printf(" (!) Ha agotado todos sus intentos \n");
        }
        else
            printf(" (!) Ha agotado todos sus intentos \n");
    }
    else
        printf(" (!) No hay lugar donde agregar otro usuario \n");
}

/*
2. MODIFICAR DATOS DEL USUARIO:​ Se ingresa el ID del usuario, permitiendo
modificar sus datos.
*/
void controller_modificarUsuario(ArrayList* this)
{
    int continua;
    int idBuscar;
    int indexModificar;
    char buffer[50];
    char bufferNombre[21];
    char bufferPW[21];

    printf("\n 2. MODIFICAR USUARIO: \n\n");

    continua = validarDatoNumerico(buffer, " Ingrese el ID del usuario que quiere modificar: ", " (!) No es un ID valido", 3, 0, 0, 10);
    if(continua == 0)
    {
        idBuscar = atoi(buffer);
        indexModificar = usuario_findByID(this, al_len(this), idBuscar);
        printf(" Index obtenido: '%d' \n", indexModificar);
        if(indexModificar != -1)
        {
            continua = validarDatoAlfabetico(buffer, " Ingrese nuevo nombre: ", " (!) Invalido", 3, 0, 50);
            if(continua == 0)
            {
                strcpy(bufferNombre, buffer);
                continua = validarDatoAlfanumerico(buffer, " Ingrese nueva PW: ", " (!) Invalido", 3, 0, 20);
                if(continua == 0)
                {
                    strcpy(bufferPW, buffer);
                    modificarUsuario(this, al_len(this), bufferNombre, bufferPW, indexModificar);
                    printf(" Los datos se han actualizado exitosamente! \n");
                }
                else
                    printf(" (!) Ha agotado todos sus intentos \n");
            }
            else
                printf(" (!) Ha agotado todos sus intentos \n");
        }
        else
            printf(" (!) ID inexistente \n");
    }
    else
        printf(" (!) No ha ingresado un ID valido \n");
}

/*
3. BAJA DEL USUARIO:​ Se ingresa el ID del usuario y eliminará junto con todos
sus productos a la venta.
*/
void controller_bajaUsuario(ArrayList* this)
{
    int continua;
    char buffer[50];
    int idBorrar;
    int indexUsuarioBorrar;

    printf("\n 3. BAJA USUARIO: \n\n");

    continua = validarDatoNumerico(buffer, " Ingrese el ID del usuario que quiere borrar: ", " (!) No es un ID valido", 3, 0, 0, 10);
    if(continua == 0)
    {
        idBorrar = atoi(buffer);
        indexUsuarioBorrar = usuario_findByID(this, al_len(this), idBorrar);

        if(indexUsuarioBorrar != -1)
        {
            bajaUsuario(this, al_len(this), indexUsuarioBorrar);
            printf(" El usuario ha sido dado de baja con exito! \n");
        }
        else
            printf(" (!) No se ha encontrado el ID de la persona que desea borrar \n");
    }
    else
        printf(" (!) No ha ingresado un ID valido \n");
}

/*
4. PUBLICAR PRODUCTO:​ Se ingresará el ID del usuario y se pedirán los datos
del producto a publicar (nombre, precio y stock)
*/
void controller_publicarProducto(ArrayList* productos, ArrayList* usuarios)
{
    int continua;
    int indexVacio;
    char buffer[50];
    char bufferNombre[21];
    float bufferPrecio;
    int bufferStock;
    int bufferID;
    int bufferUserID;

    printf("\n 4. PUBLICAR PRODUCTO: \n\n");

    continua = validarDatoNumerico(buffer, " Ingrese su ID de usuario: ", " (!) No es un ID valido", 3, 0, 0, 10);
    if(continua == 0)
    {
        bufferUserID = atoi(buffer);
        continua = usuario_findByID(usuarios, al_len(usuarios), bufferUserID);
        if(continua != -1)
        {
            indexVacio = producto_getIndexVacio(productos, al_len(productos));
            if(indexVacio > 0)
            {
                continua = validarDatoAlfabetico(buffer, " Ingrese nombre: ", " (!) Invalido", 3, 0, 20);
                if(continua == 0)
                {
                    strcpy(bufferNombre, buffer);
                    continua = validarDatoNumerico(buffer, " Ingrese precio: ", " (!) Invalido", 3, 1, 0, 10);
                    if(continua == 0)
                    {
                        bufferPrecio = atof(buffer);
                        continua = validarDatoNumerico(buffer, " Ingrese stock: ", " (!) Invalido", 3, 0, 0, 10);
                        if(continua == 0)
                        {
                            bufferStock = atoi(buffer);
                            if(continua == 0)
                            {
                                bufferID = producto_getNewID(productos, al_len(productos));
                                if(bufferID >= 0)
                                    publicarProducto(productos, al_len(productos), bufferNombre, bufferPrecio, bufferStock, bufferID, bufferUserID, indexVacio);
                            }
                            else
                                printf(" (!) Ha agotado todos sus intentos \n");
                        }
                        else
                            printf(" (!) Ha agotado todos sus intentos \n");
                    }
                    else
                        printf(" (!) Ha agotado todos sus intentos \n");
                }
                else
                    printf(" (!) Ha agotado todos sus intentos \n");
            }
            else
                printf(" (!) No hay lugar donde agregar otro producto \n");
        }
        else
            printf(" (!) No es un ID de usuario existente \n");
    }
    else
        printf(" (!) No ha ingresado un ID valido \n");
}

/*
5. MODIFICAR PUBLICACIÓN:​ Se ingresará el ID del usuario y se listarán los
productos de dicho usuario mostrando todos sus campos (id, nombre, precio,
cantidad vendida y stock), luego ingresar el ID del producto y se pedirá que se
ingrese un nuevo precio y stock.
*/
void controller_modificarPublicacion(ArrayList* productos, ArrayList* usuarios)
{
    int continua;
    int idUsuario;
    int indexUsuario;
    int idProductoModificar;
    int indexProductoModificar;
    char buffer[50];
    char bufferNombre[20];
    char bufferPrecio;
    char bufferStock;

    printf("\n 5. MODIFICAR PUBLICACION: \n\n");

    printf(" Ingrese su ID de usuario: ");
    scanf("%d", &idUsuario);

    indexUsuario = usuario_findByID(usuarios, al_len(usuarios), idUsuario);
    if(indexUsuario != -1)
    {
        listarPublicacionesDeUsuario(productos, al_len(productos), idUsuario);
        printf(" Ingrese el ID del producto que desea modificar: ");
        scanf("%d", &idProductoModificar);
        indexProductoModificar = producto_findByID(productos, al_len(productos), idProductoModificar);
        if(indexProductoModificar != -1)
        {
            continua = validarDatoAlfabetico(buffer, " Ingrese nuevo nombre: ", " (!) Invalido", 3, 0, 50);
            if(continua == 0)
            {
                strcpy(bufferNombre, buffer);
                continua = validarDatoNumerico(buffer, " Ingrese nuevo precio: ", " (!) Invalido", 3, 1, 0, 10);
                if(continua == 0)
                {
                    bufferPrecio = atof(buffer);
                    continua = validarDatoNumerico(buffer, " Ingrese nuevo stock: ", " (!) Invalido", 3, 0, 0, 10);
                    if(continua == 0)
                    {
                        bufferStock = atoi(buffer);
                        modificarPublicacion(productos, al_len(productos), bufferNombre, bufferPrecio, bufferStock, indexProductoModificar);
                        printf(" Los datos se han actualizado exitosamente! \n");
                    }
                    else
                        printf(" (!) Ha agotado todos sus intentos \n");
                    }
                else
                    printf(" (!) Ha agotado todos sus intentos \n");
            }
            else
                printf(" (!) Ha agotado todos sus intentos \n");
        }
        else
            printf(" (!) No ha ingresado un ID de producto de la lista \n");
    }
    else
        printf(" (!) ID inexistente \n");
}

/*
6. CANCELAR PUBLICACIÓN:​ Se ingresará el ID del usuario y se listarán los
productos de dicho usuario mostrando todos sus campos (id, nombre, precio,
cantidad vendida y stock), luego ingresar el ID del producto que se quiere cancelar
su publicación.
*/
void controller_cancelarPublicacion(ArrayList* productos, ArrayList* usuarios)
{
    int continua;
    char buffer[50];
    int idUsuario;
    int idProductoBorrar;
    int indexProductoBorrar;

    printf("\n 6. CANCELAR PUBLICACION: \n\n");

    continua = validarDatoNumerico(buffer, " Ingrese su ID de usuario: ", " (!) ID invalido", 3, 0, 0, 10);
    if(continua == 0)
    {
        idUsuario = atoi(buffer);
        continua = usuario_findByID(usuarios, al_len(usuarios), idUsuario);
        if(continua != -1)
        {
            listarPublicacionesDeUsuario(productos, al_len(productos), idUsuario);
            continua = validarDatoNumerico(buffer, " Ingrese el ID del producto que quiere borrar: ", "(!) ID invalido", 3, 0, 0, 10);
            if(continua == 0)
            {
                idProductoBorrar = atoi(buffer);
                indexProductoBorrar = producto_findByID(productos, al_len(productos), idProductoBorrar);
                if(indexProductoBorrar != -1)
                {
                    cancelarPublicacion(productos, al_len(productos), indexProductoBorrar);
                    printf(" La publicacion se ha cancelado exitosamente! \n");
                }
                else
                    printf(" (!) No es un ID de producto existente \n");
            }
            else
                printf(" (!) No se ingreso un ID de producto valido \n");
        }
        else
            printf(" (!) No se encontro el ID ingresado \n");
    }
    else
        printf(" (!) No se ingreso un ID de usuario valido \n");
}

/*
7. COMPRAR PRODUCTO:​ Se ingresará el ID del producto a comprar, y en el
caso que haya stock se realizará la compra, en dicho caso se ingresará una
calificación para el vendedor.
*/
void controller_comprarProducto(ArrayList* productos, ArrayList* usuarios)
{
    int continua;
    int indexProducto;
    int indexUsuario;
    int idProducto;
    int idUsuario;

    printf("\n 7. COMPRAR PRODUCTO: \n\n");

    printf(" Ingrese el ID del producto que desea comprar: ");
    scanf("%d", &idProducto);

    indexProducto = producto_findByID(productos, al_len(productos), idProducto);

    if(indexProducto != -1)
    {
        idUsuario = productos[indexProducto].idUsuario;
        indexUsuario = usuario_findByID(usuarios, al_len(usuarios), idUsuario);
        continua = comprarProducto(productos, al_len(productos), indexProducto);
        if(continua == 0)
        {
            printf(" Compra exitosa! \n");
            calificarUsuario(usuarios, al_len(usuarios), indexUsuario);
        }
        else
            printf(" (!) Este producto no cuenta con mas stock \n");
    }
    else
        printf(" (!) ID Inexistente \n");
}

/*
8. LISTAR PUBLICACIONES DE USUARIO: ​Se ingresa el ID del usuario y se
mostrará una lista de productos indicando: id, nombre, precio, cantidad vendida y
stock
*/
void controller_listarPublicacionesDeUsuario(ArrayList* productos, ArrayList* usuarios)
{
    int idUsuario;
    int continua;

    printf("\n 8. LISTAR PUBLICACIONES DE USUARIO: \n\n");

    printf(" Ingrese ID del usuario: ");
    scanf("%d", &idUsuario);
    continua = usuario_findByID(usuarios, al_len(usuarios), idUsuario);
    if(continua != -1)
    {
        continua = listarPublicacionesDeUsuario(productos, al_len(productos), idUsuario);
        if(continua == -1)
            printf(" Este usuario no tiene publicaciones para mostrar");
    }
    else
        printf(" No se ha encontrado el ID que busca");
}

/*
9. LISTAR PUBLICACIONES:​ Se mostrará una lista de productos indicando: id,
nombre, precio, cantidad vendida, stock y nombre del usuario.
*/
void controller_listarPublicaciones(ArrayList* productos, ArrayList* usuarios)
{
    int i;
    int idUsuario;
    int indexUsuario;
    char nombreDeUsuario[21];
    int flagHay = -1;

    printf("\n 9. LISTAR PUBLICACIONES: \n\n");

    for(i = 0; i < al_len(productos); i++)
    {
        if(productos[i].isEmpty == 0)
        {
            printf(" ID de producto: %d \n", productos[i].id);
            printf(" Nombre:         %s \n", productos[i].nombre);
            printf(" Precio:         $%.2f \n", productos[i].precio);
            printf(" Vendidos:       %d \n", productos[i].vendidos);
            printf(" Stock:          %d \n", productos[i].stock);
            idUsuario = productos[i].idUsuario;
            indexUsuario = usuario_findByID(usuarios, al_len(usuarios), idUsuario);
            strcpy(nombreDeUsuario, usuarios[indexUsuario].nombre);
            printf(" Publicado por:  %s \n", nombreDeUsuario);
            printf("---------------------------------------------\n");
            flagHay = 0;
        }
        if(flagHay == -1)
            printf(" Todavia no se realizo ninguna publicacion \n Sea el primero en publicar algo! \n");
    }
}

/*
10. LISTAR USUARIOS:​ Se mostrará una lista de usuarios con la calificación
promedio de cada uno.
*/
void controller_listarUsuarios(ArrayList* this)
{
    int check;

    printf("\n 10. LISTAR USUARIOS: \n\n");

    check = listarUsuarios(usuarios, al_len(usuarios));

    if(check == -1)
        printf(" (!) No hay usuarios para mostrar, cargue los datos de al menos uno para realizar esta accion \n");
}
