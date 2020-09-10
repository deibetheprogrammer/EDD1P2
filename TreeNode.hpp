#ifndef TREENODE_H
#define TREENODE_H

#include "Object.hpp"

class TreeNode : public Object
{

    public:

    //CONSTRUCTOR
    TreeNode(TreeNode* padre, TreeNode* hijo_izq, TreeNode* hijo_der, char etiqueta);

    //MUTADORES
    TreeNode* getPadre();
    void setPadre(TreeNode* padre);

    TreeNode* getIzq();
    void setIzq(TreeNode* hijo_izq);

    TreeNode* getDer();
    void setDer(TreeNode* hijo_der);

    char getEtiqueta();
    void setEtiqueta(char etiqueta);

    //METODOS
    virtual int compare(Object*){}
    virtual string toString(){}

    //DESTRUCTOR
    ~TreeNode();

    protected:

    TreeNode *padre;
    TreeNode *hijo_izq;
    TreeNode *hijo_der;
    char etiqueta;

};


#endif