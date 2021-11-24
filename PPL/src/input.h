#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/** \brief  llama a la funcion GetInt, recibe un numero de dicha funcion y verifica que se encuentre entre los valores parametrizados,
 *  si no se pudo cargar el numero, se repite dicha accion la cantidad de veces que el parametro reintentos indique.
 *
 * \param int* pResultado: se utiliza para retornar el numero ingresado en caso de ser correcto
 * \param char* mensaje: se utiliza para informar el tipo de valor a ingresar
 * \param char* mensajeError: se utiliza para informar que se produjo un error al ingresar el numero
 * \param int minimo: se utiliza para verificar el minimo que debe tener el valor ingresado
 * \param int maximo: se utiliza para verificar el maximo que debe tener el valor ingresado
 * \param int reintentos: se utiliza para limitar la cantidad de intentos en caso de que el ingreso del valor sea erroneo
 *
 * \return int: retorna 0 si el numero se cargo con exito, o retorna -1 si los reintentos llegan a 0 y no se logro cargar el numero
 *
 */
int IngresarNumero(int* pResultado, char* mensaje, char* mensajeError,
int minimo, int maximo, int reintentos);

/** \brief	Utiliza las funciones MyGets y EsNumerica para ingresar un numero y validar que sea un numero, respectivamente
 * luego retorna el resultado mediante un puntero pasado como parametro
 *
 * \param	int* pResultad: puntero por el cual se retorna el resultado en caso de ser un numero correcto
 * \return int:	Retorna 0 en caso de que el numero ingresado sea correcto o -1 en caso de error o puntero nulo.
 *
 */
int getInt(int* pResultado);

/** \brief	Recibe una cadena y valida que sea numerica
 *
 * \param char* cadena: 	La cadena que va a ser validada
 *
 * \return int: Retorna 0 en caso de no ser numerica o en caso de error asi como puntero nulo, o retorna 1 en caso de que la cadena sea numerica
 *
 */
int esNumerica(char* cadena);

/** \briefSe utiliza para ingresar una cadena y agregarle \0 a la ultima posicion,
 *
 * \param	char* cadena: el puntero por donde retornara la cadena ingresada
 * \param	int longitud: el tamaño maximo de la cadena ingresada
 * \return int:	Retorna 0 en caso de exito al ingresar la cadena o -1 en caso de error o puntero nulo
 *
 */
int myGets(char* cadena, int longitud);

/** \brief	Utiliza la funcion GetFloat para ingresar un numero flotante y validarlo entre los paramatros minimo y maximo, en caso de error
 * se vuelve a ejecutar la cantidad de veces que reintentos indique
 *
 * \param 	float* pResultado:	Puntero por el cual se retornara el numero validado
 * \param	char* mensaje:	Mensaje para ingresar el numero
 * \param	char* mensajeError:	Mensaje de error al ingresar el numero
 * \param	float minimo: numero minimo que debe tener el valor ingresado para ser valido
 * \param	float maximo: numero maximo que debe tener el valor ingresado para ser valido
 * \param	int reintentos:	cantidad de reintentos para ingresar el numero
 *
 * \return int:	Retorna -1 en caso de error o retorna 0 en caso de que el valor ingresado sea valido
 *
 */
int IngresarFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo,
float maximo, int reintentos);

/** \brief	Utiliza las funciones MyGets y EsFlotante para ingresar un numero y validar que sea un numero flotante, respectivamente
 *
 * \param	float* pResultado: puntero por el cual se retornara el numero en caso de ser valido
 * \return int: Retorna -1 en caso de error o 0 en caso de que el numero ingresado sea valido
 *
 */
int getFloat(float* pResultado);

/** \brief	Recibe una cadena y valida que sea un numero flotante
 *
 * \param	char* cadena: puntero a la cadena que se va a validar
 * \return int: Retorna 0 en caso de que la cadena no sea flotante o 1 en caso de que la cadena sea flotante
 *
 */
int esFlotante(char* cadena);

/** \brief	Utiliza las funciones MyGets, esAlfabetico, y TransformarCadena, para ingresar una cadena, validar que no sean numeros, y
 * transformar la cadena guardandola con mayuscula y minusculas.
 *
 * \param	char* pResultado:	puntero para retornar la cadena validada
 * \param	char* mensaje:	mensaje para ingresar la cadena
 * \param	char* mensajeError: mensaje de error al ingresar la cadena
 * \param	int tam: tamaño maximo que debe tener la cadena a ingresar
 *
 * \return int: Retorna -1 en caso de error o 0 en caso de que la cadena sea valida
 *
 */
int IngresarCadena(char* pResultado, char* mensaje, char* mensajeError, int tam);

/** \brief	Verifica que la cadena pasada como parametro no contega numeros o simbolos
 *
 * \param	char cadena[]: cadena a validar
 * \param	int tam: tamaño de la cadena a validar
 *
 * \return int: retorna -1 en caso de error al validar o 0 en caso de validacion exitosa
 *
 */
int esAlfabetico (char* cadena,int tam);

/** \brief	Recibe una cadena como parametro y la guarda con todas sus letras en minusculas menos la primera que se guarda en mayuscula
 *
 * \param	char cadena[]: cadena a transformar
 * \param	int len: tamaño de la cadena
 *
 * \return int:Retorna 0 en caso de transfomacion exitosa o -1 en caso de caso de cadena nula
 *
 */
int TransformarCadena(char* cadena,int len);

/** \brief	Utiliza la funcion GetCuit para ingresar un CUIT y validarlo
 *
 * \param	char* pResultado:	puntero por el cual se retornara el cuit validado
 * \param	char* mensaje:	mensaje para ingresar el cuit
 * \param	char* mensajeError:	mensaje de error al ingresar el cuit
 * \param	int reintentos:	cantidad de reintentos para ingresar el cuit
 * \param	int tam:	tamaño el cual debe tener el cuit
 *
 * \return int: Retorna -1 en caso de error o 0 encaso de cuit ingresado valido
 *
 */
int IngresarCuit(char* pResultado, char* mensaje, char* mensajeError,
int reintentos, int tam);

/** \brief	Utiliza la funcion EsNumerica para ingresar un numero cuit y validarlo, ademas transforma la forma del numero ingresado
 * EJ se ingresa(20587489667) y se guarda (20-58748955-7)
 *
 * \param	char pResultado[]:	puntero por el cual se retornara el cuit validado
 * \param	int tam: tamaño del cuit
 * \param	char* mensaje: mensaje para ingresar el cuit
 *
 * \return int: Retorna -1 en caso de error o 0 en caso de cuit ingresado valido
 *
 */
int GetCuit(char pResultado[], int tam,char* mensaje);
