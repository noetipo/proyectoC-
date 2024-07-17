#include <iostream>
#include "stack.h"
int main()
{

    BST<int> arbol;


    arbol.insert(10);
    arbol.insert(10);
    arbol.insert(10);
    arbol.insert(10);

    arbol.insert(3);
    arbol.insert(4);
    arbol.insert(5);

    arbol.inorder();
    cout << endl;
    arbol.postorder();
    cout << endl;
    arbol.preorder();
    cout << endl;

    arbol.iterativeInorder();
    cout << endl;
    arbol.iterativePostorder();
    cout << endl;
    arbol.iterativePreorder();
    cout << endl;


    arbol.breadthFirst();
    cout << endl;


    std::cout << "Hello World!\n";


}