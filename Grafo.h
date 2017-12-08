#ifndef GRAFO_H
#define GRAFO_H
#include <climits>


class Grafo
{
    public:
        static const int TAM = 10;
        bool dirigido;
        char* elementos[TAM];
        bool matriz_adyacencia[TAM][TAM];
        int matriz_pesos[TAM][TAM];
        Grafo();
        Grafo(bool dirigido);
        void nuevoElemento(char* elemento);
        int posElemento(char* elemento);
        void llenarMatrizAdy();
        void llenarMatrizPesos();
        void nuevaAdyacencia(char* elemento1, char* elemento2);
        void nuevoPeso(char* elemento1, char* elemento2, int peso);
        void eliminarAdyacencia(char* elemento1, char* elemento2);
        bool isConexo();
        bool isCompleto();
        virtual ~Grafo();

    protected:

    private:
};

#endif // GRAFO_H
