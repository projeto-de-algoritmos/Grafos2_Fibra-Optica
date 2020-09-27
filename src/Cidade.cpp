#include "Cidade.hpp"

Cidade::Cidade(int id, string nome, bool instalada) {
    this->nome = nome;
    this->id = id;
    this->instalada = instalada;
}

int Cidade::getId() {
    return id;
}


void Cidade::imprimeDados(){
    cout << nome << endl;

}

string Cidade::getNome() {
    return nome;
}

vector <Aresta> Cidade::getArestas() {
    return vizinhos;
}

void Cidade::novoVizinho(int id, int peso) {
    Aresta aresta;
    aresta.destino = id;
    aresta.peso = peso;
    vizinhos.push_back(aresta);
}

bool Cidade::isInstalada(){
    return instalada;
}

void Cidade::setInstalada(bool instalada) {
    this->instalada = instalada;
}

void Cidade::deletaVizinho(int vizinhoId) {
    for(int i = 0; i < vizinhos.size(); i++) {
        if(vizinhos[i].destino == vizinhoId) {
            vizinhos.erase(vizinhos.begin() + i);
            cout << "As cidades foram desconectadas" << endl;
            return;
        }
    }
}
