#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "Cidade.hpp"

#include <iostream>
#include <vector>

class Grafo {
private:
    vector <Cidade> cidades;
public:
    void conectar(string a, string b, int custo);
};

#endif
