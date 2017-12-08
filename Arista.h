#ifndef ARISTA_H
#define ARISTA_H
#include <iostream>
#include "Nodo.h"

using namespace std;

class Arista
{
    public:
        Nodo* nodo_origen = NULL;
        Nodo* nodo_destino = NULL;
        Arista(Nodo* nodo_origen, Nodo* nodo_destino);
        virtual ~Arista();

    protected:

    private:
};

#endif // ARISTA_H
