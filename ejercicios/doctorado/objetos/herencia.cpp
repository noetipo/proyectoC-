#include <iostream>
using namespace std;

// Definición de la clase base Persona
class Persona {
protected:
    string nombre;
    int edad;

public:
    // Constructor con parámetros
    Persona(string nombre, int edad) : nombre(nombre), edad(edad) {}

    // Método para mostrar los datos de la persona
    void mostrarDatos() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << " años" << endl;
    }

    // Método virtual para obtener la descripción
    virtual string obtenerDescripcion() {
        return "Persona";
    }
};

// Definición de la clase derivada Estudiante
class Estudiante : public Persona {
private:
    int codigoEstudiante;

public:
    // Constructor con parámetros
    Estudiante(string nombre, int edad, int codigoEstudiante)
            : Persona(nombre, edad), codigoEstudiante(codigoEstudiante) {}

    // Método para mostrar los datos del estudiante
    void mostrarDatos() {
        cout << "--- Datos del Estudiante ---" << endl;
        Persona::mostrarDatos(); // Llama al método de la clase base
        cout << "Código de Estudiante: " << codigoEstudiante << endl;
    }

    // Implementación del método virtual obtenerDescripción
    string obtenerDescripcion() override {
        return "Estudiante";
    }
};

int main() {
    // Crear un objeto Persona
    Persona persona("Juan", 30);

    // Mostrar los datos de la persona
    cout << "Datos de la persona:" << endl;
    persona.mostrarDatos();
    cout << endl;

    // Crear un objeto Estudiante
    Estudiante estudiante("María", 25, 12345);

    // Mostrar los datos del estudiante
    cout << "Datos del estudiante:" << endl;
    estudiante.mostrarDatos();
    cout << endl;

    // Uso del polimorfismo
    Persona* ptrPersona = &persona;
    cout << "Descripción de ptrPersona: " << ptrPersona->obtenerDescripcion() << endl;

    ptrPersona = &estudiante;
    cout << "Descripción de ptrPersona (polimorfismo): " << ptrPersona->obtenerDescripcion() << endl;

    return 0;
}
