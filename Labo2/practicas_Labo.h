#ifndef PRACTICAS_LABO_H_INCLUDED
#define PRACTICAS_LABO_H_INCLUDED
#define Practicas_Laboratorio "practicas.dat"

typedef struct
{
    int nro_de_practica;
    char nombre[30];
    int vigencia;///0 vigente,1 NO vigente
    struct practicas * siguiente;
}practicas;

practicas CrearPracticaLaboratorio ();
int autoincrementalPracticas(char archivo[]);
///int verificarSiExistePractica(char archivo[], char PracticaNueva[]);
void AltaDePracticasNuevas(char * nombreArchivo);
void ModificacionArchivoPracticas(char nombreArchivo[]);
practicas buscaPoscionPractica(FILE * arch,char nombrePractica[]);


#endif // PRACTICAS_LABO_H_INCLUDED
