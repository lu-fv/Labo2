#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define Practicas_Laboratorio "practicas.dat"
#define ESC 27

#include "practicas_Labo.h"
#include "diseño.h"


///Alta_de_practica

///crear un ingreso
practicas CrearPracticaLaboratorio ()
{
    practicas nuevaPractica;

//   nuevo.nro_de_practica = //funcion autoincremental Gabi;
    printf("Ingrese el nombre de la practica: \n");
    fflush(stdin);
    gets(nuevaPractica.nombre);
    printf("Ingrese informacion sobre la vigencia. 0 si no está vigente o 1 si está vigente: \n");///yo le pondria por defecto 1 porque se supone que es un ingreso (euge)
    scanf("%d", &nuevaPractica.vigencia);

    return nuevaPractica;
}

///funcion para verificar si existe la practica
int verificarSiExistePractica(FILE * nombreArchivo, char PracticaNueva[])
{
    int flag = 0;

    practicas PracticaExistente;

    if(nombreArchivo)
    {
        while(flag == 0 && fread(&PracticaExistente, sizeof(practicas), 1, nombreArchivo)>0)
        {
            if(strcmpi(PracticaExistente.nombre, PracticaNueva)==0)
            {
                flag = 1;
            }
        }
    }

    return flag;
}


///damos de alta una nueva práctica por usuario, verificando que no exista previamente en el archivo de prácticas
void AltaDePracticasNuevas(char nombreArchivo[])
{
    practicas NuevaPractica;
    FILE * archivo = fopen(nombreArchivo, "ab");
    char opcion;

    if(archivo)
    {
        while(opcion != ESC)
        {
            NuevaPractica = CrearPracticaLaboratorio();

            if(verificarSiExistePractica(archivo, NuevaPractica.nombre)==0)
            {
                fwrite(&NuevaPractica, sizeof(practicas), 1, archivo);
                printf("¿Desea seguir cargando prácticas? Presione ESC para cancelar o cualquier tecla para continuar\n");
                fflush(stdin);
                opcion = getch();
            }
            else
            {
                printf("La práctica ya existe. ¿Desea modificar su nombre? Presione cualquier tecla para continuar y modificar o ESC para salir\n");
                fflush(stdin);
                opcion = getch();

                if(opcion != ESC)
                {
                    ModificacionArchivoPracticas(nombreArchivo, NuevaPractica.nombre);
                }

                printf("¿Desea seguir cargando prácticas? Presione ESC para cancelar o cualquier tecla para continuar\n");
                fflush(stdin);
                opcion = getch();
            }
        }
        fclose(archivo);
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }

}

///Función para modificar el nombre de la práctica
void ModificacionArchivoPracticas(char * nombreArchivo, char * nombrePractica)
{
    practicas PracticaAModificar;
    FILE * archi = fopen(nombreArchivo, "r+b");
    char opcion;

    printf("Ingrese nombre de practica a modificar\n");

    if(archi)
    {
        if(verificarSiExistePractica(archi, nombrePractica)== 1)
        {
            fseek(archi, -1 * sizeof(archi),SEEK_CUR);
            fread(&PracticaAModificar, sizeof(practicas), 1, archi);
            printf("Ingrese el nuevo nombre de la practica\n");
            fflush(stdin);
            gets(PracticaAModificar.nombre);
            fseek(archi, -1 * sizeof(archi),SEEK_CUR);
            fwrite(&PracticaAModificar, sizeof(practicas), 1, archi);
            printf("Se modificó la práctica\n");
        }
        else
        {
            printf("No existe la práctica que acaba de ingresar. ¿Desea crearla? S/N");
            opcion = getch();
            if(opcion == 'S')
            {
                AltaDePracticasNuevas(nombreArchivo);
            }
        }
        fclose(archi);
    }

    else
    {
        printf("Error al abrir el archivo\n");
    }
}
