#include <iostream>
using namespace std;

// Declaración anticipada de la clase B para que la clase A pueda hacerla amiga
class B;

// Clase A
class A {
private:
    int privateDataA;

public:
    A() : privateDataA(0) {}

    // Método para mostrar privateDataA
    void mostrarPrivateDataA() {
        cout << "privateDataA en clase A: " << privateDataA << endl;
    }

    // Declaración de B como clase amiga de A
    friend class B;
};

// Clase B, que es amiga de la clase A
class B {
private:
    int privateDataB;

public:
    B() : privateDataB(0) {}

    // Método para mostrar privateDataB
    void mostrarPrivateDataB() {
        cout << "privateDataB en clase B: " << privateDataB << endl;
    }

    // Método para modificar privateDataA de la clase A
    void modificarPrivateDataA(A& objA, int newValue) {
        objA.privateDataA = newValue;
        cout << "privateDataA en clase A modificado desde B: " << objA.privateDataA << endl;
    }
};

int main() {
    A objetoA;
    B objetoB;

    // Accediendo a privateDataA de A desde B usando la amistad
    objetoB.modificarPrivateDataA(objetoA, 42);

    // Mostrando privateDataA de A desde A
    objetoA.mostrarPrivateDataA();

    // Mostrando privateDataB de B desde B
    objetoB.mostrarPrivateDataB();

    return 0;
}
