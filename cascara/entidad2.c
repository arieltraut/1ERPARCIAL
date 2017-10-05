#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entidad2.h"
#include "validar.h"

/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flagEstado un 0.
 *
 * \param Entidad2 array[] Puntero al array de .....
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int ent2_init(Entidad2 array[], int len)
{
    int i;
    int retorno = -1;
    if (array != NULL && len >0)
    {
        for(i=0;i<len;i++)
        {
            array[i].flagOcupado = 0;
        }
        retorno = 0;
    }
    return retorno;
}

static int ultimoValorIdAutoincrementable = -1;

/** \brief  Busca en el array el id mas alto entre los usados y los borrados
 * \param Entidad2 array[] Puntero al array de ...........
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (proximo ID) si Ok
 *
 */
int ent2_generarProximoId(Entidad2 array[], int len)
{
    ultimoValorIdAutoincrementable++;
    return ultimoValorIdAutoincrementable;
}


/** \brief  Busca en el array la primer posicion libre
 * \param Entidad2 array[] Puntero al array de abonados
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (index del lugar libre) si Ok
 *
 */
int ent2_buscarPosicionLibre(Entidad2 array[], int len)
{
    int i;
    int retorno = -1;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(array[i].flagOcupado == 0)
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
 * \param Entidad2 array[] Puntero al array de ........
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int ent2_alta(Entidad1 array1[],Entidad2 array[], int lenEntidad1, int lenEntidad2)
{
    int retorno = -1;
    char bMotivo[51];
    char bOtros[51];
    int idNuevo;
    char b_idEnt1[100];
    int indexVacio = ent2_buscarPosicionLibre(array,lenEntidad2);

    if (array != NULL && indexVacio >=0 && indexVacio < lenEntidad2)
    {
        if(val_getUnsignedInt(b_idEnt1,"\nIngrese ID entidad1 \n","\nSolo numeros:\n",2,100)==0)
        {
            int index = ent1_buscarIndicePorId(array1,lenEntidad1,atoi(b_idEnt1));
            if (index != -1)
            {
                if (val_getUnsignedInt(bMotivo,"\nMotivo:\n  INFARTO [0]\n  ACV [1]\n  GRIPE [2]\n Opcion:","\nMotivo invalido\n",2,51)==0)
                {

                   if (val_getNombre(bOtros, "\nIngrese ..........\n", "\n............ invalido\n",3,50)==0)
                   {
                            idNuevo = ent2_generarProximoId(array,lenEntidad2);

                            strncpy(array[indexVacio].otros,bOtros,51);
                            array[indexVacio].motivo = atoi(bMotivo);
                            array[indexVacio].idEntidad1 = atoi(b_idEnt1);
                            array[indexVacio].id = idNuevo;
                            array[indexVacio].estado = ESTADO_PENDIENTE;
                            array[indexVacio].flagOcupado = 1;
                            retorno = 0;
                   }
                }
            }
            else
            {
                printf("El ID elegido no existe\n");
                system("pause");
            }
        }
    }
    return retorno;
}

/** \brief Busca en la lista un ...... que coincida con el Id recibido
 *
 * \param Entidad2 array[] Puntero al array de .....
 * \param len int Longitud del array
 * \param id int ID del .....
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin no se encontro el ......] - (0) si Ok
 *
 */
int ent2_buscarIndicePorId(Entidad2 array[],int len,int id)
{
    int i;
    int retorno = -1;
    for(i=0;i<len;i++)
        {
            if(array[i].flagOcupado == 1)
            {
                if(array[i].id == id)        //(strcmp(array[i].a, array[i].dni) == 0)
                {
                    retorno = i;
                    break;
                }
            }
        }
    return retorno;
}


int ent2_fin(Entidad2 array[], int len)
{
    int retorno = -1;
    char bufferId[100];
    char bufferTiempo[100];
    char bufferEstado[2];


    if (array != NULL && len >=0)
    {
        if(val_getUnsignedInt(bufferId,"\nIngrese ID del caso a cerrar \n","\nSolo numeros:\n",2,100)==0);
        {
            int index = ent2_buscarIndicePorId(array,len,atoi(bufferId));
            if (index == -1)
            {
                printf("El ID elegido no existe\n");
                system("pause");

            }
            else if (array[index].estado != ESTADO_PENDIENTE)
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
                                array[index].tiempoInsumido = atoi(bufferTiempo);
                                array[index].estado = atoi(bufferEstado);
                                retorno = 0;
                       }
                }
            }
        }
    }
    return retorno;
}


void ent2_printArray(Entidad2 array[] , int len)
{
    int i;
    for (i=0;i<len;i++)
    {
        if(array[i].flagOcupado == 1)
        {
            printf("ID Ent1: %d, Motivo: %d, Tiempo insumido: %d, estado: %d\n\n\n\n",array[i].idEntidad1,array[i].motivo,array[i].tiempoInsumido,array[i].estado);
        }
    }
}

