#ifndef NODO_LISTA_H
#define NODO_LISTA_H

#include <iostream>

template <typename Tipo>
class NodoLista {
    private:
        Tipo elemento;
        NodoLista<Tipo>* siguiente;
        NodoLista<Tipo>* anterior;

    public:
        explicit NodoLista(Tipo elemento);

        Tipo obtener_elemento();

        NodoLista<Tipo>* obtener_siguiente();

        NodoLista<Tipo>* obtener_anterior();

        void asignar_siguiente(NodoLista<Tipo>* siguiente);

        void asignar_anterior(NodoLista<Tipo>* anterior);

        ~NodoLista() = default;
};

template <typename Tipo>
NodoLista<Tipo>::NodoLista(Tipo elemento){
    this -> elemento = elemento;
    this -> siguiente = nullptr;
    this -> anterior = nullptr;
}

template <typename Tipo>
Tipo NodoLista<Tipo>::obtener_elemento(){
    return elemento;
}

template <typename Tipo>
NodoLista<Tipo>* NodoLista<Tipo>::obtener_siguiente(){
    return siguiente;
}

template <typename Tipo>
NodoLista<Tipo>* NodoLista<Tipo>::obtener_anterior(){
    return anterior;
}

template <typename Tipo>
void NodoLista<Tipo>::asignar_siguiente(NodoLista<Tipo>* siguiente){
    this -> siguiente = siguiente;
}

template <typename Tipo>
void NodoLista<Tipo>::asignar_anterior(NodoLista<Tipo>* anterior){
    this -> anterior = anterior;
}

#endif // NODO_LISTA_H