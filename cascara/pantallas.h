#ifndef ENTIDAD1_H_INCLUDED
#define ENTIDAD1_H_INCLUDED
#define LCD 0
#define LED 1


typedef struct{
    int tipoPantalla;
    char nombre[51];
    char direccion[51];
    float precio;
    int id;
    int flagOcupado;

}sPantalla;

int pantalla_init(sPantalla arrayPantalla[], int len);
int pantalla_generarProximoId(sPantalla arrayPantalla[], int len); //static
int pantalla_buscarPosicionLibre(sPantalla arrayPantalla[], int len); //static
int pantalla_buscarIndicePorId(sPantalla arrayPantalla[],int len,int id); //static

int pantalla_alta(sPantalla arrayPantalla[], int len);
int pantalla_modificar(sPantalla arrayPantalla[], int len);
int pantalla_baja(sPantalla arrayPantalla[], int len);

void pantalla_printArray(sPantalla arrayPantalla[] , int len);







#endif // ENTIDAD1_H_INCLUDED
