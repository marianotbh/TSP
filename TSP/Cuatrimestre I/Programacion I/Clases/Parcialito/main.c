#include <stdio.h>
#include <stdlib.h>

#define SIZE_PELICULAS 10
#define SIZE_DIRECTORES 5

struct {
    char titulo[50];
    char year[50];
    char nacionalidad[50];
    char director[50];
    int idPelicula;
    int idDirector;
    int flagFree;
}typedef Pelicula;

struct {
    char nombre[50];
    char nacimiento[50];
    char nacionalidad[50];
    int idDirector;
    int flagFree;
}typedef Director;

void altasPeliculas(Pelicula peliculas[],int size,Director directores[],int index,int id);
void cargarDirector(Director directores[], int size,int index,int id);
void inicializarArrays(Director directores[],int dirLen,Pelicula peliculas[],int movLen);
int buscarLugarVacioEnListaPeliculas(Pelicula peliculas[],int len);
int buscarLugarVacioEnListaDirectores(Director directores[],int len);
int buscarDirectorPorID(Director directores[],int len,int idDirector);
void mostrarDirectores(Director directores[],int len);
void mostrarPeliculas(Pelicula peliculas[],int lenPelis,Director directores[],int lenDir);

int main()
{
    Pelicula peliculas[SIZE_PELICULAS];
    Director directores[SIZE_DIRECTORES];

    int contIdPeliculas = 0, contIdDirectores = 0, pointer;
    int indexVacioDirectores, indexVacioPeliculas;
    char seguir = 's';

    inicializarArrays(directores,SIZE_DIRECTORES,peliculas,SIZE_PELICULAS);

    do {
        printf("Elija una opcion: \n");
        printf("1 = Altas peliculas \n");
        printf("2 = Modificar datos \n");
        printf("3 = Baja de pelicula \n");
        printf("4 = Nuevo director \n");
        printf("5 = Eliminar director \n");
        printf("6 = Informar \n");
        printf("7 = Listar \n");
        printf("8 = Salir \n");

        scanf("%d",&pointer);

        switch(pointer)
        {
            case 1:
                contIdPeliculas++;
                indexVacioPeliculas = buscarLugarVacioEnListaPeliculas(peliculas,SIZE_PELICULAS);
                if(indexVacioPeliculas >= 0)
                {
                    altasPeliculas(peliculas,SIZE_PELICULAS,directores,indexVacioPeliculas,contIdPeliculas);
                }
                break;
            case 2:
                mostrarDirectores(directores,SIZE_DIRECTORES);
                break;
            case 3:
                mostrarPeliculas(peliculas,SIZE_PELICULAS,directores,SIZE_DIRECTORES);
                break;
            case 4:
                contIdDirectores++;
                indexVacioDirectores = buscarLugarVacioEnListaDirectores(directores,SIZE_DIRECTORES);
                if(indexVacioDirectores >= 0)
                {
                    cargarDirector(directores,SIZE_DIRECTORES,indexVacioDirectores,contIdDirectores);
                }
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                seguir = 'n';
                break;
        }
    }while(seguir == 's');

    return 0;
}

void altasPeliculas(Pelicula peliculas[],int size,Director directores[],int index,int id)
{
    printf("Ingrese el nombre de la pelicula: \n");
    fflush(stdin);
    scanf("%s",peliculas[index].titulo);

    printf("Ingrese la fecha de estreno de la pelicula: \n");
    fflush(stdin);
    scanf("%s",peliculas[index].year);

    printf("Ingrese el pais donde fue filmada: \n");
    fflush(stdin);
    scanf("%s",peliculas[index].nacionalidad);

    printf("Ingrese el ID del director: \n");
    fflush(stdin);
    scanf("%d",&peliculas[index].idDirector);

    buscarDirectorPorID(directores,SIZE_DIRECTORES,peliculas[index].idDirector);

    peliculas[index].idPelicula = id;
    peliculas[index].flagFree = 0;

}

void cargarDirector(Director directores[], int size,int index,int id)
{
    printf("Nombre director:");
    fflush(stdin);
    scanf("%s",directores[index].nombre);

    printf("Pais director:");
    fflush(stdin);
    scanf("%s",directores[index].nacionalidad);

    printf("Fecha de nacimiento:");
    fflush(stdin);
    scanf("%s",directores[index].nacimiento);

    directores[index].idDirector = id;
    directores[index].flagFree = 0;
}

void inicializarArrays(Director directores[],int dirLen,Pelicula peliculas[],int movLen)
{
    int i;
    for(i = 0; i < dirLen; i++)
    {
        directores[i].flagFree = 1;
    }
    for(i = 0; i < movLen; i++)
    {
        peliculas[i].flagFree = 1;
    }
}
int buscarLugarVacioEnListaPeliculas(Pelicula peliculas[],int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        if(peliculas[i].flagFree)
            return i;
    }
    return -1;
}
int buscarLugarVacioEnListaDirectores(Director directores[],int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        if(directores[i].flagFree)
            return i;
    }
    return -1;
}

int buscarDirectorPorID(Director directores[],int len,int idBuscado)
{
    int i;
    for(i = 0; i < len; i++)
    {
        if(directores[i].flagFree == 0 && directores[i].idDirector == idBuscado)
        {
            return i;
        }
    }
    return -1;
}

void mostrarPeliculas(Pelicula peliculas[],int lenPelis,Director directores[],int lenDir)
{
    int i;
    printf("\n \n Listado de peliculas: \n \n");
    for(i = 0; i < lenPelis; i++)
    {
        if(peliculas[i].flagFree == 0)
        {
            int idDirector = peliculas[i].idDirector;
            int indexDirector = buscarDirectorPorID(directores,lenDir,idDirector);

            printf(" Titulo: %s \n",peliculas[i].titulo);
            printf(" Year: %s \n",peliculas[i].year);
            printf(" Nacionalidad: %s \n",peliculas[i].nacionalidad);

            if(indexDirector >= 0)
            {
                printf(" Director: %s \n",directores[indexDirector].nombre);
                printf(" Fecha de Nacimiento: %s \n",directores[indexDirector].nacimiento);
                printf(" Nacionalidad: %s \n",directores[indexDirector].nacionalidad);
            }
            else {
                printf(" Director: --- \n");
                printf(" Fecha de Nacimiento: --- \n");
                printf(" Nacionalidad: --- \n");
            }
            printf("-------------------------------------- \n");
        }
    }
}

void mostrarDirectores(Director directores[],int len)
{
    int i;
    printf(" \n \n Listado de directores: \n \n");
    for(i = 0; i < len; i++)
    {
        printf("Nombre: %s \n",directores[i].nombre);
        printf("Fecha de Nacimiento: %s \n",directores[i].nacimiento);
        printf("Nacionalidad: %s \n",directores[i].nacionalidad);
        printf("ID: %d \n",directores[i].idDirector);
        printf("-------------------------------------- \n");
    }
}
