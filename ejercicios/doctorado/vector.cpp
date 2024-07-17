#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // Crear un vector de strings
    vector<string> palabras;

    // Añadir elementos uno por uno usando push_back
    palabras.push_back("Hola");
    palabras.push_back("Mundo");
    palabras.push_back("en");
    palabras.push_back("C++");

    // Mostrar los elementos del vector de strings
    cout << "Elementos del vector palabras:" << endl;
    for (size_t i = 0; i < palabras.size(); ++i) {
        cout << palabras[i] << " ";
    }
    cout << endl;

    return 0;
}
