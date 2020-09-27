#include "AristaL.hpp"

//CONSTRUCTOR
AristaL::AristaL(int origen, int destino, int peso)
{
    this->origen = origen;
    this->destino = destino;
    this->peso = peso;
}

//METODOS
bool AristaL::operator<(AristaL& rhs)
{
    return this->peso < rhs.peso;
}

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