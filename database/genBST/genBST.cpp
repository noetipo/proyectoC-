//
// Created by Noe on 6/07/24.
//

#include "genBST.h"
// BST.cpp


// Implementación de métodos de BST

template<class T>
void BST<T>::clear(BSTNode<T>* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template<class T>
T* BST<T>::search(BSTNode<T>* node, const T& el) const {
    while (node != nullptr) {
        if (el == node->el)
            return &node->el;
        else if (el < node->el)
            node = node->left;
        else
            node = node->right;
    }
    return nullptr;
}

template<class T>
void BST<T>::preorder(BSTNode<T>* node) {
    if (node != nullptr) {
        visit(node);
        preorder(node->left);
        preorder(node->right);
    }
}

template<class T>
void BST<T>::inorder(BSTNode<T>* node) {
    if (node != nullptr) {
        inorder(node->left);
        visit(node);
        inorder(node->right);
    }
}

template<class T>
void BST<T>::postorder(BSTNode<T>* node) {
    if (node != nullptr) {
        postorder(node->left);
        postorder(node->right);
        visit(node);
    }
}

// Debes proporcionar las definiciones completas de los métodos restantes según sea necesario.

template<class T>
void BST<T>::insert(const T& el) {
    BSTNode<T>* p = root, * prev = nullptr;
    while (p != nullptr) {
        prev = p;
        if (el < p->el)
            p = p->left;
        else
            p = p->right;
    }
    if (root == nullptr)
        root = new BSTNode<T>(el);
    else if (el < prev->el)
        prev->left = new BSTNode<T>(el);
    else
        prev->right = new BSTNode<T>(el);
}

// Elimina el nodo fusionando sus subárboles.
template<class T>
void BST<T>::deleteByMerging(BSTNode<T>*& node) {
    BSTNode<T>* tmp = node;
    if (node != nullptr) {
        if (node->right == nullptr) {
            node = node->left;
        } else if (node->left == nullptr) {
            node = node->right;
        } else {
            tmp = node->left;
            while (tmp->right != nullptr) {
                tmp = tmp->right;
            }
            tmp->right = node->right;
            tmp = node;
            node = node->left;
        }
        delete tmp;
    }
}

template<class T>
void BST<T>::findAndDeleteByMerging(const T& el) {
    BSTNode<T>* node = root, * prev = nullptr;
    while (node != nullptr) {
        if (node->el == el)
            break;
        prev = node;
        if (el < node->el)
            node = node->left;
        else
            node = node->right;
    }
    if (node != nullptr && node->el == el) {
        if (node == root)
            deleteByMerging(root);
        else if (prev->left == node)
            deleteByMerging(prev->left);
        else
            deleteByMerging(prev->right);
    }
}

// Implementa las funciones iterativas y Morris Inorder según las secciones mencionadas en tus comentarios.
