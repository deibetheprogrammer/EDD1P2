#include "TreeNode.hpp"

TreeNode::TreeNode(int padre, int hijo_izq, int hijo_der, char etiqueta)
{
    this->padre = padre;
    this->hijo_der = hijo_der;
    this->hijo_izq = hijo_izq;
    this->etiqueta = etiqueta;

}

int TreeNode::getPadre()
{
    return this->padre;
}

void TreeNode::setPadre(int padre)
{
    this->padre = padre;
}

int TreeNode::getDer()
{
    return this->hijo_der;
}

void TreeNode::setDer(int hijo_der)
{
    this->hijo_der = hijo_der;
}

int TreeNode::getIzq()
{
    return this->hijo_izq;
}

void TreeNode::setIzq(int hijo_izq)
{
    this->hijo_izq = hijo_izq;
}

char TreeNode::getEtiqueta()
{
    return this->etiqueta;
}

void TreeNode::setEtiqueta(char etiqueta)
{
    this->etiqueta = etiqueta;
}

int TreeNode::compare(Object* x) 
{
    TreeNode* otro = dynamic_cast<TreeNode*>(x);
    if(otro)
    {
        if (otro->getEtiqueta() == this->etiqueta)
        {
            return 1;
        }
    }
    return 0;
}

string TreeNode::toString()
{
    string etiqueta = "";
    return etiqueta.insert(0,etiqueta);
}

//DESTRUCTOR

TreeNode::~TreeNode()
{
    
}
