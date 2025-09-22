#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10   // Tamaño máximo permitido para la matriz

// Funcion que llena la matriz con números aleatorios entre 1 y 100
void llenarMatriz(int n, int matriz[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = rand() % 100 + 1; // rand()%100 genera 0-99, por eso +1
        }
    }
}

// Funcion para mostrar la matriz en forma tabular
void mostrarMatriz(int n, int matriz[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", matriz[i][j]); // %3d para alinear en columnas
        }
        printf("\n");
    }
}

// Funcion que calcula la suma de todos los elementos de la matriz
int sumaMatriz(int n, int matriz[MAX][MAX]) {
    int suma = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            suma += matriz[i][j]; // Acumula cada elemento
    return suma;
}

// Funcion que cuenta pares, impares y divisibles entre 7
void contarElementos(int n, int matriz[MAX][MAX], int *pares, int *impares, int *div7) {
    *pares = *impares = *div7 = 0; // Inicializamos contadores
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] % 2 == 0) (*pares)++;  // Verifica si es par
            else (*impares)++;                      // Si no, es impar
            if (matriz[i][j] % 7 == 0) (*div7)++;   // Verifica divisibilidad entre 7
        }
    }
}

// Funcion que genera la transpuesta de una matriz
void transpuesta(int n, int matriz[MAX][MAX], int matrizT[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrizT[j][i] = matriz[i][j]; // Intercambia filas por columnas
        }
    }
}

int main() {
    srand(time(NULL)); // Inicializa la semilla aleatoria según la hora
    int n;
    int matriz[MAX][MAX], matrizT[MAX][MAX];
    int pares, impares, div7;

    // Se pide el tamaño de la matriz al usuario
    printf("Ingrese tamaño de la matriz (max 10): ");
    scanf("%d", &n);

    if (n > 10 || n < 1) { // Validacion del tamaño ingresado
        printf("Tamaño no válido.\n");
        return 1;
    }

    llenarMatriz(n, matriz); // Llenado de la matriz con valores aleatorios

    printf("\nMatriz original:\n");
    mostrarMatriz(n, matriz); // Se muestra la matriz original

    printf("\nSuma de todos los elementos: %d\n", sumaMatriz(n, matriz));

    // Se cuentan pares, impares y divisibles entre 7
    contarElementos(n, matriz, &pares, &impares, &div7);
    printf("Cantidad de pares: %d\n", pares);
    printf("Cantidad de impares: %d\n", impares);
    printf("Cantidad divisibles entre 7: %d\n", div7);

    // Se obtiene y muestra la matriz transpuesta
    transpuesta(n, matriz, matrizT);
    printf("\nMatriz transpuesta:\n");
    mostrarMatriz(n, matrizT);

    return 0;
}
