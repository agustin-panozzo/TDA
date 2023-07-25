#include "Grafo.h"

using namespace std;

Grafo::Grafo() : n(0), matriz_adyacencia(nullptr), camino_minimo(nullptr) {}

Grafo::Grafo(int n) : n(n), matriz_adyacencia(nullptr), camino_minimo(nullptr) {
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

void Grafo::usar_dijkstra(int nodo_inicial){
    camino_minimo = new Dijkstra(n, matriz_adyacencia, nodo_inicial);
    camino_minimo -> camino_minimo();
}

Grafo::~Grafo(){
    liberar_matriz();
    delete camino_minimo;
}