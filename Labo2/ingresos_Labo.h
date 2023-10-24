#ifndef INGRESOS_LABO_H_INCLUDED
#define INGRESOS_LABO_H_INCLUDED

typedef struct
{
    int Nro_de_ingreso;
    char fecha_de_ingreso[10]; //por defecto la actual
    char fecha_de_retiro [10];
    int dni_paciente;
    int medico_matricula;
    int vigencia;///0 vigente, 1 NO vigente
}laboratorios;


#endif // INGRESOS_LABO_H_INCLUDED
