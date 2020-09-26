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
    bool instalada; 
public: 
    Cidade(int id, string nome, bool instalada);
    int getId();
    string getNome();
    void imprimeDados();
    vector <Aresta> getArestas();
    void novoVizinho(int id, int peso);
    bool isInstalada();

};

#endif
