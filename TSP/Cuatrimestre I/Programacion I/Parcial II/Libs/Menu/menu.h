#include "../Controller/controller.h"
#include "../ArrayList/ArrayList.h"

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
                controller_modificarUsuario(usuarios);
                break;
            case 3:
                controller_bajaUsuario(usuarios);
                break;
            case 4:
                controller_publicarProducto(productos, usuarios);
                break;
            case 5:
                controller_modificarPublicacion(productos, usuarios);
                break;
            case 6:
                controller_cancelarPublicacion(productos, usuarios);
                break;
            case 7:
                controller_comprarProducto(productos, usuarios);
                break;
            case 8:
                controller_listarPublicacionesDeUsuario(productos, usuarios);
                break;
            case 9:
                controller_listarPublicaciones(productos, usuarios);
                break;
            case 10:
                controller_listarUsuarios(usuarios);
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
