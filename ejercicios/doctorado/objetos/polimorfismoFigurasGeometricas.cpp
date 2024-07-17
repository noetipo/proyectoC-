#include <iostream>
#include <cmath> // Para usar M_PI con círculo
using namespace std;

// Clase base abstracta FiguraGeometrica
class FiguraGeometrica {
public:
    // Método virtual puro para calcular el área (obligatorio de implementar en subclases)
    virtual double calcularArea() const = 0;

    // Método virtual para mostrar detalles de la figura
    virtual void mostrarDetalles() const {
        cout << "Figura genérica" << endl;
    }
};

// Clase derivada Círculo
class Circulo : public FiguraGeometrica {
private:
    double radio;

public:
    Circulo(double r) : radio(r) {}

    // Implementación del método para calcular el área del círculo
    double calcularArea() const override {
        return M_PI * radio * radio;
    }

    // Método para mostrar detalles del círculo
    void mostrarDetalles() const override {
        cout << "Círculo de radio " << radio << endl;
    }
};

// Clase derivada Cuadrado
class Cuadrado : public FiguraGeometrica {
private:
    double lado;

public:
    Cuadrado(double l) : lado(l) {}

    // Implementación del método para calcular el área del cuadrado
    double calcularArea() const override {
        return lado * lado;
    }

    // Método para mostrar detalles del cuadrado
    void mostrarDetalles() const override {
        cout << "Cuadrado de lado " << lado << endl;
    }
};

// Clase derivada Triangulo
class Triangulo : public FiguraGeometrica {
private:
    double base;
    double altura;

public:
    Triangulo(double b, double a) : base(b), altura(a) {}

    // Implementación del método para calcular el área del triángulo
    double calcularArea() const override {
        return (base * altura) / 2.0;
    }

    // Método para mostrar detalles del triángulo
    void mostrarDetalles() const override {
        cout << "Triángulo de base " << base << " y altura " << altura << endl;
    }
};

int main() {
    // Crear objetos de las diferentes figuras
    Circulo circulo(3.0);
    Cuadrado cuadrado(4.0);
    Triangulo triangulo(5.0, 2.0);

    // Arreglo de punteros a FiguraGeometrica para almacenar diferentes figuras
    FiguraGeometrica* figuras[] = { &circulo, &cuadrado, &triangulo };

    // Iterar sobre el arreglo y llamar a los métodos polimórficos
    for (auto figura : figuras) {
        figura->mostrarDetalles();
        cout << "Área: " << figura->calcularArea() << endl << endl;
    }

    return 0;
}
