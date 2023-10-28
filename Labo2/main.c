#include <stdio.h>
#include <stdlib.h>
#include "empleado_laboratorio.h"
#define EMPLEADOS "archivo_empleados.dat"
#define BORRAR system("cls")
#define PAUSA system("pause")

int main()
{
    char rta='s';

    while(rta=='s')
    {
        alta_empleado(EMPLEADOS);
        printf("\nDesea ingresar un nuevo empleado? s/n : ");
        fflush(stdin);
        scanf("%c",&rta);
        BORRAR;
    }


    return 0;
}
