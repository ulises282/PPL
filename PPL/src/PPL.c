/******************************************************************************
Gomez, Alejandro Ulises.
Primer Parcial De Laboratorio 1.
*******************************************************************************/
#include "nexo.h"
#define LIBRE 0
#define PENDIENTE 1
#define COMPLETADO 2
#define TAMCLIENTES 100
#define TAMPEDIDOS 1000
#define TAMLOCALIDAD 100

int main()
{
	setbuf(stdout,NULL);
    eClientes listaClientes[TAMCLIENTES];
    ePedidos listaPedidos[TAMPEDIDOS];
    eLocalidad listaLocalidad[TAMLOCALIDAD];
    char auxLocalidad[51];
    int opcion;
    int ultimoId;
    int ultimoIdPedidos;
    int contadorPedidos;
    int ultimoIDLocalidad;
    int auxId;
    int contador;
    ultimoIDLocalidad = 0;
    contadorPedidos = 0;
    ultimoIdPedidos = 0;
    ultimoId = 0;
    contador = 0;
    int aux;

    if(initClintes(listaClientes,TAMCLIENTES) == 0 && initPedidos(listaPedidos,TAMPEDIDOS) == 0 && initLocalidad(listaLocalidad,TAMLOCALIDAD)==0)
    {
        do{
            menu();
            if(IngresarNumero(&opcion,"Ingresar Opcion: ","ERROR, ",1,14,5)==0)
            {
                switch(opcion)
                {
                    case 1:
                        if(AltaCliente(listaClientes,TAMCLIENTES,ultimoId,listaLocalidad,TAMLOCALIDAD,ultimoIDLocalidad) == 0)
                        {
                            ultimoId++;
                            ultimoIDLocalidad++;
                            contador++;
                            printf("Cliente cargado con exito\n");
                        }
                        else
                        {
                            printf("Error al cargar nuevo cliente\n");
                        }
                    break;

                    case 2:
                        if(contador!=0)
                        {
                        	MostrarClientesConPedidosPendientes(listaClientes,TAMCLIENTES,listaPedidos,TAMPEDIDOS,listaLocalidad,TAMLOCALIDAD);
                            if(IngresarNumero(&auxId,"Ingrese el id del cliente a modificar: ","ERROR!!!",0,ultimoId,5)==0)
                            {
                                if(ModificarCliente(listaClientes,TAMCLIENTES,auxId,listaLocalidad,TAMLOCALIDAD)==0)
                                {
                                    printf("Modicacion exitosa\n");
                                }
                                else
                                {
                                    printf("Error al modificar cliente\n");
                                }
                            }
                            else
                            {
                                printf("Error al ingresar id del cliente\n");
                            }
                        }
                        else
                        {
                            printf("No hay clientes que modificar\n");
                        }
                    break;

                    case 3:
                        if(contador != 0)
                        {
                        	MostrarClientesConPedidosPendientes(listaClientes,TAMCLIENTES,listaPedidos,TAMPEDIDOS,listaLocalidad,TAMLOCALIDAD);
                            if(IngresarNumero(&auxId,"Ingrese el id del cliente a eliminar: ","ERROR!!!",0,ultimoId,5)==0)
                            {
                                if(EliminarClinete(listaClientes,TAMCLIENTES,auxId,listaLocalidad,TAMLOCALIDAD)==0)
                                {
                                    printf("cliente eliminado con exito\n");
                                    contador--;
                                }
                                else
                                {
                                    printf("Error al eliminar cliente\n");
                                }
                            }
                            else
                            {
                                printf("Error al ingresar id del cliente \n");
                            }
                        }
                        else
                        {
                            printf("Primero Ingrese un cliente\n");
                        }
                    break;

                    case 4:
                        if(contador != 0)
                        {
                        	MostrarClientesConPedidosPendientes(listaClientes,TAMCLIENTES,listaPedidos,TAMPEDIDOS,listaLocalidad,TAMLOCALIDAD);
                            if(IngresarNumero(&auxId,"Ingrese el id del cliente: ","ERROR!!!",0,ultimoId,5)==0)
                            {
                                if(CrearPedido(listaClientes,TAMCLIENTES,auxId,ultimoIdPedidos,listaPedidos,TAMPEDIDOS) == 0)
                                {
                                    printf("Pedido cargado con exito\n");
                                    ultimoIdPedidos++;
                                    contadorPedidos++;
                                }
                                else
                                {
                                    printf("Error al cargar pedido\n");
                                }
                            }
                            else
                            {
                                printf("Error al cargar pedido\n");
                            }
                        }
                        else
                        {
                        	printf("Primero Ingrese un cliente\n");
                        }
                    break;

                    case 5:
                        if(ComprobarPedidos(listaPedidos,TAMPEDIDOS,PENDIENTE)==0)
                        {
                            MostrarPedidosPendientes(listaPedidos,TAMPEDIDOS,listaClientes,TAMCLIENTES);
                            if(IngresarNumero(&auxId,"Ingrese el id del pedido: ","ERROR!!!",0,ultimoIdPedidos,5)==0)
                            {
                                if(ProcesarResiduos(listaPedidos,TAMPEDIDOS,auxId) == 0)
                                {
                                    printf("Pedido procesado con exito\n");
                                }
                                else
                                {
                                    printf("Error al procesar pedido\n");
                                }
                            }
                            else
                            {
                                printf("Error al procesar pedido\n");
                            }
                        }
                        else
                        {
                            printf("No se encontraron pedidos pendientes\n");
                        }
                    break;

                    case 6:
                        if(ComprobarPedidos(listaPedidos,TAMPEDIDOS,PENDIENTE)==0)
                        {
                            MostrarClientesConPedidosPendientes(listaClientes,TAMCLIENTES,listaPedidos,TAMPEDIDOS,listaLocalidad,TAMLOCALIDAD);
                        }
                        else
                        {
                            printf("No se encontraron pedidos pendientes\n");
                        }
                    break;

                    case 7:
                        if(ComprobarPedidos(listaPedidos,TAMPEDIDOS,PENDIENTE)==0)
                        {
                            MostrarPedidosPendientesConClientes(listaPedidos,TAMPEDIDOS,listaClientes,TAMCLIENTES,listaLocalidad,TAMLOCALIDAD);
                        }
                        else
                        {
                            printf("No se encontraron pedidos pendientes\n");
                        }
                    break;

                    case 8:
                        if(ComprobarPedidos(listaPedidos,TAMPEDIDOS,COMPLETADO)==0)
                        {
                            MostrarPedidosProcesadosConClientes(listaPedidos,TAMPEDIDOS,listaClientes,TAMCLIENTES,listaLocalidad,TAMLOCALIDAD);
                        }
                        else
                        {
                            printf("No se encontraron pedidos Procesados\n");
                        }
                    break;

                    case 9:
                        if(ComprobarPedidos(listaPedidos,TAMPEDIDOS,PENDIENTE)==0)
                        {
                            if(IngresarCadena(auxLocalidad,"Ingresar Localidad: ","ERROR, ",51)==0)
                            {
                                if(listaClientes!=NULL && listaPedidos!=NULL)
                                {
                                    aux = pedidosPendientesLocalidad(listaClientes,TAMCLIENTES,listaPedidos,TAMPEDIDOS,auxLocalidad,listaLocalidad,TAMLOCALIDAD);
                                    printf("La cantidad de pedidos para %s es de: %d",auxLocalidad,aux);
                                }
                            }
                            else
                            {
                                printf("error al ingresar localidad\n");
                            }
                        }
                        else
                        {
                            printf("No se encontraron pedidos pendientes\n");
                        }
                    break;

                    case 10:
                        if(ComprobarPedidos(listaPedidos,TAMPEDIDOS,COMPLETADO)==0)
                        {
                            PPReciclado(listaPedidos,TAMPEDIDOS);
                        }
                        else
                        {
                            printf("No se encontraron pedidos Procesados\n");
                        }
                    break;
                    case 11:
                        if(ComprobarPedidos(listaPedidos,TAMPEDIDOS,PENDIENTE)==0)
                        {
                        	printf("el cliente con mas pedidos pendientes es: ");
                            MostrarClienteConMasPedidos(listaClientes,TAMCLIENTES,listaPedidos,TAMPEDIDOS,PENDIENTE);
                        }
                        else
                        {
                            printf("No se encontraron pedidos Pendientes\n");
                        }
                    break;

                    case 12:
                        if(ComprobarPedidos(listaPedidos,TAMPEDIDOS,COMPLETADO)==0)
                        {
                        	printf("el cliente con mas pedidos completados es: ");
                            MostrarClienteConMasPedidos(listaClientes,TAMCLIENTES,listaPedidos,TAMPEDIDOS,COMPLETADO);
                        }
                        else
                        {
                            printf("No se encontraron pedidos procesados\n");
                        }
                    break;

                    case 13:
                        if(ComprobarPedidos(listaPedidos,TAMPEDIDOS,3)==0)
                        {
                        	printf("el cliente con mas pedidos es: ");
                            MostrarClienteConMasPedidos(listaClientes,TAMCLIENTES,listaPedidos,TAMPEDIDOS,3);
                        }
                        else
                        {
                            printf("No se encontraron pedidos\n");
                        }
                    break;

                    case 14:
                    break;
                }

            }
            else
            {
                opcion = 14;
            }
        }while(opcion != 14);
    }
    return 0;
}
