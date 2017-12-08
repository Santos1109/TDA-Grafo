#include "Grafo.h"

Grafo::Grafo()
{
    //ctor
}

Grafo::Grafo(bool dirigido)
{
    this->dirigido = dirigido;
    llenarMatrizAdy();
    llenarMatrizPesos();
}

void Grafo::nuevoElemento(char* elemento)
{
    for(int s = 0; s < TAM; s++)
    {
        if(elementos[s] == "")
        {
            elementos[s] = elemento;
            return;
        }
    }
}

int Grafo::posElemento(char* elemento)
{
    for(int t = 0; t < TAM; t++)
    {
        if(elementos[t] == elemento)
        {
            return t;
        }
    }
    return 0;
}

void Grafo::llenarMatrizAdy()
{
    for(int h = 0; h < TAM; h++)
    {
        for(int v = 0; v < TAM; v++)
        {
            matriz_adyacencia[h][v] = false;
        }
    }
}

void Grafo::llenarMatrizPesos()
{
    for(int pos = 0; pos < TAM; pos++)
    {
        matriz_pesos[pos][pos] = 0;
    }

    for(int h = 0; h < TAM; h++)
    {
        for(int v = 0; v < TAM; v++)
        {
            if(matriz_pesos[h][v] != 0)
            {
                matriz_pesos[h][v] = INT_MAX;
            }
        }
    }
}

void Grafo::nuevaAdyacencia(char* elemento1, char* elemento2)
{
    if(dirigido)
    {
        matriz_adyacencia[posElemento(elemento1)][posElemento(elemento2)] = true;
    }
    else{
        matriz_adyacencia[posElemento(elemento1)][posElemento(elemento2)] = true;
        matriz_adyacencia[posElemento(elemento2)][posElemento(elemento1)] = true;
    }
}

void Grafo::nuevoPeso(char* elemento1, char* elemento2, int peso)
{
    matriz_pesos[posElemento(elemento1)][posElemento(elemento2)] = peso;
}

void Grafo::eliminarAdyacencia(char* elemento1, char* elemento2)
{
    if(dirigido)
    {
        matriz_adyacencia[posElemento(elemento1)][posElemento(elemento2)] = false;
    }
    else{
        matriz_adyacencia[posElemento(elemento1)][posElemento(elemento2)] = false;
        matriz_adyacencia[posElemento(elemento2)][posElemento(elemento1)] = false;
    }
}

bool Grafo::isConexo()
{
    int conexion = 0;
    for(int f = 0; f < TAM; f++)
    {
        for(int c = 0; c < TAM; c++)
        {
            if(matriz_adyacencia[f][c])
            {
                conexion++;
            }
        }
        if(conexion >= 1)
        {
            conexion = 0;
        }
        else{
            return false;
        }
    }
    return true;
}

bool Grafo::isCompleto()
{
    for(int f = 0; f < TAM; f++)
    {
        for(int c = 0; c < TAM; c++)
        {
            if(!matriz_adyacencia[f][c])
            {
                return false;
            }
        }
    }
    return true;
}

Grafo::~Grafo()
{
    //dtor
}
