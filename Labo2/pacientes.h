#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED
#include "diseño.h"
#include "empleado_laboratorio.h"
#include "ingresos_Labo.h"
#include "practicas_ingreso.h"
#include "practicas_Labo.h"
#define ARCHIVO_PACIENTES "pacientes.dat"

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
    pacientes p;
    struct nodoListaIngreso * ingreso;
    struct nodoArbol *izq;
    struct nodoArbol *der;
}nodoArbol;


pacientes cargaPacientes();
void imprimirUnPaciente( pacientes p);
nodoArbol * inicArbol();
nodoArbol * crearNodoPacientes (pacientes p);
nodoArbol * insertar( nodoArbol * arbol, int dni);


#endif // PACIENTES_H_INCLUDED
