#include <iostream>
using namespace std;

// Función para inicializar la matriz con valores
void inicializarMatriz(int matriz[][4], int filas, int columnas) {
    int valor = 1;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = valor++;
        }
    }
}

// Función para mostrar la matriz
void mostrarMatriz(int matriz[][4], int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para modificar un valor en la matriz
void modificarMatriz(int matriz[][4], int fila, int columna, int nuevoValor) {
    matriz[fila][columna] = nuevoValor;
}

int main() {
    const int FILAS = 3;
    const int COLUMNAS = 4;
    int matriz[FILAS][COLUMNAS];

    // Inicializar la matriz
    inicializarMatriz(matriz, FILAS, COLUMNAS);

    // Mostrar la matriz
    cout << "Matriz inicial:" << endl;
    mostrarMatriz(matriz, FILAS, COLUMNAS);

    // Modificar un valor en la matriz
    modificarMatriz(matriz, 1, 2, 99);

    // Mostrar la matriz después de la modificación
    cout << "Matriz después de modificar:" << endl;
    mostrarMatriz(matriz, FILAS, COLUMNAS);

    return 0;
}
