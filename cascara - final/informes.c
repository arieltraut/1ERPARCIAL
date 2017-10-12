#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"



int info_listarFacturacion(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantalla)
{
    int retorno = -1, indexContra, indexPan, idPan, flagCuitEncontrado = 0;
    char bCuit[51];

    if (val_getCuit(bCuit,"\nIngrese CUIT\n","\nCUIT invalido, ingrese nuevamente\n",2,51)==0)
    {
        for(indexContra=0; indexContra<lenContrataciones; indexContra++)
        {
            if((strcmp(arrayContratacion[indexContra].cuit,bCuit) == 0) && arrayContratacion[indexContra].flagOcupado == 1)
            {
                flagCuitEncontrado = 1;
                idPan = arrayContratacion[indexContra].idPantalla;
                indexPan = pantalla_buscarIndicePorId(arrayPantalla,lenPantalla,idPan);
                float importeContra = arrayPantalla[indexPan].precio * arrayContratacion[indexContra].diasPublicacion;
                printf("ID Contratacion: %d  Precio contratacion: %.2f\n\n",arrayContratacion[indexContra].id, importeContra);
            }
        }
        if (flagCuitEncontrado == 0)
        {
            printf("No hay contrataciones asignadas al CUIT ingresado\n");
        }
    }
    return retorno;
}


int info_listarContrataciones(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantalla)
{
    int retorno = -1, indexContra, indexPan, idPan, flagCuitEncontrado = 0;

        for(indexContra=0; indexContra<lenContrataciones; indexContra++)
        {
            if(arrayContratacion[indexContra].flagOcupado == 1)
            {
                flagCuitEncontrado = 1;
                idPan = arrayContratacion[indexContra].idPantalla;
                indexPan = pantalla_buscarIndicePorId(arrayPantalla,lenPantalla,idPan);
                printf("Nombre pantalla: %s,  Nombre video: %s, Cantidad dias: %d, CUIT Cliente: %s\n\n",arrayPantalla[indexPan].nombre, arrayContratacion[indexContra].nombreArchivoVideo,arrayContratacion[indexContra].diasPublicacion,arrayContratacion[indexContra].cuit);
            }
        }
        if (flagCuitEncontrado == 0)
        {
            printf("No se han cargado contrataciones\n");
        }

    return retorno;
}


void info_printArrayPantalla(sPantalla arrayPantalla[] , int len)
{
    int i, flagOcupadoEncontrado = 0;
    for (i=0;i<len;i++)
    {
        if(arrayPantalla[i].flagOcupado == 1)
        {
            printf("ID: %d, Tipo: %d, Nombre: %s, Direccion: %s, precio: %.2f\n\n\n",arrayPantalla[i].id,arrayPantalla[i].tipoPantalla,arrayPantalla[i].nombre,arrayPantalla[i].direccion,arrayPantalla[i].precio);
            flagOcupadoEncontrado = 1;
        }
    }
    if (flagOcupadoEncontrado == 0)
    {
            printf("No hay ninguna pantalla cargada en el sistema\n");
            system("pause");
    }
}


int info_listarClientes(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantalla)
{
    int retorno = -1, indexContra, i;
    int iArrayClientes=0, indiceCuit=0,arrayContador[lenContrataciones];
    char bCuit[51],arrayClientes[51][lenContrataciones];

    for(i=0; i<lenContrataciones; i++)
    {
        //strcpy(arrayClientes[i],"0");
        arrayContador[i] = 0;
    }

    int j;
    for(indexContra=0; indexContra<lenContrataciones; indexContra++)
    {
        if(arrayContratacion[indexContra].flagOcupado == 0)
            continue;

        strncpy(bCuit, arrayContratacion[indexContra].cuit,50);
        j=indexContra-1;

        while((strcmp(bCuit,arrayContratacion[j].cuit)!=0) && j>=0 && arrayContratacion[j].flagOcupado == 1)
        {
            j--;
        }
        if(j==-1)
        {
            strcpy(arrayClientes[iArrayClientes],bCuit);
            iArrayClientes++;
        }
    }

    char bCuit2[51];
    for (indiceCuit=0; indiceCuit<lenContrataciones; indiceCuit++)
    {
        strncpy(bCuit2, arrayClientes[indiceCuit],50);
        for(indexContra=0; indexContra<lenContrataciones; indexContra++)
        {
            if((strcmp(bCuit2,arrayContratacion[indexContra].cuit))==0 && arrayContratacion[indexContra].flagOcupado == 1)
                arrayContador[indiceCuit]++;
        }
    }


    for (indiceCuit=0; indiceCuit<lenContrataciones; indiceCuit++)
    {
        if ( arrayContador[indiceCuit] != 0)
             printf("La cantidad de contrataciones del CUIT: %s es %d\n",arrayClientes[indiceCuit],arrayContador[indiceCuit]);

        for(indexContra=0; indexContra<lenContrataciones; indexContra++)
        {
            if((strcmp(arrayContratacion[indexContra].cuit,arrayClientes[indiceCuit]))==0 && arrayContratacion[indexContra].flagOcupado == 1)
            {
                //flagCuitEncontrado = 1;
                int idPan = arrayContratacion[indexContra].idPantalla;
                int indexPan = pantalla_buscarIndicePorId(arrayPantalla,lenPantalla,idPan);
                float importeContra = arrayPantalla[indexPan].precio * arrayContratacion[indexContra].diasPublicacion;

                printf("ID Contratacion: %d  Precio contratacion: %.2f\n\n",arrayContratacion[indexContra].id, importeContra);
            }

        }
    }

/*
       printf("%s\n",arrayClientes[0]);
       printf("%s\n",arrayClientes[1]);
       printf("%s\n",arrayClientes[2]);
       printf("%s\n",arrayClientes[3]);
       printf("%d\n",arrayContador[0]);
       printf("%d\n",arrayContador[1]);
       printf("%d\n",arrayContador[2]);
*/

    return retorno;
}



