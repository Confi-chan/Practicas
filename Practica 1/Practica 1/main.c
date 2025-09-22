#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void llenarMatriz(int n, int matriz[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = rand() % 100 + 1; // valores 1-100
        }
    }
}

void mostrarMatriz(int n, int matriz[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int sumaMatriz(int n, int matriz[MAX][MAX]) {
    int suma = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            suma += matriz[i][j];
    return suma;
}

void contarElementos(int n, int matriz[MAX][MAX], int *pares, int *impares, int *div7) {
    *pares = *impares = *div7 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] % 2 == 0) (*pares)++;
            else (*impares)++;
            if (matriz[i][j] % 7 == 0) (*div7)++;
        }
    }
}

void transpuesta(int n, int matriz[MAX][MAX], int matrizT[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrizT[j][i] = matriz[i][j];
        }
    }
}

int main() {
    srand(time(NULL));
    int n;
    int matriz[MAX][MAX], matrizT[MAX][MAX];
    int pares, impares, div7;

    printf("Ingrese tamaño de la matriz (max 10): ");
    scanf("%d", &n);

    if (n > 10 || n < 1) {
        printf("Tamaño no válido.\n");
        return 1;
    }

    llenarMatriz(n, matriz);

    printf("\nMatriz original:\n");
    mostrarMatriz(n, matriz);

    printf("\nSuma de todos los elementos: %d\n", sumaMatriz(n, matriz));

    contarElementos(n, matriz, &pares, &impares, &div7);
    printf("Cantidad de pares: %d\n", pares);
    printf("Cantidad de impares: %d\n", impares);
    printf("Cantidad divisibles entre 7: %d\n", div7);

    transpuesta(n, matriz, matrizT);
    printf("\nMatriz transpuesta:\n");
    mostrarMatriz(n, matrizT);

    return 0;
}
