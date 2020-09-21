#include "Tree.hpp"
#include <iostream>
using namespace std;

Tree::Tree(int nNodos)
{
    this->root = 0;
    for (int i = 0; i < nNodos; i++)
    {
        nodes.push_back(new TreeNode(nullptr,nullptr,nullptr,NULL));
    }
    
}

TreeNode* Tree::crea(char etiqueta,int nodo, int izq, int der) {
    nodes[nodo]->setIzq(nodes[izq]);
    nodes[nodo]->setDer(nodes[der]);

    nodes[izq]->setPadre(nodes[nodo]);
    nodes[der]->setPadre(nodes[nodo]);

    nodes[nodo]->setEtiqueta(etiqueta);
}