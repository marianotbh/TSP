#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);

void inicializarFlags(EPersona array[],int len);
void agregarPersona(EPersona array[],int len,int index);
void borrarPersona(EPersona array[],int len,int index);
int buscarLugarVacioEnArray(EPersona array[],int len);
void bubbleSort(EPersona array[], int size, int orden);
void mostrarPersonas(EPersona array[],int len);
void falsificar(EPersona array[],int len);
void grafico(EPersona array[],int len);
int isnumber(char* aux);

#endif // FUNCIONES_H_INCLUDED
