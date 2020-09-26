#ifndef CIDADE_HPP
#define CIDADE_HPP

#include <iostream> 
#include <string> 
#include <vector> 

#include "Estruturas.hpp"

using namespace std;

class Cidade {
private: 
    int id;
    string nome; 
    vector <Aresta> vizinhos; 
public: 
    Cidade();
    Cidade(int id, string nome);
    int getId();
    void conectar(int id, int peso); 
    string getNome();
    void imprimeDados();
};

#endif 