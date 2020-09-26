#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "Cidade.hpp"
#include "Estruturas.hpp"

#include <iostream>
#include <vector>

class Grafo {
private:
    vector <Cidade> cidades;
public:
    void conectar(string a, string b, int custo);
    void novoVertice(string nome);
    void imprimirCidades();
    void prim();
    void dijkstra(int id1, int id2); 
    int verificaSub(vector<Distancia> lista, vector <Distancia> distancias, Distancia temp);
    int custoMinimo(vector <int> &custos, vector <bool> &visitados);
    void copiarGrafo(Grafo &grafo);
};

#endif
