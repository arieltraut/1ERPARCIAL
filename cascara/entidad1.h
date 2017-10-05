#ifndef ENTIDAD1_H_INCLUDED
#define ENTIDAD1_H_INCLUDED


typedef struct{
    char nombre[51];
    char apellido[51];
    int edad;
    int dni;
    int id;
    int flagOcupado;

}Entidad1;

int ent1_init(Entidad1 array[], int len);
int ent1_generarProximoId(Entidad1 array[], int len); //static
int ent1_buscarPosicionLibre(Entidad1 array[], int len); //static
int ent1_buscarIndicePorId(Entidad1 array[],int len,int id); //static

int ent1_alta(Entidad1 array[], int len);
int ent1_modificar(Entidad1 array[], int len);
int ent1_baja(Entidad1 array[], int len);

void ent1_printArray(Entidad1 array[] , int len);







#endif // ENTIDAD1_H_INCLUDED
