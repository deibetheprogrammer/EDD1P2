#include "TreeNode.hpp"

TreeNode::TreeNode(TreeNode* padre, TreeNode* hijo_izq, TreeNode* hijo_der, string etiqueta)
{
    this->padre = padre;
    this->hijo_der = hijo_der;
    this->hijo_izq = hijo_izq;
    this->etiqueta = etiqueta;

}

TreeNode* TreeNode::getPadre()
{
    return this->padre;
}

void TreeNode::setPadre(TreeNode* padre)
{
    this->padre = padre;
}

TreeNode* TreeNode::getDer()
{
    return this->hijo_der;
}

void TreeNode::setDer(TreeNode* hijo_der)
{
    this->hijo_der = hijo_der;
}

TreeNode* TreeNode::getIzq()
{
    return this->hijo_izq;
}

void TreeNode::setIzq(TreeNode* hijo_izq)
{
    this->hijo_izq = hijo_izq;
}

string TreeNode::getEtiqueta()
{
    return this->etiqueta;
}

void TreeNode::setEtiqueta(string etiqueta)
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
    return etiqueta;
}

//DESTRUCTOR

TreeNode::~TreeNode()
{
    
}
