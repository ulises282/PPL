#include "pedidos.h"
#include "input.h"
/******************************************************************************/
int initPedidos(ePedidos* list, int len)
{
    int retorno;
    retorno = 0;
    if(list == NULL)
    {
        retorno = -1;
    }
    else
    {
        for(int i = 0;i<len;i++)
        {
            list[i].estado = LIBRE;
        }
    }
    return retorno;
}
/******************************************************************************/
int BuscarLibreaPedidos(ePedidos* list, int len)
{
    int i;
    int index;
    index = -1;
    for(i=0;i<len;i++)
    {
        if(list[i].estado == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
/******************************************************************************/
int ProcesarResiduos(ePedidos* listP, int lenP,int id)
{
    int retorno;
    retorno = -1;
    int index;
    int auxHdpe;
    int auxLdpe;
    int auxPp;
    if(listP != NULL)
    {
        index = EncontrarPedidoPorId(listP,lenP,id);
        if(index != -1)
        {
            if(IngresarNumero(&auxHdpe,"Ingresar la cantidad de polietileno de alta densidad a reciclar: ","Error, ",0,listP[index].kilos,5) == 0)
            {
                if(IngresarNumero(&auxLdpe,"Ingresar la cantidad de polietileno de baja densidad a reciclar: ","Error, ",0,listP[index].kilos,5)==0)
                {
                    if(IngresarNumero(&auxPp,"Ingresar la cantidad de polipropileno a reciclar: ","Error, ",0,listP[index].kilos,5)==0)
                    {
                        if((auxPp+auxLdpe+auxHdpe)<=listP[index].kilos)
                        {
                            listP[index].kilosReciclaje.hdpe = auxHdpe;
                            listP[index].kilosReciclaje.ldpe = auxLdpe;
                            listP[index].kilosReciclaje.pp = auxPp;
                            listP[index].estado = COMPLETADO;
                            retorno = 0;
                        }
                    }
                }
            }

        }
    }
    return retorno;
}
/******************************************************************************/
int EncontrarPedidoPorId(ePedidos* list,int len,int id)
{
    int retorno;
    retorno = -1;
    int i;
    if(list != NULL)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].id == id && list[i].estado == PENDIENTE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
/******************************************************************************/

int ComprobarPedidos(ePedidos* listP,int lenP,int estado)
{
    int retorno;
    retorno =-1;
    if(listP!=NULL)
    {
        for(int i=0;i<lenP;i++)
        {
            if(listP[i].estado == estado)
            {
                retorno = 0;
                break;
            }
            else
            {
            	if(estado == 3 && (listP[i].estado == estado+1 || listP[i].estado == estado-1))
            	{
            		retorno = 0;
            		break;
            	}
            }
        }
    }
    return retorno;
}
/******************************************************************************/
void PPReciclado(ePedidos* listP,int lenP)
{
    int acumuladorPP;
    acumuladorPP = 0;
    int contadorPP;
    contadorPP = 0;
    float promedio;
    if(listP!=NULL)
    {
        for(int i=0;i<lenP;i++)
        {
            if(listP[i].estado == COMPLETADO)
            {
                contadorPP++;
                acumuladorPP+=listP[i].kilosReciclaje.pp;
            }

        }
    }
    promedio = (float)acumuladorPP/contadorPP;
    printf("El promedio de polipropileno reciclado es: %.2f\n",promedio);
}

int ContarPedidos(ePedidos* listP,int lenP,int id, int estado)
{
    int retorno;
    retorno = 0;
    if(listP!=NULL)
    {
        for(int i=0;i<lenP;i++)
        {
        	if(listP[i].idCliente == id)
        	{
        		if(listP[i].estado == estado)
        		{
        			retorno++;
        		}
        		else
        		{
        			if(estado == 3 && (listP[i].estado == COMPLETADO || listP[i].estado == PENDIENTE))
        			{
        				retorno++;
        			}
        		}
        	}
        }
    }
    return retorno;
}
