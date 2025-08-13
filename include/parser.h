/* Ver Archivo LICENSE Para detalles sobre la licencia*/
#ifndef __PARSER__
#define __PARSER__
/*Estructura para caracterizar operaciones*/
typedef struct Operacion{
  char *cadena;
  unsigned int orden;
  Operacion *argumento;
} operacion;

/*Estructura para caracterizar procedimientos o bloques de código*/
typedef struct Procedimiento{
  char *cadena;
  unsigned int orden;
  Operacion *listaop;
  Operacion *argumento;
  Procedimiento *listaproc;
} Procedimiento;

/*Función para levantar argumentos y procedimientos*/
int leer_archivo(char *dir, Procedimiento *procs, Operacion *ops);

/*Función para generar código y excportarlo a un archivo*/
int generar_archivo(char *dir, Procedimiento *procs, Operacion *ops);
#endif
