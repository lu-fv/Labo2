#ifndef PRACTICAS_INGRESO_H_INCLUDED
#define PRACTICAS_INGRESO_H_INCLUDED

typedef struct
{
    int nro_de_ingreso;
    int nro_de_practica;
    char nombre[20];
    int vigencia;///0 vigente,1 NO vigente
    char resultado [40];
}pracXingreso;


#endif // PRACTICAS_INGRESO_H_INCLUDED
