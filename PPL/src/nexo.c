#include "nexo.h"
void menu(void)
{
    printf("\t\t\tMENU\n");
    printf("==============================================================\n");
    printf("\t1)Alta de clientes\n\t2)Modificar datos de cliente\n\t3)Baja de cliente\n\t"
    "4)Crear pedido de recoleccion\n\t5)procesar residuos\n\t6)Imprimir clientes\n\t"
    "7)Imprimir pedidos pendientes\n\t8)Imprimir pedidos procesados\n\t9)Pedidos pendientes por localidad\n\t"
    "10)Promedio de polipropileno reciclado\n\t11)Cliente con mas pedidos pendientes\n\t"
    "12)cliente con mas pedidos completados\n\t13)Cliente con mas pedidos\n\t14)Salir\n");
    printf("==============================================================\n");
}
/******************************************************************************/
int CrearPedido(eClientes* list,int len,int id,int ultimoIdPedidos,ePedidos* listP, int lenP)
{
    int retorno;
    retorno = -1;
    int index;
    int indexP;
    int auxKilos;
    index = EncontrarClientePorId(list,len,id);
    if(list!=NULL && index!=-1)
    {
        indexP = BuscarLibreaPedidos(listP,lenP);
        if(indexP!=-1)
        {
            if(IngresarNumero(&auxKilos,"Ingrese la cantidad de kilos a recolectar: ","Error, ",0,10000,5)==0)
            {
                ultimoIdPedidos++;
                retorno = 0;
                listP[indexP].id = ultimoIdPedidos;
                listP[indexP].idCliente = id;
                listP[indexP].kilos = auxKilos;
                listP[indexP].estado = PENDIENTE;
            }
        }
    }
    return retorno;
}
/******************************************************************************/
int VerificarPedidosPendientes(ePedidos* listP,int lenP)
{
    int i;
    int retorno;
    retorno = 0;
    for(i=0;i<lenP;i++)
    {
        if(listP[i].estado == PENDIENTE)
        {
            retorno = 1;
            break;
        }
    }
    return retorno;
}
/******************************************************************************/
void MostrarPedidosPendientes(ePedidos* listP, int lenP,eClientes* list, int len)
{
    if(listP!= NULL)
    {
    	int index;
        printf("\t\t\t\t\t\tPEDIDOS\n");
        printf("============================================================================================\n");
        printf("%-4s %-25s %-15s %-20s\n","ID","Cliente","Kilos totales","Estado");
        printf("============================================================================================\n");
        for(int i=0;i<lenP;i++)
        {
            if(listP[i].estado == PENDIENTE)
            {
            	index = EncontrarClientePorId(list,len,listP[i].idCliente);
                printf("%-4d %-25s %-15.2f %-20s\n",listP[i].id,list[index].nombreDeLaEmpresa,listP[i].kilos,"PENDIENTE");
            }
        }
        printf("============================================================================================\n");
    }
}
/******************************************************************************/
void MostrarClientesConPedidosPendientes(eClientes* list, int len,ePedidos* listP,int lenP,eLocalidad* listL,int lenL)
{
    int contadorPedidosPendientes;
    int indexL;
    if(list!= NULL)
    {
    	int i;
        printf("\t\t\t\t\t\tCLIENTES\n");
        printf("====================================================================================================================\n");
        printf("%-4s %-25s %-20s %-20s %-20s %-15s \n","ID","Nombre de la empresa","Cuit","Direccion","Pedidos pendientes","Localidad");
        printf("====================================================================================================================\n");
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty == OCUPADO)
            {
                indexL = EncontrarLocalidadPorId(listL,lenL,list[i].idLocalidad);
                contadorPedidosPendientes = ContarPedidos(listP,lenP,list[i].id,PENDIENTE);
                printf("%-4d %-25s %-20s %-20s %-20d %-15s\n",list[i].id,list[i].nombreDeLaEmpresa,list[i].cuit,list[i].direccion,contadorPedidosPendientes,listL[indexL].localidad);
            }
        }
        printf("====================================================================================================================\n");
    }
}
/******************************************************************************/
void MostrarPedidosPendientesConClientes(ePedidos* listP, int lenP,eClientes* list,int len,eLocalidad* listL, int lenL)
{
    if(list!= NULL)
    {
        int index;
        printf("\t\t\t\t\t\tPEDIDOS\n");
        printf("=======================================================================================================================\n");
        printf("%-4s %-15s %-20s %-20s %-20s %-20s %-20s\n","ID","Kilos totales","Estado","ID Cliente","Nombre Empresa","Cuit cliente","direccion");
        printf("=======================================================================================================================\n");
        for(int i=0;i<lenP;i++)
        {
            if(listP[i].estado == PENDIENTE)
            {
                index = EncontrarClientePorId(list,len,listP[i].idCliente);
                printf("%-4d %-15.2f %-20s %-20d %-20s %-20s %-20s\n",listP[i].id,listP[i].kilos,"PENDIENTE",list[index].id,list[index].nombreDeLaEmpresa,list[index].cuit,list[index].direccion);
            }
        }
        printf("\n=======================================================================================================================\n");
    }
}
/******************************************************************************/
void MostrarPedidosProcesadosConClientes(ePedidos* listP, int lenP,eClientes* list,int len,eLocalidad* listL,int lenL)
{
    if(list!= NULL)
    {
        int index;
        printf("\t\t\t\t\t\tPEDIDOS COMPLETADOS\n");
        printf("========================================================================================================================================\n");
        printf("%-20s %-20s %-20s %-20s %-20s %-20s %-20s\n ","HDPE reciclado","LDPE reciclado","PP reciclado","ID Cliente","Nombre Empresa","Cuit cliente","direccion");
        printf("========================================================================================================================================\n");
        for(int i=0;i<lenP;i++)
        {
        	if(listP[i].estado == COMPLETADO)
        	{
				index = EncontrarClientePorId(list,len,listP[i].idCliente);
				printf("%-20.2f %-20.2f %-20.2f %-20d %-20s %-20s %-20s\n",listP[i].kilosReciclaje.hdpe,listP[i].kilosReciclaje.ldpe,listP[i].kilosReciclaje.pp,list[index].id,list[index].nombreDeLaEmpresa,list[index].cuit,list[index].direccion);
        	}
        }
        printf("\n========================================================================================================================================\n");
    }
}
/******************************************************************************/
int pedidosPendientesLocalidad(eClientes* list,int len,ePedidos* listP,int lenP,char* auxLocalidad,eLocalidad* listL,int lenL)
{
    int retorno;
    retorno = 0;
    int index;
    int indexL;
    for(int i=0;i<lenP;i++)
    {
        if(listP[i].estado == PENDIENTE)
        {
            index = EncontrarClientePorId(list,len,listP[i].idCliente);
            indexL = EncontrarLocalidadPorId(listL,lenL,list[index].idLocalidad);
            if(strcmp(auxLocalidad,listL[indexL].localidad) == 0)
            {
                retorno++;
            }
        }
    }
    return retorno;
}
/******************************************************************************/
int ClienteConMasPedidos(eClientes* list,int len,ePedidos* listP,int lenP,int estado)
{
    int i;
    int contador;
    int maximoDePedidos;
    maximoDePedidos = 0;
    if(list!=NULL && listP!=NULL)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty == OCUPADO)
            {
                contador = ContarPedidos(listP,lenP,list[i].id,estado);
            }
            if(maximoDePedidos<contador)
            {
                maximoDePedidos = contador;
            }
        }
    }
    return maximoDePedidos;
}

int MostrarClienteConMasPedidos(eClientes* list,int len,ePedidos* listP,int lenP,int estado)
{
    int maximo;
    int retorno;
    retorno = -1;
    int i;
    int contador;
    maximo = ClienteConMasPedidos(list,len,listP,lenP,estado);
    if(maximo!=0)
    {
        for(i=0;i<len;i++)
        {
        	if(list[i].isEmpty == OCUPADO)
        	{
				contador = ContarPedidos(listP,lenP,list[i].id,estado);
				if(contador == maximo)
				{
					printf("%s\t",list[i].nombreDeLaEmpresa);
					retorno = 0;
				}
        	}
        }
        printf("con: %d pedidos.\n",maximo);
    }
    return retorno;
}
