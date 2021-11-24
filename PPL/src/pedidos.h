#define LIBRE 0
#define PENDIENTE 1
#define COMPLETADO 2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct
{
    float hdpe;
    float ldpe;
    float pp;
}ePlasticos;

typedef struct
{
    int id;//PK
    int idCliente;//FK
    float kilos;
    int estado;
    ePlasticos kilosReciclaje;
}ePedidos;

/** \brief Inicializa el array de pedidos cambiando el campo estado en LIBRE
 *
 * \param ePedidos* list: puntero al array a inicializar
 * \param int len: tamaño del puntero al array a inicializar
 * \return int: retorna 0 en caso de inicializacion correcta o -1 en caso de error
 *
 */
int initPedidos(ePedidos* list, int len);

/** \brief Busca en el array un elemento con el campo estado en LIBRE
 *
 * \param ePedidos* list: puntero al array donde se buscara
 * \param int len: tamaño del puntero al array donde se buscara
 * \return int: retorna la posicion en el array que ocupa el elemento deseado
 *
 */
int BuscarLibreaPedidos(ePedidos* list, int len);

/** \brief  Se pide ingresar el id de un pedido con estaso PENDIENTE para procesarlo
 * tambien se pide la cantidad de kilos reciclados de los 3 diferentes tipos de plastico y se cambia su estado a COMPLETADO
 *
 * \param ePedidos* listP: puntero al array donde se guardarán los datos
 * \param int lenP: tamaño del array donde se guardarán los datos
 * \param int id: id del pedido a procesar
 * \return int: Retorna 0 en caso de proceso exitoso o -1 en caso de error
 *
 */
int ProcesarResiduos(ePedidos* listP, int lenP,int id);

/** \brief  Encuentra la posicion en el array que ocupa el pedido con el id pasado como paramertro
 *
 * \param ePedidos* list: puntero al array donde se realizará la busqueda
 * \param int len: tamaño del array donde se realizará la busqueda
 * \param int id: id del pedido que queremos su posicion en el array
 * \return int: retorna la posicion que ocupa el pedido en el array en caso de encontrarlo o -1 en caso de
 * error o no encontrar dicho pedido
 *
 */
int EncontrarPedidoPorId(ePedidos* list,int len,int id);

/** \brief Comprueba que haya al menos un pedido con estado PENDIENTE en el array
 *
 * \param ePedidos* listP: puntero al array donde se realizará la busqueda
 * \param int lenP: tamaño del array donde se realizará la busqueda
 * \return int: Retorna 0 en caso de haber al menos un pedido PENDIENTE o -1 en caso de error o de no haber ningun
 * pedido PENDIENTE
 *
 */
int ComprobarPedidos(ePedidos* listP,int lenP,int estado);

/** \brief Calcula y mustra el promedio de polipropileno reciclado entre todos los pedidos procesados
 *
 * \param ePedidos* listP: puntero al array donde se obtienen los datos
 * \param int lenP: tamaño del array donde se obtienen los datos
 * \return void
 *
 */
void PPReciclado(ePedidos* listP,int lenP);

/** \brief	Cuenta la cantidad de pedidos (pendientes, completos, o ambos segun el estado) de un cliente
 * pasado como parametro (id)
 *
 * \param	ePedidos* listP: Lista de los pedidos para hacer la busqueda
 * \param	int lenP: tamaño de la lista de pedidos
 * \param	int id: id del cliente el cual queremos saber el numero de sus pedidos
 * \param	int estado: 1 para saber la cantidad de pedidos pendientes, 2 para saber los pedidos completos
 *  o 3 para saber la cantidad de pedidos(pendientes y completos)
 *
 * \return	int: Retorna la cantidad de pedidos que tiene el cliente pasado como parametro o 0 en caso de
 * que no tenga ningun pedido o puntero nulo.
 *
 */
int ContarPedidos(ePedidos* listP,int lenP,int id, int estado);
