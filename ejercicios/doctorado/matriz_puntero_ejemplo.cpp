#include <iostream>
using namespace std;

int main() {
    int filas = 3, columnas = 4;

    // Declarar un puntero a un puntero
    int** matriz;

    // Asignar memoria para las filas
    matriz = new int*[filas];

    // Asignar memoria para cada fila
    for (int i = 0; i < filas; ++i) {
        matriz[i] = new int[columnas];
    }

    // Inicializar la matriz
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = i * columnas + j + 1;
        }
    }

    // Mostrar la matriz
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Liberar la memoria
    for (int i = 0; i < filas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}
