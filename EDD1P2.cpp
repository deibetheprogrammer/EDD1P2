#include "Tree.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

//Codificador Huffman
void codificadorHuffman(string nombre);

int main() {

    codificadorHuffman("Duke.txt");
    
}

void codificadorHuffman(string nombre)
{
    ifstream ifs(nombre);
    if(ifs.is_open())
    {
        ostringstream oss;
        oss<<ifs.rdbuf();

        string strf = oss.str();

        vector<int> freq(256,0);

        for (unsigned char c : strf)
        {
            freq[c]++;
        }

        vector<pair<TreeNode*,int>> nodes;
        nodes.push_back(make_pair(nullptr,0));

        for(int c = 0; c < 256 ;c++)
        {
            if (freq[c] > 0)
            {
                TreeNode* tNode = new TreeNode(nullptr,nullptr,nullptr,string(1,c));
                nodes.push_back(make_pair(tNode,freq[c]));
            }

        }

       
        int nodos_rest = nodes.size();
        while (nodos_rest > 2)
        {
            int p1 = 0;
            int p2 = 0;
            int f1 = INT_MAX;
            int f2 = INT_MAX;
            nodos_rest = 0;
            for (int i = 1; i < nodes.size(); i++)
            {
                TreeNode* tNode = nodes[i].first;
                int nf = nodes[i].second;
                if (tNode->getPadre() == nullptr)
                {
                    if(nf < f1)
                    {
                        p2 = p1;
                        f2 = f1;
                        p1 = i;
                        f1 = nf;
                    }
                    else if (nf < f2)
                    {
                        p2 = i;
                        f2 = nf;
                    }
                    nodos_rest++;
                }
                
            }
            TreeNode* tNode = new TreeNode(nullptr,nodes[p1].first,nodes[p2].first,"");
            int newF = f1 + f2;
            nodes[p1].first->setPadre(tNode);
            nodes[p2].first->setPadre(tNode);

            if (nodos_rest == 2)
            {
                nodes[0] = make_pair(tNode,newF);
            }
            else
            {
                nodes.push_back(make_pair(tNode,newF));
            }
            
        }

        //Adaptar la estructura

        vector<TreeNode*> arbol;

        for (int i = 0; i < nodes.size(); i++)
        {
            arbol.push_back(nodes[i].first);
        }

        //Crear el arbol

        Tree* tree = new Tree(arbol);

        //Crear el archivo con el codigo

        ofstream ofsc(nombre + ".hfc");
        if(ofsc.is_open())
        {
            cout << endl << "Codigo de Huffman: ";
            for (char c : strf)
            {
                string et = string(1,c);
                string route = tree->ruta(et);
                cout << route;
                ofsc << route;
            }
            cout << endl << "Arbol: ";
            tree->DFS_ImprimirPreOrder(tree->raiz());
            cout << endl;

            ofsc.close();
        }

        //Crear el archivo con el arbol

        ofstream ofst(nombre + ".hft");
        if (ofst.is_open())
        {
            ofst << arbol.size() << endl;
            for (int i = 0; i < arbol.size(); i++)
            {
                TreeNode* tNode = arbol[i];
                if (tNode->getIzq() != nullptr)
                {
                    ofst << tNode->getIzq()->getEtiqueta() << ",";

                    for (int j = 0; j < arbol.size(); j++)
                    {
                        if (tNode->getIzq() == arbol[j])
                        {
                            ofst << j << ";";
                            break;
                        }
                        
                    }

                    if (tNode->getDer() != nullptr)
                    {
                        ofst << tNode->getDer()->getEtiqueta() << ",";

                        for (int k = 0; k < arbol.size(); k++)
                        {
                            if (tNode->getDer() == arbol[k])
                            {
                                ofst << k;
                                break;
                            }
                        
                        }
                        
                    }
                } 
                ofst << endl;
            }
            ofst.close();
        }
    }
}
