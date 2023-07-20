#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

#include "NodoLista.h"

template <typename Tipo>
class ListaCircular{
    private:
        int tamanio;
        NodoLista<Tipo>* primero;
        NodoLista<Tipo>* ultimo;
    
    public:
        ListaCircular();

        void insertar_frente(Tipo elemento);

        void insertar_final(Tipo elemento);

        bool eliminar(Tipo elemento);

        bool contiene(Tipo elemento);

        int size() const;

        void mostrar() const;

        ~ListaCircular();
};

template <typename Tipo>
ListaCircular<Tipo>::ListaCircular() : tamanio(0), primero(nullptr), ultimo(nullptr) {}

template <typename Tipo>
void ListaCircular<Tipo>::insertar_frente(Tipo elemento){
    NodoLista<Tipo>* nuevo_nodo = new NodoLista<Tipo>(elemento);

    if(tamanio == 0){
        primero = nuevo_nodo;
        ultimo = nuevo_nodo;

        primero -> asignar_siguiente(ultimo);
        primero -> asignar_anterior(ultimo);

        ultimo -> asignar_siguiente(primero);
        ultimo -> asignar_anterior(primero);    
    }

    else{
        nuevo_nodo -> asignar_siguiente(primero);
        nuevo_nodo -> asignar_anterior(ultimo);

        primero -> asignar_anterior(nuevo_nodo);
        ultimo -> asignar_siguiente(nuevo_nodo);

        primero = nuevo_nodo;
    }

    tamanio++;
}

template <typename Tipo>
void ListaCircular<Tipo>::insertar_final(Tipo elemento){
    NodoLista<Tipo>* nuevo_nodo = new NodoLista<Tipo>(elemento);

    if(tamanio == 0){
        primero = nuevo_nodo;
        ultimo = nuevo_nodo;

        primero -> asignar_siguiente(ultimo);
        primero -> asignar_anterior(ultimo);

        ultimo -> asignar_siguiente(primero);
        ultimo -> asignar_anterior(primero);
    }

    else{
        nuevo_nodo -> asignar_siguiente(primero);
        nuevo_nodo -> asignar_anterior(ultimo);

        primero -> asignar_anterior(nuevo_nodo);
        ultimo -> asignar_siguiente(nuevo_nodo);

        ultimo = nuevo_nodo;
    }

    tamanio++;
}

template <typename Tipo>
bool ListaCircular<Tipo>::eliminar(Tipo elemento){
    NodoLista<Tipo>* nodo_actual = primero;
    while(nodo_actual -> obtener_elemento() != elemento && nodo_actual -> obtener_siguiente() != primero){
        nodo_actual = nodo_actual -> obtener_siguiente();
    }

    if(nodo_actual -> obtener_elemento() == elemento){
        if(nodo_actual == primero){
            primero = nodo_actual -> obtener_siguiente();
        }

        if(nodo_actual == ultimo){
            ultimo = nodo_actual -> obtener_anterior();
        }

        nodo_actual -> obtener_anterior() -> asignar_siguiente(nodo_actual -> obtener_siguiente());
        nodo_actual -> obtener_siguiente() -> asignar_anterior(nodo_actual -> obtener_anterior());

        delete nodo_actual;
        tamanio--;
    }

    return nodo_actual -> obtener_elemento() == elemento;
}

template <typename Tipo>
bool ListaCircular<Tipo>::contiene(Tipo elemento){
    NodoLista<Tipo>* nodo_actual = primero;

    while(nodo_actual -> obtener_elemento() != elemento && nodo_actual -> obtener_siguiente() != primero){
        nodo_actual = nodo_actual -> obtener_siguiente();
    }

    return nodo_actual -> obtener_elemento() == elemento;
}

template <typename Tipo>
int ListaCircular<Tipo>::size() const{
    return tamanio;
}

template <typename Tipo>
void ListaCircular<Tipo>::mostrar() const{
    NodoLista<Tipo>* nodo_actual = primero;

    while(nodo_actual -> obtener_siguiente() != primero){
        std::cout << nodo_actual -> obtener_elemento() << " ";
        nodo_actual = nodo_actual -> obtener_siguiente();
    }

    std::cout << nodo_actual -> obtener_elemento() << std::endl;
}

template <typename Tipo>
ListaCircular<Tipo>::~ListaCircular(){
    if(tamanio != 0){
        NodoLista<Tipo>* nodo_actual = primero -> obtener_siguiente();
        NodoLista<Tipo>* nodo_eliminar;

        while(nodo_actual != primero){
            nodo_eliminar = nodo_actual;
            nodo_actual = nodo_actual -> obtener_siguiente();
            delete nodo_eliminar;
        }

        delete nodo_actual;
    }
}

#endif // LISTA_CIRCULAR_H