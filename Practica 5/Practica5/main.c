#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PERSONAS 50

// -------------------------
//  STRUCT PERSONA
// -------------------------
typedef struct {
    char nombre[50];
    char cargo[50];
} Persona;

// -------------------------
// VARIABLES GLOBALES
// -------------------------
Persona personas[MAX_PERSONAS];
int contadorPersonas = 0;

char *textoBase = NULL;    // Mensaje dinámico
int textoLong = 0;

// -------------------------
// PROTOTIPOS
// -------------------------
void menuEditor();
void crearTexto();
void modificarTexto();
void capturarPersonas();
void mostrarDocumentos();


// -------------------------
// PROGRAMA PRINCIPAL
// -------------------------
int main() {
    menuEditor();

    if (textoBase != NULL)
        free(textoBase);

    return 0;
}


// -------------------------
// MENÚ PRINCIPAL DEL EDITOR
// -------------------------
void menuEditor() {
    int opc;

    do {
        printf("\n===== EDITOR DE TEXTO BASICO =====\n");
        printf("1. Crear texto base\n");
        printf("2. Modificar texto existente\n");
        printf("3. Capturar personas (nombre y cargo)\n");
        printf("4. Mostrar documentos personalizados\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opc);
        getchar();

        switch (opc) {
            case 1: crearTexto(); break;
            case 2: modificarTexto(); break;
            case 3: capturarPersonas(); break;
            case 4: mostrarDocumentos(); break;
            case 0: printf("Saliendo...\n"); break;
            default: printf("Opcion NO valida.\n");
        }

    } while (opc != 0);
}


// -------------------------
// 1. CREAR TEXTO (memoria dinámica)
// -------------------------
void crearTexto() {
    // Si ya existe texto, NO debe reemplazarlo
    if (textoBase != NULL) {
        printf("\nYA existe un texto base.\n");
        printf("Si desea cambiarlo, use la opción 2 (Modificar texto).\n");
        return;
    }

    char buffer[500];

    printf("\n--- Crear Texto Base ---\n");
    printf("Ingrese el texto que desea guardar:\n> ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;

    textoLong = strlen(buffer) + 1;
    textoBase = (char*)malloc(textoLong);

    if (textoBase == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }

    strcpy(textoBase, buffer);
    printf("Texto guardado exitosamente.\n");
}

// -------------------------
// 2. MODIFICAR TEXTO
// -------------------------
void modificarTexto() {
    if (textoBase == NULL) {
        printf("No hay texto aún. Use opción 1 primero.\n");
        return;
    }

    char buffer[500];
    printf("\n--- Modificar Texto ---\n");
    printf("Texto actual:\n%s\n", textoBase);
    printf("Escriba el nuevo texto:\n> ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;

    textoLong = strlen(buffer) + 1;
    textoBase = (char*)realloc(textoBase, textoLong);

    strcpy(textoBase, buffer);
    printf("Texto actualizado exitosamente.\n");
}


// -------------------------
// 3. CAPTURAR PERSONAS
// -------------------------
void capturarPersonas() {
    if (contadorPersonas >= MAX_PERSONAS) {
        printf("No se pueden agregar más personas.\n");
        return;
    }

    printf("\n--- Captura de Persona ---\n");

    printf("Nombre: ");
    fgets(personas[contadorPersonas].nombre, 50, stdin);
    personas[contadorPersonas].nombre[strcspn(personas[contadorPersonas].nombre, "\n")] = 0;

    printf("Cargo: ");
    fgets(personas[contadorPersonas].cargo, 50, stdin);
    personas[contadorPersonas].cargo[strcspn(personas[contadorPersonas].cargo, "\n")] = 0;

    contadorPersonas++;

    printf("Persona registrada exitosamente.\n");
}


// -------------------------
// 4. MOSTRAR DOCUMENTO FINAL
// -------------------------
void mostrarDocumentos() {
    if (textoBase == NULL) {
        printf("No existe texto base.\n");
        return;
    }
    if (contadorPersonas == 0) {
        printf("No hay personas registradas.\n");
        return;
    }

    printf("\n===== DOCUMENTOS PERSONALIZADOS =====\n");

    for (int i = 0; i < contadorPersonas; i++) {
        printf("\n---------------------------------------\n");
        printf("Para: %s\nCargo: %s\n",
            personas[i].nombre, personas[i].cargo);
        printf("Mensaje:\n%s\n", textoBase);
        printf("---------------------------------------\n");
    }
}
