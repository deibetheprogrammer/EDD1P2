#ifndef OBJECT_H
#define OBJECT_H

#include <string>
using std::string;


class Object
{
    public:
        //CONSTRUCTORES
        Object();

        //METODOS

        //Compara los objetos para ver si son el mismo
        virtual int compare(Object*) = 0;

        //Muestra una version textual del objeto
        virtual string toString() = 0;

        //DESTRUCTOR
        virtual ~Object() {}
    
};

#endif