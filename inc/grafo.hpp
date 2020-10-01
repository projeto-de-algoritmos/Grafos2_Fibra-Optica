#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "Cidade.hpp"

class Grafo {
private:
    vector <Cidade> cidades;
public:
    void conectar(string a, string b, double custo);
    void novoVertice(string nome, bool instalada);
    void imprimirCidades();
    int buscarCidade(string nome);
    int prim(string nome);
    int dijkstra(int id1);
    bool verificaInstalacao(int id);
    Distancia criarDistancia(int id);
    int verificaSub(vector<Distancia> lista, vector <Distancia> distancias, Distancia temp);
    int custoMinimo(vector <double> &custos, vector <bool> &visitados);
    void reset();
    bool temConexao();
    void inverterStatus(string nome);
    void desconectar(string nome1, string nome2);
};

#endif
