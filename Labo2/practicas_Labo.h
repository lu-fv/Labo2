#ifndef PRACTICAS_LABO_H_INCLUDED
#define PRACTICAS_LABO_H_INCLUDED

typedef struct
{
    int nro_de_practica;
    char nombre[30];
    int vigencia;///0 vigente,1 NO vigente

}practicas;

typedef struct
{
    practicas datos_cargados;
    struct nodo * siguiente;
}nodo;

practicas CrearPracticaLaboratorio ();
int verificarSiExistePractica(FILE * nombreArchivo, char * PracticaNueva);
void AltaDePracticasNuevas(char * nombreArchivo);
practicas ModificacionArchivoPracticas(char * nombreArchivo, char * nombrePractica);


#endif // PRACTICAS_LABO_H_INCLUDED
