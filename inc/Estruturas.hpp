#ifndef ESTRUTURAS_HPP
#define ESTRUTURAS_HPP

typedef struct Aresta {
    int destino;
    int peso;
}Arestas;

typedef struct Distancia {
    int origem;
    int destino;
    int valor;
}Distancia;

#endif
