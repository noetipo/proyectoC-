#include <iostream>
#include <string>
using namespace std;

// Declaración anticipada de la clase ControlAcceso para que Persona pueda hacerla amiga
class ControlAcceso;

// Clase Persona
class Persona {
private:
    string nombre;
    int edad;

public:
    Persona(const string& n, int e) : nombre(n), edad(e) {}

    // Método para mostrar los datos privados
    void mostrarDatos() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }

    // Declaración de ControlAcceso como clase amiga de Persona
    friend class ControlAcceso;
};

// Clase ControlAcceso, que es amiga de la clase Persona
class ControlAcceso {
public:
    // Método para modificar la edad de Persona directamente
    void modificarEdad(Persona& p, int nuevaEdad) {
        p.edad = nuevaEdad; // Acceso directo a edad gracias a la amistad
    }
};

int main() {
    // Crear un objeto de la clase Persona
    Persona persona1("Alice", 30);

    // Crear un objeto de la clase ControlAcceso
    ControlAcceso control;

    // Mostrar los datos originales de persona1
    cout << "Datos originales de la persona:" << endl;
    persona1.mostrarDatos();

    // Modificar la edad de persona1 usando ControlAcceso
    control.modificarEdad(persona1, 35);

    // Mostrar los datos actualizados de persona1
    cout << "\nDatos modificados de la persona:" << endl;
    persona1.mostrarDatos();

    return 0;
}
