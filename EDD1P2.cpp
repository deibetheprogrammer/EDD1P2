#include "Tree.hpp"
#include "GrafoM.hpp"
#include "GrafoL.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

//Codificador Huffman
void codificadorHuffman(string nombre);

//Decodificador Huffman
void decodificadorHuffman(string mensaje,string arbol);
int menu();
int subMenuArboles();
int subMenuGrafos();
int miniMenuGrafos();
void operarArbol(Tree*, int);
void operarGrafo(bool, int, GrafoL* Lista = nullptr, GrafoM* = nullptr);
string nombreArchivo();

int main() {

    Tree* arbolito = nullptr;
    GrafoL* grafoListas = nullptr;
    GrafoM* grafoMatriz = nullptr;
    bool listas = false;
    int op, subOp;
    string name;
    do {
        op = menu();
        switch (op) {
        case 1://Arboles
            do {
                subOp = subMenuArboles();
                switch (subOp) {
                case 1://leer arbol
                    if (arbolito != nullptr) {
                        delete arbolito;
                        arbolito = nullptr;
                    }
                    arbolito = Tree::leerDeArchivo(nombreArchivo());
                break;
                default://todas las demas funciones del arbol
                    operarArbol(arbolito, subOp);
                break;
                }
            } while (subOp != 8);
        break;
        case 2://Grafos
            do {
                subOp = subMenuGrafos();
                if (subOp == 1) {
                    listas = miniMenuGrafos() - 1;
                    if (listas) {//Grafo con Listas
                        if (grafoListas != nullptr) {
                            delete grafoListas;
                            grafoListas = nullptr;
                        }
                        grafoListas = new GrafoL(nombreArchivo());

                        if (grafoListas->numVertices() == 0)
                        {
                            cout << endl << "Error al leer grafo" << endl;
                            delete grafoListas;
                            grafoListas = nullptr;
                            listas = false;
                        } else {
                        cout << endl << "Grafo leido: " << endl;
                        grafoListas->imprimir();
                        }
                    } else {//Grafo con Matriz
                        if(grafoMatriz != nullptr) {
                            delete grafoMatriz;
                            grafoMatriz = nullptr;
                        }
                        grafoMatriz = new GrafoM(nombreArchivo());
                        if(grafoMatriz->numVertices() == 0){
                            cout << endl << "Error al leer grafo" << endl;
                            delete grafoMatriz;
                            grafoMatriz = nullptr;
                        } else {
                        cout << endl << "Grafo leido: " << endl;
                        }
                    }
                } else if(subOp != 5) {
                    operarGrafo(listas, subOp, grafoListas, grafoMatriz);
                }
            } while(subOp != 5);
        break;
        }
    } while (op != 3);
    //codificadorHuffman("Duke.txt");
    //decodificadorHuffman("Duke.txt.hfc","Duke.txt.hft");
}

bool validar(int &entrada, int max, int min = 1) {//valida que el tipo de dato ingresado por el usuario coincida con el de la variable
    if(!(cin >> entrada) || entrada < min || entrada > max) {//y este dentro del rango deseado
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Ingreso no valido!" << endl;
        return false;
    }
    return true;
}

int menu() {
    int op;
    cout << "\nMenu Principal\n1. Algoritmos sobre Arboles\n2. Algoritmos sobre Grafos\n3. Salir: ";
    if(!validar(op, 3)) {
        return menu();
    }
    return op;
}

int subMenuArboles() {
    int op;
    cout << endl;
    cout << "\nAlgoritmos sobre Árboles\n1. Leer Arbol de un archivo\n2. Imprimir recorrido preorder\n";
    cout << "3. Imprimir recorrido in order\n4. Imprimir recorrido postorder\n5. Imprimir recorrido en Anchura\n";
    cout << "6. Codificador de Huffman\n7. Decodificador de Huffman\n8. Regresar al Menu Principal\nIngrese la opcion que desea:  ";
    if(!validar(op, 8)) {
        return subMenuArboles();
    }
    return op;
}

int subMenuGrafos() {
    int op;
    cout << "\nAlgoritmos sobre Grafos\n1. Leer grafo de un archivo\n2. Prim\n3. Kruskal\n4. Floyd\n";
    cout << "5. Regresar al Menu Principal: ";
    if(!validar(op, 7)) {
        return subMenuGrafos();
    }
    return op;
}

int miniMenuGrafos() {
    int op;
    cout << "\nComo desea leer el grafo?\n1. A una Matriz\n2. A una Lista: ";
    if (!validar(op, 2)) {
        return miniMenuGrafos();
    }
    return op;
}

string nombreArchivo() {
    string name;
    cout << "Ingrese el nombre del archivo: ";
    cin >> name;
    return name;
}

void operarArbol(Tree* arbol, int op) {
    if (arbol == nullptr && op < 6) {
        cout << "Arbol no existe" << endl;
        return;
    }
    string name;
    switch (op) {
        case 2://preorder
        arbol->DFS_ImprimirPreOrder(arbol->raiz());
    break;
    case 3://in order
            arbol->DFS_ImprimirInOrder(arbol->raiz());
    break;
    case 4://postorder
            arbol->DFS_ImprimirPostOrder(arbol->raiz());
            cout << endl;
    break;
    case 5://BFS
            arbol->BFS_Imprimir();
    break;
    case 6://codificador Huffman
        cout << "Ingrese el nombre del archivo: ";
        cin >> name;
        codificadorHuffman(name);
    break;
    case 7://decodificador Huffman
    cout << "Ingrese el nombre del archivo: ";
        cin >> name;
        decodificadorHuffman(name + ".hfc", name + ".hft");
    break;
    }
}

void operarGrafo(bool conLista, int subOp, GrafoL* Lista, GrafoM* Matriz) {
    if (conLista) {
        if (subOp != 3) {
            cout << "Usted no tiene un grafo cargado con matrices de adyacencia. No puede usar esta funcion!\n";
            return;
        }
        Lista->kruskal();
    } else {
        if (subOp == 3) {
             cout << "Usted no tiene cargado un grafo con listas de adyacencia. No puede usar esta funcion!\n";
            return;
        }
        if (Matriz == nullptr) {
            cout << "Usted no tiene un grafo cargado con matrices de adyacencia. No puede usar esta funcion!\n";
            return;
        }
        switch (subOp) {
        case 2:
            Matriz->prim();
        break;
        case 4:
            Matriz->floyd();
        break;
        }
    }
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
                    string etiqueta = tNode->getIzq()->getEtiqueta();
                    if (etiqueta == "," )
                    {
                        etiqueta = "cm";
                    }
                    else if (etiqueta == ";")
                    {
                        etiqueta = "pc";
                    }
                
                    ofst << etiqueta << ",";

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
                        string etiquetaD = tNode->getDer()->getEtiqueta();
                        if (etiquetaD == "," )
                        {
                            etiquetaD = "cm";
                        }
                        else if (etiquetaD == ";")
                        {
                            etiquetaD = "pc";
                        }
                        ofst << etiquetaD << ",";

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
                else
                {
                    ofst << ",;,";
                }
                
                ofst << endl;
            }
            ofst.close();
        }
    }
}

//Decodificador Huffman
void decodificadorHuffman(string mensaje,string arbol)
{
    //Obtener el arbol
    ifstream ifst(arbol);
    if (ifst.is_open())
    { 
        int sizeN;
        ifst >> sizeN;
        ifst.ignore(100,'\n');

        vector<TreeNode*> nodos(sizeN,nullptr);
        for (int i = 0; i < sizeN; i++)
        {
            nodos[i] = new TreeNode(nullptr,nullptr,nullptr,"");
        }

        for (int i = 0; i < sizeN; i++)
        {
            string etiqueta;
            getline(ifst,etiqueta,',');

            if (etiqueta == "cm")
            {
                etiqueta = ",";
            }
            else if (etiqueta == "pc")
            {
                etiqueta = ";";
            }

            string nodo_izq;
            getline(ifst,nodo_izq,';');

            if(nodo_izq != "")
            {
                TreeNode* izq = nodos[stoi(nodo_izq)];
                izq->setEtiqueta(etiqueta);
                izq->setPadre(nodos[i]);
                nodos[i]->setIzq(izq);

            }

            string etiquetaD;
            getline(ifst,etiquetaD,',');

            if (etiquetaD == "cm")
            {
                etiquetaD = ",";
            }
            else if (etiquetaD == "pc")
            {
                etiquetaD = ";";
            }

            string nodo_der;
            getline(ifst,nodo_der);

            if (nodo_der != "")
            {
                TreeNode* der = nodos[stoi(nodo_der)];
                der->setEtiqueta(etiquetaD);
                der->setPadre(nodos[i]);
                nodos[i]->setDer(der);
            }
        }

        Tree* tree = new Tree(nodos);

        //Decodificar el mensaje

        ifstream ifsc(mensaje);
        if (ifsc.is_open())
        {
            char c;
            TreeNode* actual = tree->raiz();

            cout << endl << "Mensaje decodificado : ";

            while (ifsc.get(c))
            {
                if(c == '0')
                {
                    actual = actual->getIzq();
                }
                else
                {
                    actual = actual->getDer();
                }

                if(actual->getEtiqueta() != "")
                {
                    cout << actual->getEtiqueta();
                    actual = tree->raiz();
                }
                
            }

            cout << endl;
        }
    }
    
}
