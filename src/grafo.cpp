#include "grafo.hpp"

using namespace std;

void Grafo::novoVertice(string nome) {
    cidades.push_back(Cidade(cidades.size(), nome));
}

void Grafo::imprimirCidades() {
    for(Cidade c: cidades) {
        cout << c.getNome();
        for(Aresta a: c.getArestas())
            cout << a.peso << " para " << cidades[a.destino].getNome() << endl;
        cout << endl;
    }
}

void Grafo::conectar(string a, string b, int custo) {
    
}
