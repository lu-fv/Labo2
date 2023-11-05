#ifndef INGRESOS_LABO_H_INCLUDED
#define INGRESOS_LABO_H_INCLUDED

#include <time.h>
#include <stdio.h>

#include "practicas_ingreso.h"
#include "diseño.h"
#include "empleado_laboratorio.h"
#include "pacientes.h"
#include "practicas_Labo.h"

#define ARCHIVOINGRESOS "ingresos.dat"

typedef struct
{
    int Nro_de_ingreso;
    char fecha_de_ingreso[10]; //por defecto la actual
    char fecha_de_retiro [10];
    int dni_paciente;
    int medico_matricula;
    int vigencia;///0 vigente, 1 NO vigente

    struct nodoListaPracticas * listaPracticas;
    struct laboratorios * siguiente;
}laboratorios;


void fechaActual(char fecha[]);
int autoincrementalIngresos(char archivo[]);
laboratorios nuevoRegistro(char archivo[]);
nodoListaIngreso * crearNodoIngreso(laboratorios nuevo);
nodoListaIngreso * agregarAlFinalIngresos(nodoListaIngreso * lista, nodoListaIngreso * nuevo);
void altaDeLaboratorio(char archivo[], laboratorios registro);
void bajDeLabXId(int id, char archivo[]);
void modificacionDeLaboratorio(char archivo[]);
void listadoDeLaboratoriosVigentes(char archivo[]);
void listadoDeLaboratoriosEliminados(char archivo[]);


#endif // INGRESOS_LABO_H_INCLUDED
