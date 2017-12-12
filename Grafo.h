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

        static const int TAM = 10;
        int minimo = INT_MAX, sig = 0;
        int elementos[TAM];
        int matriz[TAM][TAM];
        int distancia[TAM];
        bool visitado[TAM];
        GrafoDijkstra();
        void inicializarDijkstra();
        void dijkstra(int inicio);
        virtual ~GrafoDijkstra();

        static const int tamanio = 10;
        int numeros[10] = {20,33,54,22,90,67,78,96,12,48};
        bool adyacencias[tamanio][tamanio];
        int pesos[tamanio][tamanio];
        Grafo();
        void establecerAdyacencias();
        void establecerPesos();
        bool crearAdyacencia(int num1, int num2);
        void agregarPesos(int num1, int num2, int peso);
        void eliminarAdyacencia(int num1, int num2);
        bool existeCamino(int num1, int num2);
        int caminoMinimo(int num1, int num2);
        bool isConexo();
        bool isCompleto();
        int getPosicion(int num);
        void imprimirAdyacencias();
        void imprimirPesos();


    protected:

    private:
};

#endif // GRAFO_H
