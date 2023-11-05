#ifndef DISEÒO_H_INCLUDED
#define DISEÒO_H_INCLUDED

#include "empleado_laboratorio.h"
#include "pacientes.h"
#include "ingresos_Labo.h"
#include "practicas_ingreso.h"
#include "practicas_Labo.h"
#define ARCHIVO_PACIENTES "pacientes.dat"


void gotoxy(int x,int y);

void marco_borde_ancho();
void marco_plantilla();
void marco_factura();
void marco_menu();
void marco_contrasenia();

void plantilla_laboratorios_x_paciente();
void factura();

void menu();
void menu_administrador();
void menu_gestion_administrativa();
void menu_bioquimico();
void menu_administrador_empleados();
void menu_administrador_pacientes();
void menu_administrador_practicas();
void menu_administrador_laboratorios();
void menu_administrador_resultados();
void menu_gestion_administrativa_pacientes();
void menu_gestion_administrativa_practicas();
void menu_gestion_administrativa_laboratorios();
void menu_contrasenia();

void carga_arbol();
int valida_existencia_de_ingresos_x_paciente(char archivoingresos[],int dni_paciente);
nodoArbol * busca_nodopaciente_en_arbol(nodoArbol * arbol, int dni);
nodoArbol * crear_nodo_arbol(pacientes p);
///nodoListaPracticas * crearNodoListaPracticas(pracXingreso practica);
nodoArbol * carga_arbol_un_paciente(nodoArbol * arbol,nodoArbol * nuevo);


#endif // DISEÒO_H_INCLUDED
