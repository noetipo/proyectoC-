#include <iostream>
using namespace std;

template <typename T>
class Matriz {
private:
    int filas, columnas;
    T** datos;

public:
    // Constructor
    Matriz(int f, int c) : filas(f), columnas(c) {
        datos = new T*[filas];
        for (int i = 0; i < filas; ++i) {
            datos[i] = new T[columnas];
        }
    }

    // Destructor
    ~Matriz() {
        for (int i = 0; i < filas; ++i) {
            delete[] datos[i];
        }
        delete[] datos;
    }

    // Método para establecer un valor
    void establecer(int f, int c, T valor) {
        if (f >= 0 && f < filas && c >= 0 && c < columnas) {
            datos[f][c] = valor;
        }
    }

    // Método para obtener un valor
    T obtener(int f, int c) const {
        if (f >= 0 && f < filas && c >= 0 && c < columnas) {
            return datos[f][c];
        }
        throw out_of_range("Índice fuera de rango");
    }

    // Método para mostrar la matriz
    void mostrar() const {
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                cout << datos[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int filas = 3, columnas = 4;
    Matriz<int> matriz(filas, columnas);

    // Inicializar la matriz
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz.establecer(i, j, i * columnas + j + 1);
        }
    }

    // Mostrar la matriz
    matriz.mostrar();

    return 0;
}
