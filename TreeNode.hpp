#ifndef TREENODE_H
#define TREENODE_H

#include "Object.hpp"

class TreeNode : public Object
{

    public:

    //CONSTRUCTOR
    TreeNode(int padre, int hijo_izq, int hijo_der, char etiqueta);

    //MUTADORES
    int getPadre();
    void setPadre(int padre);

    int getIzq();
    void setIzq(int hijo_izq);

    int getDer();
    void setDer(int hijo_der);

    char getEtiqueta();
    void setEtiqueta(char etiqueta);

    //METODOS
    virtual int compare(Object*);
    virtual string toString();

    //DESTRUCTOR
    ~TreeNode();

    protected:

    int padre = -1;
    int hijo_izq = -1;
    int hijo_der = -1;
    char etiqueta;

};


#endif