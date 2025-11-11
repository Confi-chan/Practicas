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

typedef struct {// Estructura que relaciona un alumno con una tarea y su calificación
    int idAlumno;
    int idTarea;
    float calificacion;
} Calificacion;

// Variables globales
Tarea tareas[MAX_TAREAS];
Alumno alumnos[MAX_ALUMNOS];
Calificacion calificaciones[MAX_ALUMNOS * MAX_TAREAS];
int contadorTareas = 0, contadorAlumnos = 0, contadorCalificaciones = 0;

// Prototipos
void menu();
void gestionarTareas();
void gestionarAlumnos();
void asignarCalificaciones();
void mostrarDatos();

// Función principal
int main() {
    menu(); // Inicia el programa mostrando el menú principal
    return 0;

}

// Menú principal con opciones
// -------------------------------
void menu() {
    int opcion;
    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1. Gestionar tareas\n");
        printf("2. Gestionar alumnos\n");
        printf("3. Asignar calificaciones\n");
        printf("4. Mostrar todos los datos\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpia el buffer del teclado

        // Selección de opción según el número ingresado
        switch (opcion) {
            case 1: gestionarTareas(); break;
            case 2: gestionarAlumnos(); break;
            case 3: asignarCalificaciones(); break;
            case 4: mostrarDatos(); break;
            case 0: printf("Saliendo del programa...\n"); break;
            default: printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 0);
}
