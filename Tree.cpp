#include "Tree.hpp"
#include <iostream>
#include <queue>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

Tree::Tree(int nNodos)
{
    this->root = 0;
    for (int i = 0; i < nNodos; i++)
    {
        nodes.push_back(new TreeNode(nullptr,nullptr,nullptr,""));
    }
    
}

Tree::Tree(vector<TreeNode*> arbol)
{
    this->nodes = arbol;
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
    cout << endl;
}

void Tree::anula() 
{
    for(TreeNode* tNode : nodes)
    {
        delete tNode;
    }
    nodes.clear();
}


void Tree::DFS_ImprimirPostOrder(TreeNode* raiz) {
    if (raiz != NULL) {
        DFS_ImprimirPostOrder(raiz->getIzq());
        DFS_ImprimirPostOrder(raiz->getDer());
        cout << raiz->toString() << "\n";
    }
    else {
        cout << "No existe el arbol" << endl;
    }
}

void Tree::DFS_ImprimirInOrder(TreeNode* A){
 	if(A==nullptr){
 		return;
	}else{
	 	DFS_ImprimirInOrder(A->getIzq());
	 	cout<<A->getEtiqueta()<<" - ";
	 	DFS_ImprimirInOrder(A->getDer());
	}

    if(A == nodes[0])
        cout << endl;
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

string Tree::ruta(string etiqueta)
{
    TreeNode* target = nullptr;
    for (TreeNode* tNode : nodes)
    {
        if (tNode->getEtiqueta() == etiqueta)
        {
            target = tNode;
            break;
        }

    }
    if(target == nullptr)
        return "";

    //Creamos la ruta
    
    string route;
    while (target != raiz())
    {
        TreeNode* padre = target->getPadre();
        if (padre->getIzq() == target)
        {
            route = "0" + route;
        }
        else
        {
            route = "1" + route;
        }
        target = padre;
        
    }

    return route;

}