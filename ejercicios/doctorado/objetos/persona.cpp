#include <iostream>
using namespace std;

// Definición de la clase Persona
class Persona {
private:
    string nombre;
    int edad;

public:
    // Constructor con parámetros
    Persona(string nombre, int edad) {
        this->nombre = nombre;
        this->edad = edad;
    }

    // Método para mostrar los datos de la persona
    void mostrarDatos() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }

    // Método para cambiar el nombre
    void setNombre(string nuevoNombre) {
        nombre = nuevoNombre;
    }

    // Método para obtener la edad
    int getEdad() {
        return edad;
    }
};

int main() {
    // Crear objetos de la clase Persona
    Persona persona1("Juan", 25);
    Persona persona2("María", 30);

    // Mostrar los datos de las personas
    cout << "Datos de la persona 1:" << endl;
    persona1.mostrarDatos();
    cout << endl;

    cout << "Datos de la persona 2:" << endl;
    persona2.mostrarDatos();
    cout << endl;

    // Cambiar el nombre de persona1
    persona1.setNombre("Pedro");

    // Mostrar los datos actualizados de persona1
    cout << "Datos actualizados de la persona 1:" << endl;
    persona1.mostrarDatos();
    cout << endl;

    // Obtener la edad de persona2
    int edadPersona2 = persona2.getEdad();
    cout << "Edad de la persona 2: " << edadPersona2 << " años" << endl;

    return 0;
}
