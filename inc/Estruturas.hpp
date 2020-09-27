#ifndef ESTRUTURAS_HPP
#define ESTRUTURAS_HPP


typedef struct Aresta {
    int destino;
    int peso;
}Aresta;

typedef struct Distancia {
    int origem; 
    int destino; 
    int valor = -1; 
}Distancia; 
#endif
