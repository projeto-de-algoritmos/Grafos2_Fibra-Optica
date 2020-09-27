#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "Cidade.hpp"
#include "Estruturas.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

class Grafo {
private:
    vector <Cidade> cidades;
public:
    void conectar(string a, string b, int custo);
    void novoVertice(string nome, bool instalada);
    void imprimirCidades();
    int buscarCidade(string nome); 
    int prim();
    int dijkstra(int id1); 
    bool verificaInstalacao(int id);
    Distancia criarDistancia(int id); 
    int verificaSub(vector<Distancia> lista, vector <Distancia> distancias, Distancia temp);
    int custoMinimo(vector <int> &custos, vector <bool> &visitados);
    void copiarGrafo(Grafo &grafo);
    void reset();
    int getTamanho();
    void inverterStatus(string nome);
    void desconectar(string nome1, string nome2);
};

#endif
