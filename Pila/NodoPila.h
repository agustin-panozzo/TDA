#ifndef NODO_PILA_H
#define NODO_PILA_H

template <typename Tipo>
class NodoPila {
    private:
        Tipo elemento;
        NodoPila<Tipo>* siguiente;

    public:
        explicit NodoPila(Tipo elemento);

        Tipo obtener_elemento();

        NodoPila<Tipo>* obtener_siguiente();

        void asignar_siguiente(NodoPila<Tipo>* siguiente);

        ~NodoPila() = default;
};

template <typename Tipo>
NodoPila<Tipo>::NodoPila(Tipo elemento){
    this -> elemento = elemento;
    this -> siguiente = nullptr;
}

template <typename Tipo>
Tipo NodoPila<Tipo>::obtener_elemento(){
    return elemento;
}

template <typename Tipo>
NodoPila<Tipo>* NodoPila<Tipo>::obtener_siguiente(){
    return siguiente;
}

template <typename Tipo>
void NodoPila<Tipo>::asignar_siguiente(NodoPila<Tipo>* siguiente){
    this -> siguiente = siguiente;
}

#endif // NODO_PILA_H