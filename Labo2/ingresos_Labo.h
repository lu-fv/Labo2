#ifndef INGRESOS_LABO_H_INCLUDED
#define INGRESOS_LABO_H_INCLUDED

#include <time.h>
#include <stdio.h>
#include "practicas_ingreso.h"

#define ARCHIVOINGRESOS "ingresos.dat"
typedef struct
{
    int Nro_de_ingreso;
    char fecha_de_ingreso[10]; //por defecto la actual
    char fecha_de_retiro [10];
    int dni_paciente;
    int medico_matricula;
    int vigencia;///0 vigente, 1 NO vigente
}laboratorios;

typedef struct
{
    char nomb_apell[40];
    int edad;
    int dni;
    char telefono[15];
    char direccion[30];
    int eliminado;///0 vigente,1 eliminado
}pacientes;

typedef struct
{
    pracXingreso ingreso;
    struct nodoListaPracticas * siguiente;

}nodoListaPracticas;


typedef struct
{
    laboratorios dato;
    nodoListaPracticas * practica;
    struct nodoListaIngreso * siguiente;

}nodoListaIngreso;


typedef struct
{
    pacientes p;
    struct nodoArbol *izq;
    struct nodoArbol *der;
    nodoListaIngreso * ingreso;

} nodoArbol;


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
