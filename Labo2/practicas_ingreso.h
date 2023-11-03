#ifndef PRACTICAS_INGRESO_H_INCLUDED
#define PRACTICAS_INGRESO_H_INCLUDED
#define ARCHIVO_PRACXINGRESO "practicaXingreso.dat"

#include "diseño.h"
#include "empleado_laboratorio.h"
#include "ingresos_Labo.h"
#include "pacientes.h"
#include "practicas_Labo.h"
#include "practicas_ingreso.h"




typedef struct
{
    int nro_de_ingreso;
    int nro_de_practica;
    char nombre[20];
    int vigencia;///0 vigente,1 NO vigente
    char resultado [40];
}pracXingreso;

typedef struct
{
    pracXingreso ingreso;
    struct nodoListaPracticas * siguiente;
}nodoListaPracticas;



#endif // PRACTICAS_INGRESO_H_INCLUDED
