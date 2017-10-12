#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantallas.h"


/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flagEstado un 0.
 *
 * \param sPantalla arrayPantalla[] Puntero al array de .....
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int pantalla_init(sPantalla arrayPantalla[], int len)
{
    int i;
    int retorno = -1;
    if (arrayPantalla != NULL && len >0)
    {
        for(i=0;i<len;i++)
        {
            arrayPantalla[i].flagOcupado = 0;
        }
        retorno = 0;
    }
    return retorno;
}

static int ultimoValorIdAutoincrementable = -1;

/** \brief  Busca en el array el id mas alto entre los usados y los borrados
 * \param sPantalla arrayPantalla[] Puntero al array de ...........
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (proximo ID) si Ok
 *
 */
int pantalla_generarProximoId(sPantalla arrayPantalla[], int len) //borrar parametros dejar tipo void
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
int pantalla_buscarPosicionLibre(sPantalla arrayPantalla[], int len)
{
    int i;
    int retorno = -1;
    if(arrayPantalla != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(arrayPantalla[i].flagOcupado == 0)
            {
                retorno =  i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Pide al usuario los datos de un nuevo ...... y luego lo agrega al array
 * \param sPantalla arrayPantalla[] Puntero al array de ........
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int pantalla_alta(sPantalla arrayPantalla[], int len)
{
    int retorno = -1;
    int idNuevo;
    int bTipoPantalla;
    char bNombre[51];
    char bDireccion[51];
    float bPrecio;
    int indexVacio = pantalla_buscarPosicionLibre(arrayPantalla,len);

     if (arrayPantalla != NULL && indexVacio >=0 && indexVacio < len)
     {
        if (val_getUnsignedInt(&bTipoPantalla,"\nIngrese tipo pantalla:\n  LCD [0]\n  LED [1]\n","\nIngrese solo numeros 0 o 1\n",2,0,1)==0)
        {
            if (val_getAlfanumerico(bNombre, "\nIngrese Nombre\n", "\nNombre invalido\n",3,50)==0) //hacer define en h para 50
            {
               if (val_getAlfanumerico(bDireccion, "\nIngrese Direccion\n", "\nDireccion invalida\n",3,50)==0)
               {
                  if(val_getPrecio(&bPrecio,"\nIngrese Precio\n","\nError:\n",2,0,9999)==0)
                  {

                        idNuevo = pantalla_generarProximoId(arrayPantalla,len);

                        strncpy(arrayPantalla[indexVacio].nombre,bNombre,51);
                        strncpy(arrayPantalla[indexVacio].direccion,bDireccion,51);
                        arrayPantalla[indexVacio].tipoPantalla = bTipoPantalla;
                        arrayPantalla[indexVacio].precio = bPrecio;
                        arrayPantalla[indexVacio].flagOcupado = 1;
                        arrayPantalla[indexVacio].id = idNuevo;
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
 * \param sPantalla arrayPantalla[] Puntero al array de .....
 * \param len int Longitud del array
 * \param id int ID del .....
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin no se encontro el ......] - (0) si Ok
 *
 */
int pantalla_buscarIndicePorId(sPantalla arrayPantalla[],int len,int id)
{
    int i;
    int retorno = -1;
    for(i=0;i<len;i++)
        {
            if(arrayPantalla[i].flagOcupado == 1)
            {
                if(arrayPantalla[i].id == id)        //(strcmp(array[i].a, array[i].dni) == 0)
                {
                    retorno = i;
                    break;
                }
            }
        }
    return retorno;
}


/** \brief Pide al usuario el ID, Nombre y Apellido  de un ....... a ser modificadolos luego los modifica
 * \param sPantalla arrayPantalla[] Puntero al array de .......
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro el id]
 *                    ( 0) si Ok
 */
int pantalla_modificar(sPantalla arrayPantalla[], int len)
{
    int retorno = -1;
    int bufferId;
    int bTipoPantalla;
    char bNombre[51];
    char bDireccion[51];
    float bPrecio;

    val_getUnsignedInt(&bufferId,"\nIngrese ID a modificar\n","\nIngrese solo numeros\n",2,0,9999);
    int index = pantalla_buscarIndicePorId(arrayPantalla,len,bufferId);

    if (index != -1)
    {
      if (val_getUnsignedInt(&bTipoPantalla,"\nIngrese tipo pantalla:\n  LCD [0]\n  LED [1]\n","\nIngrese solo numeros 0 o 1\n",2,0,1)==0)
      {
        if (val_getAlfanumerico(bNombre,"\nIngrese Nombre\n", "\nNombre invalido\n",3,50)==0) //hacer define en h para 50
        {
           if (val_getAlfanumerico(bDireccion, "\nIngrese direccion\n", "\nDireccion invalido\n",3,50)==0)
           {

              if(val_getPrecio(&bPrecio,"\nIngrese Precio\n","\nError:\n",2,0,9999)==0)
              {
                strncpy(arrayPantalla[index].nombre,bNombre,51);
                strncpy(arrayPantalla[index].direccion,bDireccion,51);
                arrayPantalla[index].precio = bPrecio;
                retorno = 0;
              }
            }
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
 * \param sPantalla arrayPantalla[] Puntero al array de .............
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro el abonado]
 *                    ( 0) si Ok
 */
int pantalla_baja(sPantalla arrayPantalla[], int len)
{
    int retorno = -1;
    int bufferId;
    char bConfirm[2];

    val_getUnsignedInt(&bufferId,"\nIngrese ID a dar de baja\n","\nIngrese solo numeros\n",2,0,9999);
    int indexPan = pantalla_buscarIndicePorId(arrayPantalla,len,bufferId);

    if (indexPan != -1)
    {
        if (val_getNombre(bConfirm,"\nConfirma dar de baja la pantalla? S/N?\n","\nValor invalido\n",2,3)==0);
        {
            if (bConfirm[0] == 'S' || bConfirm[0]=='s')
            {
                arrayPantalla[indexPan].flagOcupado = 0;
                retorno = bufferId;
                printf("Se ha realizado la baja\n\n");
            }
            else
            {
                printf("No se han realizado bajas\n\n");
            }
        }
    }
    else
    {
        printf("El ID elegido no existe\n");
    }
    return retorno;
}





// agregar ordenamiento por campos de esta estructura por un campo y otra funcion por 2 campos

