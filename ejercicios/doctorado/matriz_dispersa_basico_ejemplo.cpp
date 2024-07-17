#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

// Definición de una estructura para almacenar elementos de la matriz dispersa
struct Elemento {
    int fila;
    int columna;
    int valor;
};

// Función para mostrar una matriz dispersa
void mostrarMatrizDispersa(const vector<Elemento>& matrizDispersa, int filas, int columnas) {
    int indice = 0;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            // Verificar si hay un elemento en la posición actual (i, j)
            if (indice < matrizDispersa.size() && matrizDispersa[indice].fila == i && matrizDispersa[indice].columna == j) {
                cout << matrizDispersa[indice].valor << " ";
                indice++;
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main() {
    const int FILAS = 4;
    const int COLUMNAS = 5;

    // Creamos una matriz dispersa (simulada) con algunos elementos no cero
    vector<Elemento> matrizDispersa = {
            {0, 1, 5},
            {1, 2, 8},
            {2, 0, 3},
            {3, 3, 7}
    };

    // Mostrar la matriz dispersa
    cout << "Matriz dispersa:" << endl;
    mostrarMatrizDispersa(matrizDispersa, FILAS, COLUMNAS);

    return 0;
}
