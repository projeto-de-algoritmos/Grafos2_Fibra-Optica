#include "Cidade.hpp"

Cidade::Cidade(){}

Cidade::Cidade(int id, string nome){
    this->nome = nome; 
    this->id = id;
}

int Cidade::getId(){
    return id;
}
string Cidade::getNome(){
    return nome; 
}
void imprimeDados();