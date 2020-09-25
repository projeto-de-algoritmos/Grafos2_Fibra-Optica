#include "grafo.hpp"

#include <limits.h>

using namespace std;

void Grafo::novoVertice(string nome) {
    cidades.push_back(Cidade(cidades.size(), nome));
}

void Grafo::imprimirCidades() {
    cout << endl;
    for(Cidade c: cidades) {
        cout << c.getNome() << endl;
        for(Aresta a: c.getArestas())
            cout << "   " << a.peso << " para " << cidades[a.destino].getNome() << endl;
        cout << endl;
    }
}

void Grafo::conectar(string a, string b, int custo) {
    int cidadeA = -1, cidadeB = -1;
    for(int i = 0; i < cidades.size(); i++) {
        if(cidades[i].getNome() == a)
            cidadeA = i;
        else if(cidades[i].getNome() == b)
            cidadeB = i;
        if(cidadeA != -1 && cidadeB != -1)
            break;
    }
    cidades[cidadeA].novoVizinho(cidadeB, custo);
    cidades[cidadeB].novoVizinho(cidadeA, custo);
}

int Grafo::custoMinimo(vector <int> &custos, vector <bool> &visitados) {
    int minimo = INT_MAX, posicao;
    for(int i = 0; i < custos.size(); i++) {
        if(!visitados[i] && custos[i] < minimo) {
            minimo = custos[i];
            posicao = i;
        }
    }
    return posicao;
}

void Grafo::copiarGrafo(Grafo &grafo) {
    for(Cidade cidade: cidades)
        grafo.novoVertice(cidade.getNome());
}

void Grafo::prim() {
    vector <int> predecessores(cidades.size(), -1), custos(cidades.size(), INT_MAX);
    vector <bool> visitados(cidades.size(), false);
    Grafo arvore;
    copiarGrafo(arvore);
    custos[0] = 0;
    predecessores[0] = -1;
    for(int i = 0; i < cidades.size(); i++) {
        int u = custoMinimo(custos, visitados);
        visitados[u] = true;
        for(Aresta aresta: cidades[u].getArestas()) {
            if(!visitados[aresta.destino] && aresta.peso < custos[aresta.destino]) {
                predecessores[aresta.destino] = u;
                custos[aresta.destino] = aresta.peso;
            }
        }
        if(predecessores[u] != -1)
            arvore.conectar(cidades[u].getNome(), cidades[predecessores[u]].getNome(), custos[u]);
    }
    cout << endl;
    arvore.imprimirCidades();
}