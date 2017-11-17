#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[100];
}typedef EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna -1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie movie);

/**
 *  Modifica una pelicula del archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna -1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int modificarPelicula(EMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna -1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie* lista, char* nombre);

/**
 * Pide un nombre para comparar y copia todos los archivos que no coincidan a otro archivo temporal
 * \param pf_Origin el puntero a file del archivo original
 * \param pf_Temp el puntero a file del archivo temporal
 * \param movie un tipo de dato EMovie donde deposita los que va leyendo del archivo
 * \return retorna -1 o 0 de acuerdo a si encontro la pelicula o no
 */
int deleteByName(FILE* pf_Origin, FILE* pf_Temp, EMovie movie);

/**
 * Obtiene el puntero de una pelicula dentro del archivo a traves de su nombre ingresado por el usuario
 * \param pFile el puntero al archivo por el cual realiza la busqueda
 * \return devuelve el puntero a la pelicula con la que coincide el nombre que el usuario ingreso
 */
EMovie* getPointerOfMovieByName(FILE* pFile, EMovie* movie);


/**
 * Obtiene la cantidad de peliculas cargadas en el archivo binario
 * \param movie tipo de dato EMovie auxiliar para el fread
 * \return retorna la cantidad de datos EMovie leidos
 */
int getSizeMovies(EMovie movie);

/**
 * Imprime todos los datos de las peliculas cargadas en el binario
 * \param movie tipo de dato EMovie auxiliar para el fread
 */
void listarPeliculas(EMovie movie);
#endif // FUNCIONES_H_INCLUDED
