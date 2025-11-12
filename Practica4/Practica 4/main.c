#include <stdio.h>
#include <string.h>

#define MAX_ALUMNOS 50
#define MAX_TAREAS 50


// Estructuras principales


// Estructura para guardar los datos de una tarea
typedef struct {
    char nombre[50];
    char descripcion[100];
} Tarea;

// Estructura para guardar los datos de un alumno
typedef struct {
    char nombre[50];
} Alumno;

// Estructura que relaciona un alumno con una tarea y su calificación
typedef struct {
    int idAlumno;
    int idTarea;
    float calificacion;
} Calificacion;


// Variables globales
Tarea tareas[MAX_TAREAS];
Alumno alumnos[MAX_ALUMNOS];
Calificacion calificaciones[MAX_ALUMNOS * MAX_TAREAS];

int contadorTareas = 0;
int contadorAlumnos = 0;
int contadorCalificaciones = 0;


// Prototipos de funciones

void menu();
void gestionarTareas();
void gestionarAlumnos();
void asignarCalificaciones();
void mostrarDatos();

// -------------------------------
// Función principal
// -------------------------------
int main() {
    menu(); // Inicia el programa mostrando el menú principal
    return 0;
}


// Menú principal con opciones
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


// Función para registrar tareas

void gestionarTareas() {
    if (contadorTareas < MAX_TAREAS) {
        printf("\n--- Registro de Tarea ---\n");

        // Solicita y guarda el nombre de la tarea
        printf("Nombre de la tarea: ");
        fgets(tareas[contadorTareas].nombre, 50, stdin);
        tareas[contadorTareas].nombre[strcspn(tareas[contadorTareas].nombre, "\n")] = 0;

        // Solicita y guarda la descripción
        printf("Descripcion: ");
        fgets(tareas[contadorTareas].descripcion, 100, stdin);
        tareas[contadorTareas].descripcion[strcspn(tareas[contadorTareas].descripcion, "\n")] = 0;

        contadorTareas++; // Incrementa el contador
        printf("Tarea registrada exitosamente.\n");
    } else {
        printf("No se pueden agregar más tareas.\n");
    }
}

// Función para registrar alumnos

void gestionarAlumnos() {
    if (contadorAlumnos < MAX_ALUMNOS) {
        printf("\n--- Registro de Alumno ---\n");

        // Solicita el nombre del alumno
        printf("Nombre del alumno: ");
        fgets(alumnos[contadorAlumnos].nombre, 50, stdin);
        alumnos[contadorAlumnos].nombre[strcspn(alumnos[contadorAlumnos].nombre, "\n")] = 0;

        contadorAlumnos++;
        printf("Alumno registrado exitosamente.\n");
    } else {
        printf("No se pueden agregar más alumnos.\n");
    }
}

// Función para asignar calificaciones

void asignarCalificaciones() {
    // Verifica si existen alumnos y tareas registrados
    if (contadorAlumnos == 0 || contadorTareas == 0) {
        printf("\nDebe haber al menos un alumno y una tarea registrados.\n");
        return;
    }

    int i, j;
    float calif;
    printf("\n--- Asignacion de Calificaciones ---\n");

    // Recorre todos los alumnos y tareas para asignar notas
    for (i = 0; i < contadorAlumnos; i++) {
        for (j = 0; j < contadorTareas; j++) {
            printf("Calificacion de %s en la tarea '%s': ",
                   alumnos[i].nombre, tareas[j].nombre);
            scanf("%f", &calif);
            getchar();

            // Guarda la calificación en el arreglo
            calificaciones[contadorCalificaciones].idAlumno = i;
            calificaciones[contadorCalificaciones].idTarea = j;
            calificaciones[contadorCalificaciones].calificacion = calif;
            contadorCalificaciones++;
        }
    }
    printf("Calificaciones asignadas correctamente.\n");
}

// Función para mostrar toda la información
void mostrarDatos() {
    printf("\n===== LISTADO DE TAREAS =====\n");
    for (int i = 0; i < contadorTareas; i++) {
        printf("%d. %s - %s\n", i + 1, tareas[i].nombre, tareas[i].descripcion);
    }

    printf("\n===== LISTADO DE ALUMNOS =====\n");
    for (int i = 0; i < contadorAlumnos; i++) {
        printf("%d. %s\n", i + 1, alumnos[i].nombre);
    }

    printf("\n===== CALIFICACIONES =====\n");
    // Muestra todas las calificaciones registradas
    for (int i = 0; i < contadorCalificaciones; i++) {
        int idA = calificaciones[i].idAlumno;
        int idT = calificaciones[i].idTarea;
        printf("%s - %s: %.2f\n",
               alumnos[idA].nombre, tareas[idT].nombre, calificaciones[i].calificacion);
    }
}
