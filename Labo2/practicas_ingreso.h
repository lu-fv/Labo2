#ifndef PRACTICAS_INGRESO_H_INCLUDED
#define PRACTICAS_INGRESO_H_INCLUDED

#include "diseño.h"
#include "empleado_laboratorio.h"
#include "ingresos_Labo.h"
#include "pacientes.h"
#include "practicas_Labo.h"

typedef struct
{
    int nro_de_ingreso;
    int nro_de_practica;
    char nombre[20];
    int vigencia;///0 vigente,1 NO vigente
    char resultado [40];
    struct pracXingreso * siguiente;
}pracXingreso;

void alta_de_UNA_practXingreso(int numIngreso);
pracXingreso crear_registro_practXingreso(int numIngreso);
int verifica_existe_ingreso(int numIngreso);
void listado_pract_vigentes();
int busca_num_practica_vigente(char practica[]);
///falta hacer funcion agregar practica que seria como agregar al final de la lista

#endif // PRACTICAS_INGRESO_H_INCLUDED
