#include <stdio.h>
#include <string.h>

#define MAX_ALUMNOS 50
#define MAX_TAREAS 50

// Estructuras
typedef struct {
    char nombre[50];
    char descripcion[100];
} Tarea;

typedef struct {
    char nombre[50];
} Alumno;

typedef struct {
    int idAlumno;
    int idTarea;
    float calificacion;
} Calificacion;
