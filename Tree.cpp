#include "Tree.hpp"
#include <iostream>
using namespace std;

Tree::Tree(int nNodos)
{
    this->root = 0;
    for (int i = 0; i < nNodos; i++)
    {
        nodes.push_back(new TreeNode(nullptr,nullptr,nullptr,""));
    }
    
}

TreeNode* Tree::crea(string etiqueta,int nodo, int izq, int der) {
    if(izq != -1)
    {
        nodes[nodo]->setIzq(nodes[izq]);
        nodes[izq]->setPadre(nodes[nodo]);
    }
        
    if (der != -1)
    {
        nodes[nodo]->setDer(nodes[der]);
        nodes[der]->setPadre(nodes[nodo]);
    }

    nodes[nodo]->setEtiqueta(etiqueta);

    return nodes[nodo];
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

void Tree::anula() 
{
    for(TreeNode* tNode : nodes)
    {
        delete tNode;
    }
    nodes.clear();
}

void Tree::DFS_ImprimirPreOrder(TreeNode* tNode)
{
    cout << tNode->toString() << ",";
    if(tNode->getIzq() != nullptr)
        DFS_ImprimirPreOrder(tNode->getIzq());
    if (tNode->getDer() != nullptr)
        DFS_ImprimirPreOrder(tNode->getDer());

    if(tNode == nodes[0])
        cout << endl;

}