#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    EMovie movie;

    while(seguir=='s')
    {
        printf("Peliculas cargadas: %d \n",getSizeMovies(movie));
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Listar peliculas\n");
        printf("6- Salir\n");

        scanf("%d",&opcion);
        fflush(stdin);
        system("cls");

        switch(opcion)
        {
            case 1:
                agregarPelicula(movie);
                break;
            case 2:
                borrarPelicula(movie);
                break;
            case 3:
                modificarPelicula(movie);
                break;
            case 4:
                generarPagina(&movie, "Pagina.html");
                break;
            case 5:
                listarPeliculas(movie);
                break;
            case 6:
                seguir = 'n';
                break;
            default:
                printf("Debe ingresar una opcion valida \n");
                break;
        }
    }

    return 0;
}
