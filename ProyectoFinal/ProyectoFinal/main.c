#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXTO 500
#define MAX_PERSONAS 20

// ---------- STRUCT PARA PERSONAS ----------
typedef struct {
    char nombre[50];
    char cargo[50];
} Persona;

// Buffer dinámico para almacenar el texto creado
char *texto = NULL;

// Arreglo de personas
Persona personas[MAX_PERSONAS];
int totalPersonas = 0;

// ---------- FUNCIÓN: CREAR TEXTO ----------
void crearTexto() {
    texto = (char *)malloc(MAX_TEXTO * sizeof(char));
    if (texto == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }

    fflush(stdin);
    printf("Escribe el texto base del mensaje:\n> ");
    fgets(texto, MAX_TEXTO, stdin);

    printf("\nTexto guardado correctamente.\n\n");
}

// ---------- FUNCIÓN: MODIFICAR TEXTO ----------
void modificarTexto() {
    if (texto == NULL) {
        printf("Primero debes crear un texto.\n\n");
        return;
    }

    fflush(stdin);
    printf("Texto actual:\n%s\n", texto);
    printf("Escribe el nuevo texto:\n> ");
    fgets(texto, MAX_TEXTO, stdin);

    printf("Texto modificado exitosamente.\n\n");
}

// ---------- FUNCIÓN: CAPTURAR PERSONAS ----------
void capturarPersonas() {
    if (totalPersonas >= MAX_PERSONAS) {
        printf("Se alcanzó el límite máximo de personas.\n");
        return;
    }

    printf("Ingresa el nombre de la persona:\n> ");
    fflush(stdin);
    fgets(personas[totalPersonas].nombre, 50, stdin);

    printf("Ingresa el cargo:\n> ");
    fgets(personas[totalPersonas].cargo, 50, stdin);

    // Eliminar saltos de línea
    personas[totalPersonas].nombre[strcspn(personas[totalPersonas].nombre, "\n")] = 0;
    personas[totalPersonas].cargo[strcspn(personas[totalPersonas].cargo, "\n")] = 0;

    totalPersonas++;
    printf("\nPersona agregada.\n\n");
}

// ---------- FUNCIÓN: GENERAR MENSAJES ----------
void generarMensajes() {
    if (texto == NULL) {
        printf("Primero debes crear un texto.\n\n");
        return;
    }

    if (totalPersonas == 0) {
        printf("Primero debes capturar personas.\n\n");
        return;
    }

    printf("\n--- MENSAJES PERSONALIZADOS ---\n");

    for (int i = 0; i < totalPersonas; i++) {
        printf("\n-----------------------------\n");
        printf("Para: %s (%s)\n", personas[i].nombre, personas[i].cargo);
        printf("Mensaje:\n%s\n", texto);

        // Guardar en archivo
        char nombreArchivo[60];
        sprintf(nombreArchivo, "%s.txt", personas[i].nombre);

        FILE *archivo = fopen(nombreArchivo, "w");
        if (archivo != NULL) {
            fprintf(archivo, "Para: %s (%s)\n\n%s", personas[i].nombre, personas[i].cargo, texto);
            fclose(archivo);
        }
    }

    printf("\nTodos los archivos fueron generados exitosamente.\n\n");
}

// ---------- MENÚ PRINCIPAL ----------
int main() {
    int opcion;

    do {
        printf("======== MENU PRINCIPAL ========\n");
        printf("1. Crear texto\n");
        printf("2. Modificar texto\n");
        printf("3. Capturar personas\n");
        printf("4. Generar mensajes personalizados\n");
        printf("5. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);
        getchar(); // limpiar buffer

        switch (opcion) {
            case 1: crearTexto(); break;
            case 2: modificarTexto(); break;
            case 3: capturarPersonas(); break;
            case 4: generarMensajes(); break;
            case 5: printf("Saliendo del programa...\n"); break;
            default: printf("Opcion invalida. Intenta de nuevo.\n\n");
        }

    } while (opcion != 5);

    // Liberar memoria
    if (texto != NULL) free(texto);

    return 0;
}// para craer el archivo por completo se debe hacer los sasos 1,3,4
