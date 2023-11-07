#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conio.h"

#define ARCHIVO_PRACXINGRESO "practicaXingreso.dat"
#define BORRAR system("cls")
#define PAUSA system("pause")

void alta_de_UNA_practXingreso(int numIngreso)
{
    FILE * arch=fopen(ARCHIVO_PRACXINGRESO,"ab");

    pracXingreso p;
    p=registro_practXingreso(numIngreso);

    if(arch)
    {
        fwrite(&p,sizeof(pracXingreso),1,arch);

        fclose(arch);
    }
}

pracXingreso registro_practXingreso(int numIngreso)
{
        pracXingreso pXi;
    char nompractica[30];
    int verifica_practica;

    if(verifica_existe_ingreso(numIngreso)==1)
    {
        listado_pract_vigentes();
        printf("Ingrese el nombre de la practica que desea dar de alta: ");
        fflush(stdin);
        gets(nompractica);
        verifica_practica=busca_num_practica_vigente(nompractica);
        if(verifica_practica>=0)///Si la practica esta todo bien termina de cargar los campos.
        {
            pXi.nro_de_practica=verifica_practica;
            strcpy(pXi.nombre,nompractica);
            pXi.vigencia=0;
            strcpy(pXi.resultado,"A CONFIRMAR");
            pXi.siguiente=NULL;
        }
    }
    return pXi;
}

int verifica_existe_ingreso(int numIngreso)///verifica si existe ingreso "Y" si esta vigente
{
    FILE * arch=fopen(ARCHIVOINGRESOS,"rb");
    laboratorios lab;
    int flag=0;

    if(arch)
    {
        while(flag==0 && fread(&lab,sizeof(laboratorios),1,arch)>0)
        {
            if(lab.Nro_de_ingreso==numIngreso && lab.vigencia==0)
            {
                flag=1;
            }
        }
         fclose(arch);
    }
    if(flag==0)
    {
        printf("\nla practica ingresada no esta disponible");
    }

    return flag;
}

void listado_pract_vigentes()
{
    FILE * arch=fopen(Practicas_Laboratorio,"rb");
    practicas p;

    printf("\nLISTADO DE PRACTICAS VIGENTES\n");
    if(arch)
    {
        while(fread(&p,sizeof(practicas),1,arch)>0)
        {
            if(p.vigencia==0)
            {
                printf("\n[%s]",p.nombre);
                printf("\n======================================");
            }
        }
        fclose(arch);
    }
}

int busca_num_practica_vigente(char practica[])
{
    ///verifica si existe practica "Y" si esta vigente retornando el numero de practica.
    ///Si no cumple estas condiciones retorna -1 (si la practica no existe o no esta vigente
    FILE * arch=fopen(Practicas_Laboratorio,"rb");
    practicas p;
    int flag=-1;

    if(arch)
    {
        while(flag==-1 && fread(&p,sizeof(practicas),1,arch)>0)
        {
            if(p.nombre==practica && p.vigencia==0)
            {
                flag=p.nro_de_practica;
            }
        }
        fclose(arch);
    }

    if(flag==-1)
    {
        printf("\nLa practica ingresada no se encuentra vigente");
    }

    return flag;
}




