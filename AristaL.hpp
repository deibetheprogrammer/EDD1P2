#ifndef ARISTAL_H
#define ARISTAL_H

#include <vector>

using namespace std;

class AristaL
{
    public:

    //CONSTRUCTOR
    AristaL(int origen, int destino, int peso);

    //METODOS

    //Devuelve el origen
    int getOrigen();

    //Devuelve el destino
    int getDestino();

    //Devuelve el peso
    int getPeso();

    //DESTRUCTOR
    ~AristaL();

    private:
    
    int origen;
    int destino;
    int peso;

};

#endif