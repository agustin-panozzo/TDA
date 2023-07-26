#include "Prim.h"

using namespace std;

Prim::Prim() : CaminoMinimo() {}

Prim::Prim(int n, int** matriz_adyacencia) : CaminoMinimo(n, matriz_adyacencia) {}

int Prim::nodo_minimo(const vector<int>& pesos_minimos, const vector<bool>& visitados){
    int minimo = -1;
    int minimo_actual = INF;

    for(int i = 0; i < n; i++){
        if(!visitados[i] && pesos_minimos[i] < minimo_actual){
            minimo_actual = pesos_minimos[i];
            minimo = i;
        }
    }

    return minimo;
}

void Prim::camino_minimo(){
    vector<bool> visitados(n, false);
    vector<int> pesos_minimos(n, INF);
    vector<int> padres(n, -1);

    pesos_minimos[0] = 0;
    padres[0] = -1;

    for(int i = 0; i < n - 1; i++){
        int u = nodo_minimo(pesos_minimos, visitados);

        visitados[u] = true;

        for(int v = 0; v < n; v++){
            if(matriz_adyacencia[u][v] != 0 && !visitados[v] && matriz_adyacencia[u][v] < pesos_minimos[v]){
                padres[v] = u + 1;
                pesos_minimos[v] = matriz_adyacencia[u][v];
            }
        }
    }

    cout << "Aristas del MST: " << endl;
    for(int i = 0; i < n; i++){
        cout << padres[i] << " - " << " (" << pesos_minimos[i] << ")" << endl;
    }
}