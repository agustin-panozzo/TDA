#ifndef PRIM_H
#define PRIM_H

#include "CaminoMinimo.h"
#include <vector>
#include <iostream>

class Prim : public CaminoMinimo{
    private:
        int nodo_minimo(const std::vector<int>& pesos_minimos, const std::vector<bool>& visitados);

    public:
        Prim();

        Prim(int n, int** matriz_adyacencia);

        void camino_minimo() override;

        ~Prim() = default;
};

#endif // PRIM_H