#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUMNOS 50
#define MAX_TAREAS 50
#define MAX_PERSONAS 50

// Estructuras principales

// Estructura para guardar los datos de una tarea
typedef struct
{
    char nombre[50];
    char descripcion[100];
} Tarea;

// Estructura para guardar los datos de un alumno
typedef struct
{
    char nombre[50];
} Alumno;

// Estructura que relaciona un alumno con una tarea y su calificación
typedef struct
{
    int idAlumno;
    int idTarea;
    float calificacion;
} Calificacion;

// Estructura para el editor de texto (nueva parte)
typedef struct
{
    char nombre[50];
    char cargo[50];
} Persona;


// Variables globales
// ----------------------------
Tarea tareas[MAX_TAREAS];
Alumno alumnos[MAX_ALUMNOS];
Calificacion calificaciones[MAX_ALUMNOS * MAX_TAREAS];

int contadorTareas = 0;
int contadorAlumnos = 0;
int contadorCalificaciones = 0;

// Variables para el módulo de texto
Persona personas[MAX_PERSONAS];
int contadorPersonas = 0;
char *mensaje = NULL; // Texto base (memoria dinámica)
