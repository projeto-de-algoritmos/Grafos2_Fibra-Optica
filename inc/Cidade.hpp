#ifndef CIDADE_HPP
#define CIDADE_HPP

#include "Estruturas.hpp"

#include <iostream>
#include <vector>

using namespace std;

class Cidade {
private:
    int id;
    string nome;
    vector <Aresta> vizinhos;
    bool instalada;
public:
    Cidade(int id, string nome, bool instalada);
    int getId();
    string getNome();
    void novoVizinho(int id, double peso);
    bool isInstalada();
    void setInstalada(bool instalada);
    void deletaVizinho(int vizinhoId);
    bool isVizinho(int id);
    bool temVizinho();
    void setCusto(int cidade, double custo);
    void imprimirArestas();
    vector <Aresta> getArestas();
};

#endif
