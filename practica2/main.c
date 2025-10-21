#include <stdio.h>   // Librería estándar para entrada y salida
#include <string.h>  

// Función para llenar el texto
void llenarTexto(char *texto, int tamano) {
    printf("Ingrese el texto base:\n");
    fgets(texto, tamano, stdin); // Lee texto con espacios
    texto[strcspn(texto, "\n")] = '\0'; // Elimina salto de línea
}

// Función para mostrar texto
void mostrarTexto(const char *texto) {
    printf("%s\n", texto);
}

// Función que busca y reemplaza una subcadena dentro del texto
void buscarYReemplazar(char *texto, const char *buscar, const char *reemplazar) {
    char resultado[1000] = ""; // Arreglo temporal donde se guarda el resultado
    char *pos = texto;         // Apuntador que recorre el texto
    char *encontrado;          // Apuntador a la posición encontrada

    // Mientras exista una coincidencia con la palabra a buscar
    while ((encontrado = strstr(pos, buscar)) != NULL) {
        // Copiar la parte del texto antes del texto encontrado
        strncat(resultado, pos, encontrado - pos);
        // Agregar el texto de reemplazo
        strcat(resultado, reemplazar);
        // Avanzar el apuntador después de la palabra reemplazada
        pos = encontrado + strlen(buscar);
    }

    // Agregar el resto del texto que no fue reemplazado
    strcat(resultado, pos);
    // Copiar el resultado final al texto original
    strcpy(texto, resultado);
}

int main() {
    char texto[500];
    char buscar[50];
    char reemplazar[50];

    // 1️⃣ Llenar el texto con una función
    llenarTexto(texto, 500);

    printf("\nTexto original:\n");
    mostrarTexto(texto);

    // 2️⃣ Solicitar texto a buscar y texto a reemplazar
    printf("\nIngrese el texto a buscar: ");
    fgets(buscar, 50, stdin);
    buscar[strcspn(buscar, "\n")] = '\0'; // Eliminar salto de línea

    printf("Ingrese el texto a reemplazar: ");
    fgets(reemplazar, 50, stdin);
    reemplazar[strcspn(reemplazar, "\n")] = '\0'; // Eliminar salto de línea

    // Mostrar los textos capturados
    printf("\nTexto a buscar: %s\n", buscar);
    printf("Texto a reemplazar: %s\n", reemplazar);

    // 3️⃣ Llamar a la función de reemplazo
    buscarYReemplazar(texto, buscar, reemplazar);

    // 4️⃣ Mostrar el texto final
    printf("\nTexto final:\n");
    mostrarTexto(texto);

    return 0;
}

