#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantallas.h"
#include "contrataciones.h"
#include "validar.h"
#include "informes.h"

#define LEN_PANTALLA 50
#define LEN_CONTRATACIONES 50

int main()
{
    sPantalla arrayPantalla[LEN_PANTALLA];
    sContrataciones arrayContratacion[LEN_CONTRATACIONES];

    pantalla_init(arrayPantalla, LEN_PANTALLA);
    contra_init(arrayContratacion, LEN_CONTRATACIONES);

    //prueba(arrayPantalla,arrayContratacion,LEN_PANTALLA,LEN_CONTRATACIONES);

    char opcion[50];

    do
    {
        val_getUnsignedInt(opcion,"\n1-Alta de pantalla\n2-Modificar datos de pantalla\n3-Baja de pantalla\n4-Contratar una publicidad\n5-Cerrar caso\n6-Informes\n7-Ordenar\n8-Salir\n","\nSolo numeros\n",3,50);

        switch(atoi(opcion))
        {
            case 1:
                pantalla_alta (arrayPantalla, LEN_PANTALLA);
                break;

            case 2:
                pantalla_modificar(arrayPantalla, LEN_PANTALLA);
                break;
            case 3:
                pantalla_baja(arrayPantalla, LEN_PANTALLA);
                break;
            case 4:
                pantalla_printArray(arrayPantalla,LEN_PANTALLA);
                contra_alta(arrayPantalla,arrayContratacion, LEN_PANTALLA,LEN_CONTRATACIONES);
                break;
            case 5:

                break;
            case 6:
                contra_fin(arrayContratacion, LEN_CONTRATACIONES);

                //contratacion_printArray(arrayContratacion,LEN_CONTRATACIONES);
                //imprimirTodo(arrayPantalla, LEN_PANTALLA, arrayContratacion, LEN_CONTRATACIONES);
                //idEn1_conMasLlamadas(arrayPantalla, LEN_PANTALLA, arrayContratacion, LEN_CONTRATACIONES);

                break;
            case 7:
                //OrdenarAlfabeticamentePorCampoChar(arrayPantalla,LEN_PANTALLA);
                break;

            default:
                printf("Opcion invalida");
                system("pause");
                break;
        }

    }while( atoi(opcion) != 8);

    return 0;
}
