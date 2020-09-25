#ifndef CIDADE_HPP
#define CIDADE_HPP

#include <iostream> 
#include <string> 
#include <vector> 

using namespace std;

class Cidade {
private: 
    int id;
    string nome; 
public: 
    Cidade();
    int getId();
    string getNome();
    void imprimeDados();
};

#endif 