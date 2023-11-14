#include <time.h>
#include <stdio.h>
#include <string.h>

#include "diseño.h"
#include "empleado_laboratorio.h"
#include "pacientes.h"
#include "ingresos_Labo.h"
#include "practicas_ingreso.h"
#include "practicas_Labo.h"

#define PAUSA system("pause")
#define BORRAR system("cls")

///para pegar en el main o posterior


void fechaActual(char fecha[])
{
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    strftime(fecha,128,"%d/%m/%y",tlocal);
}


int autoincrementalIngresos(char archivo[])
{
    FILE * archi = fopen(archivo, "rb");

    laboratorios registro;
    int i=0;

    if(archi)
    {
        fseek(archi, sizeof(laboratorios)*-1,SEEK_END);
        while(fread(&registro, sizeof(laboratorios), 1, archi)>0)
        {
            i=registro.Nro_de_ingreso;
        }
        fclose(archi);
    }

    return i+1;

}

laboratorios nuevoRegistro(char archivo[], nodoArbol * arbol)
{
    char ok ='n';
    laboratorios nuevo;
    char fecha[50];
    char opc=0;
    ///le asigno la fecha de hoy al string "fecha", que se usará en la carga (automática, no la requerirá al usuario)
    fechaActual(fecha);

    marco_menu();
    gotoxy(20,6);
    printf("Ingrese DNI del Paciente: ");
    fflush(stdin);
    gotoxy(33,6);
    scanf("%d",&nuevo.dni_paciente);

    int buscado = posicionPaciente(ARCHIVO_PACIENTES, nuevo.dni_paciente);

    if(buscado == 0)
    {
        printf("\nEl paciente bajo el numero de DNI %d no existe, Desea darlo de alta? S/N: ", nuevo.dni_paciente);
        fflush(stdin);
        scanf("%c", &opc);
        if(opc== 's' || 'S')
        {
            altaPacientes(ARCHIVO_PACIENTES);
        }
        else
        {
            printf("\nVolviendo al menu de laboratorios");
            PAUSA;
            /// agregar volver al menu de laboratorios
        }


    }
    else
    {
        if(buscado == -1)
        {
            printf("\nEl paciente bajo el numero de DNI %d se encuentra dado de baja, desea reactivarlo? S/N");
            fflush(stdin);
            scanf("%c", &opc);
            if(opc== 's' || 'S')
            {
                printf("\nRedirigiendo al menu de alta de pacientes\n");
                altaPacientes(ARCHIVO_PACIENTES);
            }
            else
            {
                printf("\nVolviendo al menu de laboratorios");
                PAUSA;
                /// agregar volver al menu de laboratorios
            }
        }
    }

    ///ACA DEBERIA HABER UNA FUNCION QUE INFORME SI EL PACIENTE NO EXISTE EN LA BASE, PARA REMITIRLO A ESE MENU



    if(ok == 'n' || ok == 'N' && buscado == 1)
    {


        gotoxy(20,7);
        printf("Nro de Ingreso: ");///verificar string HACER FUNCION
        gotoxy(20,8);
        printf("Fecha de ingreso: ");
        gotoxy(20,9);
        printf("Fecha de retiro: ");
        gotoxy(20,10);
        printf("Ingrese Matricula del Medico ordenante: ");

        gotoxy(20,7);printf("Nro de Ingreso: ");///automatico
        gotoxy(20,8);printf("Fecha de ingreso: ");///automatico
        gotoxy(20,9);printf("Fecha de retiro: ");///automatico
        gotoxy(20,10);printf("Ingrese Matricula del Medico ordenante: ");



        fflush(stdin);
        gotoxy(47,7);
        nuevo.Nro_de_ingreso = autoincrementalIngresos(ARCHIVOINGRESOS);

        fflush(stdin);
        gotoxy(60,8);
        strcpy(nuevo.fecha_de_ingreso, fecha);

        fflush(stdin);
        gotoxy(58,9);
        strcpy(nuevo.fecha_de_retiro, "a confirmar");

        fflush(stdin);
        gotoxy(75,10);
        scanf("%d", nuevo.medico_matricula);

        nuevo.vigencia=0; ///vigente

        return nuevo;
    }


}





nodoListaIngresos * crearNodoIngreso(laboratorios nuevo)
{
    nodoListaIngresos * lista = (nodoListaIngresos*) malloc(sizeof(nodoListaIngresos));

    lista->lab = nuevo;
    lista->siguiente=NULL;

    return lista;
}


nodoListaIngresos * agregarAlFinalIngresos(nodoListaIngresos * lista, nodoListaIngresos * nuevo)
{
    nodoListaIngresos * aux = lista;
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        while(aux->siguiente!= NULL)
        {
            aux= aux->siguiente;
        }
        aux->siguiente= nuevo;

    }

    return lista;
}


/*void altaDeLaboratorio(char archivo[], laboratorios registro, nodoArbol * arbol)
{
    FILE * archi = fopen(archivo, "ab");
    int opc=0;

    if(archi)
    {
        printf("\nDesea cargar un nuevo laboratorio? Presione cualquier tecla para continuar o ESC para salir: ");
        scanf("%d", &opc);

        while(opc!=27)
        {
            registro = nuevoRegistro(archivo, arbol);
            printf("\nDesea cargar otro laboratorio? Presione cualquier tecla para continuar o ESC para salir: ");
            scanf("%d", &opc);
            fwrite(&registro, sizeof(laboratorios), 1, archi);
        }


        fclose(archi);
    }




}*/

    ///grabar el cambio tambien al arbol o  bien usar la funcion de traer todos los datos del archivo al ADLDL




/*nodoArbol * grabarEnArbol(nodoArbol * arbol, laboratorios registro)
{

}*/

void bajDeLabXId(int id, char archivo[], nodoArbol * arbol)
{
    FILE *archi=fopen(archivo, "r+b");
    laboratorios lab;
    int bandera=0;
    if(archi)
    {
        while(bandera == 0 && fread(&lab, sizeof(laboratorios), 1, archi)>0)
        {
            ///QUE NO TENGA PRACTICAS

            if(id==lab.Nro_de_ingreso && lab.vigencia==0) ///si encuentra el id y siempre y cuando no se encuentre dado de baja
            {
                bandera=1; /// para cortar la busqueda si encuentra y no recorra todo el archivo
                fseek(archi, (-1)*sizeof(laboratorios), SEEK_CUR); ///retrocede 1 registro
                lab.vigencia=1;
                fwrite(&lab, sizeof(laboratorios), 1, archi);
                printf("\n el Laboratorio de ID: %i  fue eliminado.\n", id);
                PAUSA;
            }

        }

        ///CONSULTAR SI PODEMOS UTILIZAR LA FUNCION DE TRAER TODOS LOS DATOS DEL ARCHIVO AL ARBOL
        /*
        ///busca el laboratorio con ese id en el arbol
        nodoListaIngresos * aux= arbol->listaIngresos;


        ///ELIMINAMOS LAS PRACTICAS REALIZADAS POR ESE LABORATORIO EN CASCADA
        if(bandera == 1)
        {
             while(aux !=NULL)
            {
                if(aux->lab.Nro_de_ingreso == id)
                {
                    while(aux->listaPracticas != NULL)
                    {
                        aux->listaPracticas->datoPractica.vigencia=1;
                        aux->listaPracticas = aux->listaPracticas->siguiente;
                        ///ACA DEBERIA GRABAR EL CAMBIO EN EL ARCHIVO DE PRACTICAS X INGRESOS
                    }
                    aux= aux->siguiente;
                }
            }

        if(bandera==0)
        {
<<<<<<< HEAD
            printf("\n La ID: %i  no fue encontrada en el archivo o se encuentra dado de baja, consultar en listado respectivo.");
=======
                printf("\n La ID: %i  no fue encontrada en el archivo o ya se encuentra dado de baja, consultar en listado respectivo.");
>>>>>>> d1dc65145e3ee9562b397570dd155d7646734a14

        }*/

        fclose(archi);

    }

}





void modificacionDeLaboratorio(char archivo[])
{
    FILE* archi = fopen(archivo,"r+b");
    laboratorios lab;
    int id;
    int bandera=0;
    int nuevo;
    int opc;
    char fecha[20];

    if(archi)
    {
        printf("\nIngrese el numero de ingreso del laboratorio que desea modificar:\n");
        fflush(stdin);
        scanf("%d",&id);

        while((bandera==0)&&(fread(&lab,sizeof(laboratorios),1,archi)>0)) ///CORTA BUSQUEDA CON EL FLAG
        {
            if(lab.Nro_de_ingreso==id && lab.vigencia==0)///MIENTRAS SE ENCUENTER DADO DE ALTA Y SI LO ENCUENTRA
            {
                bandera=1;
            }
        }

        if(bandera==1)///SE EJECUTA TODO EL MENU SI LO ENCUENTRA, SINO VA AL ELSE FINAL
        {
            fseek(archi,-1*sizeof(laboratorios),SEEK_CUR); ///SE POSICIONA AL INICIO DEL REGISTRO ENCONTRADO
            do
            {
                system("cls");
                printf("\n Elija la Opcion que Desea Modificar:\n");
                printf("\n1 - DNI del Paciente\n");
                printf("\n2 - Fecha de retiro de resultados");
                printf("\n3 - Matricula del Medico");
                printf("\n5 - Ir al Menu Anterior\n");
                fflush(stdin);
                scanf("%d",&opc);

                switch(opc)
                {
                case 1:
                    system("cls");
                    printf("\nIngrese DNI del paciente correcto:\n");
                    fflush(stdin);
                    scanf("%d",&nuevo);
                    lab.dni_paciente=nuevo;
                    break;
                case 2:
                    system("cls");
                    printf("\nIngrese nueva fecha de retiro de resultados:\n");
                    fflush(stdin);
                    scanf("%s",&fecha);
                    strcpy(lab.fecha_de_retiro, fecha);
                    break;
                case 3:
                    system("cls");
                    printf("\nIngrese la matricula correcta:\n");
                    fflush(stdin);
                    scanf("%d",&nuevo);
                    lab.medico_matricula=nuevo;
                    break;
                case 4:
                    system("cls");
                    ///ACA AGREGAR VOLVER AL MENU ANTERIOR;
                    break;
                default:
                    system("cls");
                    printf("\nUsted a seleccionado una opcion incorrecta.Reintente nuevamente.\n");
                    break;
                }

            }
            while(opc!=6);

            fwrite(&lab,sizeof(laboratorios),1,archi);

        }
        else
        {
            BORRAR;
            printf("\nEl Laboratorio se encuentra dado de Baja\n"); ///CUANDO LA.BAJA ==1 (ELIMINADO)
            PAUSA;
        }


 void listadoDeLaboratoriosVigentes(nodoArbol * arbol)
{
    nodoArbol * aux = arbol;
    if(aux != NULL)
    {
        /// los muestra en orden
        printf("\n.........................LISTADO DE INGRESO DE LABORATORIO VIGENTES.............................\n");

        listadoDeLaboratoriosVigentes(aux->izq);
        if(aux->listaIngresos->lab.vigencia==0)
        {
            mostrarListaiIngresos(aux->listaIngresos);
        }
        listadoDeLaboratoriosVigentes(aux->der);

        }
}

        /*FILE* archi = fopen(archivo,"rb");
        laboratorios lab;

        if(archi)
        {
            printf("\n.........................LISTADO DE LABORATORIOS VIGENTES.............................\n");
            while(fread(&lab,sizeof(laboratorios),1,archi)>0)
            {
                if(lab.vigencia == 0) ///MIENTRAS SE ENCUENTRE VIGENTE
                {

                    printf("\n          NUMERO DE INGRESO: %d\n", lab.Nro_de_ingreso);
                    printf("\n           FECHA DE INGRESO: %s\n", lab.fecha_de_ingreso);
                    printf("\n            FECHA DE RETIRO: %s\n", lab.fecha_de_retiro);
                    printf("\n           DNI DEL PACIENTE: %d\n", lab.dni_paciente);
                    printf("\n       MATRICULA DEL MEDICO: %d\n", lab.medico_matricula);

                    puts("\n.........................................................................................\n");
                }
            }

>>>>>>> d1dc65145e3ee9562b397570dd155d7646734a14
        fclose(archi);

    }
    else
    {
        printf("\nERROR DEL ARCHIVO\n");
    }
}



void listadoDeLaboratoriosVigentes(char archivo[])
{
    FILE* archi = fopen(archivo,"rb");
    laboratorios lab;

    if(archi)
    {
        printf("\n.........................LISTADO DE LABORATORIOS VIGENTES.............................\n");
        while(fread(&lab,sizeof(laboratorios),1,archi)>0)
        {
<<<<<<< HEAD
            if(lab.vigencia == 0) ///MIENTRAS SE ENCUENTRE VIGENTE
            {

                printf("\n          NUMERO DE INGRESO: %d\n", lab.Nro_de_ingreso);
                printf("\n           FECHA DE INGRESO: %s\n", lab.fecha_de_ingreso);
                printf("\n            FECHA DE RETIRO: %s\n", lab.fecha_de_retiro);
                printf("\n           DNI DEL PACIENTE: %d\n", lab.dni_paciente);
                printf("\n       MATRICULA DEL MEDICO: %d\n", lab.medico_matricula);

                puts("\n.........................................................................................\n");
            }
        }
=======
            printf("\nERROR DEL ARCHIVO\n");
        }*/

        fclose(archi);
    }
    else
    {
        printf("\nERROR DEL ARCHIVO\n");
    }


void mostrarListaiIngresos(nodoListaIngresos * lista)
{
    nodoListaIngresos * ingreso = lista;

    while(ingreso != NULL)
    {
        printf("\n          NUMERO DE INGRESO: %d\n", ingreso->lab.Nro_de_ingreso);
        printf("\n           FECHA DE INGRESO: %s\n", ingreso->lab.fecha_de_ingreso);
        printf("\n            FECHA DE RETIRO: %s\n", ingreso->lab.fecha_de_retiro);
        printf("\n           DNI DEL PACIENTE: %d\n", ingreso->lab.dni_paciente);
        printf("\n       MATRICULA DEL MEDICO: %d\n", ingreso->lab.medico_matricula);

        puts("\n.........................................................................................\n");

        ingreso=ingreso->siguiente;
    }




void listadoDeLaboratoriosEliminados(nodoArbol * arbol)
{

    nodoArbol * aux = arbol;
    if(aux != NULL)
    {
        /// los muestra en orden
        printf("\n.........................LISTADO DE INGRESO DE LABORATORIO VIGENTES.............................\n");

        listadoDeLaboratoriosEliminados(aux->izq);
        if(aux->listaIngresos->lab.vigencia==1)
        {
            mostrarListaiIngresos(aux->listaIngresos);
        }
        listadoDeLaboratoriosEliminados(aux->der);

    }
}


    /*
    FILE* archi = fopen(archivo,"rb");
    laboratorios lab;

    if(archi)
    {
        printf("\n.........................LISTADO DE LABORATORIOS ELIMINADOS.............................\n");
        while(fread(&lab,sizeof(laboratorios),1,archi)>0)
        {
            if(lab.vigencia == 1) ///MIENTRAS NO SE ENCUENTREN VIGENTE
            {

                printf("\n          NUMERO DE INGRESO: %d\n", lab.Nro_de_ingreso);
                printf("\n           FECHA DE INGRESO: %s\n", lab.fecha_de_ingreso);
                printf("\n            FECHA DE RETIRO: %s\n", lab.fecha_de_retiro);
                printf("\n           DNI DEL PACIENTE: %d\n", lab.dni_paciente);
                printf("\n       MATRICULA DEL MEDICO: %d\n", lab.medico_matricula);

                puts("\n.........................................................................................\n");
            }
        }

        fclose(archi);
    }
    else
    {
        printf("\nERROR DEL ARCHIVO\n");
    }


}


}*/

