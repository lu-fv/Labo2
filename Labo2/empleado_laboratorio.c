#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conio.h"

#include "diseño.h"
#include "empleado_laboratorio.h"
#include "pacientes.h"
#include "ingresos_Labo.h"
#include "practicas_ingreso.h"
#include "practicas_Labo.h"

#define ARCHIVO_EMPLEADOS "archivo_empleados.dat"
#define BORRAR system("cls")
#define PAUSA system("pause")
#define TECLA_ENTER 13
#define TECLA_BACKSPACE 8
#define LONGITUD 5
#define MAX_INTENTOS 3

empleados_laboratorio crearRegistroEmpleados()
{
    marco_menu();
    gotoxy(52,2);printf("ALTA DE EMPLEADO");
    empleados_laboratorio empleado;

    char ok ='n';

    while(ok == 'n' || ok == 'N')
    {
        gotoxy(20,6);printf("Ingrese DNI: ");///verificar int HACER FUNCION
        gotoxy(20,7);printf("Ingrese Apellido y Nombre: ");///verificar string HACER FUNCION
        gotoxy(20,8);printf("Ingrese el Usuario que desea registrar: ");
        gotoxy(20,9);printf("Ingrese la Clave que desea registrar: ");
        gotoxy(20,10);printf("Ingrese su perfil (administrador/empleado/bioquimico) : ");
        fflush(stdin);
        gotoxy(33,6);scanf("%d",&empleado.dni);

        fflush(stdin);
        gotoxy(47,7);gets(empleado.ape_nombre);

        fflush(stdin);
        gotoxy(60,8);gets(empleado.usuario);

        fflush(stdin);
        gotoxy(58,9);gets(empleado.clave);

        fflush(stdin);
        gotoxy(75,10);gets(empleado.perfil);

        empleado.eliminado=0;
        getch();
        BORRAR;
        marco_menu();
        gotoxy(52,2);printf("ALTA DE EMPLEADO");
        mostrar_un_empleado(empleado,35,8);

        gotoxy(35,14);printf("Los Datos ingresados son correctos? s/n : ");
        fflush(stdin);
        gotoxy(58,14);ok=getch();

        PAUSA;
        BORRAR;


        if(ok == 'n' || ok == 'N')
        {
            printf("\nIngrese los datos nuevamente...\n\n");
            getch();
            BORRAR;
        }
    }

    return empleado;
}

void mostrar_un_empleado(empleados_laboratorio empleado, int x, int y)
{
    gotoxy(x,y++);printf("=====================================================");
    gotoxy(x,y++);printf("APELLIDO Y NOMBRE: %s [%s]", empleado.ape_nombre,empleado.perfil);
    gotoxy(x,y++);printf("DNI: %d", empleado.dni);
    gotoxy(x,y++);printf("USUARIO : [%s]", empleado.usuario);
    gotoxy(x,y++);printf("CLAVE :[%s]", empleado.clave);
    gotoxy(x,y++);printf("=====================================================");
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

void baja_empleado(char archivoEmpleado[],int dni)
{
    marco_menu();
    gotoxy(52,2);printf("BAJA DE EMPLEADO");

    empleados_laboratorio empleado;
    int encontrado=0;

    if(verificar_archivo_empleados(archivoEmpleado,dni)==1)
    {
        FILE * arch=fopen(archivoEmpleado,"r+b");

        if(arch)
        {
            while(encontrado == 0 && fread(&empleado,sizeof(empleados_laboratorio),1,arch)>0)
            {
                if(empleado.dni==dni)
                {
                    encontrado=1;///el while corta en la posicion del empleado buscado
                }
            }
            gotoxy(30,6);printf("Usted quiere dar de baja al siguiente empleado");
            mostrar_un_empleado(empleado,25,8);
            char eliminar;
            gotoxy(25,15);printf("Presione s si es correcto sino presione cualquier tecla");
            fflush(stdin);
            gotoxy(82,15);scanf("%d",&eliminar);
                if(eliminar=='s')
                {
                    empleado.eliminado=1;///modifico

                    fwrite(&empleado,sizeof(empleados_laboratorio),1,arch);///grabo
                    gotoxy(45,18);printf("Baja de Empleado Exitosa");
                }
                else
                {
                    gotoxy(35,18);printf("Cambio NO realizado, vuelva a intentarlo");
                }
                fclose(arch);
        }

    }

}

void modificacion_de_empleado(char archivoEmpleados[],int dni)
{
    empleados_laboratorio empleado;
    int encontrado=0;
    if(verificar_archivo_empleados(archivoEmpleados,dni)==1)
    {
        FILE * arch=fopen(archivoEmpleados,"r+b");
        if(arch)
        {
            while(encontrado == 0 && fread(&empleado,sizeof(empleados_laboratorio),1,arch)>0)
            {
                if(empleado.dni==dni)
                {
                    encontrado=1;///el while corta en la posicion del empleado buscado
                }
            }
            gotoxy(30,6);printf("Usted quiere modificar el siguiente empleado");
            mostrar_un_empleado(empleado,25,8);
            char eliminar;
            gotoxy(25,15);printf("Presione \"s\" si es correcto sino presione cualquier tecla");
            fflush(stdin);
            gotoxy(82,15);scanf("%d",&eliminar);
            if(eliminar=='s')
            {
                ///modifico

                ///fwrite(&empleado,sizeof(empleados_laboratorio),1,arch);///grabo
                gotoxy(45,18);printf("Baja de Empleado Exitosa");
            }
            else
            {
                marco_borde_ancho();
                gotoxy(42,3);printf("EL EMPLEADO QUE DESEA MODIFICAR NO EXISTE EN LA BASE DE DATOS");
            }
        fclose(arch);

        }

    }
}

void listado_empleados_vigentes(char archivoEmpleados[])
{
    empleados_laboratorio empleado;
    int x=25,y=4;

    FILE * arch=fopen(archivoEmpleados,"rb");

    if(arch)
    {
        gotoxy(50,2);printf("\nLISTADO DE EMPLEADOS EN NOMINA");
        PAUSA;
        while(fread(&empleado,sizeof(empleados_laboratorio),1,arch)>0)
        {
            if(empleado.eliminado==0)
            {
                mostrar_un_empleado(empleado,x,y);
            }
            PAUSA;
            x=x+7;
            y=y+7;
        }

        PAUSA;
        fclose(arch);
    }
}

void listado_empleados_eliminados(char archivoEmpleados[])
{
    marco_menu();

    empleados_laboratorio empleado;

    FILE * arch=fopen(archivoEmpleados,"rb");

    if(arch)
    {
        printf("\nLISTADO DE EMPLEADOS NO VIGENTES");
        while(fread(&empleado,sizeof(empleados_laboratorio),1,arch)>0)
        {
            if(empleado.eliminado==1)
            {
                mostrar_un_empleado(empleado, 43, 8);
            }
        }
        fclose(arch);
    }
}

int validacion_usuarioYclave(char archivoEmpleados[], char perfil[])
{
    empleados_laboratorio empleado;
    int habilitado=0;
    int i=0;
    char usuario[20];
    char clave[20];
    char caracter;
    gotoxy(57,12);fflush(stdin);gets(usuario);
    gotoxy(59,17);

    while (caracter = getch()) {
			if (caracter == TECLA_ENTER) {
				clave[i] = '\0';
				break;

			} else if (caracter == TECLA_BACKSPACE) {
				if (i > 0) {
					i--;
					printf("\b \b");
				}

			} else {
				if (i < LONGITUD) {
					printf("*");
					clave[i] = caracter;
					i++;
				}
			}
		}
    BORRAR;
    FILE * arch=fopen(archivoEmpleados,"rb");

    if(arch)
    {
        while(fread(&empleado,sizeof(empleados_laboratorio),1,arch)>0)
        {
            if(strcmp(empleado.usuario,usuario)==0 && strcmp(empleado.clave,clave)==0 && strcmpi(empleado.perfil,perfil)==0)
            {
                habilitado=1;
            }
        }
        fclose(arch);
    }
    return habilitado;
}

void mostrar_archivo(char archivo[])
{
    empleados_laboratorio empleado;

    FILE * arch=fopen(archivo,"rb");

    if(arch)
    {
        while(fread(&empleado,sizeof(empleados_laboratorio),1,arch)>0)
        {
            printf("\n APELLIDO Y NOMBRE = %s", empleado.ape_nombre);
            printf("\n               DNI = %d",empleado.dni);
            printf("\n           USUARIO = %s",empleado.usuario);
            printf("\n             CLAVE = %s",empleado.clave);
            printf("\n            PERFIL = %s", empleado.perfil);
            printf("\n=================================================\n");
        }
        fclose(arch);
    }
}

