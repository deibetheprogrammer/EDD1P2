#include "Tree.hpp"
#include <iostream>
using namespace std;

Tree::Tree()
{
    this->root = nullptr;
}

TreeNode* Tree::crea(char etiqueta,TreeNode* padre, TreeNode* izq, TreeNode* der) {
    bool EnDer = false;
    TreeNode* node = new TreeNode(etiqueta, izq, der);
    if (padre->getIzq() != nullptr) {
        padre->setIzq(node);
    } else if (padre->getDer() != nullptr) {
        padre->setDer(node);
        EnDer = true;
    } else {
        delete node;
        cout << "El padre esta ocupado\n";
        return nullptr;
    }
    for (vector<TreeNode*> &vect : nodes) {
        if (vect.at(0) == padre) {
            vect.at(EnDer + 1) = node;
        }
    }
    vector<TreeNode*> vect;
    vect.push_back(node);
    vect.push_back(nullptr);
    vect.push_back(nullptr);
    nodes.push_back(vect);
    return node;
}