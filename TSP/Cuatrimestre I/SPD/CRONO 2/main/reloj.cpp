#include "reloj.h"
#include "Arduino.h"
#include <LiquidCrystal.h>

#define FALSE 0
#define TRUE 1

#define RELOJ_STATE_NONE 0
#define RELOJ_STATE_SHOW 1
#define RELOJ_STATE_SETUP 2

#define btnRIGHT 0
#define btnUP 1
#define btnDOWN 2
#define btnLEFT 3
#define btnSELECT 4
#define btnNONE 5

static int minutos;
static int segundos;
static int minutosSetup;
static int segundosSetup;
static int state_reloj = RELOJ_STATE_NONE;
static int ultimoInc;
static int flagTimer10ms;
static int flagTimer100ms;
static int counterTimer100ms;
static int flagTimer500ms;
static int counterTimer500ms;
static int flagTimer1000ms;
static int counterTimer1000ms;

static LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 

/** \brief  Se invoca una sola vez cuando el programa empieza. 
 *          Se utiliza para inicializar los modos de trabajo 
 *          de los pines, el puerto serie, etc... 
 * \param void
 * \return void
 */
void setup_reloj(void)
{
    minutos = 0;
    segundos = 0;
    state_reloj = RELOJ_STATE_SHOW;
    ultimoInc=0;
    flagTimer100ms = 0;
    counterTimer100ms = 0;
    flagTimer500ms = 0;
    counterTimer500ms = 0;
    flagTimer1000ms = 0;
    counterTimer1000ms = 0;
    lcd.begin(16, 2); // inicializo la biblioteca indicando 16 caracteres por 2 lineas
    Serial.begin(9600);

}

void incrementarCounter( int *flagTimer, int *counterTimer, int limit)
{
        int retorno = FALSE;
        if(*counterTimer < limit)
        {
            *counterTimer = *counterTimer + 10;
        }
        else
        {
            *flagTimer = TRUE;
            *counterTimer = 0;
        }
}

/** \brief  Incrementa los contadores
 *          
 * \param void
 * \return void
 */
void tick_reloj()
{
    int actual = millis();
    if((actual - ultimoInc) >= 10)
    {
        flagTimer10ms = TRUE;
        ultimoInc = actual - ((actual - ultimoInc) - 10);
        incrementarCounter( &flagTimer100ms, &counterTimer100ms, 100);
        incrementarCounter( &flagTimer500ms, &counterTimer500ms, 500);
        incrementarCounter( &flagTimer1000ms, &counterTimer1000ms, 1000);
    }

}


/** \brief  Contiene el programa del reloj que se ejecutará cíclicamente
 *          
 * \param void
 * \return void
 */

 /*
 #define RELOJ_STATE_NONE 0
#define RELOJ_STATE_SHOW 1
#define RELOJ_STATE_SETUP 2
 */
void loop_reloj(void)
{
      tick_reloj();
      if(flagTimer10ms)
      {
        int tecla = read_LCD_buttons();
        
        switch(tecla)
        {
            case btnSELECT:
                state_reloj = RELOJ_STATE_SETUP;
                minutosSetup = minutos;
                segundosSetup = segundos;
              
                break;
            case btnLEFT:
                state_reloj = RELOJ_STATE_SHOW;
                break;
             case btnUP:
                if(state_reloj == RELOJ_STATE_SETUP)
                {
                    segundosSetup++;
                }
                break;   
            case btnDOWN:
                if(state_reloj == RELOJ_STATE_SETUP)
                {
                    segundosSetup--;
                }
                break;           
        }
    
        flagTimer10ms = 0;
    }

    if(flagTimer100ms)
    {
        if(state_reloj == RELOJ_STATE_SHOW)
        {
            //mostrar setup 
            lcd.setCursor(0,0);
            lcd.print("Reloj  ");
            lcd.print( segundos);
        }
        else if(state_reloj == RELOJ_STATE_SETUP)
        {
            //mostrar reloj
            lcd.setCursor(0,0);
            lcd.print("SETUP  ");
            lcd.print( segundosSetup);
        }
        
        flagTimer100ms = 0;
    }

    if(flagTimer500ms)
    {

        flagTimer500ms = 0;
    }

    if(flagTimer1000ms)
    {
        incrementarSegundos();
        flagTimer1000ms = 0;
    }

}

void incrementarSegundos()
{
        if(segundos<59)
        {
            segundos++;
        }
        else
        {
            segundos=0;
            if(minutos<59)
            {
                minutos++;
            }
            else
            {
                minutos = 0;
            }
        }

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
  else if (adc_key_in < 50) 
    lcd_key = btnRIGHT;
  else if (adc_key_in < 195) 
    lcd_key = btnUP;
  else if (adc_key_in < 380) 
    lcd_key = btnDOWN;
  else if (adc_key_in < 555)  
    lcd_key = btnLEFT;
  else if (adc_key_in < 790) 
    lcd_key = btnSELECT;

  return lcd_key; 
}
