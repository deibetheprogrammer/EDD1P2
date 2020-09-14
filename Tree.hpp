#ifndef TREE_H
#define TREE_H

#include <vector>
#include "TreeNode.hpp"

using std::vector;

class Tree
{

    public:

        //CONSTRUCTOR
        Tree();

        //METODOS

        //Devuelve el padre del nodo
        TreeNode* padre(TreeNode* tNode);

        //Delvuelve el hijo mas a la izquierda del nodo
        TreeNode* hijo_mas_izq(TreeNode* tNode);

        //Devuelve el hijo mas a la derecha del nodo
        TreeNode* hermano_der(TreeNode* tNode);

        //Crea un  nuevo nodo
        TreeNode* crea(char etiqueta, TreeNode* padre, TreeNode* izq, TreeNode* der);

        //Devuelve la etiqueta de la raiz
        TreeNode* raiz();

        //Borra todos los elementos del arbol
        void anula();

        //Se le debe indicar el nombre de un archivo de texto a partir del cual se leerá el árbol
        Tree leerDeArchivo(string nombre);

        //Mostrará en pantalla el resultado de realizar el recorrido en anchura
        void BFS_Imprimir();

        //Mostrará en pantalla el resultado de realizar el recorrido en orden previo
        void DFS_ImprimirPreOrder();

        //Mostrará en pantalla el resultado de realizar el recorrido en orden simétrico 
        void DFS_ImprimirInOrder();

        //Mostrará en pantalla el resultado de realizar el recorrido en orden posterior
        void DFS_ImprimirPostOrder();

        //Pedirá el nombre de un archivo de texto, para cuyo contenido se creará un código de Huffman y se mostrará en pantalla  
        void codificadorHuffman(string nombre);

        //Pedirá el nombre de un archivo de texto codificado y el árbol, mostrará el texto original 
        void decodificadorHuffman(string mensaje,string arbol);

        //DESTRUCTOR
        ~Tree();


    protected:

        //Lista de listas de nodos
        vector<vector<TreeNode*>> nodes;

        //Raiz del arbol
        TreeNode* raiz;


};

#endif