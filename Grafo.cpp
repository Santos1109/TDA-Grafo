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

void GrafoDijkstra::inicializarDijkstra()
{
    for(int c = 0; c < TAM; c++)
    {
        visitado[c] = false;
        elementos[c] = 0;

        for(int j = 0; j < TAM; j++)
        {
            matriz[c][j] = INT_MAX;
        }
    }
    distancia[0] = matriz[0][0];
    visitado[0] = true;
    distancia[0] = 0;

    for(int n = 0; n < TAM; n++)
    {
        minimo = INT_MAX;
        for(int c = 0; c < 10; c++)
        {
            if(minimo > distancia[c] && !visitado)
            {
                minimo = distancia[c];
                sig = c;
            }
        }
        visitado[sig] = true;

        for(int s = 0; s < TAM; s++)
        {
            if(!visitado[s])
            {
                if(minimo+matriz[sig][s] < distancia[s])
                {
                    distancia[s] = minimo+matriz[sig][s];
                    elementos[s] = sig;
                }
            }
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

void Grafo::establecerAdyacencias()
{
    for(int f = 0; f < tamanio; f++)
    {
        for(int c = 0; c < tamanio; c++)
        {
            adyacencias[f][c] = false;
        }
    }
}

void Grafo::establecerPesos()
{
    for(int f = 0; f < tamanio; f++)
    {
        for(int c = 0; c < tamanio; c++)
        {
            pesos[f][c] = 0;
        }
    }
}

int Grafo::getPosicion(int num)
{
    for(int s = 0; s < tamanio; s++)
    {
        if(numeros[s] == num)
        {
            return s;
        }
    }
    return -1;
}

bool Grafo::crearAdyacencia(int num1, int num2)
{
    if(!adyacencias[getPosicion(num1)][getPosicion(num2)]
       || !adyacencias[getPosicion(num2)][getPosicion(num1)])
    {
        adyacencias[getPosicion(num1)][getPosicion(num2)] = true;
        adyacencias[getPosicion(num2)][getPosicion(num1)] = true;
        return true;
    }
    return false;
}

void Grafo::eliminarAdyacencia(int num1, int num2)
{
    adyacencias[getPosicion(num1)][getPosicion(num2)] = false;
    adyacencias[getPosicion(num2)][getPosicion(num1)] = false;
}

bool Grafo::existeCamino(int num1, int num2)
{
    bool verticesVisitados[10] = {0,0,0,0,0,0,0,0,0,0};
    verticesVisitados[getPosicion(num1)] = true;
    stack<int> siguiente;
    siguiente.push(getPosicion(num1));

    while(!siguiente.empty())
    {
        int temp = siguiente.top();
        siguiente.pop();

        for(int s = 0; s < tamanio; s++)
        {
            if(!verticesVisitados[s] && adyacencias[temp][s])
            {
                verticesVisitados[s] = true;
                siguiente.push(s);
            }
        }
    }
    return verticesVisitados[getPosicion(num2)];
}

void Grafo::agregarPesos(int num1, int num2, int peso)
{
    pesos[getPosicion(num1)][getPosicion(num2)] = peso;
    pesos[getPosicion(num2)][getPosicion(num1)] = peso;
}

int Grafo::caminoMinimo(int num1, int num2)
{
    int temporal[tamanio][tamanio];

    for(int s = 0; s < tamanio; s++)
    {
        for(int x = 0; x < tamanio; x++)
        {
            temporal[s][x] = pesos[s][x];
        }
    }

    for(int n = 0; n < tamanio; n++)
    {
        for(int m = 0; m < tamanio; m++)
        {
            for(int s = 0; s < tamanio; s++)
            {
                if(temporal[m][n]+temporal[n][s] < temporal[m][s])
                {
                    temporal[m][s] = temporal[m][n] + temporal[n][s];
                }
            }
        }
    }
    return temporal[getPosicion(num1)][getPosicion(num2)];
}

bool Grafo::isConexo()
{
    int puntos = 0;

    for(int f = 0; f < tamanio; f++)
    {
        for(int c = 0; c < tamanio; c++)
        {
            if(adyacencias[f][c])
            {
                puntos++;
            }
        }
        if(puntos >= 1)
        {
            puntos = 0;
        }
        else{
            return false;
        }
    }
    return true;
}

bool Grafo::isCompleto()
{
    for(int f = 0; f < tamanio; f++)
    {
        for(int c = 0; c < tamanio; c++)
        {
            if(!adyacencias[f][c])
            {
                return false;
            }
        }
    }
    return true;
}

void Grafo::imprimirAdyacencias()
{
    for(int f = 0; f < tamanio; f++)
    {
        for(int c = 0; c < tamanio; c++)
        {
            cout<<adyacencias[f][c]<<" ";
        }
        cout<<endl<<endl;
    }
}



void Grafo::imprimirPesos()
{
    for(int f = 0; f < tamanio; f++)
    {
        for(int c = 0; c < tamanio; c++)
        {
            cout<<pesos[f][c]<<" ";
        }
        cout<<endl<<endl;
    }
}

Grafo::~Grafo()
{
    //dtor
}
