/**
 * Recorre un array para comprobar que todos sus caracteres sean numericos
 * @param aux el array que recibe
 * @param 0 si no es numerico y 1 si lo es
*/
int istext(char* aux);

/**
 * Recorre un array para comprobar que todos sus caracteres sean numericos
 * @param aux el array que recibe
 * @param 0 si no es numerico y 1 si lo es
*/
int isnumber(char* aux);

int isalphanum(char* aux);

/**
 * Valida que la opcion ingresada del switch no sea alfabetica o fuera de rango
 * @param mensaje. imprime un mensaje para que el usuario ingrese una opcion
 * @param mensajeError, si el usuario se equivoca le imprime un error

*/
int validarOpcion(int* opcion, char* mensaje, char* mensajeError, int iError);

/**
 * Valida que un array contenga todos elementos alfabeticos
 * @param buffer direccion de memoria que va a validar como alfabetica
 * @param mensaje se muestra para indicar al usuario que debe ingresar
 * @param mensajeError indica al usuario que lo que ingreso no es valido
 * @param min largo minimo del dato a ingresar
 * @param max largo maximo del dato a ingresar
*/
int validarDatoAlfabetico(char* buffer, char* mensaje, char* mensajeError, int iError, int strMinLen, int strMaxLen);

/**
 * Valida que un array contenga todos elementos numericos
 * @param buffer direccion de memoria que va a validar como numerico
 * @param mensaje se muestra para indicar al usuario que debe ingresar
 * @param mensajeError indica al usuario que lo que ingreso no es valido
 * @param min largo minimo del dato a ingresar
 * @param max largo maximo del dato a ingresar
*/
int validarDatoNumerico(char* buffer, char* mensaje, char* mensajeError, int iError, int strMinLen, int strMaxLen);

int validarDatoAlfanumerico(char* buffer, char* mensaje, char* mensajeError, int iError, int strMinLen, int strMaxLen);

