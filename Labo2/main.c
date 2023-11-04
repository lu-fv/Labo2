#include <stdio.h>
#include <stdlib.h>
#define BORRAR system("cls")
#define PAUSA system("pause")
#define ARCHIVO_EMPLEADOS "archivo_empleados.dat"

int main()
{
    ///mostrar_archivo(ARCHIVO_EMPLEADOS);

    menu();

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
