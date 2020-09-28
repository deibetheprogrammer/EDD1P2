#ifndef GRAFOM_H
#define GRAFOM_H

#include <vector>

using std::vector;

class GrafoM
{

public:

    //CONSTRUCTOR

    //Construye un grafo con n numero de vertices
    GrafoM(int nVertices);

    //Contruye un GrafoM a partir de un archivo
    GrafoM(string nombre);

    //METODOS

    //Separa un string por un delimitador arbitrario
    vector<string> GrafoM::split(string linea, char delim);

    //Crea una arista
    void crearArista(int origen, int destino, int peso);

    //Algoritmo de prim
    GrafoM* prim();


    //DESTRUCTOR
    ~GrafoM();


protected:

    //Lista de listas de nodos
    vector<vector<int>> grafo;


};

#endif
