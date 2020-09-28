#ifndef GRAFOL_H
#define GRAFOL_H

#include <vector>
#include <string>

using namespace std;

class GrafoL
{
    public:

    //CONSTRUCTOR
    GrafoL(int nVertices);
    GrafoL(string nombre);

    //METODOS

    //Devuelve el numero de vertices
    int numVertices();

    //Separa un string por un delimitador arbitrario
    vector<string> split(string linea, char delim);

    //Crea una nueva arista
    void crearArista(int vOrigen, int vDestino, int peso);

    //Algoritmo de Kruskal
    GrafoL* kruskal();

    //Imprimir grafo
    void imprimir();

    //DESTRUCTOR
    ~GrafoL();

    private:

    //Lista de adyacencia
    vector<vector<pair<int,int>>> grafo;

};

#endif