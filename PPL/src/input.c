#include "input.h"
/******************************************************************************/
int IngresarNumero(int* pResultado, char* mensaje, char* mensajeError,
    int minimo, int maximo, int reintentos)
{
    int retorno;
    int numero;

    while(reintentos>0)
    {
        printf("%s",mensaje);
        if (getInt(&numero) == 0)
        {
            if(numero<=maximo && numero >= minimo)
            {
                *pResultado = numero;
                retorno = 0;
                break;
            }
        }
        reintentos --;
        printf("%s",mensajeError);
    }
    if(reintentos == 0)
    {
        retorno = -1;
    }
    return retorno;
}
/******************************************************************************/
int getInt(int* pResultado)
{
    int retorno = -1;
    char buffer[64];
    if(pResultado!=NULL)
    {
        if(myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer))
        {
            *pResultado = atoi(buffer);
        retorno = 0;
        }
    }
    return retorno;
}
/******************************************************************************/
int esNumerica(char* cadena)
{
    int i = 0;
    int retorno = 1;
    if (cadena != NULL && strlen(cadena)>0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena[i] < '0' || cadena[i]> '9')
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}
/******************************************************************************/
int myGets(char* cadena, int longitud)
{
	int retorno;
	retorno = -1;
    if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
    {
        fflush(stdin); // LINUX-> __fpurge o WIN-> fflush o MAC-> fpurge
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
        }
        retorno = 0;
    }
    return retorno;
}
/******************************************************************************/
int IngresarFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo,
    float maximo, int reintentos)
{
    int retorno;
    float numero;
    while(reintentos>0)
    {
        printf("%s",mensaje);
        if (getFloat(&numero) == 0)
        {
            if(numero<=maximo && numero >= minimo)
            {
                *pResultado = numero;
                retorno = 0;
                break;
            }
        }
        reintentos --;
        printf("%s",mensajeError);
    }
    if(reintentos == 0)
    {
        retorno = -1;
    }
    else
    {
        retorno = 0;
        *pResultado = numero;
    }
    return retorno;
}
/******************************************************************************/
int getFloat(float* pResultado)
{
    int retorno = -1;
    char buffer[64];
    if(pResultado!=NULL)
    {
        if(myGets(buffer, sizeof(buffer)) == 0 && esFlotante(buffer))
        {

            *pResultado = atof(buffer);
            retorno = 0;
        }
    }
    return retorno;
}
/******************************************************************************/
int esFlotante(char* cadena)
{
    int i = 0;
    int retorno = 1;
    if (cadena != NULL && strlen(cadena)>0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena[i] != '.' && (cadena[i] < '0' || cadena[i]> '9'))
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}
/******************************************************************************/
int IngresarCadena(char* pResultado, char* mensaje, char* mensajeError, int tam)
{
    int retorno;
    retorno = -1;
    char cadena[tam];
    printf("%s",mensaje);
    while(retorno!=0)
    {
        if (myGets(cadena,tam)==0)
        {
        	if(esAlfabetico(cadena,tam)==0)
        	{
        		TransformarCadena(cadena,strlen(cadena));
				strcpy(pResultado,cadena);
				retorno = 0;
				break;
        	}
        }
        printf("%s",mensajeError);
    }
    return retorno;
}
/******************************************************************************/
int esAlfabetico (char* cadena,int tam)
{
    int retorno;
    retorno = -1;
    if(cadena!=NULL)
    {
    	retorno = 0;
    	for(int i=0;i<strlen(cadena);i++)
		{
			if(isalpha(cadena[i])==0)
			{
				retorno = -1;
				break;
			}
		}
    }
    return retorno;
}
/******************************************************************************/
int TransformarCadena(char* cadena,int len)
{
    int retorno;
    retorno = -1;
    int i;
    if(cadena != NULL)
    {
        cadena[0] = toupper(cadena[0]);
        for(i=1;i<len-1;i++)
        {
            cadena[i] = tolower(cadena[i]);
        }
        retorno = 0;
    }
    return retorno;
}
/******************************************************************************/
int IngresarCuit(char* pResultado, char* mensaje, char* mensajeError,int reintentos, int tam)
{
    int retorno;
    char cadena[tam];
    while(reintentos>0)
    {
        printf("%s",mensaje);
        if (GetCuit(cadena,tam,mensaje)==0)
        {
            strcpy(pResultado,cadena);
            retorno = 0;
            break;
        }
        reintentos --;
        printf("%s",mensajeError);
    }
    if(reintentos == 0)
    {
        retorno = -1;
    }
    return retorno;
}
/******************************************************************************/

int GetCuit(char pResultado[], int tam,char* mensaje)
{
    int retorno = -1;
    char cadena[tam];
    fflush(stdin);
    fgets(cadena, tam, stdin);
    if(strlen(cadena)==12)
    {
        if(esNumerica(cadena) == 0)
        {
        	cadena[13] = '\0';
            cadena[12] = cadena[10];
            cadena[11] = '-';
            for(int i=10;i>2;i--)
            {
                cadena[i] = cadena[i-1];
            }
            cadena[2] = '-';
            strcpy(pResultado,cadena);
            retorno = 0;
        }
    }
    return retorno;
}
