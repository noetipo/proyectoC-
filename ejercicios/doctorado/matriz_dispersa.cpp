#include <iostream>
#include <vector>
using namespace std;


template <class T>
struct CeldaT {
    int fila;
    int col;
    T valor;


    CeldaT(int f, int c, T v) : fila(f), col(c), valor(v) {}
};


template <class T>
void mostrarMatrizDispersa(const vector<CeldaT<T> >& matrizDispersa, int filas, int columnas) {

    vector<vector<T> > matrizTemp(filas, vector<T>(columnas, 0));// almacenar los valores de la matriz dispersa


    for (typename vector<CeldaT<T> >::const_iterator it = matrizDispersa.begin(); it != matrizDispersa.end(); ++it) {
        matrizTemp[it->fila][it->col] = it->valor;
    }


    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matrizTemp[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    vector<CeldaT<int> > matrizDispersaInt;
    matrizDispersaInt.push_back(CeldaT<int>(0, 2, 8));
    matrizDispersaInt.push_back(CeldaT<int>(1, 1, 1));
    matrizDispersaInt.push_back(CeldaT<int>(1, 5, 9));
    matrizDispersaInt.push_back(CeldaT<int>(2, 3, 3));
    matrizDispersaInt.push_back(CeldaT<int>(3, 1, 31));
    matrizDispersaInt.push_back(CeldaT<int>(3, 5, 4));
    matrizDispersaInt.push_back(CeldaT<int>(4, 4, 7));


    cout << "Matriz dispersa de tipo int:" << endl;
    mostrarMatrizDispersa(matrizDispersaInt, 5, 7);
    cout << endl;


    vector<CeldaT<double> > matrizDispersaDouble;
    matrizDispersaDouble.push_back(CeldaT<double>(0, 2, 8.5));
    matrizDispersaDouble.push_back(CeldaT<double>(1, 1, 1.2));
    matrizDispersaDouble.push_back(CeldaT<double>(1, 5, 9.7));
    matrizDispersaDouble.push_back(CeldaT<double>(2, 3, 3.3));
    matrizDispersaDouble.push_back(CeldaT<double>(3, 1, 31.9));
    matrizDispersaDouble.push_back(CeldaT<double>(3, 5, 4.4));
    matrizDispersaDouble.push_back(CeldaT<double>(4, 4, 7.1));

    cout << "Matriz dispersa de tipo double:" << endl;
    mostrarMatrizDispersa(matrizDispersaDouble, 5, 7);

    // Ejemplo con tipo de datos float
    // Ejemplo con tipo de datos float
    vector<CeldaT<float> > matrizDispersaFloat;


    matrizDispersaFloat.push_back(CeldaT<float>(0, 2, 8.5f));
    matrizDispersaFloat.push_back(CeldaT<float>(1, 1, 1.2f));
    matrizDispersaFloat.push_back(CeldaT<float>(1, 5, 9.7f));
    matrizDispersaFloat.push_back(CeldaT<float>(2, 3, 3.3f));
    matrizDispersaFloat.push_back(CeldaT<float>(3, 1, 31.9f));
    matrizDispersaFloat.push_back(CeldaT<float>(3, 5, 4.4f));
    matrizDispersaFloat.push_back(CeldaT<float>(4, 4, 7.1f));

    cout << "Matriz dispersa de tipo float:" << endl;
    mostrarMatrizDispersa(matrizDispersaDouble, 5, 7);

    return 0;
}
