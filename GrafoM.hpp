#ifndef GRAFOM_H
#define GRAFOM_H

#include <vector>

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
    vector<vector<int>> listas;


};

#endif
