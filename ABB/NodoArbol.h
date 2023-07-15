#ifndef NODO_ARBOL_H
#define NODO_ARBOL_H

template<typename Tipo>
class NodoArbol {
    private:
        Tipo elemento;
        NodoArbol<Tipo>* padre;
        NodoArbol<Tipo>* hijo_izquierdo;
        NodoArbol<Tipo>* hijo_derecho;

    public:
        explicit NodoArbol(Tipo elemento);
        
        void asignar_elemento(Tipo elemento);

        Tipo obtener_elemento();

        NodoArbol<Tipo>* obtener_padre();

        NodoArbol<Tipo>* obtener_hijo_izquierdo();

        NodoArbol<Tipo>* obtener_hijo_derecho();

        void asignar_padre(NodoArbol<Tipo>* padre);

        void asignar_hijo_izquierdo(NodoArbol<Tipo>* hijo_izquierdo);

        void asignar_hijo_derecho(NodoArbol<Tipo>* hijo_derecho);

        ~NodoArbol() = default;
};

template <typename Tipo>
NodoArbol<Tipo>::NodoArbol(Tipo elemento){
    this->elemento = elemento;
    this->padre = nullptr;
    this->hijo_izquierdo = nullptr;
    this->hijo_derecho = nullptr;
}

template <typename Tipo>
void NodoArbol<Tipo>::asignar_elemento(Tipo elemento){
    this->elemento = elemento;
}

template <typename Tipo>
Tipo NodoArbol<Tipo>::obtener_elemento(){
    return elemento;
}

template <typename Tipo>
NodoArbol<Tipo>* NodoArbol<Tipo>::obtener_hijo_izquierdo(){
    return hijo_izquierdo;
}

template <typename Tipo>
NodoArbol<Tipo>* NodoArbol<Tipo>::obtener_hijo_derecho(){
    return hijo_derecho;
}

template <typename Tipo>
void NodoArbol<Tipo>::asignar_padre(NodoArbol<Tipo>* padre){
    this->padre = padre;
}

template <typename Tipo>
void NodoArbol<Tipo>::asignar_hijo_izquierdo(NodoArbol<Tipo>* hijo_izquierdo){
    this->hijo_izquierdo = hijo_izquierdo;
}

template <typename Tipo>
void NodoArbol<Tipo>::asignar_hijo_derecho(NodoArbol<Tipo>* hijo_derecho){
    this->hijo_derecho = hijo_derecho;
}

template <typename Tipo>
NodoArbol<Tipo>* NodoArbol<Tipo>::obtener_padre(){
    return padre;
}

#endif // NODO_ARBOL_H