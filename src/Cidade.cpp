#include "Cidade.hpp"

Cidade::Cidade(){}

Cidade::Cidade(int id, string nome){
    this->nome = nome; 
    this->id = id;
}

int Cidade::getId(){
    return id;
}

void Cidade::conectar(int id, int peso) {
    Aresta temp; 
    temp.destino = id;
    temp.peso = peso;
    vizinhos.push_back(temp);
}

string Cidade::getNome(){
    return nome;
}

void Cidade::imprimeDados(){
    cout << nome << endl;

}