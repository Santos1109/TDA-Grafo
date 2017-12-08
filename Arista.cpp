#include "Arista.h"

Arista::Arista(Nodo* nodo_origen, Nodo* nodo_destino)
{
    this->nodo_origen = nodo_origen;
    this->nodo_destino = nodo_destino;
}

Arista::~Arista()
{
    //dtor
}
