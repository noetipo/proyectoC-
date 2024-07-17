//
// Created by Noe on 30/06/24.
//


#include <iostream>
#include <vector>
using namespace std;

const int ESTUDIANTES = 800;
const int CURSOS = 300;

struct Celda {
    int fila;
    int col;
    char valor;

    Celda(int f, int c, char v) : fila(f), col(c), valor(v) {}
};

vector<Celda> data;

void inicializarMatriz() {
    data.clear();
}

void agregarCalificacion(int idEstudiante, int idCurso, char calificacion) {
    if (idEstudiante >= 0 && idEstudiante < ESTUDIANTES && idCurso >= 0 && idCurso < CURSOS) {
        for (auto& celda : data) {
            if (celda.fila == idEstudiante && celda.col == idCurso) {
                celda.valor = calificacion;
                return;
            }
        }
        data.push_back(Celda(idEstudiante, idCurso, calificacion));
    } else {
        cout << "ID de estudiante o curso fuera de rango." << endl;
    }
}

void reporteEstudiante(int idEstudiante) {
    if (idEstudiante >= 0 && idEstudiante < ESTUDIANTES) {
        cout << "Reporte del Estudiante ID " << idEstudiante << ":" << endl;
        for (const auto& celda : data) {
            if (celda.fila == idEstudiante) {
                cout << "Curso ID " << celda.col << " - Calificacion: " << celda.valor << endl;
            }
        }
    } else {
        cout << "ID de estudiante fuera de rango." << endl;
    }
}

void reporteCurso(int idCurso) {
    if (idCurso >= 0 && idCurso < CURSOS) {
        cout << "Reporte del Curso ID " << idCurso << ":" << endl;
        for (const auto& celda : data) {
            if (celda.col == idCurso) {
                cout << "Estudiante ID " << celda.fila << " - Calificacion: " << celda.valor << endl;
            }
        }
    } else {
        cout << "ID de curso fuera de rango." << endl;
    }
}

void imprimirMatriz() {
    for (int i = 0; i < ESTUDIANTES; ++i) {
        for (int j = 0; j < CURSOS; ++j) {
            char valor = ' ';
            for (const auto& celda : data) {
                if (celda.fila == i && celda.col == j) {
                    valor = celda.valor;
                    break;
                }
            }
            cout << valor << ' ';
        }
        cout << endl;
    }
}
void imprimirEspacioMatriz() {
    int espacioElementos = data.size() * sizeof(Celda);
    int espacioVector = sizeof(vector<Celda>) + (data.capacity() * sizeof(Celda));
    int espacioTotal = espacioElementos + espacioVector;
    cout << "espacio de la matriz " << espacioTotal << " bytes" << endl;
}
int main() {
    inicializarMatriz();

    agregarCalificacion(0, 0, 'A');
    agregarCalificacion(1, 0, 'B');
    agregarCalificacion(1, 1, 'C');
    agregarCalificacion(1, 2, 'F');
    agregarCalificacion(2, 1, 'B');


    imprimirMatriz();


    reporteEstudiante(1);
    reporteCurso(0);
    imprimirEspacioMatriz();
    return 0;
}
