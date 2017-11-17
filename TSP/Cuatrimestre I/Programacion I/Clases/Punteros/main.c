#include <stdio.h>
#include <stdlib.h>

//puntero: variable que guarda una direccion de memoria.

struct S_Persona {
    char nombre[20];
    int edad;
};
typedef struct S_Persona Persona;

void swap(int* auxA, int* auxB);
int cargarPersona(Persona* persona);
void printPersona(Persona* persona);

int main()
{
    Persona persona;

    if(cargarPersona(&persona))
    {
        printf("Error en la carga");
    }
    else
    {
        printf("Carga exitosa");
    }

    return 0;
}

int cargarPersona(Persona* persona)
{

    return 0;
}
void printPersona(Persona* persona)
{
    /*
    Persona per;
    per = *persona;
    printf("%d",per.edad);
    */
    printf("%s - %d", persona->nombre, persona->edad);
}

void swap(int* auxA, int* auxB)
{
    int aux;

    aux = *auxA;
    *auxA = *auxB;
    *auxB = aux;
}
