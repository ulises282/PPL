#define LIBRE 0
#define OCUPADO 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "input.h"
#include "localidad.h"
typedef struct{
    int id;//PK
    char nombreDeLaEmpresa[51];
    char cuit[15];
    char direccion[51];
    int idLocalidad;//FK
    int isEmpty;
}eClientes;


/** \brief  Inicializa el array de clientes cambiando el valor del campo isEmpty a LIBRE
 *
 * \param eClientes* list: puntero al array a inicializar
 * \param int len: tamaño del array a inicializar
 *
 * \return int: retorna 0 si inicializo el array con exito o -1 si hubo algun error
 *
 */
int initClintes(eClientes* list, int len);

/** \brief Busca en el array un elemento con el campo isEmpty en LIBRE
 *
 * \param eClientes* list: puntero al array donde se buscara
 * \param int len: tamaño del array
 *
 * \return int: retorna la posicion en el array que ocupa el elemento deseado
 *
 */
int BuscarLibreaCliente(eClientes* list, int len);

/** \brief Recibe los datos para crear un nuevo cliente en el array
 *
 * \param eClientes* list: array en donde se cargaran los datos
 * \param int len: tamaño del array en donde se cargaran los datos
 * \param int id: el id que recibirá el nuevo cliente
 * \param char nombreDeLaEmpresa[]: el nombre de la empresa que recibirá el nuevo cliente
 * \param char cuit[]: el cuit que recibirá el nuevo cliente
 * \param char direccion[]:la deireccion que recibirá el nuevo cliente
 * \param char localidad[]: la localidad que recibirá el nuevo cliente
 * \param int index: la posicion el el array en donde se guardará el nuevo cliente
 *
 * \return int: retorna 0 en caso de carga exitosa o -1 en caso de error al cargar en el array
 *
 */
int CargarCliente(eClientes* list, int len,int id, char nombreDeLaEmpresa[],char cuit[],char direccion[],char localidad[], int index,eLocalidad* listL,int lenL,int ultimoIdLocalidad);
/** \brief Pide los datos para crear un nuevo cliente, y posteriormente llama a la funcion CargarCliente() para cargarlo en el array
 *
 * \param eClientes* list: array en donde se cargaran los datos
 * \param int len: tamaño del array donde se cargaran los datos
 * \param int id: ultimo id que se utilizo para calcular el siguiente a utilizar
 *
 * \return int: retorna 0 en caso de que valores ingresados sean correctos o -1 en caso de error al cargar los valores para el nuevo cliente
 *
 */
int AltaCliente(eClientes* list, int len,int ultimoId,eLocalidad* listL,int lenL,int ultimoIdLocalidad);

/** \brief  Se pide ingresar un id y se busca la posicion en el array que ocupa el cliente con ese id
 *
 * \param eClientes* list: array donde se buscará el cliente
 * \param int len: tamaño del array donde se buscará el cliente
 * \param int id: id del cliente del que queremos su posicion en el array 1
 *
 * \return int: retorna la posicion en el array que ocupa el cliente con el id pasado como parametro en caso de ser correcto o -1 en caso de error
 *
 */
int EncontrarClientePorId(eClientes* list,int len,int id);

/** \brief  Se pide ingresar id de un clinte para modificar su direccion y localidad
 *
 * \param eClientes* list: array donde se modificará al cliente
 * \param int len: tamaño del array donde se modificará al cliente
 * \param int id: id del cliente a modificar
 *
 * \return int:Retorna 0 si se modifico correctamente o -1 en caso de error
 *
 */
int ModificarCliente(eClientes* list,int len,int id,eLocalidad* listL,int lenL);

/** \brief Se pide ingresar id de un cliente para eliminarlo de forma logica cambiando el valor del campo isEmpty a LIBRE
 *
 * \param eClientes* list: array donde se eliminará al cliente
 * \param int len: tamñao del array donde se eliminará al cliente
 * \param int id: id del cliente a eliminar
 *
 * \return int: Retorna 0 en caso de eliminarlo exitosamente o -1 en caso de error
 *
 */
int EliminarClinete(eClientes* list,int len,int id,eLocalidad* listL,int lenL);

/** \brief Se pasa como parametro el id de una localidad para contar cuantos clientes hay en dicha localidad
 *
 * \param	eClientes* list:	lista de clientes
 * \param	int len:	tamaño de la lista de clientes
 * \param 	int id: id de la localidad a buscar
 *
 * \return int:  retorna 0 en caso de ningun cliente en esa localidad o la cantidad de clientes en dicha localidad.
 *
 */
int CantidadDeClientesConLocalidad(eClientes* list, int len,int id);
