#ifndef LISTA_H
#define LISTA_H

#include "NodoLista.h"
#include "Cursor.h"
#include <iostream>

template <typename Tipo>
class LDE{
    private:
        NodoLista<Tipo>* primero;
        NodoLista<Tipo>* ultimo;
        Cursor<Tipo> cursor;
        int tamanio;

        NodoLista<Tipo>* obtener_nodo(int indice);
        
        void insertar_inicio(Tipo elemento);

        void insertar_final(Tipo elemento);

    public:
        LDE();

        void insertar(Tipo elemento, int indice);

        void eliminar(Tipo elemento);

        void eliminar_por_indice(int indice);

        void mostrar_elementos();

        int obtener_tamanio();

        void insertar_cursor(Tipo elemento);

        void eliminar_cursor();

        void siguiente();

        void anterior();

        void inicio();

        void final();

        Tipo elemento_cursor();

        ~LDE();
};

template <typename Tipo>
LDE<Tipo>::LDE() : primero(nullptr), ultimo(nullptr), cursor(Cursor<Tipo>()), tamanio(0) {}

template <typename Tipo>
NodoLista<Tipo>* LDE<Tipo>::obtener_nodo(int indice){
    if(indice < 0 || indice > tamanio){
        throw std::out_of_range("Indice fuera de rango");
    }

    NodoLista<Tipo>* actual;

    if(tamanio / 2 <= indice){ // Si el indice es mayor a la mitad del tamanio de la lista, se recorre desde el final
        actual = ultimo;

        for(int i = tamanio - 1; i > indice; i--){
            actual = actual->obtener_anterior();
        }
    }

    else{ // Si el indice es menor a la mitad del tamanio de la lista, se recorre desde el principio
        actual = primero;

        for(int i = 0; i < indice; i++){
            actual = actual->obtener_siguiente();
        }
    }

    return actual;
}

template <typename Tipo>
void LDE<Tipo>::insertar(Tipo elemento, int indice){
    if(indice < 0 || indice > tamanio){
        throw std::out_of_range("Indice fuera de rango");
    }

    if(indice == 0){
        insertar_inicio(elemento);
    }

    else if(indice == tamanio){
        insertar_final(elemento);
    } 

    else{
        NodoLista<Tipo>* nuevo = new NodoLista<Tipo>(elemento);
        NodoLista<Tipo>* actual = obtener_nodo(indice);

        actual -> obtener_anterior() -> asignar_siguiente(nuevo);
        nuevo -> asignar_anterior(actual -> obtener_anterior());
        nuevo -> asignar_siguiente(actual);
        actual -> asignar_anterior(nuevo);
    }

    tamanio++;
}

template <typename Tipo>
void LDE<Tipo>::insertar_inicio(Tipo elemento){
    NodoLista<Tipo>* nuevo = new NodoLista<Tipo>(elemento);

    nuevo -> asignar_siguiente(primero);

    if(primero){
        primero -> asignar_anterior(nuevo);
    }

    primero = nuevo;

    if(tamanio == 0){
        ultimo = nuevo;
    }

    if(!cursor.obtener_nodo()){
        cursor.apuntar(primero);
    }
}

template <typename Tipo>
void LDE<Tipo>::insertar_final(Tipo elemento){
    NodoLista<Tipo>* nuevo = new NodoLista<Tipo>(elemento);

    if(primero == nullptr){
        primero = nuevo;
        ultimo = nuevo;
    }

    else{
        NodoLista<Tipo>* actual = ultimo;

        actual -> asignar_siguiente(nuevo);
        nuevo -> asignar_anterior(actual);
    }

    ultimo = nuevo;
}

template <typename Tipo>
void LDE<Tipo>::eliminar(Tipo elemento){
    NodoLista<Tipo>* actual = primero;

    while(actual != nullptr && actual -> obtener_elemento() != elemento){
        actual = actual -> obtener_siguiente();
    }

    if(!actual){
        std::cout << "El elemento no se encuentra en la lista" << std::endl;
        return;
    }

    else if(actual -> obtener_elemento() == primero -> obtener_elemento()){ // Caso en el que el elemento a eliminar es el primero
        primero = actual -> obtener_siguiente();
        primero -> asignar_anterior(nullptr);
    }

    else if(actual -> obtener_elemento() == ultimo -> obtener_elemento()){
        ultimo = actual -> obtener_anterior();
        ultimo -> asignar_siguiente(nullptr);
    }

    else{
        actual -> obtener_anterior() -> asignar_siguiente(actual -> obtener_siguiente());
        actual -> obtener_siguiente() -> asignar_anterior(actual -> obtener_anterior());
    }

    delete actual;
    tamanio--;
}

template <typename Tipo>
void LDE<Tipo>::eliminar_por_indice(int indice){
    if(indice < 0 || indice > tamanio){
        throw std::out_of_range("Indice fuera de rango");
    }

    NodoLista<Tipo>* actual = primero;

    actual = obtener_nodo(indice);

    if(indice == 0){ // Caso en el que el elemento a eliminar es el primero
        primero = actual -> obtener_siguiente();
        primero -> asignar_anterior(nullptr);
    }

    else if(indice == tamanio - 1){
        ultimo = actual -> obtener_anterior();
        ultimo -> asignar_siguiente(nullptr);
    }

    else{
        NodoLista<Tipo>* anterior = actual -> obtener_anterior();
        NodoLista<Tipo>* siguiente = actual -> obtener_siguiente();

        anterior -> asignar_siguiente(siguiente);
        siguiente -> asignar_anterior(anterior);
    }

    delete actual;
    tamanio--;
}

template <typename Tipo>
void LDE<Tipo>::mostrar_elementos(){
    NodoLista<Tipo>* actual = primero;

    while(actual != nullptr){
        std::cout << actual -> obtener_elemento() << std::endl;
        actual = actual -> obtener_siguiente();
    }
}

template <typename Tipo>
LDE<Tipo>::~LDE(){
    std::cout << "Eliminando lista..." << std::endl;

    NodoLista<Tipo>* actual = primero;
    NodoLista<Tipo>* siguiente = nullptr;

    while(actual != nullptr){
        siguiente = actual -> obtener_siguiente();
        delete actual;
        actual = siguiente;
    }
}

template <typename Tipo>
int LDE<Tipo>::obtener_tamanio(){
    return tamanio;
}

template <typename Tipo>
void LDE<Tipo>::insertar_cursor(Tipo elemento){
    if(cursor.obtener_nodo() == ultimo){
        insertar_final(elemento);
    }

    else{
        NodoLista<Tipo>* nuevo = new NodoLista<Tipo>(elemento);
        NodoLista<Tipo>* actual = cursor.obtener_nodo();

        actual -> obtener_siguiente() -> asignar_anterior(nuevo);
        nuevo -> asignar_siguiente(actual -> obtener_siguiente());
        nuevo -> asignar_anterior(actual);
        actual -> asignar_siguiente(nuevo);
    }

    tamanio++;
}

template <typename Tipo>
void LDE<Tipo>::eliminar_cursor(){
    NodoLista<Tipo>* actual = cursor.obtener_nodo();

    if(actual == primero){
        primero = actual -> obtener_siguiente();
        primero -> asignar_anterior(nullptr);
    }

    else if(actual == ultimo){
        ultimo = actual -> obtener_anterior();
        ultimo -> asignar_siguiente(nullptr);
    }

    else{
        actual -> obtener_anterior() -> asignar_siguiente(actual -> obtener_siguiente());
        actual -> obtener_siguiente() -> asignar_anterior(actual -> obtener_anterior());
    }

    delete actual;
    tamanio--;
    actual = nullptr;
    cursor.apuntar(primero);
}

template <typename Tipo>
void LDE<Tipo>::siguiente(){
    cursor.aumentar_indice();
}

template <typename Tipo>
void LDE<Tipo>::anterior(){
    cursor.disminuir_indice();
}

template <typename Tipo>
void LDE<Tipo>::inicio(){
    cursor.apuntar(primero);
}

template <typename Tipo>
void LDE<Tipo>::final(){
    cursor.apuntar(ultimo);
}

template <typename Tipo>
Tipo LDE<Tipo>::elemento_cursor(){
    return cursor.obtener_elemento();
}

#endif // LISTA_H