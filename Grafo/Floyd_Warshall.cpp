#include "Floyd_Warshall.h"

using namespace std;

Floyd_Warshall::Floyd_Warshall(int n, int** matriz_adyacencia) : CaminoMinimo(n, matriz_adyacencia) {}

void Floyd_Warshall::mostrar_matrices(const vector<vector<int>>& matriz_costos, const vector<vector<int>>& matriz_caminos){
    cout << "Matriz de costos:" << endl;
    for(int i = 0; i < n; i++){
        cout << "\t";
        for(int j = 0; j < n; j++){
            if(matriz_costos[i][j] == INF){
                cout << "INF ";
            }

            else{
                cout << matriz_costos[i][j] << " ";
            }
        }
        cout << endl;
    }

    cout << "Matriz de caminos:" << endl;
    for(int i = 0; i < n; i++){
        cout << "\t";
        for(int j = 0; j < n; j++){
            if(matriz_caminos[i][j] == INF){
                cout << "INF ";
            }

            else{
                cout << matriz_caminos[i][j] + 1 << " ";
            }
        }
        cout << endl;
    }
}

void Floyd_Warshall::camino_minimo() {
    vector<vector<int>> matriz_costos(n, vector<int>(n, INF));
    vector<vector<int>> matriz_caminos(n, vector<int>(n, INF));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matriz_costos[i][j] = matriz_adyacencia[i][j];

            if(matriz_adyacencia[i][j] != INF){
                matriz_caminos[i][j] = j;
            }
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                if(matriz_costos[i][k] != INF && matriz_costos[k][j] != INF){
                    matriz_costos[i][j] = min(matriz_costos[i][j], matriz_costos[i][k] + matriz_costos[k][j]);
                    matriz_caminos[i][j] = matriz_caminos[i][k];
                }
            }
        }
    }

    mostrar_matrices(matriz_costos, matriz_caminos);
}