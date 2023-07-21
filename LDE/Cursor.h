#ifndef CURSOR_H
#define CURSOR_H

#include "NodoLista.h"

template <typename Tipo>
class Cursor{
    private:
        NodoLista<Tipo>* nodo;

    public:
        Cursor();
        explicit Cursor(NodoLista<Tipo>* nodo);

        void aumentar_indice();

        void disminuir_indice();

        NodoLista<Tipo>* obtener_nodo();

        void apuntar(NodoLista<Tipo>* nodo);

        Tipo obtener_elemento();

        ~Cursor() = default;
};

template <typename Tipo>
Cursor<Tipo>::Cursor() : nodo(nullptr) {}

template <typename Tipo>
Cursor<Tipo>::Cursor(NodoLista<Tipo>* nodo) : nodo(nodo) {}

template <typename Tipo>
void Cursor<Tipo>::aumentar_indice(){
    if(nodo -> obtener_siguiente()){
        nodo = nodo -> obtener_siguiente();
    }
}

template <typename Tipo>
void Cursor<Tipo>::disminuir_indice(){
    if(nodo -> obtener_anterior()){
        nodo = nodo -> obtener_anterior();
    }
}

template <typename Tipo>
NodoLista<Tipo>* Cursor<Tipo>::obtener_nodo(){
    return nodo;
}

template <typename Tipo>
void Cursor<Tipo>::apuntar(NodoLista<Tipo>* nodo){
    this -> nodo = nodo;
}

template <typename Tipo>
Tipo Cursor<Tipo>::obtener_elemento(){
    return nodo -> obtener_elemento();
}

#endif // CURSOR_H