#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

const int CAPACIDAD_INICIAL = 1;

template <typename Tipo>
class Vector {
    private:
        Tipo* elementos;
        int tamanio;
        int capacidad;

        void resize(int nuevaCapacidad);

    public:
        Vector();
        explicit Vector(int capacidad);

        int size();

        bool empty();

        Tipo at(int indice);

        void push_back(Tipo elemento);

        Tipo pop_back();

        void clear();

        ~Vector();
};

template <typename Tipo>
Vector<Tipo>::Vector(){
    this->capacidad = CAPACIDAD_INICIAL;
    this->tamanio = 0;
    this->elementos = new Tipo[capacidad];
}

template <typename Tipo>
Vector<Tipo>::Vector(int capacidad) {
    this->capacidad = capacidad;
    this->tamanio = 0;
    this->elementos = new Tipo[capacidad];
}

template <typename Tipo>
int Vector<Tipo>::size(){
    return tamanio;
}

template <typename Tipo>
bool Vector<Tipo>::empty(){
    return tamanio == 0;
}

template <typename Tipo>
Tipo Vector<Tipo>::at(int indice){
    if (indice < 0 || indice >= tamanio) {
        throw std::out_of_range("Indice fuera de rango");
    }

    return elementos[indice];
}

template <typename Tipo>
void Vector<Tipo>::resize(int nuevaCapacidad){
    Tipo* nuevoArreglo = new Tipo[nuevaCapacidad];

    for(int i = 0; i < tamanio; i++){
        nuevoArreglo[i] = elementos[i];
    }

    delete[] elementos;
    elementos = nuevoArreglo;
    capacidad = nuevaCapacidad;
}

template <typename Tipo>
void Vector<Tipo>::push_back(Tipo elemento){
    if(tamanio == capacidad){
        resize(capacidad * 2);
    }

    elementos[tamanio] = elemento;
    tamanio++;
}

template <typename Tipo>
Tipo Vector<Tipo>::pop_back(){
    if(tamanio == 0){
        throw std::out_of_range("Vector vacio");
    }

    Tipo elemento = elementos[tamanio - 1];
    tamanio--;

    return elemento;
}

template <typename Tipo>
void Vector<Tipo>::clear(){
    tamanio = 0;
}

template <typename Tipo>
Vector<Tipo>::~Vector(){
    std::cout << "Eliminando vector..." << std::endl;
    delete[] elementos;
}

#endif // VECTOR_H