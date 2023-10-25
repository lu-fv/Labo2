#include "empleado_laboratorio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BORRAR system("cls")
#define PAUSA system("pause")

empleados_laboratorio crearRegistroEmpleados()
{
    empleados_laboratorio empleado;

    printf("\nIngrese DNI: ");
    fflush(stdin);
    scanf("%d",&empleado.dni);
    printf("\nIngrese Apellido y Nombre: ");
    fflush(stdin);
    gets(empleado.ape_nombre);
    printf("\nIngrese el Usuario que desea registrar: ");
    gets(empleado.usuario);
    printf("\nIngrese la Clave que desea registrar: ");
    gets(empleado.clave);
    printf("\nIngrese su perfil (administrador/empleado/bioquimico) : ");
    gets(empleado.perfil);

    return empleado;
}

void alta_empleado(char archivoEmpleado[])
{
    empleados_laboratorio empleado;
    char rta='s';
    char modifica_empleado;

    FILE * arch=fopen(archivoEmpleado,"ab");

    if(arch)
    {
        while(rta=='s')
        {
            empleado=crearRegistroEmpleados();

            if(verificar_archivo_empleados(archivoEmpleado,empleado.dni)==0)
            {
                fwrite(&empleado,sizeof(empleados_laboratorio),1,arch);
                printf("\nDesea ingresar un nuevo empleado? s/n ");
                fflush(stdin);
                scanf("%c",&rta);
            }
            else
            {
                printf("\nEl Empleado que esta ingresando ya existe en los registros.Desea Modificarlo? s/n ");
                scanf("%c",&modifica_empleado);
                if(modifica_empleado=='s')
                {
                    ///si desea modificar poner la funcion de modifica
                }
            }
        }
        fclose(arch);
    }
    else
    {
        printf("\nERROR AL ABRIR EL ARCHIVO");
    }

}

int verificar_archivo_empleados(char archivo[],int DNI)
{
    empleados_laboratorio empleado;
    int encontrado=0;

    FILE * arch=fopen(archivo,"rb");


    if(arch)
    {
        while(encontrado==0 && fread(&empleado,sizeof(empleados_laboratorio),1,arch)>0)
        {
            if(empleado.dni==DNI)
            {
                encontrado=1;
            }
        }
        fclose(arch);
    }

    return encontrado;
}
