
struct
{
  int pin;
  int state;
}typedef Pin;


void semaforo_setup(void);
void semaforo_loop(void);
int read_LCD_buttons(void);
void light(Pin pines, int state);
