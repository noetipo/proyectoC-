#include <iostream>
using namespace std;

int main() {
    const int FILAS = 3;
    const int COLUMNAS = 4;
    int matriz[FILAS][COLUMNAS] = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
    };

    // Mostrar la matriz
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
