#include "Grafo.h"

using namespace std;

Grafo::Grafo() : n(0), matriz_adyacencia(nullptr) {}

Grafo::Grafo(int n) : n(n), matriz_adyacencia(nullptr) {
    generar_matriz();
    inicializar_matriz();
}

void Grafo::generar_matriz(){
    matriz_adyacencia = new int*[n];

    for(int i = 0; i < n; i++){
        matriz_adyacencia[i] = new int[n];
    }
}

void Grafo::inicializar_matriz(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matriz_adyacencia[i][j] = INF;
        }
    }
}

void Grafo::copiar_matriz(int** copia){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            copia[i][j] = matriz_adyacencia[i][j];
        }
    }
}

void Grafo::ampliar_matriz(){
    int** nueva_matriz = new int*[n + 1];

    for(int i = 0; i < n + 1; i++){
        nueva_matriz[i] = new int[n + 1];
    }

    copiar_matriz(nueva_matriz);
    liberar_matriz();

    matriz_adyacencia = nueva_matriz;
    n++;
}

void Grafo::liberar_matriz(){
    for(int i = 0; i < n; i++){
        delete[] matriz_adyacencia[i];
    }

    delete matriz_adyacencia;
}

void Grafo::agregar_vertice(){
    ampliar_matriz();

    for(int i = 0; i < n; i++){
        matriz_adyacencia[i][n - 1] = INF;
        matriz_adyacencia[n - 1][i] = INF;
    }
}

void Grafo::agregar_arista(int vertice1, int vertice2, int peso){
    matriz_adyacencia[vertice1 - 1][vertice2 - 1] = peso;
    //matriz_adyacencia[vertice2][vertice1] = peso; // Para que sea dirigido en un solo sentido
}

void Grafo::dfs_recursivo(int vertice, vector<bool>& visitados){
    visitados[vertice - 1] = true;
    cout << "Nodo visitado: " << vertice << endl;

    for(int i = 0; i < n; i++){
        if(!visitados[i] && matriz_adyacencia[vertice - 1][i] != INF){
            dfs_recursivo(i + 1, visitados);
        }
    }
}

void Grafo::dfs(){
    vector<bool> visitados(n, false);
    dfs_recursivo(1, visitados);
}

void Grafo::recorrer_grafo(){
    dfs();
}

void Grafo::calcular_caminos_minimos(int vertice_inicial){
    vector<int> distancias(n, INF);
    vector<bool> visitados(n, false);

    distancias[vertice_inicial - 1] = 0; // Distancia del nodo inicial a si mismo es 0

    for(int i = 0; i < n - 1; i++){
        int nodo_actual;
        int min_distancia = INF;

        for(int j = 0; j < n; j++){ // Buscamos el nodo con la menor distancia
            if(!visitados[j] && distancias[j] < min_distancia){
                min_distancia = distancias[j];
                nodo_actual = j;
            }
        }

        visitados[nodo_actual] = true;

        for(int k = 0; k < n; k++){
            int peso = matriz_adyacencia[nodo_actual][k];

            if(!visitados[k] && peso != INF) {
                int distancia_nuevo = distancias[nodo_actual] + peso;

                if(distancia_nuevo < distancias[k]){
                    distancias[k] = distancia_nuevo;
                }
            }
        }
    }

    cout << "Distancias más cortas desde el vertice " << vertice_inicial << ":" << endl;

    for(int i = 0; i < n; i++){
        cout << "Vertice "<< i + 1 << ": " << distancias[i] << endl;
    }
}

Grafo::~Grafo(){
    liberar_matriz();
}