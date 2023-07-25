#include "CaminoMinimo.h"

CaminoMinimo::CaminoMinimo() : n(0), matriz_adyacencia(nullptr) {}

CaminoMinimo::CaminoMinimo(int n, int** matriz_adyacencia) : n(n), matriz_adyacencia(matriz_adyacencia) {}