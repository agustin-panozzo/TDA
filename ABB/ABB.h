#ifndef ABB_H
#define ABB_H

#include <iostream>
#include "NodoArbol.h"

template <typename Tipo>
class ABB {
    private:
        NodoArbol<Tipo>* raiz;

        void reemplazar_nodo(NodoArbol<Tipo>* nodo_actual, NodoArbol<Tipo>* nodo_nuevo);

        NodoArbol<Tipo>* obtener_sucesor(NodoArbol<Tipo>* nodo_actual);

        Tipo buscar(Tipo dato, NodoArbol<Tipo>* nodo_actual);

        void insertar(Tipo dato, NodoArbol<Tipo>* nodo_actual);

        void eliminar(Tipo dato, NodoArbol<Tipo>* nodo_actual);

        void mostrar_subarbol(NodoArbol<Tipo>* nodo_actual);

        void eliminar_arbol(NodoArbol<Tipo>* nodo_actual);

        bool nodo_existe(Tipo dato);

    public:
        ABB();

        Tipo buscar(Tipo dato);

        void insertar(Tipo dato);

        void eliminar(Tipo dato);

        void mostrar_arbol();

        ~ABB();
};

template <typename Tipo>
ABB<Tipo>::ABB(){
    this->raiz = nullptr;
}

template <typename Tipo>
Tipo ABB<Tipo>::buscar(Tipo dato){
    return buscar(dato, raiz);
}

template <typename Tipo>
Tipo ABB<Tipo>::buscar(Tipo dato, NodoArbol<Tipo>* nodo_actual){
    if(nodo_actual == nullptr){
        return Tipo();
    }

    else if(nodo_actual -> obtener_elemento() == dato){
        return dato;
    }

    else if(nodo_actual -> obtener_elemento() > dato){
        return buscar(dato, nodo_actual -> obtener_hijo_izquierdo());
    }

    else{
        return buscar(dato, nodo_actual -> obtener_hijo_derecho());
    }

}

template <typename Tipo>
void ABB<Tipo>::insertar(Tipo dato){
    return insertar(dato, raiz);
}

template <typename Tipo>
void ABB<Tipo>::insertar(Tipo dato, NodoArbol<Tipo>* nodo_actual){
    NodoArbol<Tipo>* nodo_nuevo;

    if(nodo_existe(dato)){
        std::cout << "El nodo ya existe" << std::endl;
    }

    else if(nodo_actual == nullptr){
        raiz = new NodoArbol<Tipo>(dato);
    }

    else{

        if(nodo_actual -> obtener_elemento() > dato){

            if(!nodo_actual -> obtener_hijo_izquierdo()){
                nodo_nuevo = new NodoArbol<Tipo>(dato);
                nodo_nuevo -> asignar_padre(nodo_actual);
                nodo_actual -> asignar_hijo_izquierdo(nodo_nuevo);
            }

            else{
                insertar(dato, nodo_actual -> obtener_hijo_izquierdo());
            }
        }

        else{
            
            if(!nodo_actual -> obtener_hijo_derecho()){
                nodo_nuevo = new NodoArbol<Tipo>(dato);
                nodo_nuevo -> asignar_padre(nodo_actual);
                nodo_actual -> asignar_hijo_derecho(nodo_nuevo);
            }

            else{
                insertar(dato, nodo_actual -> obtener_hijo_derecho());
            }
        }
    }
}

template <typename Tipo>
NodoArbol<Tipo>* ABB<Tipo>::obtener_sucesor(NodoArbol<Tipo>* nodo_actual){
    NodoArbol<Tipo>* nodo_sucesor = nodo_actual -> obtener_hijo_derecho();

    while(nodo_sucesor -> obtener_hijo_izquierdo()){
        nodo_sucesor = nodo_sucesor -> obtener_hijo_izquierdo();
    }

    return nodo_sucesor;
}

template <typename Tipo>
void ABB<Tipo>::reemplazar_nodo(NodoArbol<Tipo>* nodo_actual, NodoArbol<Tipo>* nodo_nuevo){
    NodoArbol<Tipo>* nodo_padre = nodo_actual -> obtener_padre();

    if(nodo_nuevo){
        nodo_nuevo -> asignar_padre(nodo_padre);
    }

    if(nodo_padre -> obtener_hijo_izquierdo() == nodo_actual){
        nodo_padre -> asignar_hijo_izquierdo(nodo_nuevo);
    }

    else{
        nodo_padre -> asignar_hijo_derecho(nodo_nuevo);
    }
}

template <typename Tipo>
void ABB<Tipo>::eliminar(Tipo dato){
    eliminar(dato, raiz);
}

template <typename Tipo>
void ABB<Tipo>::eliminar(Tipo dato, NodoArbol<Tipo>* nodo_actual){
    if(dato == nodo_actual -> obtener_elemento()){

        if(nodo_actual -> obtener_hijo_izquierdo() && nodo_actual -> obtener_hijo_derecho()){
            NodoArbol<Tipo>* nodo_sucesor = obtener_sucesor(nodo_actual);
            nodo_actual -> asignar_elemento(nodo_sucesor -> obtener_elemento());
            eliminar(nodo_sucesor -> obtener_elemento(), nodo_sucesor);
        }

        else if(nodo_actual -> obtener_hijo_izquierdo()){
            reemplazar_nodo(nodo_actual, nodo_actual -> obtener_hijo_izquierdo());
            delete nodo_actual;
            nodo_actual = nullptr;
        }

        else if(nodo_actual -> obtener_hijo_derecho()){
            reemplazar_nodo(nodo_actual, nodo_actual -> obtener_hijo_derecho());
            delete nodo_actual;
            nodo_actual = nullptr;
        }

        else{
            reemplazar_nodo(nodo_actual, nullptr);
            delete nodo_actual;
            nodo_actual = nullptr;
        }
    }

    else if(dato < nodo_actual -> obtener_elemento()){
        eliminar(dato, nodo_actual -> obtener_hijo_izquierdo());
    }

    else{
        eliminar(dato, nodo_actual -> obtener_hijo_derecho());
    }
}

template <typename Tipo>
void ABB<Tipo>::mostrar_subarbol(NodoArbol<Tipo>* nodo_actual){
    if(nodo_actual){
        mostrar_subarbol(nodo_actual -> obtener_hijo_izquierdo());
        std::cout << nodo_actual -> obtener_elemento() << " ";
        mostrar_subarbol(nodo_actual -> obtener_hijo_derecho());
    }
}

template <typename Tipo>
void ABB<Tipo>::mostrar_arbol(){
    if(!raiz){
        std::cout << "El arbol esta vacio" << std::endl;
    }

    else{
        mostrar_subarbol(raiz);
    }

    std::cout << std::endl;
}

template <typename Tipo>
bool ABB<Tipo>::nodo_existe(Tipo dato){
    return buscar(dato) == dato;
}

template <typename Tipo>
void ABB<Tipo>::eliminar_arbol(NodoArbol<Tipo>* nodo_actual){
    if(nodo_actual){
        eliminar_arbol(nodo_actual -> obtener_hijo_izquierdo());
        eliminar_arbol(nodo_actual -> obtener_hijo_derecho());
        delete nodo_actual;
        nodo_actual = nullptr;
    }
}

template <typename Tipo>
ABB<Tipo>::~ABB(){
    std::cout << "Borrando árbol..." << std::endl;
    eliminar_arbol(raiz);
}

#endif // ABB_H