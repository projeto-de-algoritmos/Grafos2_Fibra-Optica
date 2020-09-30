#ifndef ESTRUTURAS_HPP
#define ESTRUTURAS_HPP


typedef struct Aresta {
    int destino;
    double peso;
}Aresta;

typedef struct Distancia {
    int origem; 
    int destino; 
    double valor = -1; 
}Distancia; 
#endif
