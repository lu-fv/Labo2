#include "Pacientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define ESC 27


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
    printf ("\n DNI:\n");
    fflush (stdin);
    scanf ("%d", &p.dni);
    printf ("\n EDAD:\n");
    fflush (stdin);
    scanf ("%d", &p.edad);
    printf ("\n Nro. CELULAR:\n");
    fflush (stdin);
    gets (p.telefono);
    p.eliminado =1;

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

