#ifndef COLA_H
#define COLA_H

const int TAMANIO_INICIAL = 10;

template <typename Tipo>
class Cola{
    private:
        Tipo* cola;
        int frente;
        int final;
        int capacidad;

        bool esta_llena();

        void redimensionar();

    public:
        Cola();
        explicit Cola(int capacidad);

        void encolar(Tipo elemento);

        Tipo desencolar();

        Tipo obtener_frente();

        bool esta_vacia();

        int obtener_tamanio();

        ~Cola();
};

template <typename Tipo>
Cola<Tipo>::Cola(){
    this -> cola = new Tipo[TAMANIO_INICIAL];
    this -> frente = 0;
    this -> final = 0;
    this -> capacidad = TAMANIO_INICIAL;
}

template <typename Tipo>
Cola<Tipo>::Cola(int capacidad){
    this -> cola = new Tipo[capacidad];
    this -> frente = 0;
    this -> final = 0;
    this -> capacidad = capacidad;
}

template <typename Tipo>
bool Cola<Tipo>::esta_llena(){
    return final == capacidad - 1;
}

template <typename Tipo>
void Cola<Tipo>::redimensionar(){
    Tipo* nueva_cola = new Tipo[capacidad * 2];
    int nuevo_indice = 0;
    capacidad *= 2;
    
    for(int i = frente; i < final; i++){
        nueva_cola[nuevo_indice] = cola[i];
        nuevo_indice++;
    }

    frente = 0;
    final = nuevo_indice;

    delete[] cola;
    cola = nueva_cola;
}

template <typename Tipo>
void Cola<Tipo>::encolar(Tipo elemento){
    if(esta_llena()){
        redimensionar();
    }

    cola[final] = elemento;
    final++;
}

template <typename Tipo>
Tipo Cola<Tipo>::desencolar(){
    Tipo elemento = cola[frente];
    frente++;

    return elemento;
}

template <typename Tipo>
Tipo Cola<Tipo>::obtener_frente(){
    return cola[frente];
}

template <typename Tipo>
bool Cola<Tipo>::esta_vacia(){
    return frente == final;
}

template <typename Tipo>
int Cola<Tipo>::obtener_tamanio(){
    return final - frente;
}

template <typename Tipo>
Cola<Tipo>::~Cola(){
    delete[] cola;
}

#endif // COLA_H