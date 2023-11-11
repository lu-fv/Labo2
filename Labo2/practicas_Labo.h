#ifndef PRACTICAS_LABO_H_INCLUDED
#define PRACTICAS_LABO_H_INCLUDED
#define Practicas_Laboratorio "practicas.dat"

typedef struct
{
    int nro_de_practica;
    char nombre[30];
    int vigencia;///0 vigente,1 NO vigente
} practicas;

practicas CrearPracticaLaboratorio ();
int autoincrementalPracticas(char archivo[]);
///int verificarSiExistePractica(char archivo[], char PracticaNueva[]);
void AltaDePracticasNuevas(char nombreArchivo[]);
void bajaDePractica(char archivo[],char nombrePractica[]);
void ModificacionArchivoPracticas(char nombreArchivo[],char nombrePractica[]);
practicas buscaPoscionPractica(FILE * arch,char nombrePractica[]);
void reactivacion_Practica(char archivoPractica[], char nombrePractica[]);
void listado_practicas_ordenadas_alfabeticamente(char archivoP[]);
int cargar_arreglo_practicas_ordenado_x_apellido(practicas * arreglo, practicas p, int validos);
void mostrar_arreglo_practicas(practicas arreglo[],int validos);
void mostrar_una_practica(practicas p, int x, int y);
void busca_practica_y_muestra(char archivoPrac[], char nomPrac[]);

#endif // PRACTICAS_LABO_H_INCLUDED
