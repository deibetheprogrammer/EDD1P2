#ifndef GRAFOM_H
#define GRAFOM_H

#include <vector>
#include <string>

using namespace std;

class GrafoM
{

public:

    //CONSTRUCTOR

    //Construye un grafo con n numero de vertices
    GrafoM(int nVertices);

    //Contruye un GrafoM a partir de un archivo
    GrafoM(string nombre);

    //METODOS

    //Añade un grafo directamente
    void setGrafo(vector<vector<int>> grafo);

    //Separa un string por un delimitador arbitrario
    vector<string> split(string linea, char delim);

    //Crea una arista
    void crearArista(int origen, int destino, int peso);

    //Algoritmo de prim
    GrafoM* prim();

    //Algoritmo de floyd
    vector<vector<int>> floyd();


    //DESTRUCTOR
    ~GrafoM();


protected:

    //Lista de listas de nodos
    vector<vector<int>> grafo;


};

#endif
