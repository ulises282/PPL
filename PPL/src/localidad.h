#define LIBRE 0
#define OCUPADO 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct
{
    int id;//PK
    char localidad[51];
    int isEmpty;
}eLocalidad;

/** \brief   Inicializa el array de localidad cambiando el valor del campo isEmpty a LIBRE
 *
 * \param	eLocalidad* list: lista a inicializar
 * \param	int len: tamaño de la lista a inicializar
 *
 * \return int: Retorna -1 en caso de que la lista sea nula o retorna 0 en caso de inicializacion exitosa
 *
 */
int initLocalidad(eLocalidad* list, int len);

/** \brief Se pasa como parametro el id de una localidad, la busca en el array y retorna su posicion en dicho array
 *
 * \param	eLocalidad* listL: lista de localidad para realizar la busqueda
 * \param	int lenL: tamaño de la lista de localidad
 * \param	int id: id de la localidad a buscar
 *
 * \return int: retorna -1 en caso de error o retorna la posicion en el array de la localidad pasada como parametro (id)
 *
 */
int EncontrarLocalidadPorId(eLocalidad* listL, int lenL,int id);

/** \brief  Buscar un lugar libre dentro del array de localidad (con en campo isEmpty en LIBRE)
 *
 * \param	eLocalidad* list: lista de localidad
 * \param	int len: tamaño de la lista de localidad
 *
 * \return int: Retorna un indice libre dentro del array o -1 en caso de error
 *
 */
int BuscarLibreaLocalidad(eLocalidad* list, int len);
