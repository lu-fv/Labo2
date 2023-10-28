#ifndef EMPLEADO_LABORATORIO_H_INCLUDED
#define EMPLEADO_LABORATORIO_H_INCLUDED

typedef struct
{
    int dni;
    char ape_nombre [40];
    char usuario [20];
    char clave [20];
    char perfil [20];
    int eliminado;///0 por defecto
}empleados_laboratorio;

empleados_laboratorio crearRegistroEmpleados();
void mostrar_un_empleado(empleados_laboratorio empleado);
void alta_empleado(char archivoEmpleado[]);
int verificar_archivo_empleados(char archivo[],int DNI);
int verificar_usuario_unico(char archivo[],char usuarioNuevo[]);


#endif // EMPLEADO_LABORATORIO_H_INCLUDED
