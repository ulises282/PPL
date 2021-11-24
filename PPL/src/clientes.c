#include "clientes.h"
/******************************************************************************/
int initClintes(eClientes* list, int len)
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
int BuscarLibreaCliente(eClientes* list, int len)
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
int CargarCliente(eClientes* list, int len,int id, char nombreDeLaEmpresa[],char cuit[],char direccion[],char localidad[], int index,eLocalidad* listL,int lenL,int ultimoIdLocalidad)
{
    int retorno;
    retorno = -1;
    int indexLocalidad;
    if(list!=NULL && listL!=NULL)
    {
        indexLocalidad = BuscarLibreaLocalidad(listL,lenL);
        if(index!=-1)
        {
            list[index].id = id;
            strcpy(list[index].nombreDeLaEmpresa, nombreDeLaEmpresa);
            strcpy(list[index].cuit, cuit);
            strcpy(list[index].direccion, direccion);
            strcpy(listL[indexLocalidad].localidad, localidad);
            list[index].isEmpty = OCUPADO;
            list[index].idLocalidad = ultimoIdLocalidad;
            listL[indexLocalidad].isEmpty = OCUPADO;
            listL[indexLocalidad].id = ultimoIdLocalidad;
            retorno = 0;
        }
    }
    return retorno;
}
/******************************************************************************/
int AltaCliente(eClientes* list, int len,int ultimoId,eLocalidad* listL,int lenL,int ultimoIdLocalidad)
{
    int retorno;
    retorno = -1;
    int index;
    char auxNombreDeLaEmpresa[128];
    char auxCuit[15];
    char auxDireccion[51];
    char auxLocalidad[51];

    if(list != NULL)
    {
        index = BuscarLibreaCliente(list,len);
        if(index!=-1)
        {
            if(IngresarCuit(auxCuit,"Ingresar CUIT: ","ERROR, ",5,15) == 0)
            {
                if(IngresarCadena(auxNombreDeLaEmpresa,"Ingresar nombre de la empresa: " , "ERROR, Reingrese nombre de la empresa: ",128) == 0)
                {
                    if(IngresarCadena(auxDireccion,"Ingresar Direccion: ","ERROR, Reingrese Direccion: ",51)==0)
                    {
                        if(IngresarCadena(auxLocalidad,"Ingresar Localidad: ","ERROR, Reingrese Localidad:",51)==0)
                        {
                            ultimoId++;
                            ultimoIdLocalidad++;
                            CargarCliente(list,len,ultimoId,auxNombreDeLaEmpresa,auxCuit,auxDireccion,auxLocalidad,index,listL,lenL,ultimoIdLocalidad);
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
int EncontrarClientePorId(eClientes* list,int len,int id)
{
    int retorno;
    retorno = -1;
    int i;
    if(list != NULL)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].id == id && list[i].isEmpty == OCUPADO)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
/******************************************************************************/
int ModificarCliente(eClientes* list,int len,int id,eLocalidad* listL,int lenL)
{
    int retorno;
    retorno = -1;
    char auxDireccion[51];
    char auxLocalidad[51];
    int index;
    int indexL;
    int idL;

    index = EncontrarClientePorId(list,len,id);
    idL = list[index].idLocalidad;
    indexL = EncontrarLocalidadPorId(listL,lenL,idL);
    if(index!=-1 && indexL!=-1)
    {
        if(IngresarCadena(auxDireccion,"Reingresar Direccion: ","ERROR, ",51)==0)
        {
            if(IngresarCadena(auxLocalidad,"Reingresar Localidad: ","ERROR, ",51)==0)
            {
                strcpy(list[index].direccion, auxDireccion);
                strcpy(listL[indexL].localidad, auxLocalidad);
                retorno = 0;
            }
        }
    }
    return retorno;
}
/******************************************************************************/
int EliminarClinete(eClientes* list,int len,int id,eLocalidad* listL,int lenL)
{
    int retorno;
    retorno = -1;
    int index;
    int indexL;
    int LocalidadUtilizada;
    index = EncontrarClientePorId(list,len,id);
    indexL = EncontrarLocalidadPorId(listL,lenL,list[index].idLocalidad);
    if(index != -1)
    {
        list[index].isEmpty = LIBRE;
        LocalidadUtilizada = CantidadDeClientesConLocalidad(list,len,list[index].idLocalidad);
        if(LocalidadUtilizada == 0)
        {
            listL[indexL].isEmpty = LIBRE;
        }
        retorno = 0;
    }
    return retorno;
}
/******************************************************************************/
int CantidadDeClientesConLocalidad(eClientes* list, int len,int id)
{
    int retorno;
    retorno = 0;
    int i;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty == OCUPADO && list[i].idLocalidad == id)
        {
            retorno++;
        }
    }
    return retorno;
}
/******************************************************************************/
