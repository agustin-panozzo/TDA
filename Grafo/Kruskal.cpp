#include "Kruskal.h"

using namespace std;

Kruskal::Kruskal() : CaminoMinimo() {}

Kruskal::Kruskal(int n, int** matriz_adyacencia) : CaminoMinimo(n, matriz_adyacencia) {}

void Kruskal::generar_aristas() {
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){

            if(matriz_adyacencia[i][j] != 0 && matriz_adyacencia[i][j] != INF){
                Arista arista;
                arista.origen = i;
                arista.destino = j;
                arista.peso = matriz_adyacencia[i][j];
                aristas.push_back(arista);
            }
        }
    }
}

void Kruskal::ordenar_aristas() {
    for(size_t i = 0; i < aristas.size(); i++){
        for(size_t j = 0; j < aristas.size() - 1; j++){

            if(aristas[j].peso > aristas[j + 1].peso){
                Arista aux = aristas[j];
                aristas[j] = aristas[j + 1];
                aristas[j + 1] = aux;
            }
        }
    }
}

void Kruskal::camino_minimo() {
    generar_aristas();
    ordenar_aristas();

    vector<bool> visitado(n, false); // Para evitar ciclos
    int numAristas = 0;

    for(size_t i = 0; i < aristas.size(); i++) {
        int origen = aristas[i].origen;
        int destino = aristas[i].destino;

        if (!visitado[origen] || !visitado[destino]) {
            visitado[origen] = true;
            visitado[destino] = true;

            numAristas++;
            cout << "Origen: " << origen + 1 << " Destino: " << destino + 1 << " Peso: " << aristas[i].peso << endl;

            if (numAristas == n - 1) {
                break;
            }
        }
    }
}