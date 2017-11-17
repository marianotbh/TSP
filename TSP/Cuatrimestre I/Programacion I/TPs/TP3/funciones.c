#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "Validaciones/validaciones.h"

int agregarPelicula(EMovie movie)
{
    int retorno = -1;
    char buffer[1000];
    FILE* pFile = NULL;
    EMovie* auxMovie = NULL;
    int size;

    pFile = fopen("bin.bin","a+b");
    if( pFile == NULL )
    {
        printf("No se pudo abrir el archivo \n");
        exit(1);
    }

    size = getSizeMovies(movie);

    if( (auxMovie = (EMovie*) malloc(sizeof(EMovie))) == NULL ||  (auxMovie = (EMovie*) realloc(auxMovie, sizeof(EMovie)*(size+1))) == NULL )
    {
        printf("Puntero auxMovie == NULL \n");
        exit(1);
    }
    movie = *auxMovie;

    if(validarDatoAlfanumerico(buffer, "Ingrese titulo: ", "Titulo invalido", 3, 1, 50) == 0)
    {
        strcpy(movie.titulo, buffer);
        if(validarDatoAlfabetico(buffer, "Ingrese genero: ", "Genero invalido", 3, 1, 50) == 0)
        {
            strcpy(movie.genero, buffer);
            if(validarDatoNumerico(buffer, "Ingrese duracion en minutos: ", "Duracion invalida", 3, 0, 1, 10) == 0)
            {
                movie.duracion = atoi(buffer);
                if(validarDatoAlfanumerico(buffer, "Ingrese descripcion: ", "Descripcion invalida", 3, 1, 999) == 0)
                {
                    strcpy(movie.descripcion, buffer);
                    if(validarDatoNumerico(buffer, "Ingrese un puntaje: ", "Puntaje invalido",3, 0, 1, 10) == 0)
                    {
                        movie.puntaje = atoi(buffer);
                        printf("Ingrese un link de imagen: ");
                        scanf("%[^\n]s", movie.linkImagen);
                        fseek(pFile,20L,SEEK_SET);
                        fwrite(&movie,sizeof(EMovie),1,pFile);
                        printf("Pelicula cargada con exito! \n");
                        retorno = 0;
                    }
                    else
                        printf("Ha agotado todos sus intentos \n");
                }
                else
                    printf("Ha agotado todos sus intentos \n");
            }
            else
                printf("Ha agotado todos sus intentos \n");
        }
        else
            printf("Ha agotado todos sus intentos \n");
    }
    else
        printf("Ha agotado todos sus intentos \n");


    if( fclose(pFile) == 0 )
        printf("File cerrado con exito \n");
    else
        printf("File no se cerro correctamente \n");

    return retorno;
}

int borrarPelicula(EMovie movie)
{
    int retorno = -1;
    FILE* pFile = NULL;
    FILE* pTemp = NULL;
    int sizeMovies = getSizeMovies(movie);

    if(sizeMovies > 0)
    {
        if( (pFile = fopen("bin.bin","rb")) == NULL || (pTemp = fopen("temp.bin","wb")) == NULL )
        {
            printf("No se pudo abrir el archivo: \n");
            if(pFile == NULL){printf(" - pFile\n");}
            if(pTemp == NULL){printf(" - pTemp\n");}
            exit(1);
        }

        if( deleteByName(pFile, pTemp, movie) == 0 )
            printf("Eliminado con exito! \n");
        else
            printf("No se encontro la pelicula que busca \n");

        if( fclose(pFile) == 0 )
            printf("File cerrado con exito \n");
        else
            printf("File no se cerro correctamente \n");
        if( fclose(pTemp) == 0 )
            printf("Temp cerrado con exito \n");
        else
            printf("Temp no se cerro correctamente \n");


        if(remove("bin.bin") == 0)
        {
            rename("temp.bin","bin.bin");
            retorno = 0;
        }
        else
            printf("Failed to remove: bin.bin\n");
    }
    else
        printf("Para realizar esta accion debe haber cargado al menos una pelicula \n");


    return retorno;
}

int deleteByName(FILE* pf_Origin, FILE* pf_Temp, EMovie movie)
{
    int retorno = -1;
    int iRead;
    int iWrote;
    char buffer[200];

    printf("Ingrese el nombre de la pelicula que quiere borrar: ");
    scanf("%[^\n]s",buffer);
    fflush(stdin);

    while(!(feof(pf_Origin)))
    {
        if( (iRead = fread(&movie, sizeof(EMovie),1,pf_Origin)) == 1 )
        {
            printf("Leido con exito: %s \n", movie.titulo);
            if(retorno == -1 && strcmp(movie.titulo, buffer) == 0)
            {
                printf("Encontrada: %s \n", movie.titulo);
                retorno = 0;
            }
            else
            {
                if((iWrote = fwrite(&movie, sizeof(EMovie), 1,pf_Temp)) == 1)
                    printf("Copiado a temp: %s \n", movie.titulo);
                else
                {
                    printf("Error de escritura \n");
                    exit(1);
                }
            }
        }
    }

    return retorno;
}

int modificarPelicula(EMovie movie)
{
    int retorno = -1;
    char buffer[200];
    FILE* pFile = NULL;
    EMovie* pAuxMovie;
    int sizeMovies = getSizeMovies(movie);

    if(sizeMovies > 0)
    {
        if(  (pFile = fopen("bin.bin","r+b")) == NULL )
        {
            printf("No se pudo abrir el archivo \n");
            exit(1);
        }
        if( ((pAuxMovie = getPointerOfMovieByName(pFile, &movie)) != NULL) )
        {
            if(validarDatoAlfanumerico(buffer, "Ingrese nuevo titulo: ", "Nuevo titulo invalido", 3, 1, 50) == 0)
            {
                printf("%s ---> %s\n",pAuxMovie->titulo,buffer);
                strcpy(pAuxMovie->titulo, buffer);
                if(validarDatoAlfabetico(buffer, "Ingrese nuevo genero: ", "Nuevo genero invalido", 3, 1, 50) == 0)
                {
                    printf("%s ---> %s\n",pAuxMovie->genero,buffer);
                    strcpy(pAuxMovie->genero, buffer);
                    if(validarDatoNumerico(buffer, "Ingrese nueva duracion en minutos: ", "Nueva duracion invalida", 3, 0, 1, 10) == 0)
                    {
                        printf("%d minutos ---> %s minutos\n",pAuxMovie->duracion,buffer);
                        pAuxMovie->duracion = atoi(buffer);
                        if(validarDatoAlfanumerico(buffer, "Ingrese nueva descripcion: ", "Nueva descripcion invalida", 3, 1, 999) == 0)
                        {
                            printf("%s ---> %s\n",pAuxMovie->descripcion,buffer);
                            strcpy(pAuxMovie->descripcion, buffer);
                            if(validarDatoNumerico(buffer, "Ingrese nuevo un puntaje: ", "Nuevo puntaje invalido",3, 0, 1, 10) == 0)
                            {
                                printf("%d ---> %s\n",pAuxMovie->puntaje,buffer);
                                pAuxMovie->puntaje = atoi(buffer);
                                printf("Ingrese un nuevo link de imagen: ");
                                strcpy(buffer, pAuxMovie->linkImagen);
                                scanf("%[^\n]s", pAuxMovie->linkImagen);
                                printf("%s ---> %s\n",buffer,pAuxMovie->linkImagen);
                                fseek (pFile,(long)(-1)*sizeof(EMovie),SEEK_CUR);
                                fwrite(&movie,sizeof(EMovie),1,pFile);
                                printf("Pelicula cargada con exito! \n");
                                retorno = 0;
                            }
                            else
                                printf("Ha agotado todos sus intentos \n");
                        }
                        else
                            printf("Ha agotado todos sus intentos \n");
                    }
                    else
                        printf("Ha agotado todos sus intentos \n");
                }
                else
                    printf("Ha agotado todos sus intentos \n");
            }
            else
                printf("Ha agotado todos sus intentos \n");
        }
        else
            printf("No se encontro la pelicula que busca \n");

        if( fclose(pFile) == 0 )
            printf("File cerrado con exito \n");
        else
            printf("File no se cerro correctamente \n");
    }
    else
        printf("Para realizar esta accion debe haber cargado al menos una pelicula \n");

    return retorno;
}

EMovie* getPointerOfMovieByName(FILE* pFile, EMovie* movie)
{
    EMovie* retorno = NULL;
    int iLeidos;
    char buffer[100];

    printf("Ingrese el nombre de la pelicula: ");
    scanf("%[^\n]s",buffer);
    fflush(stdin);

    rewind(pFile);
    while(!(feof(pFile)))
    {
        iLeidos = fread(movie,sizeof(EMovie),1,pFile);
        if(iLeidos != 1)
        {
            if(feof(pFile))
                break;
            else
            {
                printf("Error de lectura \n");
                break;
            }
        }
        if(strcmp(movie->titulo, buffer) == 0)
        {
            retorno = movie;
            break;
        }
    }

    return retorno;
}

void generarPagina(EMovie* lista, char* nombre)
{
    FILE* pBIN = NULL;
    FILE* pWeb = NULL;
    int iLeidos;
    int iEscritos;
    EMovie auxMovie;
    char HTMLopen[] = "<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'> <!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>";
    char HTMLarticleBuffer[2000];
    char HTMLclose[] = "</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>";
    int len;
    int sizeMovies = getSizeMovies(*lista);

    if(sizeMovies > 0)
    {
        if( ((pBIN = fopen("bin.bin","rb")) == NULL) || ((pWeb = fopen(nombre,"wb")) == NULL) )
        {
            printf("No se pudo abrir algun archivo \n");
            exit(1);
        }

        rewind(pBIN);
        rewind(pWeb);
        len = strlen(HTMLopen);
        fwrite(&HTMLopen,sizeof(char)*len,1,pWeb);
        while(!(feof(pBIN)))
        {
            iLeidos = fread(&auxMovie,sizeof(EMovie),1,pBIN);
            if(iLeidos != 1)
            {
                if(feof(pBIN))
                {
                    printf("End of file \n");
                    break;
                }
                else
                {
                    printf("Error de lectura \n");
                    break;
                }
            }
            sprintf(HTMLarticleBuffer,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Género:%s</li><li>Puntaje:%d</li><li>Duración:%d&nbsp;minutos</li></ul><p>%s</p></article>",auxMovie.linkImagen,auxMovie.titulo,auxMovie.genero,auxMovie.puntaje,auxMovie.duracion,auxMovie.descripcion);
            len = strlen(HTMLarticleBuffer);
            if( (iEscritos = fwrite(&HTMLarticleBuffer,sizeof(char)*len,1,pWeb)) == 1 )
                printf("Carganda con exito: %s \n",auxMovie.titulo);
            else
                printf("Algo salio mal \n");
        }
        len = strlen(HTMLclose);
        fwrite(&HTMLclose,sizeof(char)*len,1,pWeb);

        if( fclose(pWeb) == 0 )
            printf("Web cerrado con exito \n");
        else
            printf("Web no se cerro correctamente \n");
        if( fclose(pBIN) == 0 )
            printf("BIN cerrado con exito \n");
        else
            printf("BIN no se cerro correctamente \n");
    }
    else
        printf("Debe cargar los datos de por lo menos una pelicula antes de realizar esta accion \n");
}

int getSizeMovies(EMovie movie)
{
    FILE* pFile;
    int cantLeidos = 0;
    int leido;

    if( (pFile = fopen("bin.bin","rb")) == NULL )
    {
        printf("No se pudo abrir el archivo \n");
        exit(1);
    }
    while(!(feof(pFile)))
    {
        leido = fread(&movie,sizeof(EMovie),1,pFile);
        if(leido == 1)
            cantLeidos++;
        else
            break;
    }

    fclose(pFile);

    return cantLeidos;
}

void listarPeliculas(EMovie movie)
{
    FILE* pFile;
    int iRead;

    if( (pFile = fopen("bin.bin","rb")) == NULL )
    {
        printf("No se pudo abrir el archivo \n");
        exit(1);
    }

    while(!(feof(pFile)))
    {
        if( (iRead = fread(&movie, sizeof(EMovie), 1, pFile)) != 1 )
        {
            if(feof(pFile))
            {
                printf("Fin del archivo \n");
                break;
            }
            else
            {
                printf("Error de lectura \n");
                break;
            }
        }
        else
        {
            printf("Titulo: %s \n",movie.titulo);
            printf("Descripcion: %s. \n",movie.descripcion);
            printf("Duracion: %d minutos \n",movie.duracion);
            printf("Genero: %s \n",movie.genero);
            printf("Puntaje: %d \n",movie.puntaje);
            printf("--------------------------\n");
        }
    }

    if( fclose(pFile) == 0 )
        printf("File cerrado con exito \n");
    else
        printf("File no se cerro correctamente \n");
}
