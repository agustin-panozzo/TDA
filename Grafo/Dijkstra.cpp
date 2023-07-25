#include "Dijkstra.h"

using namespace std;

Dijkstra::Dijkstra(int n, int** matriz_adyacencia, int nodo_inicial) : CaminoMinimo(n, matriz_adyacencia), nodo_inicial(nodo_inicial) {}

int Dijkstra::encontrar_nodo_minimo(const vector<int>& distancias, const vector<bool>& visitados){
    int minimo = INF;
    int nodo_minimo = -1;

    for(int i = 0; i < n; i++){
        if(!visitados[i] && distancias[i] < minimo){
            minimo = distancias[i];
            nodo_minimo = i;
        }
    }

    return nodo_minimo;
}

void Dijkstra::actualizar_distancias(int nodo_actual, vector<int>& distancias, const vector<bool>& visitados){
    int distancia_nueva;

    for(int k = 0; k < n; k++){
        int peso = matriz_adyacencia[nodo_actual][k];

        if(!visitados[k] && peso != INF){
            distancia_nueva = distancias[nodo_actual] + peso;

            if(distancia_nueva < distancias[k]){
                distancias[k] = distancia_nueva;
            }
        }
    }
}

void Dijkstra::camino_minimo(){
    vector<int> distancias(n, INF);
    vector<bool> visitados(n, false);
    int nodo_actual;

    distancias[nodo_inicial - 1] = 0;

    for(int i = 0; i < n - 1; i++){
        nodo_actual = encontrar_nodo_minimo(distancias, visitados);

        if(nodo_actual != -1){
            visitados[nodo_actual] = true;
            actualizar_distancias(nodo_actual, distancias, visitados);
        }
    }

    for(int i = 0; i < n; i++){
        cout << "Distancia del nodo " << nodo_inicial << " al nodo " << i + 1 << ": " << distancias[i] << endl;
    }
}