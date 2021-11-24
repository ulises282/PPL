#include "localidad.h"
/******************************************************************************/
int initLocalidad(eLocalidad* list, int len)
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
            list[i].isEmpty = LIBRE;
        }
    }
    return retorno;
}
/******************************************************************************/
int EncontrarLocalidadPorId(eLocalidad* listL, int lenL,int id)
{
    int retorno;
    retorno = -1;
    int i;
    if(listL != NULL)
    {
        for(i=0;i<lenL;i++)
        {
            if(listL[i].id == id && listL[i].isEmpty == OCUPADO)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
/******************************************************************************/
int BuscarLibreaLocalidad(eLocalidad* list, int len)
{
    int i;
    int index;
    index = -1;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
/******************************************************************************/
