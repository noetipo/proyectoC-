//
// Created by Noe on 30/06/24.
//

#include "tareaCursos.h"
#include <iostream>
#include <cstring> // Para memset
using namespace std;

const int ESTUDIANTES = 800;
const int CURSOS = 300;

char matriz[ESTUDIANTES][CURSOS];

void inicializarMatriz() {
    for (int i = 0; i < ESTUDIANTES; ++i) {
        for (int j = 0; j < CURSOS; ++j) {
            matriz[i][j] = ' ';
        }
    }
}

void agregarCalificacion(int idEstudiante, int idCurso, char calificacion) {
    if (idEstudiante >= 0 && idEstudiante < ESTUDIANTES && idCurso >= 0 && idCurso < CURSOS) {
        matriz[idEstudiante][idCurso] = calificacion;
    } else {
        cout << "ID de estudiante o curso fuera de rango." << endl;
    }
}

void reporteEstudiante(int idEstudiante) {
    if (idEstudiante >= 0 && idEstudiante < ESTUDIANTES) {
        cout << "Reporte del Estudiante ID " << idEstudiante + 1 << ":" << endl;
        for (int j = 0; j < CURSOS; ++j) {
            if (matriz[idEstudiante][j] != ' ') {
                cout << "Curso ID " << j << " - Calificacion: " << matriz[idEstudiante][j] << endl;
            }
        }
    } else {
        cout << "ID de estudiante fuera de rango." << endl;
    }
}

void reporteCurso(int idCurso) {
    if (idCurso >= 0 && idCurso < CURSOS) {
        cout << "Reporte del Curso ID " << idCurso + 1 << ":" << endl;
        for (int i = 0; i < ESTUDIANTES; ++i) {
            if (matriz[i][idCurso] != ' ') {
                cout << "Estudiante ID " << i << " - Calificacion: " << matriz[i][idCurso] << endl;
            }
        }
    } else {
        cout << "ID de curso fuera de rango." << endl;
    }
}

void imprimirMatriz() {
    for (int i = 0; i < ESTUDIANTES; ++i) {
        for (int j = 0; j < CURSOS; ++j) {
            cout << matriz[i][j] << ' ';
        }
        cout << endl;
    }
}
void imprimirEspacioMatriz() {
    cout << "tamanio de char" << sizeof(char) << " bytes" << endl;
    int espacio = ESTUDIANTES * CURSOS * sizeof(char);
    cout << "espacio de la matriz " << espacio << " bytes" << endl;
}
int main() {
    inicializarMatriz();
    agregarCalificacion(0, 0, 'A');
    agregarCalificacion(1, 0, 'B');
    agregarCalificacion(1, 1, 'C');
    agregarCalificacion(1, 2, 'F');
    agregarCalificacion(2, 1, 'B');
    imprimirMatriz();
    imprimirEspacioMatriz();

    reporteEstudiante(1);
    reporteCurso(0);

    return 0;
}
