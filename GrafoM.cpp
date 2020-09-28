#include "GrafoM.hpp"
#include "AristaL.hpp"
#include <fstream>
#include <iostream>


using namespace std;

//CONSTRUCTORES

 //Construye un grafo con n numero de vertices
GrafoM::GrafoM(int nVertices)
{
    grafo.clear();
    grafo.resize(nVertices,vector<int>(nVertices,0));
}

//Contruye un GrafoM a partir de un archivo
GrafoM::GrafoM(string nombre)
{

    ifstream ifs(nombre);
    if(ifs.is_open())
    {
        int nVertices;
        ifs >> nVertices;
        ifs.ignore(100,'\n');

        grafo.clear();
        grafo.resize(nVertices,vector<int>(nVertices,0));

        string linea;

        for (int i = 0; i < nVertices; i++)
        {
            getline(ifs,linea);
            vector<string> aristas = split(linea,',');

            for (int j = 0; j < nVertices; j++)
            {
                crearArista(i,j,stoi(aristas[j]));
            }

        }
        
    }

}

//METODOS

//Devuelve el numero de vertices
int GrafoM::numVertices()
{
    return grafo.size();
}

//Añade un grafo directamente
void GrafoM::setGrafo(vector<vector<int>> grafo)
{
	this->grafo = grafo;
}

//Separa un string por un delimitador arbitrario
vector<string> GrafoM::split(string linea, char delim)
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

//Crea una arista
void GrafoM::crearArista(int origen, int destino, int peso)
{
    grafo[origen][destino] = peso;
}

//Algoritmo de prim
GrafoM* GrafoM::prim()
{

    vector<AristaL> cs;

    int x = 0;
    vector<bool> visit(grafo.size(),false);
    visit[0] = true;

    vector<int> origen(grafo.size(),0);

    vector<int> aux(grafo.size(),INT_MAX);
    for (int i = 0; i < grafo.size(); i++)
    {
        if(grafo[x][i] != 0)
            aux[i] = grafo[x][i];
    }

    for (int i = 1; i < grafo.size(); i++)
    {
        int u = 0;
        int pu = INT_MAX;
        for (int j = 0; j < grafo.size(); j++)
        {
            if (visit[j] == false && aux[j] < pu)
            {
                u = j;
                pu = aux[j];
            }
            
        }
        visit[u] = true;
        cs.push_back(AristaL(origen[u],u,pu));

        for (int j = 0; j < grafo.size(); j++)
        {
            if(visit[j] == false && grafo[u][j] != 0 && grafo[u][j] < aux[j])
            {
                aux[j] = grafo[u][j];
                origen[j] = u;
            }
        }
        
    }

    cout << endl
         << "AACM: "
         << endl;

    GrafoM* AACM = new GrafoM(grafo.size());

    for (AristaL arista : cs)
    {
        cout << arista.getOrigen() 
             << " <---> " << arista.getDestino() 
             << " : " << arista.getPeso() 
             << endl;
        
        AACM->crearArista(arista.getOrigen(),arista.getDestino(),arista.getPeso());
        AACM->crearArista(arista.getDestino(),arista.getOrigen(),arista.getPeso());
    }

    return AACM;
}

vector<vector<int>> GrafoM::floyd(){

	//Copia del grafo
	vector<vector<int>> path(grafo.size(),vector<int>(grafo.size(),INT_MAX));

	for (int i = 0; i < grafo.size(); i++)
	{
		for (int j = 0; j < grafo.size(); j++)
		{
			if (grafo[i][j] != 0)
			{
				path[i][j] = grafo[i][j];
			}

		}
		
	}

	for (int i = 0; i < path.size(); i++)
	{
		path[i][i] = 0;
	}
	

	for(int i = 0; i < this->grafo.size(); i++){
 		for(int k = 0; k < this->grafo.size(); k++) {
    		for(int i = 0; i < this->grafo.size(); i++) {
     			for(int j = 0; j < this->grafo.size(); j++){
					if (path[i][k] == INT_MAX || path[k][j] == INT_MAX || i == j)
					{ 
						continue;
					}
     				int dt = path[i][k] + path[k][j];
      				if(path[i][j] > dt) {
						path[i][j] = dt;
					}
    			}
			}
		}
	}

	//Imprimir el resultado

	cout << endl << "Path: " << endl;

	for (int i = 0; i < path.size(); i++)
	{
		for (int j = 0; j < path.size(); j++)
		{
			if (path[i][j] != INT_MAX && i != j)
			{
				cout << i
             	 << " ---> " << j
             	 << " : " << path[i][j]
             	 << endl;
			}

		}

	}
	
 	return path;
}


//DESTRUCTOR

GrafoM::~GrafoM() 
{

}