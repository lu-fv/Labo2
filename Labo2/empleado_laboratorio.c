#include "empleado_laboratorio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conio.h"

#define BORRAR system("cls")
#define PAUSA system("pause")

empleados_laboratorio crearRegistroEmpleados()
{
    empleados_laboratorio empleado;

    char ok ='n';

    while(ok == 'n' || ok == 'N')
    {
        printf("\nIngrese DNI: ");///verificar int HACER FUNCION
        fflush(stdin);
        scanf("%d",&empleado.dni);
        printf("\nIngrese Apellido y Nombre: ");///verificar string HACER FUNCION
        fflush(stdin);
        gets(empleado.ape_nombre);
        printf("\nIngrese el Usuario que desea registrar: ");
        fflush(stdin);
        gets(empleado.usuario);
        printf("\nIngrese la Clave que desea registrar: ");
        fflush(stdin);
        gets(empleado.clave);
        printf("\nIngrese su perfil (administrador/empleado/bioquimico) : ");
        fflush(stdin);
        gets(empleado.perfil);
        empleado.eliminado=0;
        PAUSA;
        BORRAR;

        mostrar_un_empleado(empleado);

        printf("\n\nLos Datos ingresados son correctos? s/n : ");
        fflush(stdin);
        ok=getch();

        PAUSA;
        BORRAR;

        if(ok == 'n' || ok == 'N')
        {
            printf("\nSobreescribir los campos nuevamente...\n\n");
            BORRAR;
        }
    }

    return empleado;
}

void mostrar_un_empleado(empleados_laboratorio empleado)
{
    printf("\n____________________________________________________\n");
    printf("\nAPELLIDO Y NOMBRE: %s", empleado.ape_nombre);
    printf("\t[%s]", empleado.perfil);
    printf("\nDNI: %d", empleado.dni);
    printf("\nUSUARIO : [%s]", empleado.usuario);
    printf("\nCLAVE :[%s]", empleado.clave);
    printf("\n____________________________________________________\n");
}

void alta_empleado(char archivoEmpleado[])
{
    empleados_laboratorio empleado;

    char modifica_empleado;

    FILE * arch=fopen(archivoEmpleado,"ab");

        if(arch)
        {
            empleado=crearRegistroEmpleados();

            if(verificar_archivo_empleados(archivoEmpleado,empleado.dni)==0 && verificar_usuario_unico(archivoEmpleado,empleado.usuario)==0)
            {
                fwrite(&empleado,sizeof(empleados_laboratorio),1,arch);
            }
            else
            {
                if(verificar_archivo_empleados(archivoEmpleado,empleado.dni)==1)
                {
                    printf("\nEl Empleado que esta ingresando ya existe en los registros.Desea Modificarlo? s/n ");
                    fflush(stdin);
                    scanf("%c",&modifica_empleado);
                    BORRAR;

                    if(modifica_empleado=='s')
                    {
                        ///si desea modificar poner la funcion de modifica
                        printf("\nARCHIVO MODIFICADO\n");
                    }
                }
                else
                    {
                         if(verificar_usuario_unico(archivoEmpleado,empleado.usuario)==1)
                        {
                            printf("\nEl USUARIO que ingreso ya existe en la base de datos vuelva a ingresarlo\n");
                            PAUSA;
                            BORRAR;
                        }
                    }

            }
            fclose(arch);
        }
        else
        {
            printf("\nERROR AL ABRIR EL ARCHIVO. LLAME AL 111\n");
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

int verificar_usuario_unico(char archivo[],char usuarioNuevo[])
{
    empleados_laboratorio empleado;

    int encontrado=0;

    FILE * arch=fopen(archivo,"rb");


    if(arch)
    {
        while(encontrado==0 && fread(&empleado,sizeof(empleados_laboratorio),1,arch)>0)
        {
            if(strcmp(empleado.usuario,usuarioNuevo)==0)
            {
                encontrado=1;
            }
        }
        fclose(arch);
    }

    return encontrado;

}
