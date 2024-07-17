//
// Created by Noe on 6/07/24.
//

#include <queue>
#include <stack>
using namespace std;
#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE
template<class T>
class Stack : public stack<T> {  } // as in Figure 4.21
template<class T>
class Queue : public queue<T> {
public:
    T dequeue() {
        T tmp = front();
        queue<T>::pop();
        return tmp;
    }
    void enqueue(const T& el) {
        push(el);
    }
};
template<class T>
class BSTNode {
public:
    BSTNode() {
        left = right = 0;
    }
    BSTNode(const T& e, BSTNode<T> *l = 0, BSTNode<T> *r = 0) {
        el = e; left = l; right = r;
    }
    T el;
    BSTNode<T> *left, *right;
};
template<class T>
class BST {
public:
    BST() {
        root = 0;
    }
    ~BST() {
        clear();
    }
    void clear() {
        clear(root); root = 0;
    }
    bool isEmpty() const {
        return root == 0;
    }
    void preorder() {
        preorder(root); // Figure 6.11
    }
    void inorder() {
        inorder(root); // Figure 6.11
    }
    void postorder() {
        postorder(root); // Figure 6.11
    }
    T* search(const T& el) const {
        return search(root,el); // Figure 6.9
    }
    void breadthFirst(); // Figure 6.10
    void iterativePreorder(); // Figure 6.15
    void iterativeInorder(); // Figure 6.17
    void iterativePostorder(); // Figure 6.16
    void MorrisInorder(); // Figure 6.20
    void insert(const T&); // Figure 6.23
    void deleteByMerging(BSTNode<T>*&); // Figure 6.29
    void findAndDeleteByMerging(const T&); // Figure 6.29
    void deleteByCopying(BSTNode<T>*&); // Figure 6.32
    void balance(T*,int,int); // Section 6.7
   //. . . . . . . . . . . . . . .
protected:
    BSTNode<T>* root;
    void clear(BSTNode<T>*);
    T* search(BSTNode<T>*, const T&) const; // Figure 6.9
    void preorder(BSTNode<T>*); // Figure 6.11
    void inorder(BSTNode<T>*); // Figure 6.11
    void postorder(BSTNode<T>*); // Figure 6.11
    virtual void visit(BSTNode<T>* p) {
        cout << p->el << ' ';
    }
   // . . . . . . . . . . . . . . .
};
#endif