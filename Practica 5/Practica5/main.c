#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUMNOS 50
#define MAX_TAREAS 50
#define MAX_PERSONAS 50

// Estructuras principales

// Estructura para guardar los datos de una tarea
typedef struct {
    char nombre[50];
    char descripcion[100];
} Tarea;
