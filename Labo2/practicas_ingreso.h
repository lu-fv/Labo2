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
    struct pracXingreso * siguiente;
}pracXingreso;

pracXingreso alta_de_UNA_practXingreso(int numIngreso);
pracXingreso registro_practXingreso(int numIngreso);
int verifica_existe_ingreso(int numIngreso);
void listado_pract_vigentes();
int busca_num_practica_vigente(char practica[]);

#endif // PRACTICAS_INGRESO_H_INCLUDED
