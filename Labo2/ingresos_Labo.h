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
} laboratorios;

typedef struct
{
    laboratorios lab;
<<<<<<< HEAD
    nodoListaPracticas * listaPracticas;
=======
    nodoListaPracticas * listaPracticas;///deberia ser pracXingreso en lugar de nodolistapracticas
>>>>>>> d92dac111805beff97532220a8ee613923924154
    struct nodoListaIngresos * siguiente;
} nodoListaIngresos;


void fechaActual(char fecha[]);
int autoincrementalIngresos(char archivo[]);
laboratorios nuevoRegistro(char archivo[], nodoArbol * arbol);
nodoListaIngresos * crearNodoIngreso(laboratorios nuevo);///deberia ser pracXingreso en lugar de nodolistapracticas
nodoListaIngresos * agregarAlFinalIngresos(nodoListaIngresos * lista, nodoListaIngresos * nuevo);///deberia ser pracXingreso en lugar de nodolistapracticas
void altaDeLaboratorio(char archivo[], laboratorios registro, nodoArbol * arbol);
void bajDeLabXId(int id, char archivo[], nodoArbol * arbol);
void modificacionDeLaboratorio(char archivo[]);
void listadoDeLaboratoriosVigentes(nodoArbol * arbol);
void mostrarListaiIngresos(nodoListaIngresos * lista);
void mostrarListaiIngresos(nodoListaIngresos * lista);


#endif // INGRESOS_LABO_H_INCLUDED
