#include <iostream>
#include <memory>
using namespace std;

int main()
{

    int x = 100;
    int y = 50;
    int z[4];




    z[0] = 10;
    z[1] = 11;
    z[2] = 12;
    z[3] = 13;


    int* p;

    //unique_ptr<int> num1 = make_unique<int>(1000);
   // cout << *num1<<endl;

    p = &x;
    cout << *p<<endl;   //100

    p = &y;
    cout << *p<<endl;  //50

    p = &x;
    cout << *p << endl;  //100

    cout << "Direccion: "<< p <<" "<< &x << " " << &y << endl;

    p = z;     /// p = &z[0];

    cout << *p << endl;
    p++;
    cout << *p << endl;
    p++;
    cout << *p << endl;
    p++;
    cout << *p << endl;
    p--;
    cout << *p << endl;

    p = z;

    cout << *p + *(p + 3) << endl;

    cout << z[0] + z[3] << endl;

    p = &y;
    *p = 150;

    cout << y <<endl;

    p = new int[3];

    p[0] = 23;
    p[1] = 24;
    p[2] = 25;


    cout << p[0] <<endl;

    /*
    p = &x;

    p[1] = 10;

    cout << p[1]<<endl;
    */
    delete[]p;       //java -> garbage collector

}