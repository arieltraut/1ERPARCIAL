#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contrataciones.h"
#include "validar.h"

/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flagEstado un 0.
 *
 * \param sContrataciones arrayContratacion[] Puntero al array de .....
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int contra_init(sContrataciones arrayContratacion[], int len)
{
    int i;
    int retorno = -1;
    if (arrayContratacion != NULL && len >0)
    {
        for(i=0;i<len;i++)
        {
            arrayContratacion[i].flagOcupado = 0;
        }
        retorno = 0;
    }
    return retorno;
}

static int ultimoValorIdAutoincrementable = -1;

/** \brief  Busca en el array el id mas alto entre los usados y los borrados
 * \param sContrataciones arrayContratacion[] Puntero al array de ...........
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (proximo ID) si Ok
 *
 */
int contra_generarProximoId(sContrataciones arrayContratacion[], int len)
{
    ultimoValorIdAutoincrementable++;
    return ultimoValorIdAutoincrementable;
}


/** \brief  Busca en el array la primer posicion libre
 * \param sContrataciones arrayContratacion[] Puntero al array de abonados
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (index del lugar libre) si Ok
 *
 */
int contra_buscarPosicionLibre(sContrataciones arrayContratacion[], int len)
{
    int i;
    int retorno = -1;
    if(arrayContratacion != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(arrayContratacion[i].flagOcupado == 0)
            {
                retorno =  i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Pide al usuario los datos de un nuevo ...... y luego lo agrega al array
 * \param Entidad1 array[] Puntero al array de ........
 * \param sContrataciones arrayContratacion[] Puntero al array de ........
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int contra_alta(sPantalla arrayPantalla[],sContrataciones arrayContratacion[], int lenPantalla, int lenContratacion)
{
    int retorno = -1;
    char bNombreArchivo[51];
    char bCuit[51];
    char diasPublicacion[100];
    int idNuevo;
    char bIdPantalla[100];
    int indexVacio = contra_buscarPosicionLibre(arrayContratacion,lenContratacion);

    if (arrayContratacion != NULL && indexVacio >=0 && indexVacio < lenContratacion)
    {
        if(val_getUnsignedInt(bIdPantalla,"\nElija pantalla a contratar ingresando su ID\n","\nSolo numeros:\n",2,100)==0)
        {
            int index = pantalla_buscarIndicePorId(arrayPantalla,lenPantalla,atoi(bIdPantalla));
            if (index != -1)
            {
                if (val_getUnsignedInt(diasPublicacion,"\nIngrese dias que dura la publicacion\n","\nValor invalido\n",2,51)==0)    //"\nMotivo:\n  INFARTO [0]\n  ACV [1]\n  GRIPE [2]\n Opcion:"
                {

                   if (val_getUnsignedInt(bCuit,"\nIngrese CUIT\n","\nValor invalido\n",2,12)==0)
                   {

                        if (val_getAlfanumerico(bNombreArchivo,"\nIngrese nombre archivo de video\n", "Nombre invalido",2,51)==0)
                        {
                            idNuevo = contra_generarProximoId(arrayContratacion,lenContratacion);

                            strncpy(arrayContratacion[indexVacio].cuit,bCuit,51);
                            strncpy(arrayContratacion[indexVacio].nombreArchivoVideo,bNombreArchivo,51);
                            arrayContratacion[indexVacio].diasPublicacion = atoi(diasPublicacion);
                            arrayContratacion[indexVacio].idPantalla = atoi(bIdPantalla);
                            arrayContratacion[indexVacio].id = idNuevo;
                            arrayContratacion[indexVacio].estado = ESTADO_PENDIENTE;
                            arrayContratacion[indexVacio].flagOcupado = 1;
                            retorno = 0;
                        }
                   }
                }
            }
            else
            {
                printf("El ID de pantalla elegido no existe\n");
                system("pause");
            }
        }
    }
    return retorno;
}
/*
int contra_modificar(sContrataciones arrayContratacion[], int len)
{
    int retorno = -1;
    char bufferId[51];

    val_getUnsignedInt(bufferId,"\nIngrese CUIT cliente\n","\nIngrese solo numeros\n",2,40);

    int index = pantalla_buscarIndicePorId(arrayPantalla,len,atoi(bufferId));
    int index = pantalla_buscarIndicePorId(arrayPantalla,len,atoi(bufferId));

    if (index != -1)
    {
*/

/** \brief Busca en la lista un ...... que coincida con el Id recibido
 *
 * \param sContrataciones arrayContratacion[] Puntero al array de .....
 * \param len int Longitud del array
 * \param id int ID del .....
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin no se encontro el ......] - (0) si Ok
 *
 */
int contra_buscarIndicePorId(sContrataciones arrayContratacion[],int len,int id)
{
    int i;
    int retorno = -1;
    for(i=0;i<len;i++)
        {
            if(arrayContratacion[i].flagOcupado == 1)
            {
                if(arrayContratacion[i].id == id)        //(strcmp(array[i].a, array[i].dni) == 0)
                {
                    retorno = i;
                    break;
                }
            }
        }
    return retorno;
}


int contra_fin(sContrataciones arrayContratacion[], int len)
{
    int retorno = -1;
    char bufferId[100];
    char bufferTiempo[100];
    char bufferEstado[2];


    if (arrayContratacion != NULL && len >=0)
    {
        if(val_getUnsignedInt(bufferId,"\nIngrese ID del caso a cerrar \n","\nSolo numeros:\n",2,100)==0);
        {
            int index = contra_buscarIndicePorId(arrayContratacion,len,atoi(bufferId));
            if (index == -1)
            {
                printf("El ID elegido no existe\n");
                system("pause");

            }
            else if (arrayContratacion[index].estado != ESTADO_PENDIENTE)
            {
                printf("Caso cumplido, Solo se pueden cerrar casos pendientes\n");
                system("pause");
            }
            else
            {
                if (val_getUnsignedInt(bufferTiempo,"\nIngrese tiempo insumido\n","\nSolo numeros:\n",2,100)==0)
                {
                    if (val_getUnsignedInt(bufferEstado,"\nEstado de Cierre:\n  Resuelto [1]\n  No Resuelto [2]\n\n Opcion: ","\nRango valido 1-2",2,2)==0)
                       {
                                arrayContratacion[index].diasPublicacion = atoi(bufferTiempo);
                                arrayContratacion[index].estado = atoi(bufferEstado);
                                retorno = 0;
                       }
                }
            }
        }
    }
    return retorno;
}


/*void contra_printArray(sContrataciones arrayContratacion[] , int len,int cuit)
{
    int i;
    for (i=0;i<len;i++)
    {
        if(arrayContratacion[i].flagOcupado == 1)
        {



            if(arrayContratacion[i].cuit == cuit)
            {
                printf("ID: %d, Tipo: %d, Nombre: %s, precio: %.2f\n\n\n",arrayContratacion[i].id,arrayContratacion[i].tipoPantalla,arrayContratacion[i].nombre,arrayContratacion[i].precio);
            }
        }
    }
}
*/
