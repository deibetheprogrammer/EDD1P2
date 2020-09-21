#include "Tree.hpp"
#include <iostream>
using namespace std;

Tree::Tree(int nNodos)
{
    this->root = 0;
    for (int i = 0; i < nNodos; i++)
    {
        nodes.push_back(new TreeNode(-1,-1,-1,NULL));
    }
    
}

TreeNode* Tree::crea(char etiqueta,int nodo, int izq, int der) {
    nodes[nodo]->setIzq(izq);
    nodes[nodo]->setDer(der);
    nodes[nodo]->setEtiqueta(etiqueta);
}