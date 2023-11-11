#include <stdio.h>
#include <stdlib.h>
#define BORRAR system("cls")
#define PAUSA system("pause")
#define ARCHIVO_EMPLEADOS "archivo_empleados.dat"
#include "practicas_Labo.h"
#define ARCHIVO_PACIENTES "pacientes.dat"
int main()
{
    ///AltaDePracticasNuevas(Practicas_Laboratorio);
    ///mostrar_archivo(ARCHIVO_EMPLEADOS);
    altaPacientes (ARCHIVO_PACIENTES);
    //menu();

    ///carga el archivo empleados
    /*char rta='s';

    while(rta=='s')
    {
        alta_empleado(ARCHIVO_EMPLEADOS);
        printf("\nDesea ingresar un nuevo empleado? s/n : ");
        fflush(stdin);
        scanf("%c",&rta);
        BORRAR;
    }*/

    return 0;
}
