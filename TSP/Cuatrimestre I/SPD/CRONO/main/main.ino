/******************************************************************
* Programa: Ejemplo de uso del LCD Keypad Shield
*
* Objetivo:
*   Mostrar los aspectos básicos de funcionamiento del LCD Keypad Shield
*   Manejar una entrada analógica
*
* Aspectos a destacar:
*   -Lectura de la entrada analogica 
*
* Versión: 0.3 del 5 de marzo de 2017
* Autor: Mauricio Dávila
* Revisión: -
*
* *******************************************************************/

#include "reloj.h"


/** \brief  Se invoca una sola vez cuando el programa empieza. 
 *          Se utiliza para inicializar los modos de trabajo 
 *          de los pines, el puerto serie, etc... 
 * \param void
 * \return void
 */
void setup(void)
{
  setup_reloj(); // inicializo el reloj
  //setup_calefa(); // inicializo el reloj
  //setup_semaforo(); // inicializo el reloj
}


/** \brief  Contiene el programa que se ejecutará cíclicamente
 *          
 * \param void
 * \return void
 */
void loop(void)
{
    loop_reloj();
    //loop_calefa();
    //loop_semaforo();
}
