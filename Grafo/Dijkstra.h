#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <iostream>
#include "CaminoMinimo.h"

class Dijkstra : public CaminoMinimo{
    private:
        int nodo_inicial;

        int encontrar_nodo_minimo(const std::vector<int>& distancias, const std::vector<bool>& visitados);

        void actualizar_distancias(int nodo_actual, std::vector<int>& distancias, const std::vector<bool>& visitados);

    public:
        Dijkstra(int n, int** matriz_adyacencia, int nodo_inicial);

        void camino_minimo();

        ~Dijkstra() = default;
};

#endif // DIJKSTRA_H