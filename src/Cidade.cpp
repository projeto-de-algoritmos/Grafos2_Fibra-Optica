#include "Cidade.hpp"

Cidade::Cidade(int id, string nome) {
    this->nome = nome;
    this->id = id;
}

int Cidade::getId() {
    return id;
}

string Cidade::getNome() {
    return nome;
}

void Cidade::imprimeDados() {
    cout << nome << endl;
}

vector <Aresta> Cidade::getArestas() {
    return vizinhos;
}
