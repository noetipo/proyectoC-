#include <iostream>
using namespace std;

// Definición del template de clase
template <typename T1, typename T2>
class Par {
public:
    T1 primero;
    T2 segundo;

    Par(T1 a, T2 b) : primero(a), segundo(b) {}

    void mostrar() {
        cout << "Primero: " << primero << ", Segundo: " << segundo << endl;
    }
    Par() : primero(T1()), segundo(T2()) {}
    // Métodos para establecer los valores
    void establecerPrimero(T1 a) {
        primero = a;
    }

    void establecerSegundo(T2 b) {
        segundo = b;
    }
};

int main() {

    // Usando el constructor vacío
    Par<int, double> p3;
    p3.mostrar();  // Mostrará los valores por defecto de int y double
    // Establecer valores después de la creación
    p3.establecerPrimero(42);
    p3.establecerSegundo(3.14);
    p3.mostrar();  // Mostrará los valores establecidos (42 y 3.14)

    Par<int, double> p1(1, 2.5);
    p1.mostrar();

    Par<string, char> p2("Hola", 'A');
    p2.mostrar();

    return 0;
}
