#ifndef GRAFO_H
#define GRAFO_H

#include <limits>
#include <vector>
#include <iostream>

const int INF = std::numeric_limits<int>::max();

class Grafo{
    private:
        int n;
        int** matriz_adyacencia;

        void generar_matriz();

        void inicializar_matriz();

        void copiar_matriz(int** matriz);

        void liberar_matriz();

        void ampliar_matriz();

        void dfs_recursivo(int vertice, std::vector<bool>& visitados);

        void dfs();

        int encontrar_nodo_minimo(const std::vector<int>& distancias, const std::vector<bool>& visitados);

        void actualizar_distancias(int nodo_actual, std::vector<int>& distancias, const std::vector<bool>& visitados);

    public:
        Grafo();

        Grafo(int n);

        void agregar_vertice();

        void agregar_arista(int vertice1, int vertice2, int peso);

        void recorrer_grafo();

        void dijsktra(int nodo_inicial);

        ~Grafo();
};

#endif // GRAFO_H