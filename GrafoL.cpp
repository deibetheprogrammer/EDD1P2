#include "GrafoL.hpp"
#include "AristaL.hpp"
#include <fstream>
#include <iostream>

using namespace std;

//CONSTRUCTOR
GrafoL::GrafoL(int nVertices)
{
    grafo.clear();
    grafo.resize(nVertices);
}

GrafoL::GrafoL(string nombre)
{
    ifstream ifs(nombre);
    if(ifs.is_open())
    {
        int nVertices;
        ifs >> nVertices;
        ifs.ignore(100,'\n');

        string linea;

        for (int i = 0; i < nVertices; i++)
        {
            getline(ifs,linea);
            vector<string> aristas = split(linea,';');

            for (string arista : aristas)
            {
                vector<string> elementos = split(arista,',');
                crearArista(i,stoi(elementos[0]),stoi(elementos[1]));
            }

        }
        
    }
    
}

//METODOS

//Separa un string por un delimitador arbitrario
vector<string> GrafoL::split(string linea, char delim)
{
    vector<string> respuesta;
    string temp = "";

    for (char c : linea)
    {
        if (c != delim)
        {
            temp.push_back(c);
        }
        else
        {
            respuesta.push_back(temp);
            temp = "";
        }
        
    }

    if (temp.size() > 0)
    {
        respuesta.push_back(temp);
    }
    
    return respuesta;
    
}

//Crea una nueva arista
void GrafoL::crearArista(int vOrigen, int vDestino, int peso)
{
    grafo[vOrigen].push_back(make_pair(vDestino,peso));
}


//Algoritmo de Kruskal
GrafoL* GrafoL::kruskal()
{
    GrafoL* AACM;
    vector<AristaL> aristasOrd;

    for (int i = 0; i < grafo.size(); i++)
    {
        for (pair<int,int> arista : grafo[i])
        {
            if (arista.first > i)
            {
                aristasOrd.push_back(AristaL(i,arista.first,arista.second));
            }
            
        }
        
    }
    sort(aristasOrd.begin(),aristasOrd.end());
    vector<int> conjuntos;

    for (int i = 0; i < grafo.size(); i++)
    {
        conjuntos.push_back(i);
    }
    

    int na = 0;

    for (AristaL arista : aristasOrd)
    {
        int origen = arista.getOrigen();
        int destino = arista.getDestino();
        if (conjuntos[origen] != conjuntos[destino])
        {
            int x = conjuntos[destino];

            for (int i = 0; i < conjuntos.size(); i++)
            {
                if (conjuntos[i] == x)
                {
                    conjuntos[i] = conjuntos[origen];
                }
                
            }
            AACM->crearArista(origen,destino,arista.getPeso());
            na++;
            if (na == grafo.size() - 1)
            {
                break;
            }
            
        }
 
    }

    AACM->imprimir();

    return AACM;
 
}

//Imprime el grafo
void GrafoL::imprimir()
{
    for (int i = 0; i < grafo.size(); i++)
    {
        for (int j = 0; j < grafo[i].size(); j++)
        {
            cout << i << " --> " << grafo[i][j].first << " : " << grafo[i][j].second << endl;
        }
        
    }
    
}

//DESTRUCTOR

GrafoL::~GrafoL()
{

}

