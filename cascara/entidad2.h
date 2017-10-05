#ifndef ENTIDAD2_H_INCLUDED
#define ENTIDAD2_H_INCLUDED

#define ESTADO_PENDIENTE 0
#define ESTADO_CUMPLIDO 1
#define ESTADO_NO_CUMPLIDO 2

#define INFARTO 0
#define ACV 1
#define GRIPE 2

#include "entidad1.h"

typedef struct{
    int motivo;
    char otros[51];
    int estado;
    int tiempoInsumido;
    int id;
    int idEntidad1;
    int flagOcupado;


}Entidad2;

int ent2_init(Entidad2 array[], int len);
int ent2_generarProximoId(Entidad2 array[], int len); //static
int ent2_buscarPosicionLibre(Entidad2 array[], int len); //static
int ent2_buscarIndicePorId(Entidad2 array[],int len,int id); //static

int ent2_alta(Entidad1 array1[],Entidad2 array[], int lenEntidad1, int lenEntidad2);
int ent2_fin(Entidad2 array[], int len);

void ent2_printArray(Entidad2 array[] , int len);


#endif // ENTIDAD2_H_INCLUDED
