#ifndef CIDADE_HPP
#define CIDADE_HPP

#include "Estruturas.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cidade {
private:
    int id;
    string nome;
    vector <Aresta> vizinhos;
public: 
    Cidade(int id, string nome);
    int getId();
    string getNome();
    void imprimeDados();
    vector <Aresta> getArestas();
};

#endif
