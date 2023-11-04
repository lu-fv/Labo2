#ifndef EMPLEADO_LABORATORIO_H_INCLUDED
#define EMPLEADO_LABORATORIO_H_INCLUDED

#include "diseño.h"
#include "ingresos_Labo.h"
#include "pacientes.h"
#include "practicas_Labo.h"
#include "practicas_ingreso.h"

typedef struct
{
    int dni;
    char ape_nombre [40];
    char usuario [20];
    char clave [20];
    char perfil [20];
    int eliminado;///0 por defecto
}empleados_laboratorio;

empleados_laboratorio crearRegistroEmpleados();
void mostrar_un_empleado(empleados_laboratorio empleado, int x, int y);
void alta_empleado(char archivoEmpleado[]);
int verificar_archivo_empleados(char archivo[],int DNI);
int verificar_usuario_unico(char archivo[],char usuarioNuevo[]);
void baja_empleado(char archivoEmpleado[],int dni);
void modificacion_de_empleado(char archivoEmpleados[],int dni);
void listado_empleados_vigentes(char archivoEmpleados[]);
void listado_empleados_eliminados(char archivoEmpleados[]);
int validacion_usuarioYclave(char archivoEmpleados[], char perfil[]);
void mostrar_archivo(char archivo[]);
void menu_modifica_campo_registro(FILE * archivo, empleados_laboratorio empleado);

#endif // EMPLEADO_LABORATORIO_H_INCLUDED
