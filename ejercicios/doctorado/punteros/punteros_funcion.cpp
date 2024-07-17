#include <iostream>

using namespace std;

int suma(int a, int b) {
    return a + b;
}

int resta(int a, int b) {
    return a - b;
}

float multi(float a, float b) {
    return a * b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void maxmin(int a, int b, int &max, int &min) {
    max = (a > b) ? a : b;
    min = (a < b) ? a : b;
}

int buscar(int *datos, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (datos[i] == x) return i;
    }
    return -1;
}

void matrizpow(int** matriz, int nf, int nc) {
    for (int i = 0; i < nf; ++i) {
        for (int j = 0; j < nc; ++j) {
            matriz[i][j] *= matriz[i][j];
        }
    }
}

void mostrarMatriz(int** matriz, int nf, int nc) {
    for (int i = 0; i < nf; ++i) {
        for (int j = 0; j < nc; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void leerDimensiones(int &nf, int &nc) {
    cout << "filas: ";
    cin >> nf;
    cout << "columnas: ";
    cin >> nc;
}

int** crearMatriz(int nf, int nc) {
    int** matriz = new int*[nf];
    for (int f = 0; f < nf; f++) {
        matriz[f] = new int[nc];
    }
    return matriz;
}

void ingresarValoresMatriz(int** matriz, int nf, int nc) {
    for (int i = 0; i < nf; ++i) {
        for (int j = 0; j < nc; ++j) {
            cout << "Ingrese valor para la posición [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

void liberarMatriz(int** matriz, int nf) {
    for (int f = 0; f < nf; f++) {
        delete[] matriz[f];
    }
    delete[] matriz;
}

int main() {
    int (*pFunc)(int, int);  // puntero a función

    int a = 10, b = 11;
    int lista[] = { 2, 4, 5, 4, 3, 5, 7, 3, 9, 0 }; // 40 bytes

    int nf, nc;
    leerDimensiones(nf, nc);
    int** matriz = crearMatriz(nf, nc);
    ingresarValoresMatriz(matriz, nf, nc);
    cout << "===================================================" << endl;
    cout << "Matriz:" << endl;
    mostrarMatriz(matriz, nf, nc);
    cout << "===================================================" << endl;
    matrizpow(matriz, nf, nc);
    cout << "===================================================" << endl;
    cout << "Matriz pow:" << endl;
    mostrarMatriz(matriz, nf, nc);
    cout << "===================================================" << endl;

    liberarMatriz(matriz, nf);

    pFunc = suma;
    cout << pFunc(a, b) << endl;

    pFunc = resta;
    cout << pFunc(a, b) << endl;

    // pFunc = multi;  // error los tipos de parámetros diferentes
    // cout << pFunc(a, b);  // error

    int max, min;
    maxmin(a, b, max, min);
    cout << "Máximo: " << max << endl;
    cout << "Mínimo: " << min << endl;

    int index = buscar(lista, 10, 7);
    cout << "Índice del número 7 en la lista: " << index << endl;

    return 0;
}
