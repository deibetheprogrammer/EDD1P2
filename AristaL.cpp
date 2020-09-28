#include "AristaL.hpp"

//CONSTRUCTOR
AristaL::AristaL(int origen, int destino, int peso)
{
    this->origen = origen;
    this->destino = destino;
    this->peso = peso;
}

//METODOS

int AristaL::getOrigen()
{
    return this->origen;
}

int AristaL::getDestino()
{
    return this->destino;
}

int AristaL::getPeso()
{
    return this->peso;
}

//DESTRUCTOR
AristaL::~AristaL()
{
    
}