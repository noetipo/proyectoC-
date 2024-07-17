#include <iostream>
#include <vector>
using namespace std;

// Definición de la estructura CeldaT usando template
template <class T>
struct CeldaT {
    int fila;
    int col;
    T valor;

    // Constructor con parámetros
    CeldaT(int f, int c, T v) : fila(f), col(c), valor(v) {}
};

// Función para mostrar una matriz dispersa
template <class T>
void mostrarMatrizDispersa(const vector<vector<CeldaT<T> > >& matrizDispersa, int filas, int columnas) {
    // Crear una matriz temporal para almacenar los valores de la matriz dispersa
    vector<vector<T>> matrizTemp(filas, vector<T>(columnas, 0));

    // Llenar la matriz temporal con los valores de la matriz dispersa
    for (const auto& fila : matrizDispersa) {
        for (const auto& celda : fila) {
            matrizTemp[celda.fila][celda.col] = celda.valor;
        }
    }

    // Mostrar la matriz dispersa
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matrizTemp[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Ejemplo con tipo de datos double en una matriz dispersa
    vector<vector<CeldaT<double>>> matrizDispersaDouble;

    // Llenar matriz dispersa de tipo double
    matrizDispersaDouble.push_back({ CeldaT<double>(0, 2, 8.5), CeldaT<double>(1, 1, 1.2), CeldaT<double>(1, 5, 9.7) });
    matrizDispersaDouble.push_back({ CeldaT<double>(2, 3, 3.3), CeldaT<double>(3, 1, 31.9), CeldaT<double>(3, 5, 4.4) });
    matrizDispersaDouble.push_back({ CeldaT<double>(4, 4, 7.1) });

    // Mostrar la matriz dispersa de tipo double
    cout << "Matriz dispersa de tipo double:" << endl;
    mostrarMatrizDispersa(matrizDispersaDouble, 5, 7);
    cout << endl;

    return 0;
}
