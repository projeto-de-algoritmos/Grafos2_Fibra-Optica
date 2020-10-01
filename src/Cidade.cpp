#include "Cidade.hpp"

Cidade::Cidade(int id, string nome, bool instalada) {
    this->nome = nome;
    this->id = id;
    this->instalada = instalada;
}

int Cidade::getId() {
    return id;
}

string Cidade::getNome() {
    return nome;
}

void Cidade::novoVizinho(int id, double peso) {
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
    int tamanho = vizinhos.size();
    for(int i = 0; i < tamanho; i++) {
        if(vizinhos[i].destino == vizinhoId) {
            vizinhos.erase(vizinhos.begin() + i);
            return;
        }
    }
}

bool Cidade::isVizinho(int id) {
    for(Aresta a: vizinhos){
        if(a.destino == id) 
            return true;
    }
    return false;
}

bool Cidade::temVizinho() {
    if(!vizinhos.empty())
        return true;
    else
        return false;
}

void Cidade::setCusto(int cidade, double custo) {
    int tamanho = vizinhos.size();
    for(int i = 0; i < tamanho; i++) {
        if(vizinhos[i].destino == cidade) {
            vizinhos[i].peso = custo;
            return;
        }
    }
}

vector <Aresta> Cidade::getArestas() {
    return vizinhos;
}
