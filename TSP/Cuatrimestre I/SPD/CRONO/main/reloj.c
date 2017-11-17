
#include "reloj.h"
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
static int state_reloj = RELOJ_STATE_NONE;
static int ultimoInc;
static int flagTimer10ms;
static int counterTimer10ms;
static int flagTimer100ms;
static int counterTimer100ms;
static int flagTimer500ms;
static int counterTimer500ms;
static int flagTimer1000ms;
static int counterTimer1000ms;





/** \brief  Se invoca una sola vez cuando el programa empieza. 
 *          Se utiliza para inicializar los modos de trabajo 
 *          de los pines, el puerto serie, etc... 
 * \param void
 * \return void
 */
void setup_reloj(void)                               
{
    //lcd.begin(16, 2); // inicializo la biblioteca indicando 16 caracteres por 2 lineas
    
    minutos = 0;
    segundos = 0;
    state_reloj = RELOJ_STATE_SHOW;
    ultimoInc=0;
    
    flagTimer10ms = 0;
    counterTimer10ms = 0;
    flagTimer100ms = 0;
    counterTimer100ms = 0;
    flagTimer500ms = 0;
    counterTimer500ms = 0;
    flagTimer1000ms = 0;
    counterTimer1000ms = 0;

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
        return retorno;
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
        flagTimer10ms=TRUE;
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
    int tecla;
    if(flagTimer10ms)
    {
        tecla = read_LCD_button();
        switch(tecla)
        {
            case btnSELECT:
                state_reloj = RELOJ_STATE_SETUP;
                break;
            case btnLEFT:
                state_reloj = RELOJ_STATE_SHOW;
                break;
             case btnUP:
                if(state_reloj == RELOJ_STATE_SETUP)
                {
                    //segundosSetup++;
                }
                break;   
            case btnDOWN:
                if(state_reloj == RELOJ_STATE_SETUP)
                {
                    //segundosSetup--;
                }
                break;           
        }

        flagTimer10ms = 0;
    }

    if(flagTimer100ms)
    {
        if(state_reloj == RELOJ_STATE_SETUP)
        {
            //mostrar setup 
        }
        else if(state_reloj == RELOJ_STATE_SHOW)
        {
            //mostrar reloj

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

    /*
    


  int lcd_key = 0;
  lcd.setCursor(0,0);
 // lcd.print("Boton_v2:"); // imprime por el lcd
  lcd.setCursor(0,1); // mueve el cursor a la primer linea "0" y lo desplaza "0" espacios
  lcd_key = read_LCD_buttons(); // read the buttons
  
  switch (lcd_key) // depending on which button was pushed, we perform an action
  {
     case btnRIGHT:
     {
       lcd.print("RIGHT   ");
       break;
     }
     case btnLEFT:
     {
       lcd.print("LEFT   ");
       
       break;
     }
     case btnUP:
     {
        horas = 0;
        minutos = 0;
        segundos = 0;
        decimas = 0;
        lcd.clear();
        break;
     }
     case btnDOWN:
     {
       lcd.print("DOWN   ");
       break;
     }
     case btnSELECT:
     {
       lcd.print("SELECT");
       break;
     }
     case btnNONE:
     {

       break;
     }
  }

  milisegundos = millis();
  if(milisegundos % 100 == 0){ //Only enter if it has passed tenth of a second
    decimas++;
    if(decimas == 10){ //When it has passed 10 tenths of a second it count one second
      decimas = 0;
      segundos++;
    }
    if(segundos == 60){ //When it has passed 60 seconds it count one minute
      segundos = 0;
      minutos++;
    }
    if(minutos == 60){ //When it has passed 60 minutes it count one hour
      minutos = 0;
      horas++;
    }
    
    //Print Time
    lcd.setCursor(0,1);
    if(horas < 10){
      lcd.print("0");
    }
    lcd.print(horas);
    lcd.print(":");
    lcd.setCursor(3,1);
    if(minutos < 10){
      lcd.print("0");
    }
    lcd.print(minutos);
    lcd.print(":");
    lcd.setCursor(6,1);
    if(segundos < 10){
      lcd.print("0");
    }
    lcd.print(segundos);
    lcd.print(":");
    lcd.setCursor(9,1);
    lcd.print(decimas);
  }
  
    
    */

}

void incrementarSegundos(void)
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
