
#include <Arduino.h>
#include <LiquidCrystal.h>
#include "semaforo.h"
#include "timer.h"

#define FALSE 0
#define TRUE 1

#define SEMAFORO_STATE_IDLE 0
#define SEMAFORO_STATE_PEATON 1
#define SEMAFORO_STATE_VEHICULO 2

#define R1
#define Y1
#define G1
#define R2
#define Y2
#define G2
#define PR1
#define PG1
#define PR2
#define PG2

#define RED 0
#define YELLOW 1
#define GREEN 2

#define btnNONE 5
#define btnVEHICULO 0
#define btnPEATON 1

static int state_semaforo = SEMAFORO_STATE_IDLE;
static int lastKey = btnNONE;
static int ilapso = 0;
static int state_semaforos = SEMAFORO_STATE_IDLE;
static int state_semaforoPrincipal = GREEN;
static int state_semaforoSecundario = RED;

static LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 

static Pin pines[10];
/** \brief  Se invoca una sola vez cuando el programa empieza. 
 *          Se utiliza para inicializar los modos de trabajo 
 *          de los pines, el puerto serie, etc... 
 * \param void
 * \return void
 */
void semaforo_setup(void)
{
    Serial.begin(9600);
    lcd.begin(16, 2); // inicializo la biblioteca indicando 16 caracteres por 2 lineas
}


/** \brief  Contiene el programa del reloj que se ejecutará cíclicamente
 *          
 * \param void
 * \return void
 */
void semaforo_loop(void)
{
    int tecla = btnNONE;
    char pantalla[21];
    if(timer_waitMs(RELOJ_TIMER_0,150))
    {
        tecla = read_LCD_buttons();
        if(tecla != btnNONE)
          timer_resetWait(RELOJ_TIMER_0);
    }    
        
    if(state_semaforo == SEMAFORO_STATE_IDLE)
    {
        if(tecla == btnPEATON)
        {
            state_semaforo = SEMAFORO_STATE_PEATON;
        }
        else if(tecla == btnVEHICULO)
        {
            state_semaforo = SEMAFORO_STATE_VEHICULO;
        }
        
        lcd.setCursor(0,0);
        //sprintf(pantalla,"Rel - %02d:%02d",minutos,segundos);
        lcd.print(pantalla);
    }

    if(timer_waitMs(RELOJ_TIMER_1,1000))
    {
        ilapso++;
        light(pines,ilapso);
        if(ilapso == 24)
         ilapso = 0;
    }
}

void light(Pin pines, int state)
{
  int i;
  for(i=0; i<9; i++)
  {
    pines[i].state = state;
  }
}

void ledON(int led)
{
  
}
void ledOFF(int led)
{
  
}

/** \brief  Realiza la lectura de la entrada analogica y determina según su valor
 *          a que botón hace referencia.
 * \param void
 * \return int: Que representa el botón pulsado
 */
int read_LCD_buttons(void)
{
  int lcd_key = btnNONE; // el valor inicial es NONE
  int adc_key_in = 0;
  adc_key_in = analogRead(0); // lectura de la entrada analogica

  if (adc_key_in > 1000)
    lcd_key = btnNONE;
  else if (adc_key_in < 195) 
    lcd_key = btnPEATON;
  else if (adc_key_in < 380) 
    lcd_key = btnVEHICULO;
  else
    lcd_key = btnNONE;
    

  return lcd_key; 
}
