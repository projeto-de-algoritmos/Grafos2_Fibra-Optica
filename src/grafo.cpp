#include "grafo.hpp"

#include <limits.h>

using namespace std;

void Grafo::novoVertice(string nome, bool instalada) {
    cidades.push_back(Cidade(cidades.size(), nome, instalada));
}

void Grafo::imprimirCidades() {
    cout << endl;
    for(Cidade c: cidades) {
        cout << c.getNome();
        if(c.isInstalada())
            cout << " (instalada)" << endl;
        else
            cout << " (não instalada)" << endl;
        for(Aresta a: c.getArestas())
            cout << "   " << a.peso << " km para " << cidades[a.destino].getNome() << endl;
        cout << endl;
    }
    if(cidades.empty())
        cout << "Não há cidades cadastradas." << endl;
}

int Grafo::getTamanho() {
    return cidades.size();
}

void Grafo::reset() {
    cidades.clear();
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
    if(!cidades[cidadeA].isVizinho(cidadeB)){
        cidades[cidadeA].novoVizinho(cidadeB, custo);
        cidades[cidadeB].novoVizinho(cidadeA, custo);
    }
    else 
        cout << "As cidades já estão conectadas" << endl;
}

void Grafo::desconectar(string nome1, string nome2) {
    int id1 = -1, id2 = -1;
    for(int i = 0; i < cidades.size(); i++) {
        if(cidades[i].getNome() == nome1)
            id1 = i;
        else if(cidades[i].getNome() == nome2)
            id2 = i;
        if(id1 != -1 && id2 != -1)
            break;
    }
    if(id1 != -1 && id2 != -1) {
        cidades[id1].deletaVizinho(id2);
        cidades[id2].deletaVizinho(id1);
    }
}

int Grafo::custoMinimo(vector <int> &custos, vector <bool> &visitados) {
    int minimo = INT_MAX, posicao = -1;
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
    int id = -1;
    for(Cidade c: cidades){
        if(c.getNome() == nome)
            return (c.getId()); 
    }
    return id;
}

int Grafo::prim(string nome) {
    int verticeInicial = buscarCidade(nome);
    vector <int> predecessores(cidades.size(), -1), custos(cidades.size(), INT_MAX), distancias;
    vector <bool> visitados(cidades.size(), false);
    vector<vector<string>> vertices;
    int total = 0, u = verticeInicial;
    custos[verticeInicial] = 0;
    for(int i = 0; i < cidades.size(); i++) {
        if(i > 0)
            u = custoMinimo(custos, visitados);
        if(u == -1)
            break;
        visitados[u] = true;
        for(Aresta aresta: cidades[u].getArestas()) {
            if(!visitados[aresta.destino] && aresta.peso < custos[aresta.destino]) {
                predecessores[aresta.destino] = u;
                custos[aresta.destino] = aresta.peso;
            }
        }
        if(predecessores[u] != -1) {
            vector<string> par;
            par.push_back(cidades[u].getNome());
            par.push_back(cidades[predecessores[u]].getNome());
            vertices.push_back(par);
            par.clear();
            distancias.push_back(custos[u]);
            total += custos[u];
        }
    }
    for(int i = 0; i < vertices.size(); i++)
        cout << vertices[i][0] << " - " << vertices[i][1] << "   " << distancias[i] << " km" << endl;
    cout << endl << total << " km de fibra óptica serão necessários." << endl;
    return total;
}
int Grafo::dijkstra(int id1){
    Distancia dist_temp;
    vector <Distancia> distancias(cidades.size());
    vector <Distancia> listaPrioridades;
    int cidadeProxima = -1; 
    if(verificaInstalacao(id1))
       return -1;
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
    if(cidadeProxima != -1){
        cout << "A distância para a cidade mais próxima com instalação é de " << distancias[cidadeProxima].valor << " km" << endl;
        return distancias[cidadeProxima].valor; 
    }
    return -1;
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

void Grafo::inverterStatus(string nome) {
    Cidade *cidade;
    int tamanho = cidades.size();
    for(int i = 0; i < tamanho; i++) {
        if(cidades[i].getNome() == nome) {
            cidade = &cidades[i];
            cidades[i].setInstalada(!cidades[i].isInstalada());
            break;
        }
    }
    cout << cidade->getNome() << " agora ";
    if(cidade->isInstalada())
        cout << "possui instalação." << endl;
    else
        cout << "não possui instalação." << endl;
}