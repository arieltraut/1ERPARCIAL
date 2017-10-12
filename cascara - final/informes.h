#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "pantallas.h"
#include "contrataciones.h"
#include "validar.h"

int info_listarFacturacion(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantalla);
int info_listarContrataciones(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantalla);
void info_printArrayPantalla(sPantalla arrayPantalla[] , int len);
int info_listarClientes(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantalla);


/*
void imprimirTodo(Entidad1 arrayEntidad1[], int lenEntidad1, Entidad2 arrayEntidad2[], int lenEntidad2);
void prueba(Entidad1 arrayEntidad1[], Entidad2 arrayEntidad2[], int lenEntidad1, int lenEntidad2);

void idEn1_conMasLlamadas(Entidad1 arrayEntidad1[], int lenEntidad1, Entidad2 arrayEntidad2[], int lenEntidad2);

int OrdenarAlfabeticamentePorCampoChar(Entidad1 arrayEntidad1[], int lenEntidad1);

*/



#endif // INFORMES_H_INCLUDED
