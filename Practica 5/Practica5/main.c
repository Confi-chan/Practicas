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

void gestionarAlumnos() {
    if (contadorAlumnos < MAX_ALUMNOS) {
        printf("\n--- Registro de Alumno ---\n");
        printf("Nombre del alumno: ");
        fgets(alumnos[contadorAlumnos].nombre, 50, stdin);
        alumnos[contadorAlumnos].nombre[strcspn(alumnos[contadorAlumnos].nombre, "\n")] = 0;

        contadorAlumnos++;
        printf("Alumno registrado exitosamente.\n");
    } else {
        printf("No se pueden agregar más alumnos.\n");
    }
}

void asignarCalificaciones() {
    if (contadorAlumnos == 0 || contadorTareas == 0) {
        printf("\nDebe haber al menos un alumno y una tarea registrados.\n");
        return;
    }

    int i, j;
    float calif;
    printf("\n--- Asignacion de Calificaciones ---\n");

    for (i = 0; i < contadorAlumnos; i++) {
        for (j = 0; j < contadorTareas; j++) {
            printf("Calificacion de %s en la tarea '%s': ",
                   alumnos[i].nombre, tareas[j].nombre);
            scanf("%f", &calif);
            getchar();

            calificaciones[contadorCalificaciones].idAlumno = i;
            calificaciones[contadorCalificaciones].idTarea = j;
            calificaciones[contadorCalificaciones].calificacion = calif;
            contadorCalificaciones++;
        }
    }
    printf("Calificaciones asignadas correctamente.\n");
}

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
    for (int i = 0; i < contadorCalificaciones; i++) {
        int idA = calificaciones[i].idAlumno;
        int idT = calificaciones[i].idTarea;
        printf("%s - %s: %.2f\n",
               alumnos[idA].nombre, tareas[idT].nombre, calificaciones[i].calificacion);
    }
}

// NUEVA SECCIÓN: Editor de Texto
// ----------------------------
void menuEditor() {
    int opcion;
    do {
        printf("\n===== EDITOR DE TEXTO =====\n");
        printf("1. Crear texto base\n");
        printf("2. Modificar texto existente\n");
        printf("3. Capturar personas (nombre y cargo)\n");
        printf("4. Mostrar mensajes personalizados\n");
        printf("0. Volver al menú principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1: crearTexto(); break;
            case 2: modificarTexto(); break;
            case 3: capturarPersonas(); break;
            case 4: mostrarMensajes(); break;
            case 0: break;
            default: printf("Opcion no valida.\n");
        }
    } while (opcion != 0);
}

// Crear texto base
void crearTexto() {
    char buffer[500];
    printf("\n--- Crear Texto Base ---\n");
    printf("Escriba el mensaje que desea guardar:\n> ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;

    mensaje = (char *)malloc(strlen(buffer) + 1);
    strcpy(mensaje, buffer);
    printf("Texto guardado correctamente.\n");
}

// Modificar texto
void modificarTexto() {
    if (mensaje == NULL) {
        printf("No hay texto creado aún. Use la opción 1 primero.\n");
        return;
    }
