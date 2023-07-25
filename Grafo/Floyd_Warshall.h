#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H

#include "CaminoMinimo.h"
#include <vector>
#include <iostream>

class Floyd_Warshall : public CaminoMinimo {
    private:
        void mostrar_matrices(const std::vector<std::vector<int>>& matriz_costos, const std::vector<std::vector<int>>& matriz_caminos);

    public:
        Floyd_Warshall(int n, int** matriz_adyacencia);

        void camino_minimo() override;

        ~Floyd_Warshall() = default;
};

#endif // FLOYD_WARSHALL_H