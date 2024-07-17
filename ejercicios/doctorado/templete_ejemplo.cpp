#include <iostream>
using namespace std;

// Definición del template
template <typename T>
void intercambiar(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
    cout << "Dentro del intercanvio: x = " << a << ", y = " << b  << endl;
}

int main() {
    int x = 5, y = 10;
    cout << "Antes de intercambiar: x = " << x << ", y = " << y << endl;
    intercambiar(x, y);
    cout << "Después de intercambiar: x = " << x << ", y = " << y << endl;

    float a = 1.5f, b = 2.5f;
    cout << "Antes de intercambiar: a = " << a << ", b = " << b << endl;
    intercambiar(a, b);
    cout << "Después de intercambiar: a = " << a << ", b = " << b << endl;

    return 0;
}

