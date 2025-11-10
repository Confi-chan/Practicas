#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -------------------------
// Función para llenar texto dinámicamente
// -------------------------
char* llenarTexto() {
    char *texto = NULL;
    char buffer[200];   // Buffer temporal
    size_t tamano = 0;  // Tamaño actual del texto

    printf("Ingrese el texto base (escriba 'FIN' para terminar):\n");

    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Eliminar salto de línea

        // Si el usuario escribe "FIN", se detiene
        if (strcmp(buffer, "FIN") == 0)
            break;

        // Calcular el nuevo tamaño y usar realloc
        size_t nuevoTamano = tamano + strlen(buffer) + 2; // +1 espacio y +1 '\0'
        char *temp = realloc(texto, nuevoTamano);

        if (temp == NULL) {
            printf("Error al asignar memoria.\n");
            free(texto);
            exit(1);
        }

        texto = temp;

        // Copiar o concatenar el texto
        if (tamano == 0)
            strcpy(texto, buffer);
        else {
            strcat(texto, " ");
            strcat(texto, buffer);
        }

        tamano = strlen(texto);

        printf("[Memoria usada: %zu bytes]\n", nuevoTamano);
    }

    return texto;
}

// -------------------------
// Función para mostrar texto
// -------------------------
void mostrarTexto(const char *texto) {
    printf("%s\n", texto);
}

// -------------------------
// Función para buscar y reemplazar
// -------------------------
char* buscarYReemplazar(char *texto, const char *buscar, const char *reemplazar) {
    char *resultado = NULL;
    char *pos = texto;
    size_t tamResultado = 0;
    size_t lenBuscar = strlen(buscar);
    size_t lenReemplazar = strlen(reemplazar);

    while (1) {
        char *encontrado = strstr(pos, buscar);
        if (!encontrado) {
            // Copiar el resto del texto
            size_t lenResto = strlen(pos);
            resultado = realloc(resultado, tamResultado + lenResto + 1);
            if (!resultado) {
                printf("Error de memoria.\n");
                exit(1);
            }
            strcpy(resultado + tamResultado, pos);
            break;
        }

        // Copiar texto antes del encontrado
        size_t lenAntes = encontrado - pos;
        resultado = realloc(resultado, tamResultado + lenAntes + lenReemplazar + 1);
        if (!resultado) {
            printf("Error de memoria.\n");
            exit(1);
        }

        strncpy(resultado + tamResultado, pos, lenAntes);
        tamResultado += lenAntes;

        // Agregar el texto reemplazado
        strcpy(resultado + tamResultado, reemplazar);
        tamResultado += lenReemplazar;

        pos = encontrado + lenBuscar; // Mover el puntero
    }

    return resultado;
}

// -------------------------
// Función principal
// -------------------------
int main() {
    char *texto = NULL;
    char buscar[50];
    char reemplazar[50];

    // Llenar texto dinámicamente
    texto = llenarTexto();

    printf("\nTexto original:\n");
    mostrarTexto(texto);

    // Pedir texto a buscar y reemplazar
    printf("\nIngrese el texto a buscar: ");
    fgets(buscar, sizeof(buscar), stdin);
    buscar[strcspn(buscar, "\n")] = '\0';

    printf("Ingrese el texto a reemplazar: ");
    fgets(reemplazar, sizeof(reemplazar), stdin);
    reemplazar[strcspn(reemplazar, "\n")] = '\0';

    printf("\nTexto a buscar: %s\n", buscar);
    printf("Texto a reemplazar: %s\n", reemplazar);

    // Reemplazar texto usando memoria dinámica
    char *nuevoTexto = buscarYReemplazar(texto, buscar, reemplazar);

    // Mostrar el resultado final
    printf("\nTexto final:\n");
    mostrarTexto(nuevoTexto);

    // Liberar memoria
    free(texto);
    free(nuevoTexto);

    return 0;
}

