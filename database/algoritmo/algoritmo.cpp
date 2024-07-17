    #include <iostream>
    #define INF 0x3f3f3f3f
    #define MAX_VERTICES 5
    using namespace std;

    /*int graph[MAX_VERTICES][MAX_VERTICES] = {
            {0, 5, INF, 10},
            {INF, 0, 3, INF},
            {INF, INF, 0, 1},
            {INF, INF, INF, 0}
    };*/
    /*int graph[MAX_VERTICES][MAX_VERTICES] = {
            {0, 4, 8, INF,INF},
            {4, 0, 1, 2,INF},
            {8, INF, 0, 2,INF},
            {INF, 2, 4, 0,7},
            {INF, INF, 2, 7,0}
    };*/

    int graph[MAX_VERTICES][MAX_VERTICES] = {
            {0, 4, 8, INF,INF},
            {4, 0, 1, 2,INF},
            {8, INF, 0, 2,INF},
            {INF, 2, 4, 0,7},
            {INF, INF, 2, 7,0}
    };
    int P[MAX_VERTICES][MAX_VERTICES]; // Matriz de predecesores, utilizada para trazar las rutas
    int D[MAX_VERTICES][MAX_VERTICES]; // Matriz de distancias, guarda la distancia más corta entre todos los pares de vértices

    void getPath(int a, int b) {
        if (P[a][b] == a) {
            cout << a << " " << b << " ";
            return;
        }
        getPath(a, P[a][b]);
        cout << b << " ";
    }

    void printSolution() {
        for (int i = 0; i < MAX_VERTICES; i++) {
            for (int j = 0; j < MAX_VERTICES; j++) {
                cout << "De " << i << " a " << j << " : ";
                if (D[i][j] == INF) {
                    cout << "No hay camino" << endl;
                    continue;
                } else {
                    cout << D[i][j] << endl;
                    cout << "Ruta: ";
                    getPath(i, j);
                    cout << endl;
                }
            }
            cout << endl;
        }
    }

    void floydWarshall() {
        for (int i = 0; i < MAX_VERTICES; i++) {
            for (int j = 0; j < MAX_VERTICES; j++) {
                D[i][j] = graph[i][j];
                P[i][j] = (i == j || graph[i][j] == INF) ? -1 : i;
            }
        }

        for (int k = 0; k < MAX_VERTICES; k++) {
            for (int i = 0; i < MAX_VERTICES; i++) {
                for (int j = 0; j < MAX_VERTICES; j++) {
                    if (D[i][k] < INF && D[k][j] < INF && D[i][k] + D[k][j] < D[i][j]) {
                        D[i][j] = D[i][k] + D[k][j];
                        P[i][j] = P[k][j];
                    }
                }
            }
        }
        printSolution();
    }

    int main() {
        floydWarshall();
        return 0;
    }
