#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "empleado_laboratorio.h"
#include "pacientes.h"
#include "ingresos_Labo.h"
#include "practicas_ingreso.h"
#include "practicas_Labo.h"

#define ARCHIVO_EMPLEADOS "archivo_empleados.dat"
#define ARCHIVO_PRACXINGRESO "practicaXingreso.dat"
#define BORRAR system("cls")
#define PAUSA system("pause")

///coordenadas de impresion en pantalla
void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X= x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}


///marcos
void marco_borde_ancho()
{
    for(int i=0;i<=119;i++)
    {
        gotoxy(0+i,0);printf("%c",223);
    }
    for(int i=0;i<=119;i++)
    {
        gotoxy(0+i,28);printf("%c",220);
    }
    for(int j=0;j<=28;j++)
    {
        gotoxy(0,0+j);printf("%c",219);
    }
    for(int j=0;j<=28;j++)
    {
        gotoxy(119,0+j);printf("%c",219);
    }
}

void marco_plantilla()
{
    ///linea horizontal superior
    printf("%c",201);
    for(int i=1;i<=118;i++)
    {
        gotoxy(0+i,0);printf("%c",205);
    }
    printf("%c",187);

    ///linea horizontal inferior
    gotoxy(0,28);printf("%c",200);
    for(int i=1;i<=118;i++)
    {
        gotoxy(0+i,28);printf("%c",205);
    }
    printf("%c",188);

    ///linea vertical izquierda
    for(int j=1;j<8;j++)
    {
        gotoxy(0,0+j);printf("%c",186);
    }
    gotoxy(0,8);printf("%c",204);

     for(int i=1;i<=118;i++)
    {
        gotoxy(0+i,8);printf("%c",205);
    }

    for(int j=9;j<28;j++)
    {
        gotoxy(0,0+j);printf("%c",186);
    }

    for(int i=1;i<=118;i++)
    {
        gotoxy(0+i,28);printf("%c",205);
    }
    printf("%c",188);

    ///linea vertical derecha
    for(int j=1;j<8;j++)
    {
        gotoxy(119,0+j);printf("%c",186);
    }
    gotoxy(119,8);printf("%c",185);

    for(int j=9;j<28;j++)
    {
        gotoxy(119,0+j);printf("%c",186);
    }
}

void marco_factura()
{
    ///linea horizontal superior
    printf("%c",201);
    for(int i=1;i<=60;i++)
    {
        gotoxy(0+i,0);printf("%c",205);
    }
    printf("%c",187);

    ///linea horizontal inferior
    gotoxy(0,28);printf("%c",200);
    for(int i=1;i<=60;i++)
    {
        gotoxy(0+i,28);printf("%c",205);
    }
    printf("%c",188);

    ///linea vertical izquierda
    for(int j=1;j<8;j++)
    {
        gotoxy(0,0+j);printf("%c",186);
    }
    gotoxy(0,8);printf("%c",204);

     for(int i=1;i<=60;i++)
    {
        gotoxy(0+i,8);printf("%c",205);
    }

    for(int j=9;j<28;j++)
    {
        gotoxy(0,0+j);printf("%c",186);
    }

    for(int i=1;i<=60;i++)
    {
        gotoxy(0+i,28);printf("%c",205);
    }
    printf("%c",188);

    ///linea vertical derecha
    for(int j=1;j<8;j++)
    {
        gotoxy(61,0+j);printf("%c",186);
    }
    gotoxy(61,8);printf("%c",185);

    for(int j=9;j<28;j++)
    {
        gotoxy(61,0+j);printf("%c",186);
    }
}

void marco_menu()
{
    ///linea horizontal superior
    printf("%c",201);
    for(int i=1;i<=118;i++)
    {
        gotoxy(0+i,0);printf("%c",205);
    }
    printf("%c",187);

    ///linea horizontal inferior
    gotoxy(0,28);printf("%c",200);
    for(int i=1;i<=118;i++)
    {
        gotoxy(0+i,28);printf("%c",205);
    }
    printf("%c",188);

    ///linea vertical izquierda
    for(int j=1;j<8;j++)
    {
        gotoxy(0,0+j);printf("%c",186);
    }
    gotoxy(0,4);printf("%c",204);

     for(int i=1;i<=118;i++)
    {
        gotoxy(0+i,4);printf("%c",205);
    }

    for(int j=5;j<28;j++)
    {
        gotoxy(0,0+j);printf("%c",186);
    }

    for(int i=1;i<=118;i++)
    {
        gotoxy(0+i,28);printf("%c",205);
    }
    printf("%c",188);

    ///linea vertical derecha
    for(int j=1;j<4;j++)
    {
        gotoxy(119,0+j);printf("%c",186);
    }
    gotoxy(119,4);printf("%c",185);

    for(int j=5;j<28;j++)
    {
        gotoxy(119,0+j);printf("%c",186);
    }
}

void marco_contrasenia()
{
    ///linea horizontal superior
    gotoxy(40,9);printf("%c",201);
    for(int i=41;i<=79;i++)
    {
        gotoxy(0+i,9);printf("%c",205);
    }
    gotoxy(80,9);printf("%c",187);

    ///linea horizontal inferior
    gotoxy(40,19);printf("%c",200);
    for(int i=41;i<=79;i++)
    {
        gotoxy(0+i,19);printf("%c",205);
    }
    gotoxy(80,19);printf("%c",188);

    ///linea vertical izquierda
    for(int j=10;j<14;j++)
    {
        gotoxy(40,0+j);printf("%c",186);
    }
    gotoxy(40,14);printf("%c",204);

    for(int j=15;j<19;j++)
    {
        gotoxy(40,0+j);printf("%c",186);
    }

    for(int i=41;i<=79;i++)
    {
        gotoxy(0+i,14);printf("%c",205);
    }
    gotoxy(80,14);printf("%c",185);

    ///linea vertical derecha
    for(int j=10;j<14;j++)
    {
        gotoxy(80,0+j);printf("%c",186);
    }

    for(int j=15;j<19;j++)
    {
        gotoxy(80,0+j);printf("%c",186);
    }
}


///plantillas
void plantilla_laboratorios_x_paciente()
{
    marco_plantilla();
    system("COLOR E");
    gotoxy(15,2);printf("FECHA: 10/10/2023");
    gotoxy(80,2);printf("MEDICO: BELTRAN, JORGE");
    gotoxy(15,5);printf("Nro LABORATORIO: 027");
    gotoxy(80,5),printf("PACIENTE: 154");

    gotoxy(10,11);printf("%c GLUCEMIA .................",254);
    gotoxy(40,11);printf("RESULTADO: 107 mg/dl  ......");
    gotoxy(70,11);printf("VALOR DE REFERENCIA:  < 110 mg/dl ......");

    gotoxy(10,12);printf("%c CREATININEMIA ............",254);
    gotoxy(40,12);printf("RESULTADO: 0.73 mg/dl  .....");
    gotoxy(70,12);printf("VALOR DE REFERENCIA:  0.52-1.06 mg/dl ..");

    gotoxy(10,13);printf("%c COLESTEROL TOTAL .........",254);
    gotoxy(40,13);printf("RESULTADO: 205 mg/dl   .....");
    gotoxy(70,13);printf("VALOR DE REFERENCIA:  < 200 mg/dl ......");

    getch();

}

void factura()
{
    marco_factura();
    system("COLOR E");
    gotoxy(4,2);printf("FECHA: 10/10/2023");
    gotoxy(37,2);printf("Nro FACTURA: 01-003");
    gotoxy(4,4);printf("NOMBRE Y APELLIDO: NEIRA MARIA EUGENIA");
    gotoxy(4,5);printf("DNI: 31561321");

    gotoxy(6,11);printf("%c PRACTICA:  .......",254);
    gotoxy(30,11);printf("IMPORTE: $   ......");

    gotoxy(6,12);printf("%c PRACTICA:  .......",254);
    gotoxy(30,12);printf("IMPORTE: $   ......");

    gotoxy(6,13);printf("%c PRACTICA:  .......",254);
    gotoxy(30,13);printf("IMPORTE: $   ......");

    gotoxy(6,15);printf("%c COBERTURA:  .......",254);
    gotoxy(4,17);printf("______________________________________________________");
    gotoxy(15,20);printf("%c IMPORTE TOTAL:  .......",254);

    gotoxy(65,2);printf("Presione ALT+P para imprimir");

    getch();

}


///menu
void menu()
{
    menu:
    BORRAR;
    system("COLOR E");marco_menu();

    int opc;

    gotoxy(48,2);printf("MENU PRINCIPAL");

    gotoxy(43,6);printf("1) ACCESO ADMINISTRADOR");
    gotoxy(43,7);printf("2) ACCESO ADMINISTRATIVO");
    gotoxy(43,8);printf("3) ACCESO PROFESIONALES");
    gotoxy(43,9);printf("4) SALIR");
    /*gotoxy(43,10);printf("5) QUINTA OPCION");
    gotoxy(43,11);printf("6) SEXTA OPCION");
    gotoxy(43,12);printf("7) SEPTIMA OPCION");
    gotoxy(43,13);printf("8) SALIR");*/
    gotoxy(45,11);printf("OPCION SELECCIONADA...");
    gotoxy(70,11);scanf("%d",&opc);

    do
    {
        switch(opc)
        {
        case 1:
            BORRAR;
            menu_contrasenia();

            if(validacion_usuarioYclave(ARCHIVO_EMPLEADOS,"administrador")==1)
            {
                menu_administrador();
            }
            else
            {
                marco_borde_ancho();
                gotoxy(35,2);printf("contraseña o usuario incorrecto");
                getch();
            }
            goto menu;

        case 2:
            BORRAR;
            menu_contrasenia();

            if(validacion_usuarioYclave(ARCHIVO_EMPLEADOS,"empleado")==1)
            {
                menu_gestion_administrativa();
            }
            else
            {
                marco_borde_ancho();
                gotoxy(35,2);printf("contraseña o usuario incorrecto");
                getch();
            }
            goto menu;

        case 3:
            BORRAR;
            menu_contrasenia();
            char usuario[20];
            char clave[20];

            if(validacion_usuarioYclave(ARCHIVO_EMPLEADOS,"bioquimico")==1)
            {
                menu_bioquimico();
            }
            else
            {
                marco_borde_ancho();
                gotoxy(35,2);printf("contraseña o usuario incorrecto");
                getch();
            }
            goto menu;

        /*case 4:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 4");
            getch();
            goto menu;

        case 5:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 5");
            getch();
            goto menu;

        case 6:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 6");
            getch();
            goto menu;

        case 7:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 7");
            getch();
            goto menu;*/

        case 4:
            BORRAR;
            marco_borde_ancho();
            gotoxy(50,3);printf("EXIT....");
            getch();
            break;
        }

    }while(opc!=4);

}

void menu_administrador()
{
    menu:
    BORRAR;
    system("COLOR E");marco_menu();

    int opc;

    gotoxy(45,2);printf("MENU ADMINISTRADOR");

    gotoxy(43,6);printf("1) EMPLEADOS");
    gotoxy(43,7);printf("2) PACIENTES");
    gotoxy(43,8);printf("3) PRACTICAS");
    gotoxy(43,9);printf("4) LABORATORIOS");
    /*gotoxy(43,10);printf("5) QUINTA OPCION");
    gotoxy(43,11);printf("6) SEXTA OPCION");
    gotoxy(43,12);printf("7) SEPTIMA OPCION");*/
    gotoxy(43,10);printf("5) SALIR");
    gotoxy(45,12);printf("OPCION SELECCIONADA...");
    gotoxy(70,12);scanf("%d",&opc);

    do
    {
        switch(opc)
        {
        case 1:
            BORRAR;
            menu_administrador_empleados();
            goto menu;

        case 2:
            BORRAR;
            menu_administrador_pacientes();
            goto menu;

        case 3:
            BORRAR;
            menu_administrador_practicas();
            goto menu;

        case 4:
            BORRAR;
            menu_administrador_laboratorios();
            goto menu;

        /*case 5:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 5");
            getch();
            goto menu;

        case 6:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 6");
            getch();
            goto menu;

        case 7:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 7");
            getch();
            goto menu;*/

        case 5:
            BORRAR;
            break;
        }

    }while(opc!=5);

}

void menu_gestion_administrativa()
{
    menu:
    BORRAR;
    system("COLOR E");marco_menu();

    int opc;

    gotoxy(45,2);printf("MENU DE ADMINISTRACION");

    gotoxy(47,6);printf("1) PACIENTE");
    gotoxy(47,7);printf("2) PRACTICAS");
    gotoxy(47,8);printf("3) LABORATORIOS");
    gotoxy(47,9);printf("4) SALIR");
    /*gotoxy(43,10);printf("5) QUINTA OPCION");
    gotoxy(43,11);printf("6) SEXTA OPCION");
    gotoxy(43,12);printf("7) SEPTIMA OPCION");
    gotoxy(43,13);printf("8) SALIR");*/
    gotoxy(50,11);printf("OPCION SELECCIONADA...");
    gotoxy(72,11);scanf("%d",&opc);

    do
    {
        switch(opc)
        {
        case 1:
            BORRAR;
            menu_gestion_administrativa_pacientes();
            goto menu;

        case 2:
            BORRAR;
            menu_gestion_administrativa_practicas();
            goto menu;

        case 3:
            BORRAR;
            menu_gestion_administrativa_laboratorios();
            goto menu;

        /*case 4:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 4");
            getch();
            goto menu;

        case 5:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 5");
            getch();
            goto menu;

        case 6:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 6");
            getch();
            goto menu;

        case 7:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 7");
            getch();
            goto menu;*/

        case 4:
            BORRAR;
            break;
        }

    }while(opc!=4);

}

void menu_bioquimico()
{
    menu:
    BORRAR;
    system("COLOR E");marco_menu();

    int opc;

    gotoxy(45,2);printf("MENU DE PROFESIONALES");

    gotoxy(40,6);printf("1) BUSQUEDA LABORATORIO X ID");
    gotoxy(40,7);printf("2) BUSQUEDA DE LABORATORIO X PACIENTE");
    /*gotoxy(43,8);printf("3) TERCERA OPCION");
    gotoxy(43,9);printf("4) CUARTA OPCION");
    gotoxy(43,10);printf("5) QUINTA OPCION");
    gotoxy(43,11);printf("6) SEXTA OPCION");
    gotoxy(43,12);printf("7) SEPTIMA OPCION");*/
    gotoxy(40,8);printf("3) SALIR");
    gotoxy(43,10);printf("OPCION SELECCIONADA...");
    gotoxy(68,10);scanf("%d",&opc);

    do
    {
        switch(opc)
        {
        case 1:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 1");
            getch();
            goto menu;

        case 2:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 2");
            getch();
            goto menu;

        case 3:
            BORRAR;
            break;

        /*case 4:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 4");
            getch();
            goto menu;

        case 5:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 5");
            getch();
            goto menu;

        case 6:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 6");
            getch();
            goto menu;

        case 7:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 7");
            getch();
            goto menu;

        case 8:
            BORRAR;
            marco_borde_ancho();
            gotoxy(50,3);printf("EXIT....");
            getch();
            break;*/

        }

    }while(opc!=3);
}

void menu_administrador_empleados()
{
    menu:
    BORRAR;
    system("COLOR E");marco_menu();

    int opc;

    gotoxy(42,2);printf("MENU ADMINISTRADOR - EMPLEADOS");

    gotoxy(43,6);printf("1) ALTA DE EMPLEADO");
    gotoxy(43,7);printf("2) BAJA DE EMPLEADO");
    gotoxy(43,8);printf("3) MODIFICACION DE EMPLEADO");
    gotoxy(43,9);printf("4) LISTADO DE EMPLEADOS EN NOMINA");
    gotoxy(43,10);printf("5) LISTADO DE EMPLEADOS NO VIGENTES");
    gotoxy(43,11);printf("6) BLANQUEO DE CLAVES");
    ///gotoxy(43,12);printf("7) SEPTIMA OPCION");
    gotoxy(43,12);printf("7) SALIR");
    gotoxy(45,14);printf("OPCION SELECCIONADA...");
    gotoxy(70,14);scanf("%d",&opc);

    do
    {
        switch(opc)
        {
        case 1:
            BORRAR;
            char rta='s';

            while(rta=='s')
            {
                alta_empleado(ARCHIVO_EMPLEADOS);
                printf("\nDesea ingresar un nuevo empleado? s/n : ");
                fflush(stdin);
                scanf("%c",&rta);
                BORRAR;
            }
            goto menu;
        case 2:
            BORRAR;
            int dnibaja;
            marco_menu();
            gotoxy(52,2);printf("BAJA DE EMPLEADO");
            gotoxy(20,6),printf("INGRESE EL DNI DEL EMPLEADO QUE QUIERE DAR DE BAJA : ");
            fflush(stdin);
            gotoxy(80,6);scanf("%d",&dnibaja);
            BORRAR;
            ///validar dni
            baja_empleado(ARCHIVO_EMPLEADOS, dnibaja);
            getch();
            goto menu;

        case 3:
            BORRAR;
            int dni_a_modificar;
            marco_menu();
            gotoxy(45,2);printf("MODIFICACION DE EMPLEADO");
            gotoxy(20,6),printf("INGRESE EL DNI DEL EMPLEADO QUE QUIERE MODIFICAR : ");
            fflush(stdin);
            gotoxy(75,6);scanf("%d",&dni_a_modificar);
            ///validar dni
            modificacion_de_empleado(ARCHIVO_EMPLEADOS,dni_a_modificar);
            goto menu;

        case 4:
            BORRAR;
            listado_empleados_vigentes(ARCHIVO_EMPLEADOS);
            goto menu;

        case 5:
            BORRAR;
            listado_empleados_eliminados(ARCHIVO_EMPLEADOS);
            goto menu;

        case 6:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("que se hace aca????");
            getch();
            goto menu;

       /*case 7:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 7");
            getch();
            goto menu;*/

        case 7:
            BORRAR;
            break;
        }

    }while(opc!=7);

}

void menu_administrador_pacientes()
{
     menu:
    BORRAR;
    system("COLOR E");marco_menu();

    int opc;

    gotoxy(42,2);printf("MENU ADMINISTRADOR - PACIENTES");

    gotoxy(43,6);printf("1) ALTA PACIENTES");
    gotoxy(43,7);printf("2) BAJA PACIENTES");
    gotoxy(43,8);printf("3) MODIFICACION DE PACIENTES");
    gotoxy(43,9);printf("4) LISTADO DE PACIENTES VIGENTES");
    gotoxy(43,10);printf("5) LISTADO DE PACIENTES ELIMINADOS");
    gotoxy(43,11);printf("6) BUSQUEDA DE PACIENTES");
    ///gotoxy(43,12);printf("7) SEPTIMA OPCION");
    gotoxy(43,12);printf("7) SALIR");
    gotoxy(45,14);printf("OPCION SELECCIONADA...");
    gotoxy(70,14);scanf("%d",&opc);

    do
    {
        switch(opc)
        {
        case 1:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 1");
            getch();
            goto menu;

        case 2:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 2");
            getch();
            goto menu;

        case 3:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 3");
            getch();
            goto menu;

        case 4:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 4");
            getch();
            goto menu;

        case 5:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 5");
            getch();
            goto menu;

        case 6:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 6");
            getch();
            goto menu;

        /*case 7:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 7");
            getch();
            goto menu;*/

        case 7:
            BORRAR;
            break;
        }

    }while(opc!=7);

}

void menu_administrador_practicas()
{
     menu:
    BORRAR;
    system("COLOR E");marco_menu();

    int opc;

    gotoxy(42,2);printf("MENU ADMINISTRADOR - PRACTICAS");

    gotoxy(43,6);printf("1) ALTA DE PRACTICA");
    gotoxy(43,7);printf("2) BAJA DE PRACTICA");
    gotoxy(43,8);printf("3) MODIFICACION DE PRACTICA");
    gotoxy(43,9);printf("4) LISTADO DE PRACTICAS AUTORIZADAS");
    /*gotoxy(43,10);printf("5) QUINTA OPCION");
    gotoxy(43,11);printf("6) SEXTA OPCION");
    gotoxy(43,12);printf("7) SEPTIMA OPCION");*/
    gotoxy(43,10);printf("5) SALIR");
    gotoxy(45,12);printf("OPCION SELECCIONADA...");
    gotoxy(70,12);scanf("%d",&opc);

    do
    {
        switch(opc)
        {
        case 1:
            BORRAR;
            marco_menu();
            gotoxy(52,2);printf("ALTA DE PRACTICA");
            AltaDePracticasNuevas(Practicas_Laboratorio);
            getch();
            goto menu;

        case 2:
            BORRAR;
            marco_menu();
            gotoxy(52,2);printf("BAJA DE PRACTICA");
            char nombre[30];
            gotoxy(30,5);printf("Ingrese el Nombre de la Practica que desea dar de baja = ");
            fflush(stdin);
            scanf("%s",&nombre);
            BORRAR;
            bajaDePractica(Practicas_Laboratorio,nombre);
            goto menu;

        case 3:
            BORRAR;
            marco_menu();
            char practicamodif[30];
            gotoxy(52,2);printf("MODIFICACION DE PRACTICA");
            gotoxy(30,6);printf("Ingrese el nombre de la practica: ");
            fflush(stdin);
            gotoxy(65,6);gets(practicamodif);
            ModificacionArchivoPracticas(Practicas_Laboratorio,practicamodif);
            getch();
            goto menu;

        case 4:
            BORRAR;
            marco_menu();
            gotoxy(52,2);printf("LISTADO DE PRACTICAS");
            listado_practicas_ordenadas_alfabeticamente(Practicas_Laboratorio);
            getch();
            goto menu;

        /*case 5:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 5");
            getch();
            goto menu;

        case 6:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 6");
            getch();
            goto menu;

        case 7:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 7");
            getch();
            goto menu;*/

        case 5:
            BORRAR;
            break;

        }

    }while(opc!=5);

}

void menu_administrador_laboratorios()
{
    menu:
    BORRAR;
    system("COLOR E");marco_menu();

    int opc;

    gotoxy(42,2);printf("MENU ADMINISTRADOR - LABORATORIOS");

    gotoxy(43,6);printf("1) ALTA DE LABORATORIO");
    gotoxy(43,7);printf("2) BAJA DE LABORATORIO");
    gotoxy(43,8);printf("3) MODIFICACION DE LABORATORIO");
    gotoxy(43,9);printf("4) LISTADO DE LABORATORIOS VIGENTES");
    gotoxy(43,10);printf("5) LISTADO DE LABORATORIOS ELIMINADOS");
    /*gotoxy(43,11);printf("6) SEXTA OPCION");
    gotoxy(43,12);printf("7) SEPTIMA OPCION");*/
    gotoxy(43,11);printf("6) SALIR");
    gotoxy(45,13);printf("OPCION SELECCIONADA...");
    gotoxy(70,13);scanf("%d",&opc);

    do
    {
        switch(opc)
        {
        case 1:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 1");
            getch();
            goto menu;

        case 2:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 2");
            getch();
            goto menu;

        case 3:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 3");
            getch();
            goto menu;

        case 4:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 4");
            getch();
            goto menu;

        case 5:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 5");
            getch();
            goto menu;

        /*case 6:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 6");
            getch();
            goto menu;

        case 7:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 7");
            getch();
            goto menu;*/

        case 6:
            BORRAR;
            break;

        }

    }while(opc!=6);
}

void menu_administrador_resultados()
{
    menu:
    BORRAR;
    system("COLOR E");marco_menu();

    int opc;

    gotoxy(42,2);printf("ADMINISTRADOR - CARGA DE RESULTADOS");

    gotoxy(43,6);printf("1) BUSQUEDA LABORATORIO X ID");
    gotoxy(43,7);printf("2) BUSQUEDA DE LABORATORIO X PACIENTE");
    /*gotoxy(43,8);printf("3) TERCERA OPCION");
    gotoxy(43,9);printf("4) CUARTA OPCION");
    gotoxy(43,10);printf("5) QUINTA OPCION");
    gotoxy(43,11);printf("6) SEXTA OPCION");
    gotoxy(43,12);printf("7) SEPTIMA OPCION");*/
    gotoxy(43,8);printf("3) SALIR");
    gotoxy(45,10);printf("OPCION SELECCIONADA...");
    gotoxy(68,10);scanf("%d",&opc);

    do
    {
        switch(opc)
        {
        case 1:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 1");
            getch();
            goto menu;

        case 2:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 2");
            getch();
            goto menu;

        case 3:
            BORRAR;
            break;

        /*case 4:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 4");
            getch();
            goto menu;

        case 5:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 5");
            getch();
            goto menu;

        case 6:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 6");
            getch();
            goto menu;

        case 7:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 7");
            getch();
            goto menu;

        case 8:
            BORRAR;
            marco_borde_ancho();
            gotoxy(50,3);printf("EXIT....");
            getch();
            break;*/

        }

    }while(opc!=3);
}

void menu_gestion_administrativa_pacientes()
{
    menu:
    BORRAR;
    system("COLOR E");marco_menu();

    int opc;

    gotoxy(42,2);printf("MENU ADMINISTRATIVO PACIENTES");

    gotoxy(43,6);printf("1) ALTA DE PACIENTES");
    gotoxy(43,7);printf("2) BAJA DE PACIENTES");
    gotoxy(43,8);printf("3) MODIFICACION DE PACIENTES");
    gotoxy(43,9);printf("4) LISTADO DE PACIENTES VIGENTES");
    gotoxy(43,10);printf("5) LISTADO DE PACIENTES ELIMINADOS");
    gotoxy(43,11);printf("6) BUSQUEDA DE PACIENTE");
    ///gotoxy(43,12);printf("7) SEPTIMA OPCION");
    gotoxy(43,12);printf("7) SALIR");
    gotoxy(45,14);printf("OPCION SELECCIONADA...");
    gotoxy(70,14);scanf("%d",&opc);

    do
    {
        switch(opc)
        {
        case 1:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 1");
            getch();
            goto menu;

        case 2:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 2");
            getch();
            goto menu;

        case 3:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 3");
            getch();
            goto menu;

        case 4:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 4");
            getch();
            goto menu;

        case 5:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 5");
            getch();
            goto menu;

        case 6:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 6");
            getch();
            goto menu;

        /*case 7:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 7");
            getch();
            goto menu;*/

        case 7:
            BORRAR;
            break;
        }

    }while(opc!=7);

}

void menu_gestion_administrativa_practicas()
{
    menu:
    BORRAR;
    system("COLOR E");marco_menu();

    int opc;

    gotoxy(42,2);printf("MENU ADMINISTRATIVO PRACTICAS");

    gotoxy(43,6);printf("1) ALTA DE PRACTICA");
    gotoxy(43,7);printf("2) BAJA DE PRACTICA");
    gotoxy(43,8);printf("3) MODIFICACION DE PRACTICA");
    gotoxy(43,9);printf("4) LISTADO DE PRACTICAS AUTORIZADAS");
    gotoxy(43,10);printf("5) SALIR");
    /*gotoxy(43,11);printf("6) SEXTA OPCION");
    gotoxy(43,12);printf("7) SEPTIMA OPCION");
    gotoxy(43,13);printf("8) SALIR");*/
    gotoxy(45,12);printf("OPCION SELECCIONADA...");
    gotoxy(70,12);scanf("%d",&opc);

    do
    {
        switch(opc)
        {
        case 1:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 1");
            getch();
            goto menu;

        case 2:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 2");
            getch();
            goto menu;

        case 3:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 3");
            getch();
            goto menu;

        case 4:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 4");
            getch();
            goto menu;

        /*case 5:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 5");
            getch();
            goto menu;

        case 6:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 6");
            getch();
            goto menu;

        case 7:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 7");
            getch();
            goto menu;*/

        case 5:
            BORRAR;
            break;
        }

    }while(opc!=5);

}

void menu_gestion_administrativa_laboratorios()
{
    menu:
    BORRAR;
    system("COLOR E");marco_menu();

    int opc;

    gotoxy(42,2);printf("MENU ADMINISTRATIVO LABORATORIOS");

    gotoxy(43,6);printf("1) ALTA DE LABORATORIOS");
    gotoxy(43,7);printf("2) BAJA DE LABORATORIOS");
    gotoxy(43,8);printf("3) MODIFICACION DE LABORATORIO");
    gotoxy(43,9);printf("4) LISTADO DE LABORATORIOS VIGENTES");
    gotoxy(43,10);printf("5) LISTADO DE LABORATORIOS ELIMINADOS");
    /*gotoxy(43,11);printf("6) SEXTA OPCION");
    gotoxy(43,12);printf("7) SEPTIMA OPCION");*/
    gotoxy(43,11);printf("6) SALIR");
    gotoxy(45,13);printf("OPCION SELECCIONADA...");
    gotoxy(70,13);scanf("%d",&opc);

    do
    {
        switch(opc)
        {
        case 1:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 1");
            getch();
            goto menu;

        case 2:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 2");
            getch();
            goto menu;

        case 3:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 3");
            getch();
            goto menu;

        case 4:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 4");
            getch();
            goto menu;

        case 5:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 5");
            getch();
            goto menu;

        /*case 6:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 6");
            getch();
            goto menu;

        case 7:
            BORRAR;
            marco_borde_ancho();
            gotoxy(35,2);printf("HACEMOS LO QUE CORRESPONDE A LA OPCION 7");
            getch();
            goto menu;*/

        case 6:
            BORRAR;
            break;
        }

    }while(opc!=6);

}

void menu_contrasenia()
{
    char login[20];
    int password;
    marco_contrasenia();
    gotoxy(57,10);printf("LOGIN:");gotoxy(56,15);printf("PASSWORD:");
}


///carga arbol de la base de datos de los 3 archivos (empleado,ingresos_lab y practicasXingreso)

/*void carga_arbol()
{
    nodoArbol * arbol=NULL;

    FILE * pac=fopen(ARCHIVO_PACIENTES,"rb");
    pacientes pacientito;
    FILE * ing=fopen(ARCHIVOINGRESOS,"rb");
    laboratorios ingreso;
    FILE * prac=fopen(ARCHIVO_PRACXINGRESO,"rb");
    pracXingreso practica;

    if(pac && ing && prac)
    {
        ///carga los pacientes al arbol
        while(fread(&pacientito,sizeof(pacientes),1,pac)>0)
        {
            ///cargo paciente en el arbol
            carga_arbol_un_paciente(arbol,crearNodoPacientes(pacientito));
            ///verifico que el paciente tenga ingresos de laboratorios y
            ///si tiene ingresos procedo a cargar la lista de ingresos del nodo arbol paciente
            if(valida_existencia_de_ingresos_x_paciente(ARCHIVOINGRESOS,pacientito.dni)==1)
            {
                nodoArbol * arbolpaciente=busca_nodopaciente_en_arbol(arbol,pacientito.dni);

                while(fread(&ingreso,sizeof(laboratorios),1,ing)>0)
                {
                    if(ingreso.dni_paciente==pacientito.dni)
                    {
                        ///arbolpaciente->ingreso=agregarAlFinalIngresos(arbolpaciente->ingreso,crearNodoIngreso(ingreso));
                    }
                }
                ///procedo a cargar las practicas al ingreso correspondiente
                while(fread(&practica,sizeof(pracXingreso),1,ing)>0)
                {
                    if(practica.nro_de_ingreso == ingreso.Nro_de_ingreso)
                    {
                        ///arbolpaciente->ingreso->practica=agregarAlFinalListaPracticas(arbolpaciente->ingreso->practica,crearNodoListaPracticas(practica));

                    }
                }
            }

        }

        fclose(pac);
        fclose(ing);
        fclose(prac);
    }
}

int valida_existencia_de_ingresos_x_paciente(char archivoingresos[],int dni_paciente)
{
    laboratorios ing;
    int existeIngreso=-1;
    FILE * arch=fopen(archivoingresos,"rb");

    if(arch)
    {
        while(existeIngreso==-1 && fread(&ing,sizeof(laboratorios),1,arch)>0)
        {
            if(ing.dni_paciente==dni_paciente)
            {
                existeIngreso=1;
            }
        }
        fclose(arch);
    }
    return existeIngreso;
}

nodoArbol * busca_nodopaciente_en_arbol(nodoArbol * arbol, int dni)
{
    nodoArbol * pacientebuscado;

    if(arbol->p.dni==dni)
    {
        pacientebuscado=arbol;
    }
    else
    {
        if(dni < arbol->p.dni)
        {
            arbol->izq=busca_nodopaciente_en_arbol(arbol->izq,dni); //pacientebuscado =busca_paciente_en_arbol(arbol->izq,dni);
        }
        else
        {
            arbol->der=busca_nodopaciente_en_arbol(arbol->der,dni); //pacientebuscado =busca_paciente_en_arbol(arbol->der,dni);
        }
    }


    return pacientebuscado;
}

/*nodoArbol * crear_nodo_arbol(pacientes p)
{
    nodoArbol * nuevo=(nodoArbol*)malloc(sizeof(nodoArbol));

    nuevo->p=p;
    nuevo->izq=NULL;
    nuevo->ingreso=NULL;

    return nuevo;
}

nodoListaPracticas * crearNodoListaPracticas(pracXingreso practica)
{
    nodoListaPracticas * nuevo = (nodoListaPracticas*)malloc(sizeof(nodoListaPracticas));

    nuevo->ingreso=practica;
    nuevo->siguiente=NULL;

    return nuevo;
}

 nodoArbol * carga_arbol_un_paciente(nodoArbol * arbol,nodoArbol * nuevo)
{
    if(arbol==NULL)
    {
        arbol=nuevo;
    }
    else
    {
        if(nuevo->p.dni > arbol->p.dni)
        {
            arbol->der=carga_arbol_un_paciente(arbol->der,nuevo);
        }
        else
        {
            arbol->izq=carga_arbol_un_paciente(arbol->izq,nuevo);
        }
    }
}
*/

