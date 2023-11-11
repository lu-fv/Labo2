#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "diseño.h"
#include "empleado_laboratorio.h"
#include "pacientes.h"
#include "ingresos_Labo.h"
#include "practicas_ingreso.h"
#include "practicas_Labo.h"
#define ESC 27
#define ARCHIVO_PACIENTES "pacientes.dat"

pacientes cargaPacientes()
{
   pacientes p;

   printf ("\n\n\t\t>>>>> INGRESO NUEVO PACIENTE: <<<<<<\n");


    printf ("\n NOMBRE Y APELLIDO: \n");
    fflush (stdin);
    gets (p.nomb_apell);
    printf ("\n DIRECCION: \n");
    fflush (stdin);
    gets (p.direccion);
    printf ("\n EDAD:\n");
    fflush (stdin);
    scanf ("%d", &p.edad);
    printf ("\n Nro. CELULAR:\n");
    fflush (stdin);
    gets (p.telefono);
    p.eliminado =0;
    ///p.ingreso = NULL;

    return p;
}
void imprimirUnPaciente( pacientes p)
{

    printf("\n\t     >>>>> DATOS PACIENTE: <<<<<< \n");
    printf("\n\t     EDAD: ...............%d",p.edad);
    printf("\n\t  NOMBRE Y APELLIDO: ................%s", p.nomb_apell);
    printf("\n\t DIRECCION: ...............%s", p.direccion);
    printf("\n\t       DNI: ...............%d", p.dni);
    printf("\n\t   Nro.CEL: ...............%s\n\n", p.telefono);

    if(p.eliminado==0)
    {
        printf("\n\t EL PACIENTE ESTA ACTIVO \n\n\n ");
    }else{
        printf("\n\t EL PACIENTE ESTA INACTIVO \n\n\n");
    }

}

nodoArbol * inicArbol()
{
    return NULL;
}
nodoArbol * crearNodoPacientes (pacientes p)
{
    nodoArbol* nuevoNodo = (nodoArbol*)malloc (sizeof (nodoArbol));

    nuevoNodo->p = p;
    nuevoNodo->der =NULL;
    nuevoNodo ->izq = NULL;

    return nuevoNodo;

}
nodoArbol* insertarPacientes ( nodoArbol* miArbol, pacientes p)
{

    if(miArbol==NULL)
    {
        miArbol = crearNodoPacientes(p);
    }
    else
    {
        if ( p.dni > miArbol->p.dni)
        {
            miArbol->der = insertarPacientes(miArbol->der, p);
        }
        else
        {

            miArbol->izq = insertarPacientes(miArbol->izq, p);
        }
    }
    return miArbol;
}

int verificarPaciente (FILE* arc, int dni)
{
   int flag =0;
   pacientes p;

    while((flag ==0)&& fread(&p, sizeof(pacientes), 1, arc)>0)
       {
           if(p.dni==dni) //si encuentra dni
            {
               if(p.eliminado==0) // esta activo
                {
                    flag=1;
                }
                else // esta pero dado de baja
                {
                   flag=-1;
                }
            }

      }
    return flag;
}

void reactivaPaciente (FILE* arc, pacientes p)
{
        p.eliminado =0;
        fseek (arc, sizeof (pacientes)*-1, SEEK_CUR);
        fwrite (&p, sizeof (pacientes), 1, arc);

        printf ("\n Se reactivo paciente correctamente\n");
}

void altaPacientes (char archivo[])
{
    pacientes p;

    FILE* arc = fopen (archivo, "r+b");

    if (arc)
    {
    printf ("\n DNI:\n");
    fflush (stdin);
    scanf ("%d", &p.dni);

     if (verificarPaciente (arc, p.dni)==0)
     {
         p= cargaPacientes ();
         fseek (arc, sizeof(pacientes)*-1, SEEK_CUR);
         fwrite(&p,sizeof(pacientes),1,arc);
     }
     if (verificarPaciente (arc,p.dni)==1)
      {
          printf ("\n ya se encuentra ingresado\n");
      }
     else (verificarPaciente (arc, p.dni)==-1);
     {
         reactivaPaciente (arc, p);
     }

     fclose (arc);
   }

}

/*void menu_modifica_campo_registro(FILE * archivo, pacientes paciente)
{
    menu:
    BORRAR;
    system("COLOR E");marco_menu();

    int opc;
    char rta;

    gotoxy(48,2);printf("MODIFICA PACIENTE");
    gotoxy(35,7);printf("Seleccione el campo que desea modificar");

    gotoxy(43,9);printf("1) NOMBRE Y APELLIDO");
    gotoxy(43,10);printf("2) DNI");
    gotoxy(43,11);printf("3) EDAD");
    gotoxy(43,12);printf("4) TELEFONO");
    gotoxy(43,13);printf("5) DIRECCION");
    gotoxy(43,14);printf("6) SALIR...");
    gotoxy(45,15);printf("OPCION SELECCIONADA...");
    gotoxy(70,15);scanf("%d",&opc);

    do
    {
        switch(opc)
        {
        case 1:
            system ("cls");
            marco_menu();
            modificarNombreYapellido (ARCHIVO_PACIENTES,paciente);
            goto menu;

        case 2:
            system ("cls");
            marco_menu();
            modificarDni (char ARCHIVO_PACIENTES,paciente);
            goto menu;

        case 3:
            BORRAR;
            marco_menu();
            modificarEdad (ARCHIVO_PACIENTES,paciente);
            goto menu;

        case 4:
            BORRAR;
            marco_menu();
            modificarTel (ARCHIVO_PACIENTES,paciente);
            goto menu;

        case 5:
            BORRAR;
            marco_menu();
            modificarDireccion (ARCHIVO_PACIENTES, paciente);
            goto menu;

        case 6:
            BORRAR;
            break;
        }
}
    while(opc!=6);
}


void modificarNombreYapellido (char archivo[], pacientes p)
{
            printf("Ingrese el nuevo Apellido y Nombre : ");
            fflush(stdin);
            gets(p.nomb_apell);
            imprimirUnPaciente(p);
            ("Los datos son correctos? s/n : ");
            fflush(stdin);
            scanf("%c",&rta);
            if(rta=='s'|| rta=='S')
            {
                fseek(archivo,sizeof(pacientes)*-1,SEEK_CUR);
                fwrite(&p,sizeof(pacientes),1,archivo);
                printf("MODIFICACION EXITOSA");
                getch();
            }
            else
            {
                printf("VUELVA A SELECCIONAR LA OPCION A MODIFICAR O PRESIONE SALIR");
                getch();
            }
}

void modificarDdni (char archivo[], pacientes p)
{
            printf("Ingrese el nuevo DNI : ");
            fflush(stdin);
            scanf ("&c",p.dni);
            imprimirUnPaciente(p);
            printf("Los datos son correctos? s/n : ");
            fflush(stdin);
            scanf("%c",&rta);
            if(rta=='s'|| rta=='S')
            {
                fseek(archivo,sizeof(pacientes)*-1,SEEK_CUR);
                fwrite(&p,sizeof(pacientes),1,archivo);
                printf("MODIFICACION EXITOSA");
            }
            else
            {
                printf("VUELVA A SELECCIONAR LA OPCION A MODIFICAR O PRESIONE SALIR");
            }
}

void modificarEdad (char archivo[],pacientes p)
{
            printf("Ingrese el nueva edad : ");
            fflush(stdin);
            gets(p.edad);
            imprimirUnPaciente(p);
            printf("Los datos son correctos? s/n : ");
            fflush(stdin);
            scanf("%c",&rta);
            if(rta=='s'|| rta=='S')
            {
                fseek(archivo,sizeof(pacientes)*-1,SEEK_CUR);
                fwrite(&p,sizeof(pacientes),1,archivo);
                printf("MODIFICACION EXITOSA");
            }
            else
            {
                printf("VUELVA A SELECCIONAR LA OPCION A MODIFICAR O PRESIONE SALIR");
            }
}

void modificarTel (char archivo[], pacientes p)
{
            printf("Ingrese el nuevo cel : ");
            fflush(stdin);
            gets (p.telefono);
            imprimirUnPaciente(p);
            printf("Los datos son correctos? s/n : ");
            fflush(stdin);
            scanf("%c",&rta);
            if(rta=='s'|| rta=='S')
            {
                fseek(archivo,sizeof(pacientes)*-1,SEEK_CUR);
                fwrite(&p,sizeof(pacientes),1,archivo);
                printf("MODIFICACION EXITOSA");
            }
            else
            {
                printf("VUELVA A SELECCIONAR LA OPCION A MODIFICAR O PRESIONE SALIR");
            }
}

void modificarDireccion (char archivo[], pacientes p)
{

            printf("Ingrese nueva direccion : ");
            fflush(stdin);
            gets (p.direccion);
            imprimirUnPaciente(p);
            printf("Los datos son correctos? s/n : ");
            fflush(stdin);
            scanf("%c",&rta);
            if(rta=='s'|| rta=='S')
            {
                fseek(archivo,sizeof(pacientes)*-1,SEEK_CUR);
                fwrite(&p,sizeof(pacientes),1,archivo);
                printf("MODIFICACION EXITOSA");
            }
            else
            {
                printf("VUELVA A SELECCIONAR LA OPCION A MODIFICAR O PRESIONE SALIR");
            }
}

*/
