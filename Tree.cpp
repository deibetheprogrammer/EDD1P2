#include "Tree.hpp"
#include <iostream>
#include <queue>
using namespace std;

Tree::Tree(int nNodos)
{
    this->root = 0;
    for (int i = 0; i < nNodos; i++)
    {
        nodes.push_back(new TreeNode(nullptr,nullptr,nullptr,NULL));
    }
    
}

TreeNode* Tree::crea(string etiqueta,int nodo, int izq, int der) {
    nodes[nodo]->setIzq(nodes[izq]);
    nodes[nodo]->setDer(nodes[der]);

    nodes[izq]->setPadre(nodes[nodo]);
    nodes[der]->setPadre(nodes[nodo]);

    nodes[nodo]->setEtiqueta(etiqueta);
}

TreeNode* Tree::padre(TreeNode* tNode) {
    return tNode->getPadre();
}

TreeNode* Tree::hijo_izq(TreeNode* tNode)
{
    return tNode->getIzq();
}

TreeNode* Tree::hijo_der(TreeNode* tNode)
{
    return tNode->getDer();
}

TreeNode* Tree::raiz()
{
    return nodes[0];
}

void Tree::BFS_Imprimir() {
    if (raiz() == nullptr)
        return;
    queue<TreeNode*> q;
    q.push(raiz());
    while (!q.empty()) {
        cout << q.front()->getEtiqueta() << " ";
        TreeNode* temp = q.front()->getIzq();
        if (temp) {
            q.push(temp);
        }
        temp = q.front()->getDer();
        if (temp) {
            q.push(temp);
        }
        temp = nullptr;
        q.pop();
    }
}

void Tree::anula() 
{
    for(TreeNode* tNode : nodes)
    {
        delete tNode;
    }
    nodes.clear();
}