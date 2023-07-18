#ifndef PILA_H
#define PILA_H

#include <stdexcept>
#include "NodoPila.h"

template <typename Tipo>
class Pila{
    private:
        NodoPila<Tipo>* tope;

    public:
        Pila();

        void apilar(Tipo elemento);

        Tipo desapilar();

        Tipo obtener_tope();

        bool esta_vacia();

        ~Pila();
};

template <typename Tipo>
Pila<Tipo>::Pila(){
    tope = nullptr;
}

template <typename Tipo>
void Pila<Tipo>::apilar(Tipo elemento){
    NodoPila<Tipo>* nuevo_nodo = new NodoPila<Tipo>(elemento);
    nuevo_nodo -> asignar_siguiente(tope);
    tope = nuevo_nodo;
}

template <typename Tipo>
Tipo Pila<Tipo>::desapilar(){
    if(esta_vacia()){
        throw std::underflow_error("La pila esta vacia");
    }

    else{
        NodoPila<Tipo>* nodo_auxiliar = tope;
        Tipo elemento = nodo_auxiliar -> obtener_elemento();
        tope = tope -> obtener_siguiente();

        delete nodo_auxiliar;
        return elemento;
    }
}

template <typename Tipo>
Tipo Pila<Tipo>::obtener_tope(){
    if(esta_vacia()){
        throw std::underflow_error("La pila esta vacia");
    }

    else{
        return tope -> obtener_elemento();
    }
}

template <typename Tipo>
bool Pila<Tipo>::esta_vacia(){
    return tope == nullptr;
}

template <typename Tipo>
Pila<Tipo>::~Pila(){
    while(!esta_vacia()){
        desapilar();
    }
}

#endif // PILA_H