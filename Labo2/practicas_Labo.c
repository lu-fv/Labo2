#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define ESC 27

#include "practicas_Labo.h"
#include "diseño.h"

practicas CrearPracticaLaboratorio ()
{
    practicas nuevaPractica;

    nuevaPractica.nro_de_practica=autoincrementalPracticas(Practicas_Laboratorio);
    printf("Ingrese el nombre de la practica: \n");
    fflush(stdin);
    gets(nuevaPractica.nombre);
    nuevaPractica.vigencia=0;

    return nuevaPractica;
}

int autoincrementalPracticas(char archivo[])
{
    FILE * archi = fopen(archivo, "rb");

    practicas p;
    int i=0;

    if(archi)
    {
        fseek(archi, sizeof(practicas)*-1,SEEK_END);
        while(fread(&p, sizeof(practicas), 1, archi)>0)
        {
            i=p.nro_de_practica;
        }
    fclose(archi);
    }

    return i+1;
}

///funcion para verificar si existe la practica
int verificarSiExistePractica(char archivo[], char PracticaNueva[])
{
    int flag = 0;

    FILE * arch=fopen(archivo,"rb");
    practicas PracticaExistente;

    if(arch)
    {
        while(flag == 0 && fread(&PracticaExistente, sizeof(practicas), 1, arch)>0)
        {
            if(strcmpi(PracticaExistente.nombre, PracticaNueva)==0 && PracticaExistente.vigencia==0)
            {
                flag = 1;
            }
        }
        fclose(arch);
    }

    return flag;
}

///damos de alta una nueva práctica por usuario, verificando que no exista previamente en el archivo de prácticas
void AltaDePracticasNuevas(char nombreArchivo[])
{
    char opcion='s', modifica;

    while(opcion == 's'||opcion=='S')
    {
        practicas NuevaPractica=CrearPracticaLaboratorio();

        if(verificarSiExistePractica(nombreArchivo, NuevaPractica.nombre)==0)
        {
            FILE * archivo = fopen(nombreArchivo, "ab");

            if(archivo)
            {
                fwrite(&NuevaPractica, sizeof(practicas), 1, archivo);
                printf("¿Desea seguir cargando prácticas? s/n\n");
                fflush(stdin);
                scanf("%c",&opcion);
                fclose(archivo);
            }
            else
            {
                printf("No se pudo abrir el archivo\n");
                opcion='n';
            }
        }
        else
        {
            printf("La práctica ya existe. ¿Desea modificar su nombre? s/n \n");
            fflush(stdin);
            modifica = getch();

            if(modifica=='s'|| modifica=='S')
            {
                ModificacionArchivoPracticas(nombreArchivo);
                printf("¿Desea seguir cargando prácticas? S/N\n");
                fflush(stdin);
                scanf("%c",&opcion);
            }

        }

    }

}


///Función para modificar el nombre de la práctica
void ModificacionArchivoPracticas(char nombreArchivo[])
{
    char practicaModifica[30];
    char opcion;

    printf("\nINGRESE LA PRACTICA QUE DESEA MODIFICAR: ");
    fflush(stdin);
    gets(practicaModifica);

    if(verificarSiExistePractica(nombreArchivo,practicaModifica)== 1)
    {
        FILE * archi = fopen(nombreArchivo, "r+b");
        practicas Pract;

        if(archi)
        {
            Pract=buscaPoscionPractica(archi,practicaModifica);
            printf("Ingrese el nuevo nombre de la practica\n");
            fflush(stdin);
            gets(Pract.nombre);
            fseek(archi,sizeof(practicas)*-1,SEEK_CUR);
            fwrite(&Pract, sizeof(practicas), 1, archi);

            fclose(archi);
        }
        else
        {
            printf("Error al abrir el archivo\n");
        }
    }
    else
    {
        printf("No existe la práctica que acaba de ingresar. ¿Desea crearla? S/N");
        opcion = getch();
        if(opcion == 'S' || opcion == 's')
        {
            AltaDePracticasNuevas(nombreArchivo);
        }
    }

}

practicas buscaPoscionPractica(FILE * arch,char nombrePractica[])
{
    practicas registro;
    fseek(arch,0,SEEK_SET);
    int flag=0;

    while(flag==0 && fread(&registro,sizeof(practicas),1,arch)>0)
    {
        if(registro.nombre==nombrePractica)
        {
            flag=1;
        }
    }

    return registro;
}
