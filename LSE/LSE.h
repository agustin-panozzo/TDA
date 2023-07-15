#ifndef LISTA_H
#define LISTA_H

#include "NodoLista.h"
#include <iostream>

const int TAMANIO_INICIAL = 1;

template <typename Tipo>
class LSE{
    private:
        NodoLista<Tipo>* primero;
        int tamanio;

        NodoLista<Tipo>* obtener_nodo(int indice);

    public:
        LSE();

        void insertar(Tipo elemento, int indice);

        void insertar_inicio(Tipo elemento);

        void insertar_final(Tipo elemento);

        void eliminar(Tipo elemento);

        void eliminar_por_indice(int indice);

        void mostrar_elementos();

        ~LSE();
};

template <typename Tipo>
LSE<Tipo>::LSE() {
    this -> primero = nullptr;
    this -> tamanio = TAMANIO_INICIAL;
}

template <typename Tipo>
NodoLista<Tipo>* LSE<Tipo>::obtener_nodo(int indice){
    if(indice < 0 || indice >= tamanio){
        throw std::out_of_range("Indice fuera de rango");
    }

    NodoLista<Tipo>* actual = primero;

    for(int i = 0; i < indice; i++){
        actual = actual->obtener_siguiente();
    }

    return actual;
}

template <typename Tipo>
void LSE<Tipo>::insertar(Tipo elemento, int indice){
    if(indice < 0 || indice >= tamanio){
        throw std::out_of_range("Indice fuera de rango");
    }

    if(indice == 0){
        insertar_inicio(elemento);
    }

    else{
        NodoLista<Tipo>* nuevo = new NodoLista<Tipo>(elemento);
        NodoLista<Tipo>* anterior = obtener_nodo(indice - 1);

        anterior -> asignar_siguiente(nuevo);
        nuevo -> asignar_siguiente(anterior -> obtener_siguiente());
    }

    tamanio++;
}

template <typename Tipo>
void LSE<Tipo>::insertar_inicio(Tipo elemento){
    NodoLista<Tipo>* nuevo = new NodoLista<Tipo>(elemento);
    nuevo -> asignar_siguiente(primero);
    primero = nuevo;
    tamanio++;
}

template <typename Tipo>
void LSE<Tipo>::insertar_final(Tipo elemento){
    NodoLista<Tipo>* nuevo = new NodoLista<Tipo>(elemento);

    if(primero == nullptr){
        primero = nuevo;
    }

    else{
        NodoLista<Tipo>* actual = primero;

        while(actual -> obtener_siguiente() != nullptr){
            actual = actual -> obtener_siguiente();
        }

        actual -> asignar_siguiente(nuevo);
    }
}

template <typename Tipo>
void LSE<Tipo>::eliminar(Tipo elemento){
    NodoLista<Tipo>* actual = primero;
    NodoLista<Tipo>* anterior = nullptr;

    while(actual != nullptr && actual -> obtener_elemento() != elemento){
        anterior = actual;
        actual = actual -> obtener_siguiente();
    }

    if(!actual){
        std::cout << "El elemento no se encuentra en la lista" << std::endl;
    }

    else if(!anterior){ // Caso en el que el elemento a eliminar es el primero
        primero = actual -> obtener_siguiente();
    }

    else{
        anterior -> asignar_siguiente(actual -> obtener_siguiente());
    }

    delete actual;
    tamanio--;
}

template <typename Tipo>
void LSE<Tipo>::eliminar_por_indice(int indice){
    if(indice < 0 || indice >= tamanio){
        throw std::out_of_range("Indice fuera de rango");
    }

    NodoLista<Tipo>* actual = primero;
    NodoLista<Tipo>* anterior = nullptr;

    for(int i = 0; i < indice; i++){
        anterior = actual;
        actual = actual -> obtener_siguiente();
    }

    if(!anterior){ // Caso en el que el elemento a eliminar es el primero
        primero = actual -> obtener_siguiente();
    }

    else{
        anterior -> asignar_siguiente(actual -> obtener_siguiente());
    }

    delete actual;
    tamanio--;
}

template <typename Tipo>
void LSE<Tipo>::mostrar_elementos(){
    NodoLista<Tipo>* actual = primero;

    while(actual != nullptr){
        std::cout << actual -> obtener_elemento() << std::endl;
        actual = actual -> obtener_siguiente();
    }
}

template <typename Tipo>
LSE<Tipo>::~LSE(){
    std::cout << "Eliminando lista..." << std::endl;

    NodoLista<Tipo>* actual = primero;
    NodoLista<Tipo>* siguiente = nullptr;

    while(actual != nullptr){
        siguiente = actual -> obtener_siguiente();
        delete actual;
        actual = siguiente;
    }
}

#endif // LISTA_H