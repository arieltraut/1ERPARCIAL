#ifndef ENTIDAD2_H_INCLUDED
#define ENTIDAD2_H_INCLUDED

#define ESTADO_PENDIENTE 0
#define ESTADO_CUMPLIDO 1
#define ESTADO_NO_CUMPLIDO 2

#define INFARTO 0
#define ACV 1
#define GRIPE 2

#include "pantallas.h"

typedef struct{
    char cuit[12];
    char nombreArchivoVideo[51];
    int estado; //ver
    int diasPublicacion;
    int id;
    int idPantalla;
    int flagOcupado;


}sContrataciones;

int contra_init(sContrataciones arrayContratacion[], int len);
int contra_generarProximoId(sContrataciones arrayContratacion[], int len); //static
int contra_buscarPosicionLibre(sContrataciones arrayContratacion[], int len); //static
int contra_buscarIndicePorId(sContrataciones arrayContratacion[],int len,int id); //static
int contra_buscarIndicePorCuit(sContrataciones arrayContratacion[],int len,int id);

int contra_alta(sPantalla arrayPantalla[],sContrataciones arrayContratacion[], int lenPantalla, int lenContratacion);
int contra_fin(sContrataciones arrayContratacion[], int len);

void contra_printArray(sContrataciones arrayContratacion[] , int len);


#endif // ENTIDAD2_H_INCLUDED
