#include "../Controller/controller.h"
#include "../ArrayList/ArrayList.h"

//void falsificarDatos(sUsuario* usuarios, int lengthUsuarios, sProducto* productos, int lengthProductos);

void menu(void)
{
    int opcion;
    char seguir = 's';
    ArrayList* usuarios;
    ArrayList* productos;

    if(((usuarios = al_newArrayList()) == NULL) || ((productos = al_newArrayList()) == NULL))
    {
        printf("Error 1: saliendo");
        exit(1);
    }

    do
    {
        printf("\n MENU: \n Que desea hacer? \n\n");
        printf("  1 = Alta usuario \n");
        printf("  2 = Modificar usuario \n");
        printf("  3 = Baja usuario \n");
        printf("  4 = Publicar producto \n");
        printf("  5 = Modificar publicacion \n");
        printf("  6 = Cancelar publicacion \n");
        printf("  7 = Comprar producto \n");
        printf("  8 = Listar publicaciones de usuario \n");
        printf("  9 = Listar publicaciones \n");
        printf(" 10 = Listar usuarios\n");
        printf(" 11 = Salir \n");

        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch(opcion)
        {
            case 1:
                controller_altaUsuario(usuarios);
                break;
            case 2:
                //controller_modificarUsuario(usuarios);
                break;
            case 3:
                //controller_bajaUsuario(usuarios);
                break;
            case 4:
                //controller_publicarProducto(productos, usuarios);
                break;
            case 5:
                //controller_modificarPublicacion(productos, usuarios);
                break;
            case 6:
//controller_cancelarPublicacion(productos, usuarios);
                break;
            case 7:
                //controller_comprarProducto(productos, usuarios);
                break;
            case 8:
                //controller_listarPublicacionesDeUsuario(productos, usuarios);
                break;
            case 9:
                //controller_listarPublicaciones(productos, usuarios);
                break;
            case 10:
                //controller_listarUsuarios(usuarios);
                break;
            case 11:
                seguir = 'n';
                break;
            default:
                printf("Elija una opcion valida \n");
                break;
        }
    }while(seguir == 's');
}
/*
void falsificarDatos(sUsuario* usuarios, int lengthUsuarios, sProducto* productos, int lengthProductos)
{
    int i;
    for(i = 0 ; i < 10; i++)
    {
        strcpy(usuarios[i].nombre, "Nombrenom");
        strcpy(usuarios[i].passWord, "abc123");
        usuarios[i].reputacion = 20;
        usuarios[i].ventas = 2;
        usuarios[i].id = i;
        usuarios[i].isEmpty = 0;
    }
    strcpy(usuarios[++i].nombre, "marito");
    strcpy(usuarios[i].passWord, "dafasdfabc123");
    usuarios[i].id = i;
    usuarios[i].isEmpty = 0;
    strcpy(usuarios[++i].nombre, "weni");
    strcpy(usuarios[i].passWord, "abdasfd");
    usuarios[i].id = i;
    usuarios[i].isEmpty = 0;
    strcpy(usuarios[++i].nombre, "zaon");
    strcpy(usuarios[i].passWord, "a242fsd3");
    usuarios[i].id = i;
    usuarios[i].isEmpty = 0;
    strcpy(usuarios[i+=10].nombre, "anito");
    strcpy(usuarios[i].passWord, "32423");
    usuarios[i].id = i;
    usuarios[i].isEmpty = 0;
    strcpy(usuarios[++i].nombre, "pepe");
    strcpy(usuarios[i].passWord, "42342");
    usuarios[i].id = i;
    usuarios[i].isEmpty = 0;
    strcpy(usuarios[i+=3].nombre, "Simonetto");
    strcpy(usuarios[i].passWord, "asdfasdf");
    usuarios[i].id = i;
    usuarios[i].isEmpty = 0;
    strcpy(usuarios[i+=10].nombre, "Lady Simonette");
    strcpy(usuarios[i].passWord, "32423");
    usuarios[i].id = i;
    usuarios[i].isEmpty = 0;

    for(i = 0 ; i < 10; i++)
    {
        strcpy(productos[i].nombre, "Nombrenom");
        productos[i].precio = 100;
        productos[i].id = i;
        productos[i].idUsuario = 37;
        productos[i].stock = 10;
        productos[i].isEmpty = 0;
    }
    strcpy(productos[++i].nombre, "marito");
    productos[i].precio = 100;
    productos[i].id = i;
    productos[i].idUsuario = 0;
    productos[i].isEmpty = 0;
    strcpy(productos[++i].nombre, "weni");
    productos[i].precio = 100;
    productos[i].id = i;
    productos[i].idUsuario = 0;
    productos[i].isEmpty = 0;
    strcpy(productos[++i].nombre, "zaon");
    productos[i].precio = 100;
    productos[i].id = i;
    productos[i].idUsuario = 0;
    productos[i].isEmpty = 0;
    strcpy(productos[i+=10].nombre, "anito");
    productos[i].precio = 100;
    productos[i].id = i;
    productos[i].idUsuario = 0;
    productos[i].isEmpty = 0;
    strcpy(productos[++i].nombre, "pepe");
    productos[i].precio = 100;
    productos[i].id = i;
    productos[i].idUsuario = 0;
    productos[i].isEmpty = 0;
    strcpy(productos[i+=3].nombre, "Simonetto");
    productos[i].precio = 100;
    productos[i].id = i;
    productos[i].idUsuario = 0;
    productos[i].isEmpty = 0;
    strcpy(productos[i+=10].nombre, "Lady Simonette");
    productos[i].precio = 100;
    productos[i].id = i;
    productos[i].idUsuario = 0;
    productos[i].isEmpty = 0;
}
*/
