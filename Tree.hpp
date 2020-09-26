#ifndef TREE_H
#define TREE_H

#include <vector>
#include "TreeNode.hpp"

using std::vector;

class Tree
{

    public:

        //CONSTRUCTOR
        Tree(int nNodos);
        
        //METODOS

        //Devuelve el padre del nodo
        TreeNode* padre(TreeNode* tNode);

        //Delvuelve el hijo mas a la izquierda del nodo
        TreeNode* hijo_izq(TreeNode* tNode);

        //Devuelve el hijo mas a la derecha del nodo
        TreeNode* hijo_der(TreeNode* tNode);

        //Crea un  nuevo nodo
        TreeNode* crea(string etiqueta, int nodo = -1 ,int izq = -1, int der = -1);

        //Devuelve el nodo raiz
        TreeNode* raiz();

        //Borra todos los elementos del arbol
        void anula();

        //Se le debe indicar el nombre de un archivo de texto a partir del cual se leerá el árbol
        Tree leerDeArchivo(string nombre);

        //Mostrará en pantalla el resultado de realizar el recorrido en anchura
        void BFS_Imprimir();

        //Mostrará en pantalla el resultado de realizar el recorrido en orden previo
        void DFS_ImprimirPreOrder(TreeNode* tNode);

        //Mostrará en pantalla el resultado de realizar el recorrido en orden simétrico 
        void DFS_ImprimirInOrder();

        //Mostrará en pantalla el resultado de realizar el recorrido en orden posterior
        void DFS_ImprimirPostOrder();

        //DESTRUCTOR
        ~Tree();


    protected:

        //Lista de listas de nodos
        vector<TreeNode*> nodes;

        //Raiz del arbol
        int root;


};

#endif