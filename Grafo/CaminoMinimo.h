#ifndef CAMINO_MINIMO_H
#define CAMINO_MINIMO_H

#include <limits>
const int INF = std::numeric_limits<int>::max();

class CaminoMinimo{
    protected:
        int n;
        int** matriz_adyacencia;

    public:
        CaminoMinimo();

        CaminoMinimo(int n, int** matriz_adyacencia);

        virtual void camino_minimo() = 0;

        virtual ~CaminoMinimo() = default;
};

#endif // CAMINO_MINIMO_H