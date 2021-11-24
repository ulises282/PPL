#include "clientes.h"
#include "pedidos.h"
/** \brief Se muestra el menu de opciones para el usuario
 *
 * \return void
 *
 */
void menu(void);

/** \brief se ingresa el id de un cliente existente y la cantidad de kilos a recolectar, y se crea un pedido con id
 *  y estado PENDIENTE
 *
 * \param eClientes* list: puntero a array de clientes, para vincular el pedido nuevo a un cliente existente
 * \param int len: tamaño del array clientes
 * \param int id: id del cliente al que le generaremos un pedido
 * \param int ultimoIdPedidos: ultimo id utilizado en pedidos para calcular el proximo id a utilizar
 * \param ePedidos* listP: puntero a array de pedidos donde se almacenara el nuevo pedido
 * \param int lenP: tamaño del array de pedidos
 *
 * \return int: Retorna 0 si el pedido se cargo con exito o -1 si ocurrio algun error al cargar el nuevo pedido
 *
 */
int CrearPedido(eClientes* list,int len,int id,int ultimoIdPedidos,ePedidos* listP, int lenP);

/** \brief 	verifica que en la lista se encuentre al menos un pedido pendiente
 *
 * \param	ePedidos* listP: lista de pedidos para realizar la busqueda
 * \param	int lenP: tamaño de la lista de pedidos
 *
 * \return int: retorna 1 si hay al menos un pedido pendiente o 0 en caso contrario
 *
 */
int VerificarPedidosPendientes(ePedidos* listP,int lenP);

/** \brief	Muestra los pedidos en estado pendiente y la informacion del cliente
 *
 * \param	ePedidos* listP:	lista de pedidos para imprimir los datos
 * \param	int lenP:	tamaño de la lista de pedidos
 * \param	eClientes* list:	lista de clientes para imprimir los datos
 * \param	int len:	tamaño de la lista de clientes
 *
 * \return void
 *
 */
void MostrarPedidosPendientes(ePedidos* listP, int lenP,eClientes* list, int len);


/** \brief se muestra el cliente con la cantidad de pedidos pendientes que posee dicho cliente
 *
 * \param eClientes* list: Puntero al array clientes para obtener los datos a mostrar
 * \param int len: tamaño del array clientes
 * \param ePedidos* listP: puntero al array pedidos para obtener los datos a mostrar
 * \param int lenP: tamaño del array pedidos
 *
 * \return void
 *
 */
void MostrarClientesConPedidosPendientes(eClientes* list, int len,ePedidos* listP,int lenP,eLocalidad* listL,int lenL);

/** \brief se muestra los pedidos con estado pendiente y la informacion del cliente de dicho pedido
 *
 * \param ePedidos* listP: puntero al array pedidos para obtener los datos a mostrar
 * \param int lenP: tamaño del array pedidos
 * \param eClientes* list: puntero al array clientes para obtener los datos a mostrar
 * \param int len: tamaño del array clientes
 * \return void
 *
 */
void MostrarPedidosPendientesConClientes(ePedidos* listP, int lenP,eClientes* list,int len,eLocalidad* listL, int lenL);

/** \brief se muestra los pedidos con estado completado y la informacion del cliente de dicho pedido
 *
 * \param ePedidos* listP: puntero al array pedidos para obtener los datos a mostrar
 * \param int lenP: tamaño del array pedidos
 * \param eClientes* list: puntero al array clientes para obtener los datos a mostrar
 * \param int len: tamaño del array clientes
 * \return void
 *
 */
void MostrarPedidosProcesadosConClientes(ePedidos* listP, int lenP,eClientes* list,int len,eLocalidad* listL,int lenL);

/** \brief se ingresa una localidad e indica la cantidad de pedidos pendientes para dicha localidad.
 *
 * \param eClientes* list: puntero al array clientes para obtener los datos a mostrar
 * \param int len: tamaño del array clientes
 * \param ePedidos* listP: puntero al array pedidos para obtener los datos a mostrar
 * \param int lenP: tamaño del array pedidos
 * \param char* auxLocalidad: localidad para buscar los pedidos pendientes en dicha localidad
 * \return int: retorna 0 si encontro al menos 1 pedido pendiente en la localidad pasada como parametro, o -1 si
 * no encontro ningun pedido pendiente para dicha localidad
 *
 */
int pedidosPendientesLocalidad(eClientes* list,int len,ePedidos* listP,int lenP,char* auxLocalidad,eLocalidad* listL,int lenL);

/** \brief	Cuenta la cantidad maxima de pedidos que tiene un cliente, segun el estado cuenta los pedidos
 *  pendientes, completos, o ambos
 *
 * \param	eClientes* list: lista de clientes
 * \param	int len: tamaño de la lista de clientes
 * \param	ePedidos* listP: lista de pedidos
 * \param	int lenP: tamaño de la lista de clientes
 * \para	int estado: 1 para pedidos pendientes, 2 para pedidos completos
 *  o 3 para ambos pedidos(pendientes y completos)
 *
 * \return int	retorna el maximo de pedidos de una sola pesona, segun el estado puede ser pedidos pendientes, completos, o ambos
 *
 */
int ClienteConMasPedidos(eClientes* list,int len,ePedidos* listP,int lenP,int estado);

/** \brief	Mustra el cliente con mayores pedidos, (pendientes, completos, o ambos segun estado) y la cantidad de pedidos que posee
 *
 * \param	eClientes* list: lista de clientes
 * \param	int len: tamaño de la lista de clientes
 * \param	ePedidos* listP: lista de pedidos
 * \param	int lenP: tamaño de la lista de pedidos
 * \param	int estado: 1 para pedidos pendientes, 2 para pedidos completos
 *  o 3 para ambos pedidos(pendientes y completos)
 *
 * \return int	Retorna 0 en caso de exito o -1 en caso de error
 *
 */
int MostrarClienteConMasPedidos(eClientes* list,int len,ePedidos* listP,int lenP,int estado);
