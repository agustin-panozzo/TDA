#ifndef GRAFO_H
#define GRAFO_H

#include <limits>
#include <vector>
#include <iostream>
#include "Dijkstra.h"
#include "Floyd_Warshall.h"
#include "Prim.h"
#include "Kruskal.h"

class Grafo{
    private:
        int n;
        int** matriz_adyacencia;
        CaminoMinimo* camino_minimo;

        void generar_matriz();

        void inicializar_matriz();

        void copiar_matriz(int** matriz);

        void liberar_matriz();

        void ampliar_matriz();

        void dfs_recursivo(int vertice, std::vector<bool>& visitados);

        void dfs();

    public:
        Grafo();

        Grafo(int n);

        void agregar_vertice();

        void agregar_arista(int vertice1, int vertice2, int peso);

        void recorrer_grafo();

        void usar_dijkstra(int nodo_inicial);

        void usar_floyd_warshall();

        void usar_prim();

        void usar_kruskal();

        ~Grafo();
};

#endif // GRAFO_H