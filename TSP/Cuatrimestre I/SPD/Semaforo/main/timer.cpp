#include <Arduino.h>
#include "timer.h"
#define TIMERS_QTY 8

#ifndef TMR
#define TMR
    #define RELOJ_TIMER_0 0
    #define RELOJ_TIMER_1 1

    typedef struct
    {
        unsigned long delayValue;
        char running;
    }S_timerData;
#endif

int timer_waitMs(int delayNumber,int delayMs);
void timer_resetWait(int delayNumber);
void timer_setup();
void timer_tick();
int timer_loop();

static S_timerData timersArray[TIMERS_QTY];
static int anterior = 0;

/** \brief  Si el timer no esta corriendo setea el contador del timer caso contrario evalua si finalizo
 *          
 * \param void
 * \return Retorna 1 si finalizo la cuenta
 */
int timer_loop()
{
    int actual = millis();
    if(anterior!=actual)
    {
        anterior=actual;
        timer_tick();
    }
} 
/** \brief  Si el timer no esta corriendo setea el contador del timer caso contrario evalua si finalizo
 *          
 * \param void
 * \return Retorna 1 si finalizo la cuenta
 */
int timer_waitMs(int delayNumber,int delayMs)
{
	if(timersArray[delayNumber].running==0)
	{
		timersArray[delayNumber].delayValue = delayMs;
		timersArray[delayNumber].running=1;
	}
	else
	{
		if(timersArray[delayNumber].delayValue==0)
		{
			timersArray[delayNumber].running=0;
			return 1;
		}	
	}
	return 0;
}

/** \brief  Baja el flag running
 *          
 * \param void
 * \return void
 */
void timer_resetWait(int delayNumber)
{
	timersArray[delayNumber].running=0;
}

/** \brief  Inicializa el array de timers
 *          
 * \param void
 * \return void
 */
void timer_setup()
{
  int i;  
  for(i=0;i<TIMERS_QTY;i++) // inicializo array de timers
        timersArray[i].running=0;

}

/** \brief  Decrementa los contadores de los timers
 *          
 * \param void
 * \return void
 */
void timer_tick()
{
  int i;  
  for(i=0;i<TIMERS_QTY;i++) 
        if(timersArray[i].running && timersArray[i].delayValue > 0)
            timersArray[i].delayValue--;   
}
