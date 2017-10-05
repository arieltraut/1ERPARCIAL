#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entidad1.h"
#include "entidad2.h"
#include "validar.h"


/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flagEstado un 0.
 *
 * \param Entidad1 array[] Puntero al array de .....
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int ent1_init(Entidad1 array[], int len)
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
 * \param Entidad1 array[] Puntero al array de ...........
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (proximo ID) si Ok
 *
 */
int ent1_generarProximoId(Entidad1 array[], int len) //**********************************ver
{
    ultimoValorIdAutoincrementable++;
    return ultimoValorIdAutoincrementable;
}

/** \brief  Busca en el array la primer posicion libre
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (index del lugar libre) si Ok
 *
 */
int ent1_buscarPosicionLibre(Entidad1 array[], int len)
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
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int ent1_alta(Entidad1 array[], int len)
{
    int retorno = -1;
    int idNuevo;
    char bNombre[51];
    char bApellido[51];
    char bEdad[3];
    char bDni[8];
    int indexVacio = ent1_buscarPosicionLibre(array,len);

    if (array != NULL && indexVacio >=0 && indexVacio < len)
    {
        if (val_getNombre(bNombre, "\nIngrese Nombre\n", "\nNombre invalido\n",3,50)==0) //hacer define en h para 50
        {

           if (val_getNombre(bApellido, "\nIngrese Apellido\n", "\nApellido invalido\n",3,50)==0)
           {

              if(val_getEdad(bEdad,"\nEdad?\n","\nError:\n",2,3)==0)
              {

                if(val_getDni(bDni,"\nDNI?\n","\nError:\n",2,8)==0)
                {

                    idNuevo = ent1_generarProximoId(array,len);

                    strncpy(array[indexVacio].nombre,bNombre,51);
                    strncpy(array[indexVacio].apellido,bApellido,51);
                    array[indexVacio].edad = atoi(bEdad);
                    array[indexVacio].dni = atoi(bDni);
                    array[indexVacio].flagOcupado = 1;
                    array[indexVacio].id = idNuevo;
                    retorno = 0;
                }
            }
           }
        }
    }
    return retorno;
}


/** \brief Busca en la lista un ...... que coincida con el Id recibido
 *
 * \param Entidad1 array[] Puntero al array de .....
 * \param len int Longitud del array
 * \param id int ID del .....
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin no se encontro el ......] - (0) si Ok
 *
 */
int ent1_buscarIndicePorId(Entidad1 array[],int len,int id)
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


/** \brief Pide al usuario el ID, Nombre y Apellido  de un ....... a ser modificadolos luego los modifica
 * \param Entidad1 array[] Puntero al array de .......
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro el id]
 *                    ( 0) si Ok
 */
int ent1_modificar(Entidad1 array[], int len)
{
    int retorno = -1;
    char bufferId[100];
    char bNombre[51];
    char bEdad[3];

    val_getUnsignedInt(bufferId,"\nIngrese ID a modificar\n","\nIngrese solo numeros\n",2,40);
    int index = ent1_buscarIndicePorId(array,len,atoi(bufferId));

    if (index != -1)
    {
        if (val_getNombre(bNombre, "\nIngrese Nombre\n", "\nNombre invalido\n",3,50)==0) //hacer define en h para 50
        {

            if (val_getEdad(bEdad,"\nIngrese edad\n","\nEdad invalida:\n",2,3)==0)
            {
                array[index].edad = atoi(bEdad);
                strncpy(array[index].nombre,bNombre,51);
                retorno = 0;
            }
        }
    }
    else
    {
        printf("El ID elegido no existe\n");
        system("pause");
    }

    return retorno;
}


/** \brief Pide al usuario el ID de un ......... a ser dado de baja
 * \param Entidad1 array[] Puntero al array de .............
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro el abonado]
 *                    ( 0) si Ok
 */
int ent1_baja(Entidad1 array[], int len)
{
    int retorno = -1;
    char bufferId[100];

    val_getUnsignedInt(bufferId,"\nIngrese ID a dar de baja\n","\nIngrese solo numeros\n",2,40);
    int index = ent1_buscarIndicePorId(array,len,atoi(bufferId));

    if (index != -1)
    {
        array[index].flagOcupado = 0;
        retorno = 0;
    }
    else
    {
        printf("El ID elegido no existe\n");
        system("pause");
    }
    return retorno;
}


void ent1_printArray(Entidad1 array[] , int len)
{
    int i;
    for (i=0;i<len;i++)
    {
        if(array[i].flagOcupado == 1)
        {
            printf("ID: %d, Nombre y apellido: %s %s, edad: %d\n\n\n",array[i].id,array[i].nombre,array[i].apellido,array[i].edad);
        }
    }
}



// agregar ordenamiento por campos de esta estructura por un campo y otra funcion por 2 campos

