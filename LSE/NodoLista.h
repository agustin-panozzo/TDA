#ifndef NODO_LISTA_H
#define NODO_LISTA_H

template <typename Tipo>
class NodoLista {
    private:
        Tipo elemento;
        NodoLista<Tipo>* siguiente;

    public:
        explicit NodoLista(Tipo elemento);

        Tipo obtener_elemento();

        NodoLista<Tipo>* obtener_siguiente();

        void asignar_siguiente(NodoLista<Tipo>* siguiente);

        ~NodoLista() = default;
};

template <typename Tipo>
NodoLista<Tipo>::NodoLista(Tipo elemento){
    this -> elemento = elemento;
    this -> siguiente = nullptr;
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
void NodoLista<Tipo>::asignar_siguiente(NodoLista<Tipo>* siguiente){
    this -> siguiente = siguiente;
}

#endif // NODO_LISTA_H