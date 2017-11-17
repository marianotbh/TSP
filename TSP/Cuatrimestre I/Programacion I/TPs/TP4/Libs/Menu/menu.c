#include "../ArrayList/arrayList.h"

void menu(void)
{
    ArrayList* usuarios = al_newArrayList();
    ArrayList* productos = al_newArrayList();
    int opcion;
    char seguir = 's';

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
        printf(" 11 = Salir \n\n");

        printf(" Elija una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);

        system("cls");

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
                printf("\n (!) Ingrese un numero del 1 al 11 \n");
                break;
        }
    }while(seguir == 's');

    return 0;
}
