#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED
typedef struct
{

    char nomb_apell[40];
    int edad;
    int dni;
    char telefono[15];
    char direccion[30];
    int eliminado;///0 vigente,1 eliminado
}pacientes;



#endif // PACIENTES_H_INCLUDED
