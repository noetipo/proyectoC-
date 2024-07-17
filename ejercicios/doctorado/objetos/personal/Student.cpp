#include "Student.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Constructor default de Student
Student::Student() : Personal(), majorLen(10) {
    major = new char[majorLen + 1];
}

// Constructor parametrizado de Student
Student::Student(char *ssn, char *n, char *c, int y, long s, char *m)
        : Personal(ssn, n, c, y, s), majorLen(11) {
    major = new char[majorLen + 1];
    strncpy(major, m, majorLen);
}

// Método para escribir en archivo
void Student::writeToFile(fstream& out) const {
    Personal::writeToFile(out);  // Llama al método de la clase base
    out.write(major, majorLen);  // Escribe el major en el archivo
}

// Método para leer desde archivo
void Student::readFromFile(fstream& in) {
    Personal::readFromFile(in);  // Llama al método de la clase base
    in.read(major, majorLen);    // Lee el major desde el archivo
}

// Método para escribir legiblemente en consola
ostream& Student::writeLegibly(ostream& out) {
    Personal::writeLegibly(out);  // Llama al método de la clase base
    major[majorLen] = '\0';       // Asegura que el major tenga fin de cadena
    out << ", major = " << major; // Escribe el major en consola
    return out;
}

// Método para leer desde consola
istream& Student::readFromConsole(istream& in) {
    Personal::readFromConsole(in);  // Llama al método de la clase base
    char s[80];
    cout << "Major: ";
    in.getline(s, 80);
    strncpy(major, s, majorLen);    // Copia el major ingresado
    return in;
}
