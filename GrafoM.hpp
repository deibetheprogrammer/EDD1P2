#ifndef GRAFOM_H
#define GRAFOM_H

#include <vector>
#include "TreeNode.hpp"

using std::vector;

class Tree
{

public:

    //CONSTRUCTOR
    GrafoM();

    

    //DESTRUCTOR
    ~GrafoM();


protected:

    //Lista de listas de nodos
    vector<TreeNode*> nodes;

    //Raiz del arbol
    int root;


};

#endif