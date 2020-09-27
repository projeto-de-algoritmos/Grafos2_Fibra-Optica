#include "grafo.hpp"

#include <limits.h>

using namespace std;

void Grafo::novoVertice(string nome, bool instalada) {
    cidades.push_back(Cidade(cidades.size(), nome, instalada));
}

void Grafo::imprimirCidades() {
    cout << endl;
    for(Cidade c: cidades) {
        cout << c.getNome() << endl;
        for(Aresta a: c.getArestas())
            cout << "   " << a.peso << " km para " << cidades[a.destino].getNome() << endl;
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
        grafo.novoVertice(cidade.getNome(), cidade.isInstalada());
}

int Grafo::buscarCidade(string nome){
    for(Cidade c: cidades){
        if(c.getNome() == nome)
            return (c.getId()); 
    }
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

void Grafo::dijkstra(int id1){
    Distancia dist_temp;
    vector <Distancia> distancias(cidades.size());
    vector <Distancia> listaPrioridades;
    int cidadeProxima; 
    if(verificaInstalacao(id1))
       return;
    dist_temp = criarDistancia(id1); 
    listaPrioridades.push_back(dist_temp);
    while(!listaPrioridades.empty()){
        Cidade aux = cidades[listaPrioridades[0].destino]; 
        distancias[aux.getId()] = listaPrioridades[0];
        if(aux.isInstalada()){
            cidadeProxima = aux.getId(); 
            break;
        } 
        listaPrioridades.erase(listaPrioridades.begin());
        for(Aresta a: aux.getArestas()){
            dist_temp.origem = aux.getId();
            dist_temp.destino = a.destino; 
            dist_temp.valor = a.peso + distancias[aux.getId()].valor; 
            int pos = verificaSub(listaPrioridades,distancias,dist_temp);
            if(pos >= 0){
                listaPrioridades.erase(listaPrioridades.begin()+pos); 
                listaPrioridades.push_back(dist_temp);
            }
            else if(pos == -1)
                listaPrioridades.push_back(dist_temp); 
        }
        sort(listaPrioridades.begin(), listaPrioridades.end(), [](Distancia a, Distancia b){return (a.valor < b.valor); 
        });
    }
    cout << "A distância para a cidade mais próxima com instalação é de " << distancias[cidadeProxima].valor << " km" << endl;
}



int Grafo::verificaSub(vector<Distancia> lista, vector <Distancia> distancias, Distancia temp){
            int achou = -1;
            int pos = -1;
            if(distancias[temp.destino].valor != -1)
                return -2;
            for(Distancia d:lista){
                pos++; 
                if(d.destino == temp.destino){
                    if(d.valor > temp.valor)
                        achou = pos; 
                    else
                        achou = -2;
                    break; 
                }
            }
            return achou; 
        }

bool Grafo::verificaInstalacao(int id){
    if(id == -1)
        return true;
    if(cidades[id].isInstalada()){
        cout << "A cidade já tem instalação" << endl;
        return true; 
    }
    return false; 
}

Distancia Grafo::criarDistancia(int id){
    Distancia dist_temp;
    dist_temp.origem = id; 
    dist_temp.destino = id;
    dist_temp.valor = 0;
    return dist_temp;
}
