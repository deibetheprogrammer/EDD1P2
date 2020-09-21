#ifndef TREENODE_H
#define TREENODE_H

#include "Object.hpp"

class TreeNode : public Object
{

    public:

    //CONSTRUCTOR
    TreeNode(TreeNode* padre, TreeNode* hijo_izq, TreeNode* hijo_der, string etiqueta);

    //MUTADORES
    TreeNode* getPadre();
    void setPadre(TreeNode* padre);

    TreeNode* getIzq();
    void setIzq(TreeNode* hijo_izq);

    TreeNode* getDer();
    void setDer(TreeNode* hijo_der);

    string getEtiqueta();
    void setEtiqueta(string etiqueta);

    //METODOS
    virtual int compare(Object*);
    virtual string toString();

    //DESTRUCTOR
    ~TreeNode();

    protected:

    TreeNode *padre;
    TreeNode *hijo_izq;
    TreeNode *hijo_der;
    string etiqueta;

};


#endif