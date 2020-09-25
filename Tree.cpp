#include "Tree.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
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
    nodes.at(nodo)->setIzq((izq == - 1) ? nullptr : nodes[izq]);
    nodes.at(nodo)->setDer((der == - 1) ? nullptr : nodes[der]);
    if (izq != -1)
        nodes.at(izq)->setPadre(nodes[nodo]);
    if (der != -1)    
        nodes.at(der)->setPadre((der == - 1) ? nullptr : nodes[nodo]);
    nodes.at(nodo)->setEtiqueta(etiqueta);
    return nullptr;
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

Tree Tree::leerDeArchivo(string nombre) {
    ifstream archivo;
    archivo.open(nombre + ".txt", ios::in);
    vector<string> lineas;
    string linea;
    getline(archivo, linea);
    int nLin = stoi(linea);
    for(int i = 0; i < nLin; i++) {
        if (getline(archivo, linea)) {
            lineas.push_back(linea);
        } else {
            lineas.push_back("");
        }        
    }
    linea = lineas.at(0);
    Tree Arbol(nLin);
    for (int i = 0; i < lineas.size(); i++) {
        linea = lineas.at(i);
        if (linea.size() == 3) {
            Arbol.crea(to_string(i), i, (linea.at(0) - 48), (linea.at(2) - 48));
        } else if(linea.size() == 2) {
            Arbol.crea(to_string(i), i, (linea.at(0) - 48));
        } else {
            Arbol.crea(to_string(i), i);
        }
    }
    return Arbol;
}

Tree::~Tree() {
    anula();
}