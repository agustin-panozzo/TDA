#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "CaminoMinimo.h"
#include <vector>
#include <iostream>

struct Arista {
    int origen, destino, peso;
};

class Kruskal : public CaminoMinimo {
    private:
        std::vector<Arista> aristas;

    public:
        Kruskal();

        Kruskal(int n, int** matriz_adyacencia);

        void generar_aristas();

        void ordenar_aristas();

        void camino_minimo() override;

        ~Kruskal() = default;
};

#endif // KRUSKAL_H