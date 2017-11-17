/**
 * Recorre un array para comprobar que todos sus caracteres sean numericos
 * @param aux el array que recibe
 * @return -1 si no es numerico y 0 si lo es
*/
int istext(char* aux);

/**
 * Recorre un array para comprobar que todos sus caracteres sean numericos
 * @param aux el array que recibe
 * @param isDecimal si recibe un 1 contempla los puntos, si no, no
 * @return -1 si no es numerico y 0 si lo es
*/
int isnumber(char* aux, int isDecimal);

/**
 * Recorre un array para comprobar que todos sus caracteres sean alfanumericos
 * @param aux el array que recibe
 * @return -1 si no es numerico y 0 si lo es
*/
int isalphanum(char* aux);

/**
 * Valida que un array contenga todos elementos alfabeticos
 * @param buffer direccion de memoria que va a validar como alfabetica
 * @param mensaje se muestra para indicar al usuario que debe ingresar
 * @param mensajeError indica al usuario que lo que ingreso no es valido
 * @param iError contador de cantidad de errores ingresados que tolera antes de terminar la funcion
 * @param strMinLen largo minimo del dato a ingresar
 * @param strMaxLen largo maximo del dato a ingresar
 * @return -1 si no es alfabetico | 0 si es alfabetico
*/
int validarDatoAlfabetico(char* buffer, char* mensaje, char* mensajeError, int iError, int strMinLen, int strMaxLen);

/**
 * Valida que un array contenga todos elementos numericos
 * @param buffer direccion de memoria que va a validar como numerico
 * @param mensaje se muestra para indicar al usuario que debe ingresar
 * @param mensajeError indica al usuario que lo que ingreso no es valido
 * @param iError contador de cantidad de errores ingresados que tolera antes de terminar la funcion
 * @param isDecimal le pasa un 1 o un 0 al isdigit para saber si toma en cuenta un punto o no
 * @param strMinLen largo minimo del dato a ingresar
 * @param strMaxLen largo maximo del dato a ingresar
 * @return -1 si no es numerico | 0 si es numerico
*/
int validarDatoNumerico(char* buffer, char* mensaje, char* mensajeError, int iError, int isDecimal, int strMinLen, int strMaxLen);

/**
 * Valida que todos los elementos de un array sean caracteres alfanumericos
 * @param buffer direccion de memoria que va a validar como numerico
 * @param mensaje se muestra para indicar al usuario que debe ingresar
 * @param mensajeError indica al usuario que lo que ingreso no es valido
 * @param iError contador de cantidad de errores ingresados que tolera antes de terminar la funcion
 * @param strMinLen largo minimo del dato a ingresar
 * @param strMaxLen largo maximo del dato a ingresar
 * @return -1 si no es numerico | 0 si es numerico
*/
int validarDatoAlfanumerico(char* buffer, char* mensaje, char* mensajeError, int iError, int strMinLen, int strMaxLen);

