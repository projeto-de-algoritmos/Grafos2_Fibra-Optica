#include "grafo.hpp"

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
