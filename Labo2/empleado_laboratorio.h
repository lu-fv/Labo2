#ifndef EMPLEADO_LABORATORIO_H_INCLUDED
#define EMPLEADO_LABORATORIO_H_INCLUDED

typedef struct
{
    int dni;
    char ape_nombre [40];
    char usuario [20];
    char clave [20];
    char perfil [20];
}empleados_laboratorio;

typedef struct
{
    empleados_laboratorio empleado;
    struct nodo * siguiente;
}nodoEmpleado;


#endif // EMPLEADO_LABORATORIO_H_INCLUDED
