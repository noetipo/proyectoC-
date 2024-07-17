#include <iostream>

using namespace std;

struct CeldaE {
    char fila;   //1b
    char col;    //1b
    int valor;   //4b   //6b;
};


class CeldaC {
    char fila;   //1b
    char col;    //1b
    int valor;   //4b   //6b;
};


template <class T>
class CeldaT {

    char fila;   //1b
    char col;    //1b
    T valor;   //4b   //6b;
};


int main()
{

    int x;
    int matriz[5][7];  /// 14000 bytes





    cout << "ENTERO " << sizeof(x);   /// ocupa 4 bytes   matriz  = 5x7*4 = 140 bytes

    for (int f = 0; f < 5; f++) {
        for (int c = 0; c < 7; c++)
            matriz[f][c] = 0;
    }

    matriz[0][2] = 8;
    matriz[1][1] = 1;
    matriz[1][5] = 9;
    matriz[2][3] = 3;
    matriz[3][1] = 31;
    matriz[3][5] = 4;
    matriz[4][4] = 7;

    cout << "El resultado con Matriz Normal";
    for (int f = 0; f < 5; f++) {
        cout << endl;
        for (int c = 0; c < 7; c++)
            cout << matriz[f][c]<<" ";
    }


    /*
        0 0 8 0 0 0 0
        0 1 0 0 0 9 0
        0 0 0 3 0 0 0
        0 31 0 0 0 4 0
        0 0 0 0 7 0 0

     */

    int me[7][3];   // 7 x3 * 4  = 84 bytes

    me[0][0] = 0;  //4b
    me[0][1] = 2;  //4b
    me[0][2] = 8;  //4b   = 12bytes

    me[1][0] = 1;
    me[1][1] = 1;
    me[1][2] = 1;

    me[2][0] = 1;
    me[2][1] = 5;
    me[2][2] = 9;

    me[3][0] = 2;
    me[3][1] = 3;
    me[3][2] = 3;

    me[4][0] = 3;
    me[4][1] = 1;
    me[4][2] = 31;

    me[5][0] = 3;
    me[5][1] = 5;
    me[5][2] = 4;

    me[6][0] = 4; // fila
    me[6][1] = 4; // col
    me[6][2] = 7; // val

    /// <summary>

    /// </summary>
    /// <returns></returns>

    cout << "El resultado con Matriz Reducida";

    for (int f = 0; f < 5; f++) {
        cout << endl;
        for (int c = 0; c < 7; c++) {

            bool existe = false;
            for (int n = 0; n < 7; n++) {

                if (me[n][0] == f && me[n][1] == c) {
                    cout << me[n][2] << " ";
                    existe = true;
                    break;
                }
            }
            if (!existe)
                cout << "0" << " ";
        }
    }

    /*
    El resultado con Matriz Normal  140 byte
        0 0 8 0 0 0 0
        0 1 0 0 0 9 0
        0 0 0 3 0 0 0
        0 31 0 0 0 4 0
        0 0 0 0 7 0 0

    El resultado con Matriz Reducida 84
        0 0 8 0 0 0 0
        0 1 0 0 0 9 0
        0 0 0 3 0 0 0
        0 31 0 0 0 4 0
        0 0 0 0 7 0 0

*/



}