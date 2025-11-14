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


// Prototipos
// ----------------------------
void menu();
void gestionarTareas();
void gestionarAlumnos();
void asignarCalificaciones();
void mostrarDatos();

// Nuevas funciones del editor de texto
void menuEditor();
void crearTexto();
void modificarTexto();
void capturarPersonas();
void mostrarMensajes();


// Función principal
// ----------------------------
int main() {
    menu();
    if (mensaje != NULL) free(mensaje); // Liberar memoria antes de salir
    return 0;
}


// Menú principal
// ----------------------------
void menu() {
    int opcion;
    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1. Gestionar tareas\n");
        printf("2. Gestionar alumnos\n");
        printf("3. Asignar calificaciones\n");
        printf("4. Mostrar todos los datos\n");
        printf("5. Editor de texto (mensajes personalizados)\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1: gestionarTareas(); break;
            case 2: gestionarAlumnos(); break;
            case 3: asignarCalificaciones(); break;
            case 4: mostrarDatos(); break;
            case 5: menuEditor(); break;
            case 0: printf("Saliendo del programa...\n"); break;
            default: printf("Opcion no valida.\n");
        }
    } while (opcion != 0);
}

// Funciones originales
// ----------------------------
void gestionarTareas() {
    if (contadorTareas < MAX_TAREAS) {
        printf("\n--- Registro de Tarea ---\n");
        printf("Nombre de la tarea: ");
        fgets(tareas[contadorTareas].nombre, 50, stdin);
        tareas[contadorTareas].nombre[strcspn(tareas[contadorTareas].nombre, "\n")] = 0;

        printf("Descripcion: ");
        fgets(tareas[contadorTareas].descripcion, 100, stdin);
        tareas[contadorTareas].descripcion[strcspn(tareas[contadorTareas].descripcion, "\n")] = 0;

        contadorTareas++;
        printf("Tarea registrada exitosamente.\n");
    } else {
        printf("No se pueden agregar más tareas.\n");
    }
}

